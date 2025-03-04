#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int a, b;
    cin >> a >> b;
    int na = a, nb = b;
    int sa = 0, sb = 0;
    while(a){
        sa += a % 10;
        a /= 10;
    }
    while (b){
        sb += b % 10;
        b /= 10;
    }
    if(na%sb==0&&nb%sa!=0)
        cout << "A" << '\n';
    else if(nb%sa==0&&na%sb!=0)
        cout << "B" << '\n';
    else{
        if(na>nb)
            cout<<"A"<<"\n";
        else
            cout<<"B"<<"\n";
    }
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