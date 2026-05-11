#include<iostream>
#include<vector>
using namespace std;

#define maxn 300005

int t, n;
vector<int> graph[maxn];
int maxsub[maxn];
int sz[maxn];
int centers[2];

void addEdge(int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void Init(){
    for (int i = 1; i <= n; ++i){
        graph[i].clear();
        sz[i] = 0;
        maxsub[i] = 0;
    }
}

void dfs(int u, int f){
    sz[u] = 1;
    maxsub[u] = 0;
    for(int v : graph[u]){
        if(v != f){
            dfs(v, u);
            sz[u] += sz[v];
            maxsub[u] = max(maxsub[u], sz[v]);
        }
    }
    maxsub[u] = max(maxsub[u], n - sz[u]);
}

int getCenters(){
    int count = 0;
    for (int i = 1; i <= n; ++i){
        if(maxsub[i] <= n / 2){
            centers[count++] = i;
        }
    }
    return count;
}

void getLeave(int u, int f, int &leaf, int &leafparent){
    for(int v : graph[u]){
        if(v != f){
            getLeave(v, u, leaf, leafparent);
            return;
        }
    }
    leaf = u;
    leafparent = f;
}

int main(){
    int u, v;
    cin >> t;
    while(t--){
        cin >> n;
        Init();
        for (int i = 0; i < n - 1; ++i){
            cin >> u >> v;
            addEdge(u, v);
        }
        dfs(1, 0);
        int centerCount = getCenters();
        if(centerCount == 1){
            cout << centers[0] << " " << graph[centers[0]][0] << endl;
            cout << centers[0] << " " << graph[centers[0]][0] << endl;
        }
        else if(centerCount == 2){
            int leaf = 0;
            int leafparent = 0;
            getLeave(centers[1], centers[0], leaf, leafparent);
            cout << leaf << " " << leafparent << endl;
            cout << centers[0] << " " << leaf << endl;
        }
    }
}