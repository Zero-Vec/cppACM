#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
long long dp[N];
int weishu_he(int x){
    int y,sum=0;
    while(x){
        y = x % 10;
        sum += y;
        x /= 10;
    }
    return sum;
}
int main()
{
    dp[0] = 1;//第0步是1
    for (int i = 1; i < N;i++){
        dp[i] = weishu_he(dp[i-1]) + dp[i - 1];
    }
    /*
    for (int i = 0; i <= 100;i++){
        cout << dp[i] << endl;
    }
    */
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        bool flag = false;
        for (int i = 0; i < N;i++){
            if(dp[i]==n){
                cout<<i<<'\n';
                flag = true;
                break;
            }
        }
        if(!flag)
            cout << -1 << '\n';
    }
    return 0;
}