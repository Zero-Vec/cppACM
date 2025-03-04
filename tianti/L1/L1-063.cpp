#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int op, h, w;
    cin >> op >> h >> w;
    if(op==0){
        if(h<129)
            cout << "duo chi yu! ";
        else if(h==129)
            cout << "wan mei! ";
        else
            cout << "ni li hai! ";
        if(w<25)
            cout << "duo chi rou!";
        else if(w==25)
            cout << "wan mei!";
        else
            cout << "shao chi rou!";
        cout << '\n';
    }
    else{
        if (h < 130)
            cout << "duo chi yu! ";
        else if (h == 130)
            cout << "wan mei! ";
        else
            cout << "ni li hai! ";
        if (w < 27)
            cout << "duo chi rou!";
        else if (w == 27)
            cout << "wan mei!";
        else
            cout << "shao chi rou!";
        cout << '\n';
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