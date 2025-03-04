#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 9;
string s[N], music;
vector<int> idx[26];
int n;
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    cin >> music;
    for (int i = 0; i < music.size(); i++)
    {
        idx[music[i] - 'a'].push_back(i);
    }
    for (int i = 1; i <= n; i++){
        int len = s[i].size();
        bool tag = 1;
        int id = -1;
        for (int j = 0; j < len;j++){
            int k = s[i][j] - 'a';
            int l = -1, r = idx[k].size();
            if(!r){
                tag = 0;
                break;
            }
            while(l+1!=r){
                int mid = (l + r) / 2;
                if(idx[k][mid]>id)
                    r = mid;
                else
                    l = mid;
            }
            if(r==idx[k].size()){
                tag = 0;
                break;
            }
            id = idx[k][r];
        }
        cout << (tag ? "YES" : "NO") << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}