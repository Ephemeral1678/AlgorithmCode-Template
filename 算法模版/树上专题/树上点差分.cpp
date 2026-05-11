//松鼠的新家
#include<iostream>
#include<vector>
using namespace std;

#define LOG 20
#define maxn 300005

int deep[maxn];
int up[LOG][maxn];
vector<int> g[maxn];
int path[maxn];
int diff[maxn];
int val[maxn];

void diffSum(int u, int fa){
    val[u] = diff[u];
    for(int v : g[u]){
        if(v == fa){
            continue;
        }
        diffSum(v, u);
        val[u] += val[v];
    }
}

void dfs(int u, int fa){
    up[0][u] = fa;
    for(int v : g[u]){
        if(v != fa){
            deep[v] = deep[u] + 1;
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
    diff[LCA(u, v)] -= 1;
    diff[up[0][LCA(u, v)]] -= 1;
}

void print(int n){
    for (int i = 2; i <= n; ++i){
        val[path[i]]--;
    }
    for (int i = 1; i <= n; ++i){
        cout << val[i] << endl;
    }
}

int main(){
    int n, u, v;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> path[i];
    }
    
    for (int i = 1; i <= n - 1; ++i){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    InitLCA(path[1], n);

    for (int i = 1; i <= n - 1; ++i){
        add_path(path[i], path[i + 1]);
    }
    
    diffSum(path[1], 0);
    print(n);
}