#include<iostream>
using namespace std;

#define maxn 101
#define maxv 40001

int numbers[maxn];
int weight[maxn];
int value[maxn];
int dp1[maxv];
int dp2[maxv];

void back01(int n, int v){
    for (int i = 1; i <= n; ++i){
        int number = numbers[i];
        int k = 1;
        while(k <= number){
            int current_w = k * weight[i];
            int current_v = k * value[i];
            for (int j = v; j > 0; --j){
                if(current_w <= j){
                    dp1[j] = max(dp1[j], dp1[j - current_w] + current_v);
                }
            }
            number -= k;
            k *= 2;
        }

        if(number > 0){
            int current_w = number * weight[i];
            int current_v = number * value[i];
            for (int j = v; j > 0; --j){
                if(current_w <= j){
                    dp1[j] = max(dp1[j], dp1[j - current_w] + current_v);
                }
            }
        }
    }
}

void completeback(int n, int v){
    
}

int main(){
    int n, v;
    cin >> n >> v;
    for (int i = 1; i <= n; ++i){
        cin >> value[i] >> weight[i] >> numbers[i];
    }
    back01(n, v);
    cout << dp1[v] << endl;

    return 0;
}