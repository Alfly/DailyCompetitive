const int N = 100010, M = N * 2;
int h[N], e[M], ne[M], idx;
bool st[N];
int n, ans = N;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

// 返回以 u 为根的子树点的数量
int dfs(int u)
{
    st[u] = true;
 
    int sum = 1, res = 0;   
    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            int s = dfs(j);
            res = max(res, s);
            sum += s;           // 各子节点数目累加
        }
    }
    res = max(res, n - sum);    // 父节点所在的连通块点数
    ans = min(ans, res);
    return sum;
}

memset(h, -1, sizeof h);

for (int i = 0; i < n - 1; i ++ )
{
    int a, b;
    cin >> a >> b;
    add(a, b), add(b, a);
}

dfs(1);
cout << ans;