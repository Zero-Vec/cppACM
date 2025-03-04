#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// 多项式输入
void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int i = n; i >= 0;i--){
        int x;
        cin >> x;
        if(x != 0)
            a.push_back({x, i});
    }
    for (int i = 0; i < a.size();i++){
        if(a[i].first > 0){
            if(i)
                cout << "+";
            if(a[i].first != 1 || i + 1 == a.size())
                cout << a[i].first;
        }
        else{
            if(a[i].first != -1)cout<<a[i].first;
            else
                cout << "-";
        }
        if(a[i].second > 1)
            cout << "x^" << a[i].second;
        else if(a[i].second == 1)
            cout << "x";
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