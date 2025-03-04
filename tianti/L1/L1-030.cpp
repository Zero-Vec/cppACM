#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 55;
int nex[N];
string name[N];
bool v[N];
int n;
void solve(){
    cin>>n;
    for (int i = 1; i <= n;i++)
        cin >> nex[i] >> name[i];
    int t = n / 2;
    for (int i = 1; i <= t;i++){
        int k = nex[i];
        for (int j = n; j > t;j--){
            if(v[j])continue;
            if(nex[j]!=nex[i]){
                cout << name[i] << " " << name[j] << '\n';
                v[j] = 1;
                break;
            }
        }
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