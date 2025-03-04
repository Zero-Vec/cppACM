#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
int pre[N];
int n,m;
int root(int x){
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}
struct Edge{
    int x,y;
    double e;
    bool operator<(const Edge &u)const{
        return e < u.e;
    }
};
double dis(int x1,int y1,int x2,int y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int a[N], b[N],a1[N],b1[N];
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        pre[i] = i;
    for (int i = 1; i <= n;i++){
        cin >> a[i] >> b[i];
    }
    vector<Edge> v;
    for (int i = 1; i < n;i++){
        for (int j = i + 1; j <= n;j++){
            double d = dis(a[i], b[i], a[j], b[j]);
            v.push_back({i, j, d});
        }
    }
    sort(v.begin(), v.end());
    double sum = 0;
    for (int i = 1; i <= m;i++){
        cin >> a1[i] >> b1[i];
        double dist = 0x3f3f3f3f3f3f3f3f;
        for(int j=1;j<=n;j++){
            double dt = dis(a1[i], b1[i], a[j], b[j]);
            dist = min(dt, dist);
        }
        sum += dist;
    }
    for(auto edge:v){
        if(root(edge.x)==root(edge.y))continue;
        sum += edge.e;
        pre[root(edge.x)] = root(edge.y);
    }
    cout << fixed << setprecision(2) << sum;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}