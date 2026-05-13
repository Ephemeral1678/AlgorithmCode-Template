//树状数组用于维护可差分信息，代码量少，空间少等优势，单点增加，区间查询
#include<iostream>
using namespace std;

#define maxn 500001

int n, m;
//维护原数组的信息
int ret[maxn];
int tree[maxn];

//得到i最右侧的1的状态
int lowbit(int i){
    return i & -i;
}

//所有维护i的值都要加上v
void add(int i, int v){
    while(i <= n){
        tree[i] += v;
        i += lowbit(i);
    }
}

//返回1-i累加和的值
int sum(int i){
    int ans = 0;
    while(i >= 1){
        ans += tree[i];
        i -= lowbit(i);
    }
    return ans;
}

//返回l-r范围内的累加和
int qurry(int l, int r){
    return sum(r) - sum(l - 1);
}

int main(){
    int p, x, y, v;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        ret[i] = 0;
    }
    for (int i = 1; i <= n; ++i){
        add(i, ret[i]);
    }

    while (m--){
        cin >> p;
        if (p == 1){
            cin >> x >> v;
            add(x, v);
        }
        if(p == 2){
            cin >> x >> y;
            cout << qurry(x, y) << endl;
        }
    }

    return 0;
}