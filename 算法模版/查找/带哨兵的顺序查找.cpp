#include<iostream>
using namespace std;

int find(int x, int ret[], int n){
    ret[0] = x;
    int i = n;
    while(ret[i] != x){
        i--;
    }
    return i;
}

int main(){
    int n;
    cin >> n;
    int ret[n + 1];
    for (int i = 1; i <= n; ++i){
        cin >> ret[i];
    }

    int m;
    cin >> m;
    while(m--){
        int x;
        cin >> x;
        int idx = find(x, ret, n);
        if(idx == 0){
            cout << "error" << endl;
        }else{
            cout << idx << endl;
        }
    }
    return 0;
}