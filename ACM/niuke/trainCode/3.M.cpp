#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll a[N], cnt1[9], cnt2[9][10], mod9[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> a[i];
        int sum = 0, j = a[i] % 10;
        ll t = a[i];
        while(t){
            sum += t % 10;
            t /= 10;
        }
        sum %= 9;
        cnt1[sum]++;
        cnt2[sum][j]++;
        mod9[i] = sum;
    }
    ll ans = 0;
    for (int i = 0; i < n;i++){
        if(a[i]<10){
            for (int j = 0; j <= 9;j++){
                if((j*10+a[i])%4==0){
                    ans += cnt2[(9 - a[i]) % 9][j];
                }
            }
        }
        else{
            int x = a[i] % 100;
            if(x%4==0){
                ans += cnt1[(9 - mod9[i]) % 9];
                if(mod9[i]==0)
                    ans--;
            }
        }
    }
    cout << ans;
    return 0;
}