#include<bits/stdc++.h>
using namespace std;
int ans = 0;
void dfs(int n){
    if(!n)
        return;
    else{
        for (int i = 1; i <= n / 2;i++){
            dfs(i);
        }
    }
    ans++;
}
int main()
{
    int n;
    cin >> n;
    dfs(n);
    cout << ans << '\n';
    return 0;
}