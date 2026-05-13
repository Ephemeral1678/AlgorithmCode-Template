#include<iostream>
using namespace std;

#define maxn 30001

int n;
long long maxv;
long long nums[maxn];
long long tree1[maxn];
long long tree2[maxn];

int lowbit(int i){
    return i & -i;
}

void add(long long tree[maxn], int i, long long v){
    while(i <= maxv){
        tree[i] += v;
        i += lowbit(i);
    }
}

long long sum(long long tree[maxn], int i){
    long long ans = 0;
    while(i > 0){
        ans += tree[i];
        i -= lowbit(i);
    }
    return ans;
}

int main(){
    cin >> n;
    maxv = 0;
    for (int i = 1; i <= n; ++i){
        cin >> nums[i];
        maxv = max(nums[i], maxv);
    }

    long long total = 0;
    for (int i = 1; i <= n; ++i){
        total += sum(tree2, nums[i] - 1);
        add(tree1, nums[i], 1);
        add(tree2, nums[i], sum(tree1, nums[i] - 1));
    }
    cout << total << endl;

    return 0;
}
