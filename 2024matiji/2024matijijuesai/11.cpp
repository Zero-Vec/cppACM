#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
struct node{
    int xue, p;
}a[N],b[N];
int n, m;
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> a[i].xue >> a[i].p;
    }
    for (int i = 1; i <= m;i++){
        cin >> b[i].xue >> b[i].p;
    }
    int l1 = 1, l2 = 1;
    while(l1<=n&&l2<=m){
        int t1 = (a[l1].xue + b[l2].p - 1) / b[l2].p;
        int t2 = (b[l2].xue + a[l1].p - 1) / a[l1].p;
        if(t1==t2){
            l1++, l2++;
            continue;
        }
        if(t1>t2){
            a[l1].xue -= 1ll * t2 * b[l2].p;
            l2++;
        }
        else{
            b[l2].xue -= 1ll * t1 * a[l1].p;
            l1++;
        }
    }
    if(l1>n&&l2>m){
        cout << "Fine";
    }
    else if(l1>n){
        cout << "QAQ";
    }
    else{
        cout << "Win";
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