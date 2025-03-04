#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int m;
    cin >> m;
    vector<int> v1;
    vector<int> v2;
    int cnt = 0;
    while(m--){
        int op;
        cin >> op;
        if(op==1){
            int x;
            cin >> x;
            if(cnt%2==0){
                v1.push_back(x);
            }
            else{
                v1.insert(v1.begin(), x);
            }
        }
        else if(op==2){
            if(cnt&1){
                int t = v1.back();
                v1.pop_back();
                v2.push_back(t);
            }
            else{
                int t = v1.front();
                v1.erase(v1.begin());
                v2.push_back(t);
            }
        }
        else{
            cnt++;
        }
    }
    for(auto i:v2)
        cout << i << " ";
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