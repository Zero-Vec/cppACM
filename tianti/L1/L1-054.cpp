#include <iostream>
#include <string>
using namespace std;

const int N = 110;
char g[N][N];

int main()
{
    char c;
    int n;
    cin >> c >> n;

    getchar();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%c", &g[i][j]);
        }
        getchar();
    }

    bool flag = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (g[i][j] != g[n - i + 1][n - j + 1])
                flag = 0;
        }
    }
    if (flag)
    {
        printf("bu yong dao le\n");
    }

    for (int i = n; i >= 1; i--)
    {
        for (int j = n; j >= 1; j--)
        {
            if (g[i][j] == '@')
                printf("%c", c);
            else
                printf(" ");
        }
        puts("");
    }

    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
char mp[N][N], ans[N][N], t[N][N];
char ch;
int n;
void solve(){
    cin >> ch >> n;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            mp[i][j] = getchar();
            t[i][j] = mp[i][j];
        }
        getchar();
    }
    
    cout << "---------" << '\n';
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            cout << mp[i][j];
        cout << '\n';
    }
    
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n / 2;j++)
            swap(mp[i][j], mp[i][n - j + 1]);
    for (int j = 1; j <= n;j++)
        for (int i = 1; i <= n / 2;i++)
            swap(mp[i][j], mp[n - i + 1][j]);
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            if(mp[i][j]=='@'){
                ans[i][j] = ch;
            }
            else
                ans[i][j] = ' ';
        }
    }
    bool tag = 0;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            if(mp[i][j]!=t[i][j]){
                tag = 1;
                break;
            }
        }
    }
    if(!tag)
        cout << "bu yong dao le\n";
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++)
            cout << ans[i][j];
        cout << '\n';
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
*/