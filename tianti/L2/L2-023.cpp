#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=510;
vector<int> g[N];
int col[N];
int v, e, k;
void solve(){
    set<int> s;
    for (int i = 1; i <= v;i++){
        int c;
        cin>>c;
        col[i] = c;
        s.insert(c);
    }
    if(s.size()!=k){
        cout << "No" << '\n';
        return;
    }
    for (int i = 1; i <= v;i++){
        for(auto j:g[i]){
            if(col[i]==col[j]){
                cout<<"No"<<'\n';
                return;
            }
        }
    }
    cout << "Yes" << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> v >> e >> k;
    for (int i = 1; i <= e;i++){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}