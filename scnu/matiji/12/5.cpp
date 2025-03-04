#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int n, k, A[N];
map<int, int> mp;
set<int> s;
void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> A[i];
    for (int i = 1; i <= k;i++)
        mp[A[i]]++;
    for (int i = 1; i <= k;i++)
        if(mp[A[i]]==1)
            s.insert(A[i]);
    if(s.empty())
        cout << "-1 ";
    else
        cout << *s.rbegin() << " ";
    for (int i = k + 1; i <= n;i++){
        if(mp[A[i-k]]==1)
            s.erase(A[i - k]);
        if(mp[A[i-k]]==2)
            s.insert(A[i - k]);
        mp[A[i - k]]--;

        if(mp[A[i]]==0)
            s.insert(A[i]);
        if(mp[A[i]]==1)
            s.erase(A[i]);
        mp[A[i]]++;

        if(s.empty())
            cout << "-1 ";
        else
            cout << *s.rbegin() << " ";
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