#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &hash, int m){
    for (int i = 0; i < m; ++i){
        if(hash[i] == 0){
            cout << "NULL";
        }else{
            cout << hash[i];
        }
        if(i < m - 1){
            cout << " ";
        }
    }
    cout << endl;
}

void Insert(vector<int> &hash, int x, int m){
    int d = x % 11;
    int i = 1;
    int pos = d;
    while(hash[pos] != 0 && i <= m){

        pos = (d + i * i) % m;
        if(hash[pos] == 0) break;

        pos = (d - i * i + m) % m;
        if(hash[pos] == 0) break;

        i++;
    }
    if(i <= m){
        hash[pos] = x;
    }
    
}

int find(vector<int> &hash, int x, int m){
    for (int i = 0; i < m; ++i){
        if(hash[i] == x){
            return i + 1;
        }
    }
    return -1;
}

int getCount(vector<int> &hash, int x, int m){
    int count = 0;
    int d = x % 11;
    int i = 1;
    int pos = d;

    count++;
    if(hash[pos] == x){
        return count;
    }

    while(hash[pos] != 0 && i <= m){
       
        count++;
        pos = (d + i * i) % m;
        if(hash[pos] == x){
            return count;
        }

        count++;
        pos = (d - i * i + m) % m;
        if(hash[pos] == x){
            return count;
        }

        i++;
    }
    return count;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int m, n;
        cin >> m >> n;
        vector<int> hash(m, 0);
        while(n--){
            int x;
            cin >> x;
            Insert(hash, x, m);
        }
        print(hash, m);
        int k;
        cin >> k;
        while(k--){
            int x;
            cin >> x;
            int idx = find(hash, x, m);
            int count = getCount(hash, x, m);
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