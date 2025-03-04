#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 9;
struct node{
    string a;
    int sco;
    bool operator<(const node &u)const{
        return sco == u.sco ? a < u.a : sco > u.sco;
    }
}d[N];
int n, g, k;
void solve(){
    cin >> n >> g >> k;
    int sum = 0;
    for (int i = 1; i <= n;i++){
        cin >> d[i].a >> d[i].sco;
        if(d[i].sco>=60&&d[i].sco<g)
            sum += 20;
        else if(d[i].sco>=g&&d[i].sco<=100)
            sum += 50;
    }
    cout << sum << '\n';
    int cur = 0, gs = 0;//当前排名，当前分数并列人数
    sort(d + 1, d + 1 + n);
    set<int> s;
    for (int i = 1; i <= n;i++){
        if(s.count(d[i].sco)){
            gs++;
        }
        else{
            cur += gs + 1;
            gs = 0;
            s.insert(d[i].sco);
        }
        if(cur>k)
            break;
        cout << cur << ' ' << d[i].a << ' ' << d[i].sco << '\n';
    }
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