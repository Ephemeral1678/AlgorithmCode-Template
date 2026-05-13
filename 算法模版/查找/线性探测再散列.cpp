#include<iostream>
#include<vector>
using namespace std;

void Insert(int m, int x, vector<int> &ret){
    int idx = x % 11;
    while(ret[idx] != 0){
        idx = (idx + 1) % m;
    }
    ret[idx] = x;
    return;
}

int FindIndex(int x, vector<int> ret){
    for (int i = 0; i < ret.size();++i){
        if(ret[i] == x){
            return i + 1;
        }
    }
    return -1;
}

int getCount(int m, int x, vector<int> ret){
    int idx = x % 11;
    int count = 1;
    while(ret[idx] != x){
        if(ret[idx] == 0){
            break;
        }
        count++;
        idx = (idx + 1) % m;
    }
    return count;
}

void print(vector<int> ret){
    for (int i = 0; i < ret.size(); ++i){
        if(!ret[i]){
            cout << "NULL";
        }
        else cout << ret[i];
        if(i < ret.size() - 1){
            cout << " ";
        }
    }
    cout << endl;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int m, n;
        cin >> m >> n;
        vector<int> ret(m, 0);
        while(n--){
            int x;
            cin >> x;
            Insert(m, x, ret);
        }
        print(ret);

        int k;
        cin >> k;
        while(k--){
            int x;
            cin >> x;
            int idx = FindIndex(x, ret);
            int count = getCount(m, x, ret);
            if(idx == -1){
                cout << 0 << " " << count << endl;
            }
            else{
                cout << 1 << " " << count << " " << idx << endl;
            }
        }
    }
    return 0;
}