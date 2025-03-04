#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e4 + 9;
int a[N];
map<pair<int, int>, int> mp;
int mex(set<int> &st){
    for (int i = 0;;i++)
        if(st.find(i)==st.end())
            return i;
}
int _sg(int x,int y){
    //不妨设x>=y
    if(x<y)
        return _sg(y, x);
    if(y==0)
        return 0;
    if(mp.count({x,y}))
        return mp[{x, y}];
    set<int> st;
    for (int i = 1; i < y;i++)
        st.insert(_sg(i, y - i));
    for (int i = 1; i < x;i++)
        st.insert(_sg(x - i, i));
    return mp[{x, y}] = mex(st);
}
/*
void table(int n){
    cout << "   ";
    for (int i = 1; i <= n;i++)
        cout << setw(2) << i << ' ';
    cout << '\n';
    for (int i = 1; i <= n;i++){
        cout << setw(2) << i << ' ';
        for (int j = 1; j <= n;j++)
            cout << setw(2) << sg(i, j) << ' ';
        cout << '\n';
    }
}
*/
int sg(int x,int y){
    if(y>x)
        return sg(y, x);
    if((x&1)&&(y&1))
        return 0;
    if(x&1)
        return sg((x + 1) / 2, y / 2) + 1;
    if(y&1)
        return sg(x / 2, (y + 1) / 2) + 1;
    return sg(x / 2, y / 2) + 1;
}
void solve(){
    
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= n;i+=2)
        ans ^= sg(a[i], a[i + 1]);
    cout << (ans ? "YES" : "NO") << '\n';
    //table(20);
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