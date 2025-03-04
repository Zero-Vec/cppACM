#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        string name;
        int a, b;
        cin >> name;
        cin >> a >> b;
        bool tag1 = 1, tag2 = 1;
        if(a<15||a>20)
            tag1 = 0;
        if(b<50||b>70)
            tag2 = 0;
        if(tag1&&tag2)continue;
        cout << name << '\n';
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