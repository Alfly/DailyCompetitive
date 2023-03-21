#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <string.h>
using namespace std;

void Hierholzer(vector<int>adj[], int n) {
    if (n == 0) return;
    vector<int> curr_path;  // Maintain a stack to keep vertices
    vector<int> circuit;    // list to store final circuit

    // We can start from any vertex, here we start with 0
    curr_path.push_back(0);
    while (!curr_path.empty()) { 
        int u = curr_path.back();
        // If there's remaining edge in adjacency list of the current vertex
        if (adj[u].size() > 0) {
            int v = adj[u].back();
            adj[u].pop_back();
            // Push the new vertex to the stack
            curr_path.push_back(v);
        } else {
            // back-track to find remaining circuit
            circuit.push_back(curr_path.back());
            curr_path.pop_back();
        }
    }
    for (int i = circuit.size() - 1; i >= 0; i --) {
        cout << circuit[i];
        if (i) cout << " ";
    }
}

int main() {
    // Input Graph 1
    int n1 = 3;
    vector<int> adj1[n1];
    // Build the edges
    adj1[0].push_back(1);
    adj1[1].push_back(2);
    adj1[2].push_back(0);
    Hierholzer(adj1, n1);
    cout << endl;
 
    // Input Graph 2
    int n2 = 7;
    vector<int> adj2[n2];
    adj2[0].push_back(1);
    adj2[0].push_back(6);
    adj2[1].push_back(2);
    adj2[2].push_back(0);
    adj2[2].push_back(3);
    adj2[3].push_back(4);
    adj2[4].push_back(2);
    adj2[4].push_back(5);
    adj2[5].push_back(0);
    adj2[6].push_back(4);
    Hierholzer(adj2, n2);
    cout << endl;

    return 0;
}
/*
https://www.geeksforgeeks.org/hierholzers-algorithm-directed-graph/

0 1 2 0
0 6 4 5 0 1 2 3 4 2 0
*/