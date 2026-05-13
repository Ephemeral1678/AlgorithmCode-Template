#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

#define maxn 101

vector<vector<int>> g(maxn, vector<int>(maxn));
unordered_map<int, int> h;

bool isvalid(int n){
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            int x = g[i][j];
            h[x]++;
        }
    }
    int limit = n * (n - 1);
    for(auto it : h){
        if(it.second > limit){
            return false;
        }
    }
    return true;
}

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        h.clear();
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                cin >> g[i][j];
            }
        }
        if(isvalid(n)){
            cout << "YES" << endl;
        }else{
            cout <<  "NO" << endl;
        }
        
    }
}