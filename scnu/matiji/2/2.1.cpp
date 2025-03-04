#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 260;
int a[N];
int n;
void solve(){
    //cout << log(8)/log(2);
    while(cin>>n&&n){
        for (int i = 1; i <= n;i++)
            cin >> a[i];
        int gs = log(n) / log(2);
        for (int i = 1; i <= gs;i++){
            int k = pow(2, i - 1);
            vector<int> v;
            for (int j = 1; j <= k;j++){
                int t = (a[j] + a[j + k]) / 2;
                v.push_back(t);
                v.push_back(a[j] - t);
            }
            for (int j = 0; j < v.size();j++)
                a[j + 1] = v[j];
        }
        for (int i = 1; i <= n;i++)
            cout << a[i] << " \n"[i == n];
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