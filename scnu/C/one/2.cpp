#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    char ch;
    cin >> ch;
    cout << "  " << ch << "  \n";
    cout << " " << ch << ch << ch << " \n";
    for (int i = 0; i < 5;i++)
        cout << ch;
    cout << '\n';
    cout << " " << ch << ch << ch << " \n";
    cout << "  " << ch << "  ";
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