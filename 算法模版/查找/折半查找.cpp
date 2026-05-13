#include<iostream>
using namespace std;

int BinarySearch(int x, int n, int ret[]){
    int left = 0;
    int right = n - 1;
    int mid;
    while(left <= right){
        mid = left + (right - left) / 2;
        if(ret[mid] == x){
            return mid + 1;
        }
        if(ret[mid] > x){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    int ret[n];
    for (int i = 0; i < n;++i){
        cin >> ret[i];
    }
    int m;
    cin >> m;
    while(m--){
        int x;
        cin >> x;
        int idx = BinarySearch(x, n, ret);
        if(idx == -1){
            cout << "error" << endl;
        }
        else{cout << idx << endl;}
    }
    return 0;
}