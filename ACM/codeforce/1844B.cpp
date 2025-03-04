// https://codeforces.com/problemset/problem/1844/B
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;

void solve(){
    int n;
    cin >> n;
    deque<int> v;
    v.push_back(1);
    for (int i = n; i > 1;i--){
        if(i&1)
            v.push_front(i);
        else
            v.push_back(i);
    }
    for(auto i:v)
        cout << i << " ";
    cout << "\n";
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