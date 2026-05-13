#include<iostream>
#include<list>
using namespace std;

list<int> h[11];

void Insert(list<int> h[], int x){
    int d = x % 11;
    h[d].push_front(x);
}

void find(list<int> h[], int x){
    int d = x % 11;
    int count = 0;
    for (auto it = h[d].begin(); it != h[d].end(); ++it){
        count++;
        if(*it == x){
            cout << x % 11 << " " << count << endl;
            return;
        }
    }
    cout << "error" << endl;
    h[d].push_front(x);
    return;
}

int main(){
    int n, x;
    cin >> n;
    while(n--){
        cin >> x;
        Insert(h, x);
    }
    int m;
    cin >> m;
    while(m--){
        cin >> x;
        find(h, x);
    }
    return 0;
}