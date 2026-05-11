#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define maxn 1001
#define ll long long
#define inf 1000000001

struct Node{
    int v;
    ll w;
    Node() { v = w = 0; }
    Node(int vv, ll ww): v(vv), w(ww) {}
    bool operator < (const Node& other) const{
        return w > other.w;
    }
};

vector<Node> g[maxn];
priority_queue<Node> heap;
ll dist[maxn];    
bool visited[maxn];

void addEdge(int u, int v, ll w){
    g[u].push_back(Node(v, w));
}

void DijkstraInit(int n, int st){
    for (int i = 0; i < n; ++i){
        visited[i] = false;
        dist[i] = inf;
    }
    dist[st] = 0;
    heap.push(Node(st, 0));
}

int DijkstraFindMin(){
    Node u = heap.top();
    heap.pop();
    return u.v;
}

void DijkstraUpdate(int u){
    if(visited[u]){
        return;
    }
    visited[u] = true;
    for (int i = 0; i < g[u].size(); ++i){
        int v = g[u][i].v;
        ll w = g[u][i].w;
        if(dist[u] + w < dist[v]){
            dist[v] = dist[u] + w;
            heap.push(Node(v, dist[v]));
        }
    }
}

void DijkstraHeap(int n, int st){
    DijkstraInit(n, st);
    while(!heap.empty()){
        int u = DijkstraFindMin();
        DijkstraUpdate(u);
    }
}

int getTotal(int n){
    ll total = 0;
    for (int i = 0; i < n; ++i){
        total += dist[i];
    }
    for (int i = 1; i < n; ++i){
        DijkstraHeap(n, i);
        total += dist[0];
    }
    return total;
}

int main(){
    int n, m, u, v;
    ll w;
    cin >> n >> m;
    while(m--){
        cin >> u >> v >> w;
        u--;
        v--;
        addEdge(u, v, w);
    }
    DijkstraHeap(n, 0);
    ll ans = getTotal(n);
    cout << ans << endl;
    return 0;
}
