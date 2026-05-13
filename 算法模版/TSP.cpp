#include<iostream>
#include<vector>
using namespace std;

#define maxn 20

int g[maxn][maxn];

void Init(int n, vector<vector<int>> &dp){
    for (int s = 0; s < (1 << n); ++s){
        for (int i = 0; i < n; ++i){
            dp[s][i] = -1;
        }
    }
}

int f(int n, int status, int i, vector<vector<int>> &dp){
    if(status == (1 << n) - 1){
        return g[i][0];
    }
    if(dp[status][i] != -1){
        return dp[status][i];
    }
    int ans = 1000000001;
    for (int j = 0; j < n; ++j){
        if((status & (1 << j)) == 0){
            ans = min(ans, g[i][j] + f(n, status | (1 << j), j, dp));
        }
    }
    dp[status][i] = ans;
    return ans;
}


int main(){
    int n;
    cin >> n;
    vector<vector<int>> dp(1 << n, vector<int>(n, 0));
    Init(n, dp);
    
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> g[i][j];
        }    
    }
    int ans = f(n, 1, 0, dp);
    cout << ans << endl;
}