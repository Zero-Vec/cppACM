#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main()
{
    int t;
    cin >> t;
    int n;
    while(t--){
        int ans = 0,sum=0;
        cin >> n;
        for (int i = 0; i < n;i++){
            cin >> a[i];
            if(!a[i]){
                ans++;
                a[i]++;
            }
        }
        for (int i = 0; i < n;i++){
            sum += a[i];
        }
        if (!sum)
            ans++;
        cout << ans << '\n';
    }
    return 0;
}