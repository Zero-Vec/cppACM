#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
int v[N];
stack<int> a;
stack<int> b;
int ans = 0;
int cnt = 0;
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> v[i];
    for (int i = 1; i <= n;i++){
        if(i==1)
            a.push(v[i]);
        else if(v[i]<a.top())
            a.push(v[i]);
        else{
            if(b.size()==0||v[i]>b.top())
                b.push(v[i]);
            else{
                cnt++;
                int size = a.size();
                ans = max(ans, size);
                while(a.size())
                    a.pop();
                while(b.size()&&b.top()>v[i]){
                    a.push(b.top());
                    b.pop();
                }
                a.push(v[i]);
            }
        }
    }
    if(a.size()){
        cnt++;
        int size = a.size();
        ans = max(ans, size);
    }
    if(b.size()){
        cnt++;
        int size = b.size();
        ans = max(ans, size);
    }
    cout << cnt << " " << ans;
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