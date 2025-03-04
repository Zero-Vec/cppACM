#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    string s;
    char ch;
    cin >> s >> ch;
    vector<int> idx;
    bool tag = false;
    for (int i = 0; i < s.size();i++)
        if(s[i] == ch)
            idx.push_back(i), tag = true;
    if(!tag){
        cout << "NULL\n";
    }
    for(auto i:idx)
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