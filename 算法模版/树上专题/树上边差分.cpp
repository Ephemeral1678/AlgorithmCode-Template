//蓝桥杯——砍树
#include<iostream>
#include<vector>
using namespace std;

#define LOG 20
#define maxn 300005

int deep[maxn];
int up[LOG][maxn];
vector<pair<int, int>> g[maxn];
int diff[maxn];
int val[maxn];//用子节点来代表对应的边
int edge_id[maxn];

void diffSum(int u, int fa){
    val[u] = diff[u];
    for(auto &edge : g[u]){
        int v = edge.first;
        if(v == fa){
            continue;
        }
        diffSum(v, u);
        val[u] += val[v];
    }
}

void dfs(int u, int fa){
    up[0][u] = fa;
    for(auto [v, id] : g[u]){
        if(v != fa){
            deep[v] = deep[u] + 1;
            edge_id[v] = id;
            dfs(v, u);
        }
    }
}

void InitLCA(int root, int n){
    deep[root] = 0;
    dfs(root, 0);
    for (int k = 1; k < LOG; ++k){
        for (int u = 1; u <= n; ++u){
            up[k][u] = up[k - 1][up[k - 1][u]];
        }
    }
}

int LCA(int u, int v){
    if(deep[u] < deep[v]){
        swap(u, v);
    }
    for (int k = LOG - 1; k >= 0; --k){
        if(deep[u] - (1 << k) >= deep[v]){
            u = up[k][u];
        }
    }
    if(v == u){
        return u;
    }
    for (int k = LOG - 1; k >= 0; --k){
        if(up[k][u] != up[k][v]){
            u = up[k][u];
            v = up[k][v];
        }
    }
    return up[0][u];
}

void add_path(int u, int v){
    diff[u] += 1;
    diff[v] += 1;
    diff[LCA(u, v)] -= 2;
}

int getAns(int n, int m){
    int ans = -1;
    for (int i = 1; i <= n; ++i){
        if(val[i] == m){
            ans = max(ans, edge_id[i]);
        }
    }
    return ans;
}

int main(){
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= n - 1; ++i){
        cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }

    InitLCA(1, n);

    for (int i = 1; i <= m; ++i){
        cin >> u >> v;
        add_path(u, v);
    }
    
    diffSum(1, 0);
    cout << getAns(n, m) << endl;
}