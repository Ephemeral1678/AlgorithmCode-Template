#include<iostream>
using namespace std;

int main(){
    int t, n, x;
    cin >> t;
    while(t--){
        cin >> n;
        int p = 0;
        while(n--){
            cin >> x;
            p ^= x;
        }
        if(p){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

    return 0;
}
