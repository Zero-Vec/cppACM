// https://codeforces.com/problemset/problem/1605/B
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
char s[N];
int n;
void solve(){
    cin>>n;
    cin >> s + 1;
    bool tag = 0;
    for (int i = 2; i <= n;i++){
        if(s[i]<s[i-1]){
            tag = 1;
            break;
        }
    }
    if(!tag)
        cout << 0 << '\n';
    else{
        cout << 1 << '\n';
        vector<int> v;
        int l = 1, r = n;
        while(l<=r){
            if(s[l]=='0'){
                l++;
                continue;
            }
            if(s[r]=='1'){
                r--;
                continue;
            }
            v.push_back(l);
            v.push_back(r);
            l++, r--;
        }
        sort(v.begin(), v.end());
        cout << v.size() << " ";
        for(auto i:v)
            cout << i << " ";
        cout << "\n";
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