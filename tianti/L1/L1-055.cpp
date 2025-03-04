#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int a1, b1;
    cin >> a1 >> b1;
    bool tag = (a1 > b1);
    int cnt = 0;
    for (int i = 0; i < 3;i++){
        int x;
        cin >> x;
        if(!x)
            cnt++;
    }
    if((tag&&cnt)||(!tag&&cnt==3)){
        cout << "The winner is a: " << a1 << " + " << cnt;
    }
    else{
        cout << "The winner is b: " << b1 << " + " << 3 - cnt;
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