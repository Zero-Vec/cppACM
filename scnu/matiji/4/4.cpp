#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 7;
struct node{
    double x, y;
    bool operator<(const node &u)const{
        return x == u.x ? y < u.y : x < u.x;
    }
}a[N];
int n, tmp[N];
double pw(double x) { return x * x; }
double dis(node x, node y) { return sqrt(pw(x.x - y.x) + pw(x.y - y.y)); }
bool cmp(int x, int y) { return a[x].y < a[y].y; }
double solve(int l,int r){
    if (l==r)
        return 0x3f3f3f3f;
    if(l+1==r)
        return dis(a[l], a[r]);
    int mid = (l + r) >> 1;
    double minL = solve(l, mid), minR = solve(mid + 1, r);
    double mn = min(minL, minR);
    int cnt = 0;
    for (int i = l; i <= r;i++)
        if(fabs(a[mid].x-a[i].x)<=mn)
            tmp[++cnt] = i;
    sort(tmp + 1, tmp + cnt + 1, cmp);
    for (int i = 1; i <= cnt;i++)
        for (int j = i + 1; j <= cnt && a[tmp[j]].y - a[tmp[i]].y < mn;j++)
            mn = min(mn, dis(a[tmp[i]], a[tmp[j]]));
    return mn;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i].x >> a[i].y;
    sort(a + 1, a + 1 + n);
    cout << fixed << setprecision(4) << solve(1, n);
    return 0;
}