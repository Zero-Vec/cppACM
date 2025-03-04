#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
const int M = 15;
int n, m;
vector<int> a[N];
void solve(){
    cin >> n >> m;
    for (int i = 0; i < n;i++)
        for (int j = 0; j < m;j++){
            int x;
            cin >> x;
            a[i].push_back(x);
        }
            
    int j;
    for (int i = 0; i < n;i++){
        int cnt;
        bool tag;
        for (j = 0; j < n;j++){
            cnt = 0;
            tag = 0;
            for (int k = 0; k < m;k++){
                if(a[i][k]<a[j][k])
                    cnt++;
            }
            if(cnt==m){
                tag = 1;
                break;
            }
        }
        cout << (tag ? j + 1 : 0) << '\n';
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