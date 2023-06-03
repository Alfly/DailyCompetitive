#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

struct PairHash {
  size_t operator()(const std::pair<int, int>& p) const {
    return p.first ^ p.second;
  }
};

struct Face {
  unordered_set<int> vertices;
  unordered_map<int, int> next;
};

struct Fragment {
  unordered_set<int> attachment;
  unordered_set<int> component;
  vector<int> face_indices;
  Fragment() {}
  Fragment(unordered_set<int> a) : attachment(a) {}
  Fragment(unordered_set<int> a, unordered_set<int> c) : attachment(a), component(c) {}
};

struct EmbeddedGraph {
  unordered_set<int> vertices;
  unordered_set<pair<int, int>, PairHash> edges;
  void add_edge(int u, int v) {
    if (u > v) swap(u, v);
    edges.emplace(u, v);
  }
  bool has_edge(int u, int v) const {
    if (u > v) swap(u, v);
    return edges.count({u, v});
  }
  bool operator!=(const EmbeddedGraph& other) const {
    return vertices != other.vertices || edges != other.edges;
  }
};

void Assert(bool condition, const string& msg) {
  if (!condition) {
    cout << msg << endl;
    exit(EXIT_FAILURE);
  }
}

vector<vector<pair<int, int>>> GetBlocks(const vector<vector<int>>& graph_adj) {
  enum { kWhite = 0,
         kGray,
         kBlack };

  int vertex_num = graph_adj.size();
  vector<vector<pair<int, int>>> res_block;

  int global_time = 0;
  int curr_root = 0;
  vector<int> color_set(vertex_num, kWhite);
  vector<int> parent_set(vertex_num, -1);
  vector<int> children_cnter(vertex_num, 0);
  vector<int> time_rec(vertex_num, 0);
  vector<int> back_rec(vertex_num, 0);
  stack<pair<int, int>> st;

  function<void(int)> dfs =
    [&](int v) {
      color_set[v] = kGray;
      global_time += 1;
      back_rec[v] = time_rec[v] = global_time;
      int num = graph_adj[v].size();
      for (int i = 0; i < num; ++i) {
        int neighbor = graph_adj[v][i];
        if (color_set[neighbor] == kWhite) {
          parent_set[neighbor] = v;
          children_cnter[v] += 1;
          st.emplace(v, neighbor);
          dfs(neighbor);
          if (
            (v == curr_root && children_cnter[v] > 1) ||
            (v != curr_root && back_rec[neighbor] >= time_rec[v])
          ) {
            vector<pair<int, int>> block;
            int x = -1, y = -1;
            do {
              if (st.empty()) break;
              std::tie(x, y) = st.top();
              st.pop();
              block.emplace_back(x, y);
            } while (!(x == v && y == neighbor));
            if (!block.empty()) res_block.push_back(block);
          }
          back_rec[v] = min(back_rec[v], back_rec[neighbor]);
        } else if (color_set[neighbor] == kGray && parent_set[v] != neighbor) {
          st.emplace(v, neighbor);
          back_rec[v] = min(back_rec[v], time_rec[neighbor]);
        }
      }
      color_set[v] = kBlack;
    };

  for (int i = 0; i < vertex_num; ++i) {
    if (color_set[i] == kWhite) {
      if (graph_adj[i].empty()) {
        res_block.push_back({});
        continue;
      }
      curr_root = i;
      dfs(curr_root);
      vector<pair<int, int>> block;
      while (!st.empty()) {
        int x = -1, y = -1;
        std::tie(x, y) = st.top();
        st.pop();
        block.emplace_back(x, y);
      }
      if (!block.empty()) res_block.push_back(block);
    }
  }

  return res_block;
}

vector<vector<int>> Block2Adj(vector<pair<int, int>> block) {
  vector<vector<int>> graph_adj;
  unordered_map<int, int> vertex_map;
  int vertex_num = 0;
  for (auto& edge : block) {
    if (!vertex_map.count(edge.first)) {
      vertex_map[edge.first] = vertex_num++;
      graph_adj.push_back({});
    }
    if (!vertex_map.count(edge.second)) {
      vertex_map[edge.second] = vertex_num++;
      graph_adj.push_back({});
    }
    graph_adj[vertex_map[edge.first]].push_back(vertex_map[edge.second]);
    graph_adj[vertex_map[edge.second]].push_back(vertex_map[edge.first]);
  }
  // cout << "vertex_map:" << endl;
  // for (auto& p : vertex_map) {
  //   cout << p.first << " " << p.second << endl;
  // }
  // cout << endl;
  return graph_adj;
}

EmbeddedGraph Adj2Embedded(const vector<vector<int>>& graph_adj) {
  EmbeddedGraph graph_embedded;
  int vertex_num = graph_adj.size();
  for (int i = 0; i < vertex_num; ++i) {
    graph_embedded.vertices.insert(i);
    for (int j : graph_adj[i]) {
      if (i < j) {
        graph_embedded.add_edge(i, j);
      }
    }
  }
  return graph_embedded;
}

vector<int> FindCycle(const vector<vector<int>>& graph_adj) {
  int vertex_num = graph_adj.size();
  vector<bool> visited(vertex_num, false);
  vector<int> parent(vertex_num, -1);
  vector<int> cycle;

  function<bool(int, int)> dfs =
    [&](int u, int p) {
      visited[u] = true;
      parent[u] = p;
      for (int v : graph_adj[u]) {
        if (!visited[v]) {
          if (dfs(v, u)) return true;
        } else if (v != p) {
          cycle.push_back(v);
          for (int x = u; x != v; x = parent[x]) {
            cycle.push_back(x);
          }
          return true;
        }
      }
      return false;
    };

  for (int i = 0; i < vertex_num; ++i) {
    if (!visited[i]) {
      if (dfs(i, -1)) break;
    }
  }
  Assert(!cycle.empty(), "No cycle found!");
  cycle.push_back(cycle.front());
  return cycle;
}

void UpdateEmbedding(
  EmbeddedGraph& graph_embedded, const vector<int>& path
) {
  for (int i = 0; i < path.size() - 1; ++i) {
    graph_embedded.vertices.insert(path[i]);
    graph_embedded.add_edge(path[i], path[i + 1]);
  }
  graph_embedded.vertices.insert(path.back());
}

void Init(
  const vector<vector<int>>& graph_adj,
  EmbeddedGraph& subgraph_embedded,
  vector<Face>& faces
) {
  vector<int> cycle = FindCycle(graph_adj);
  UpdateEmbedding(subgraph_embedded, cycle);

  Face face;
  for (int i = 0; i < cycle.size() - 1; ++i) {
    face.vertices.insert(cycle[i]);
    face.next[cycle[i]] = cycle[i + 1];
  }

  // Inside face and outside face.
  faces.push_back(face);
  faces.push_back(face);
}

vector<Fragment> FindFragments(
  const vector<vector<int>>& graph_adj, const EmbeddedGraph& subgraph_embedded
) {
  vector<Fragment> fragments;
  int vertex_num = graph_adj.size();
  vector<bool> visited(vertex_num, false);

  function<void(int, unordered_set<int>&, unordered_set<int>&)> dfs =
    [&](
      int u, unordered_set<int>& attachment, unordered_set<int>& component
    ) {
      visited[u] = true;
      component.insert(u);
      for (int v : graph_adj[u]) {
        if (!visited[v]) {
          dfs(v, attachment, component);
        } else if (subgraph_embedded.vertices.count(v)) {
          attachment.insert(v);
        }
      }
    };

  // Mark the vertices in the embedded graph as visited.
  // Find fragments of one edge whose endpoints are in the embedded graph.
  for (auto u : subgraph_embedded.vertices) {
    visited[u] = true;
    for (int v : graph_adj[u]) {
      if (
        u < v &&
        subgraph_embedded.vertices.count(v) &&
        !subgraph_embedded.has_edge(u, v)
      ) {
        fragments.push_back(Fragment({u, v}));
      }
    }
  }

  // Find fragments of components.
  for (int i = 0; i < vertex_num; ++i) {
    if (!visited[i]) {
      unordered_set<int> attachment;
      unordered_set<int> component;
      dfs(i, attachment, component);
      fragments.push_back(Fragment(attachment, component));
    }
  }

  return fragments;
}

bool IsAttachmentContained(const Fragment& fragment, const Face& face) {
  for (int u : fragment.attachment) {
    if (!face.vertices.count(u)) {
      return false;
    }
  }
  return true;
}

vector<int> find_path_of_attactment(
  const vector<vector<int>>& graph_adj, const Fragment& fragment
) {
  int vertex_num = graph_adj.size();
  vector<bool> visited(vertex_num, false);
  vector<int> path;
  int root;

  function<bool(int)> dfs =
    [&](int u) {
      visited[u] = true;
      path.push_back(u);
      if (u != root && fragment.attachment.count(u)) {
        return true;
      }
      for (int v : graph_adj[u]) {
        if (!visited[v]) {
          if (dfs(v)) return true;
        }
      }
      path.pop_back();
      return false;
    };

  if (fragment.component.empty()) {
    Assert(fragment.attachment.size() == 2, "Invalid fragment!");
    path = vector<int>(fragment.attachment.begin(), fragment.attachment.end());
  } else {
    bool succ = false;
    root = *fragment.attachment.begin();
    visited[root] = true;
    path.push_back(root);
    vector<int> nodes;
    for (int v : graph_adj[root]) {
      if (fragment.component.count(v)) {
        nodes.push_back(v);
      }
    }
    for (int v : nodes) {
      if (dfs(v)) {
        succ = true;
        break;
      }
    }
    Assert(succ, "No path found!");
  }
  return path;
}

void UpdateFace(
  vector<Face>& faces, const vector<int>& path, int face_index
) {
  Face old_face = faces[face_index];

  function<Face(const vector<int>&)> make_face = [&](const vector<int>& p) {
    Face face;
    for (int i = 0; i < p.size() - 1; ++i) {
      face.vertices.insert(p[i]);
      face.next[p[i]] = p[i + 1];
    }
    for (int u = p.back(); u != p.front(); u = old_face.next[u]) {
      face.vertices.insert(u);
      face.next[u] = old_face.next[u];
    }
    return face;
  };

  faces.erase(faces.begin() + face_index);
  vector<int> rpath = path;
  reverse(rpath.begin(), rpath.end());
  faces.push_back(make_face(path));
  faces.push_back(make_face(rpath));
}

bool DMP(const vector<vector<int>>& graph_adj) {
  if (graph_adj.size() < 5) return true;

  EmbeddedGraph graph_embedded = Adj2Embedded(graph_adj);
  if (graph_embedded.edges.size() > 3 * graph_embedded.vertices.size() - 6) {
    return false;
  }

  vector<Face> faces;
  EmbeddedGraph h;
  Init(graph_adj, h, faces);

  while (h != graph_embedded) {
    int tar_fragment_index = 0;
    vector<Fragment> fragments = FindFragments(graph_adj, h);
    for (int i = 0; i < fragments.size(); ++i) {
      for (int j = 0; j < faces.size(); ++j) {
        if (IsAttachmentContained(fragments[i], faces[j])) {
          fragments[i].face_indices.push_back(j);
        }
      }
      if (fragments[i].face_indices.empty()) {
        return false;
      } else if (fragments[i].face_indices.size() == 1) {
        tar_fragment_index = i;
        // break; // TODO: check if break is correct.
      }
    }
    vector<int> path = find_path_of_attactment(graph_adj, fragments[tar_fragment_index]);
    UpdateFace(faces, path, fragments[tar_fragment_index].face_indices[0]);
    UpdateEmbedding(h, path);
  }
  return true;
}

void print_graph_adj(const vector<vector<int>>& graph_adj) {
  for (int i = 0; i < graph_adj.size(); ++i) {
    cout << i << ": ";
    for (int j = 0; j < graph_adj[i].size(); ++j) {
      cout << graph_adj[i][j] << ' ';
    }
    cout << endl;
  }
}

int main() {
  int vertex_num, edge_num;
  cin >> vertex_num >> edge_num;
  vector<vector<int>> graph_adj(vertex_num);

  int data1, data2;
  for (int i = 0; i < edge_num; ++i) {
    cin >> data1 >> data2;
    // cout << data1 << ' ' << data2 << endl;
    graph_adj[data1 - 1].push_back(data2 - 1);
    graph_adj[data2 - 1].push_back(data1 - 1);
  }

  // print_graph_adj(graph_adj);
  // cout << endl;

  bool succ = true;
  vector<vector<pair<int, int>>> blocks = GetBlocks(graph_adj);

  // cout << blocks.size() << endl;
  // cout << "block 0" << endl;
  // for (auto p : blocks[0]) {
  //   cout << p.first << ' ' << p.second << endl;
  // }
  // cout << endl;

  for (int i = 0; i < blocks.size(); ++i) {
    vector<vector<int>> graph_adj = Block2Adj(blocks[i]);
    // cout << "block " << i << endl;
    // print_graph_adj(graph_adj);
    // cout << endl;
    if (!DMP(graph_adj)) {
      succ = false;
    }
  }
  if (succ) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  cin.get();
  cin.get();
  return 0;
}
