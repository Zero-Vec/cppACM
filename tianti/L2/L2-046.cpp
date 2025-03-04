#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5009;
priority_queue<int> pq;
int a[N];
int cnt;//最后开监考室的个数
void solve(){
    int n, c;
    cin >> n >> c;
    int ans = 0;
    while(n--){
        string s;
        int a;
        cin >> s >> a;
        cout << s << " " << (a % c ? a / c + 1 : a / c) << '\n';
        ans += a / c;
        if(a%c){
            pq.push(a % c);
        }
    }
    while(pq.size()){
        int x = pq.top();
        pq.pop();
        bool tag = 0;
        for (int i = 0; i < cnt;i++){
            if(a[i]+x<=c){
                a[i] += x;
                tag = 1;
                break;
            }
        }
        if(!tag){
            a[cnt] = x;
            cnt++;
        }
    }
    cout << cnt + ans;
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