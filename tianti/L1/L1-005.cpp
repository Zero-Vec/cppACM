#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 5;
struct stu{
    string id;
    int x, y;
} s[N];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> s[i].id >> s[i].x >> s[i].y;
    int m;
    cin >> m;
    while(m--){
        int tx;
        cin >> tx;
        for (int i = 1; i <= n;i++){
            if(s[i].x==tx){
                cout << s[i].id << " " << s[i].y << "\n";
                break;
            }
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