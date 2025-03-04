#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[30];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cnt = 0;
        for (int i = 1; i <= n;i++){
            cin >> a[i];
            if(a[i]+a[i-1]%2==0)
                cnt++;
        }
        if(n%4==0||n%4==2)
            cout << "zn"
                 << "\n";
        else{
            cout << "qcjj"
                 << "\n";
        }
    }
    return 0;
}