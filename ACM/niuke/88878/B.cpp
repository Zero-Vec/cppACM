    #include<bits/stdc++.h>
    using namespace std;
    using ll = long long;
    void solve(){
        ll n, x;
        cin >> n;
        for (int i = 1; i <= n;i++)
            cin >> x;
        if(n == 1){
            cout << -1;
            return;
        }
        cout << (n + 1) / 2;
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