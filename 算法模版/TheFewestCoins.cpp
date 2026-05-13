#include<iostream>
#include<vector>
using namespace std;

#define maxn 101
#define inf 1000001

int value[maxn];
int numbers[maxn];
vector<int> dp1;
vector<int> dp2;

void multipleBack(int n, int V){
    for (int i = 0; i <= V; ++i){
        dp1[i] = inf;
    }
    dp1[0] = 0;
    for (int i = 1; i <= n; ++i){
        int number = numbers[i];
        int k = 1;
        while(k < number){
            int current_v = k * value[i];
            for (int j = V; j >= current_v; --j){
                dp1[j] = min(dp1[j], dp1[j - current_v] + k);
            }
            number -= k;
            k *= 2;
        }
        if(number > 0){
            int current_v = number * value[i];
            for (int j = V; j >= current_v; --j){
                dp1[j] = min(dp1[j], dp1[j - current_v] + number);
            }
        }
    }
}

void completeBack(int n, int V){
    for (int i = 0; i <= V; ++i){
        dp2[i] = inf;
    }
    dp2[0] = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = value[i]; j <= V; ++j){
            dp2[j] = min(dp2[j], dp2[j - value[i]] + 1);
        }
    }
}

int main(){
    int n, T;
    cin >> n >> T;
    int max_v = 0;
    for (int i = 1; i <= n; ++i){
        cin >> value[i];
        max_v = max(max_v, value[i]);
    }
    for (int i = 1; i <= n; ++i){
        cin >> numbers[i];
    }

    int V = T + max_v * max_v;
    dp1.resize(V + 1);
    dp2.resize(V + 1);
    multipleBack(n, V);
    completeBack(n, V);

    int ans = inf;
    for (int v = T; v <= V; ++v){
        if(dp1[v] != inf && dp2[v - T] != inf){
            ans = min(ans, dp1[v] + dp2[v - T]);
        }
    }

    if(ans == inf){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

    return 0;
}