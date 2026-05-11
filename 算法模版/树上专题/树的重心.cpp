#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 1000001

int n;
vector<int> graph[maxn];
int sz[maxn];
int best = 1000001;
vector<int> ans;

void addEdge(int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void dfs(int u, int f){
    sz[u] = 1;
    int maxsub = 0;
    for(int v : graph[u]){
        if(v != f){
            dfs(v, u);
            sz[u] += sz[v];
            maxsub = max(maxsub, sz[v]);
        }
    }
    maxsub = max(maxsub, n - sz[u]);
    if(maxsub < best){
        ans.clear();
        ans.push_back(u);
        best = maxsub;
    }
    else if(maxsub == best){
        ans.push_back(u);
    }
}

void print(){
    for (int i = 0; i < ans.size(); ++i){
        cout << ans[i] << " ";
    }
}

int main(){
    int u, v;
    cin >> n;
    for (int i = 0; i < n - 1;++i){
        cin >> u >> v;
        addEdge(u, v);
    }
    dfs(1, 0);
    sort(ans.begin(), ans.end());
    print();
}

