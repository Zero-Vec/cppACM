#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
set<string> s;
void solve(){
    int n;
    cin>>n;
    for (int i = 1; i <= n;i++){
        int x;
        cin >> x;
        string p;
        if(x==1){
            cin>>p;
            continue;
        }
        while(x--){
            cin>>p;
            s.insert(p);
        }
    }
    vector<string>ans;
    int m;
    cin >> m;
    string a;
    while(m--){
        cin >> a;
        if(!s.count(a)&&find(ans.begin(),ans.end(),a)==ans.end())
            ans.push_back(a);
    }
    int cnt = 0;
    if(!ans.size()){
        cout << "No one is handsome";
        return;
    }
    for(auto i:ans){
        if(!cnt){
            cout << i;
            cnt++;
        }
        else{
            cout << " " << i;
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