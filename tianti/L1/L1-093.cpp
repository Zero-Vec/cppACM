#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int a[110], b[110];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    int k;
    cin >> k;
    while(k--){
        bool tag = 1, flag = 0;
        for (int i = 1; i <= n;i++){
            cin >> b[i];
            if(b[i]!=0)
                flag = 1;
            if(b[i]!=0&&b[i]!=a[i]){
                tag = 0;
            }
        }
        if(!flag||!tag)
            cout << "Ai Ya"<<"\n";
        else
            cout << "Da Jiang!!!"<<"\n";
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