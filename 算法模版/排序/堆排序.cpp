#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &ret){
    for (int i = 0; i < ret.size(); ++i){
        cout << ret[i];
        if(i < ret.size() - 1){
            cout << " ";
        }
    }
    cout << endl;
}

void heapify(vector<int> &ret, int n, int i){
    int maxidx = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && ret[left] > ret[maxidx]){
        maxidx = left;
    }
    if(right < n && ret[right] > ret[maxidx]){
        maxidx = right;
    }
    if(maxidx != i){
        swap(ret[i], ret[maxidx]);
        heapify(ret, n, maxidx);
    }
}

void HeapSort(vector<int> &ret, int n){
    for (int i = n / 2 - 1; i >= 0; --i){
        heapify(ret, n, i);
    }
    print(ret);
    for (int i = n - 1; i > 0; --i){
        swap(ret[0], ret[i]);
        heapify(ret, i, 0);
        print(ret);
    }
}

int main(){

    return 0;
}