#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool judge(int n){
    if(n%7==0)return 1;
    while(n){
        int x = n % 10;
        n/=10;
        if(x==7)
            return 1;
    }
    return 0;
}
void solve(){
    int n, k, a;
    cin>>n>>a>>k;
    int cur = a;
    for (int i = 1; i <= k;i++){
        if(i==1){
            a++;
        }
        else{
            a += n;
        }
        if (judge(a))
            cout << "p ";
        else
            cout << a << ' ';
    }
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}