#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool check(int s[]) {
    for (int i = 5; i <= 6;i++){
        if(s[i]-1==s[i-1]&&s[i]+1==s[i+1])
            return true;
    }
    return false;
}
void solve(){
    int ans = 0;
    int s[8] = {2, 0, 2, 2, 0, 0, 0, 0};
    for (int i = 1; i <= 12;i++){
        s[4] = i / 10 % 10;
        s[5] = i % 10;
        for (int j = 1; j <= day[i];j++){
            s[6] = j / 10 % 10;
            s[7] = j % 10;
            if (check(s)){
                ans++;
                /*
                for (int k = 0; k < 8; k++)
                    cout << s[k];
                cout << "\n";
                */
            }
        }
    }
    cout << ans;
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