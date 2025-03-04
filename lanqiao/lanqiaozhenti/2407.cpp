#include<bits/stdc++.h>
using namespace std;
using ll = long long;
char ch[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 
'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
void solve(){
    int cnt=0;
    for (int i = 0; i < 26;i++){
        for (int j = 0; j < 26;j++){
            for (int k = 0; k < 26;k++){
                cnt++;
                if(cnt==1320){
                    cout<<ch[i]<<ch[j]<<ch[k];
                    return;
                }
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