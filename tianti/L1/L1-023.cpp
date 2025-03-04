#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    string s;
    cin>>s;
    int maxn = 0;
    int g = 0, p = 0, l = 0, t = 0;
    for (int i = 0; i < s.size(); i++){
        if(s[i]=='g'||s[i]=='G')g++;
        if(s[i]=='p'||s[i]=='P')p++;
        if(s[i]=='l'||s[i]=='L')l++;
        if(s[i]=='t'||s[i]=='T')t++;
    }
    maxn = max(maxn, g);
    maxn = max(maxn, p);
    maxn = max(maxn, l);
    maxn = max(maxn, t);
    for (int i = 1; i <= maxn;i++){
        if(g>0){
            cout << 'G';
            g--;
        }
        if(p>0){
            cout << 'P';
            p--;
        }
        if(l>0){
            cout<<'L';
            l--;
        }
        if(t>0){
            cout << 'T';
            t--;
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