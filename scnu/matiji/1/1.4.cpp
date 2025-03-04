#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int a[N];
int n;
bool check(int i,int step){
    for (int j = i; j <= n;j+=step){
        if(a[j]==0)
            return false;
    }
    return true;
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 3; i <= n;i++){
        if(n%i!=0)continue;
        int step = n / i;
        for (int j = 1; j <= step;j++){
            if(check(j,step)){
                cout << "YES";
                return;
            }
        }
    }
    cout<<"NO";
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