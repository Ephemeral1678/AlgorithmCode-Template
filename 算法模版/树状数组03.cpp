//二维树状数组 单点增加，范围查询
//树状数组用于维护可差分信息，代码量少，空间少等优势，单点增加，区间查询
#include<iostream>
using namespace std;

#define maxn 501

int n, m;
//维护原数组的信息
int ret[maxn][maxn];
int tree[maxn][maxn];

//得到i最右侧的1的状态
int lowbit(int i){
    return i & -i;
}

//所有维护i的值都要加上v
void add(int x, int y, int v){
    for (int i = 1; i <= x; i += lowbit(i)){
        for (int j = 1; j <= y; j += lowbit(j)){
            tree[i][j] += v;
        }
    }
}

//返回(1, 1) - (x, y)累加和的值
int sum(int x, int y){
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i)){
        for (int j = y; j > 0; j -= lowbit(j)){
            ans += tree[i][j];
        }
    }
    return ans;
}

//返回左上角和右下角范围内的累加和
int qurry(int x1, int y1, int x2, int y2){
    return sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1);
}

void update(int x, int y, int v){
    add(x, y, v - ret[x][y]);
    ret[x][y] = v;
}

int main(){
    int p, x, y, v;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> ret[i][j];
            add(i, j, ret[i][j]);
        }
    }
    
    while (m--){
        cin >> p;
        if (p == 1){
            cin >> x >> y >> v;
            update(x, y, v);
        }
        if(p == 2){
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            cout << qurry(a,b,c,d) << endl;
        }
    }

    return 0;
}