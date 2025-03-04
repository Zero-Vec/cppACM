// https://codeforces.com/problemset/problem/1837/C
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 9;
char s[N];
void solve(){
    cin >> s + 1;
    int n = strlen(s + 1);
    int id = 0;
    char t;
    for (int i = 1; i <= n;i++){
        if(s[i]!='?'){
            id = i;
            t = s[i];
            break;
        }
    }
    if(id==0){
        for (int i = 1; i <= n;i++)
            s[i] = '0';
    }
    else if(id==1){
        for (int i = 2; i <= n;i++){
            if(s[i]!='?')continue;
            s[i] = s[i - 1];
        }
    }
    else{
        for (int i = 1; i < id;i++)
            s[i] = t;
        for (int i = id; i <= n; i++){
            if (s[i] != '?')
                continue;
            s[i] = s[i - 1];
        }
    }
    cout << s + 1 << '\n';
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