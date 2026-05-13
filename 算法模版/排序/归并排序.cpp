#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n;
vector<string> ret;

void print(vector<string> ret){
    for (int i = 0; i < n;++i){
        cout << ret[i];
        if (i < n - 1){
            cout << " ";
        }
    }
    cout << endl;
}

//归并排序
void merge(vector<string> &ret, int left, int mid, int right){
    vector<string> temp(n);
    int i = left;
    int j = mid + 1;
    int k = 0;
    while(i <= mid && j <= right){
        if(ret[i] >= ret[j]){
            temp[k++] = ret[i++];
        }
        else{
            temp[k++] = ret[j++];
        }
    }
    while(i <= mid){
        temp[k++] = ret[i++];
    }
    while(j <= right){
        temp[k++] = ret[j++];
    }

    k = 0;
    for (int m = left; m <= right; ++m){
        ret[m] = temp[k++];
    }
}

void MergeSort(vector<string> &ret){
    int step = 1;
    while(step < n){
        for (int i = 0; i < n; i += step * 2){
            int left = i;
            int mid = min(i + step - 1, n - 1);
            int right = min(i + 2 * step - 1, n - 1);
            merge(ret, left, mid, right);
        }
        print(ret);
        step *= 2;
    }
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        ret.resize(n);
        for (int i = 0; i < n; ++i){
            cin >> ret[i];
        }
        MergeSort(ret);
        cout << endl;
        ret.clear();
    }
    return 0;
}