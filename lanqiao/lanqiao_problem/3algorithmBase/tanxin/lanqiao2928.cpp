#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
char s[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,x;
    cin >> n >> x;
    for (int i = 1; i <= n;i++)
        cin >> s[i];
    sort(s + 1, s + 1 + n);
    if(s[1]==s[n]){
        int k = (n % x ? 1 : 0);
        for (int i = 1; i <= n / x + k;i++)
            cout << s[i];
    }
    else if(s[1]==s[x]){
        for (int i = x; i <= n;i++)
            cout << s[i];
    }
    else{
        cout << s[x];
    }
    return 0;
}