#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;

#define maxv 1000000001

struct point{
    double x;
    double y;
    double angle;
    point(): x(0), y(0){}
    point(double xx, double yy) : x(xx), y(yy), angle(0){}
};

stack<point> s;
vector<point> ret;

point st_p;

double dist(const point &a, const point &b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

bool compareAngle(const point &a, const point &b){
    if(a.angle != b.angle){
        return a.angle < b.angle;
    }
    return dist(st_p, a) < dist(st_p, b);
}

void getAngles(point &st_p){
    for (int i = 0; i < ret.size(); ++i){
        double k = atan2(ret[i].y - st_p.y, ret[i].x - st_p.x);
        ret[i].angle = k;
    }
}

bool isOnRight(const point &p1, const point &p2, const point &p3){
    double value = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    return value <= 0;
}

double grahamScan(int n, point &st_p){
    double total = 0;
    s.push(ret[0]);
    s.push(ret[1]);
    for (int i = 2; i < n; ++i){
        while(s.size() >= 2){
            point p2 = s.top(); s.pop();
            point p1 = s.top();
            point p3 = ret[i];
            if(isOnRight(p1, p2, p3)){
                continue;
            }
            else{
                s.push(p2);
                break;
            }
        }
        s.push(ret[i]);
    }
    vector<point> temp;
    while(!s.empty()){
        temp.push_back(s.top());
        s.pop();
    }
    reverse(temp.begin(), temp.end());
    for (int i = 0; i < temp.size(); ++i){
        int j = (i + 1) % temp.size();
        total += dist(temp[i], temp[j]);
    }
    return total;
}

int main(){
    int n;
    cin >> n;
    double x, y;
    double min_x = maxv, min_y = maxv;
    for (int i = 0; i < n; ++i){
        cin >> x >> y;
        point p = point(x, y);
        ret.push_back(p);
        if(y < min_y || (y == min_y && x < min_x)){
            min_x = x;
            min_y = y;
            st_p = p;
        }
    }

    getAngles(st_p);
    sort(ret.begin(), ret.end(), compareAngle);
    double ans = grahamScan(n, st_p);
    cout << fixed << setprecision(2) << ans << endl;

    return 0;
}
