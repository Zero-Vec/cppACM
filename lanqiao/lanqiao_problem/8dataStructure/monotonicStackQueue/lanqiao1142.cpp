#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 7e5 + 9;
int st[N], top;
int n;
int a[N], dpl[N], dpr[N];
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= n;i++){
        while(top&&a[st[top]]<a[i])
            top--;
        dpl[i] = top ? st[top] : -1;
        st[++top] = i;
    }
    top = 0;
    for (int i = n; i >= 1; i--){
        while (top && a[st[top]] < a[i])
            top--;
        dpr[i] = top ? st[top] : -1;
        st[++top] = i;
    }
    for (int i = 1; i <= n;i++)
        cout << dpl[i] << ' ';
    cout << '\n';
    for (int i = 1; i <= n;i++)
        cout << dpr[i] << ' ';
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