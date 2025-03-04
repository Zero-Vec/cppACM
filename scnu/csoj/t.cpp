#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll a, b, n;
struct Matrix{
    int a[3][3];
    Matrix() { memset(a, 0, sizeof a); }
    Matrix operator*(const Matrix &b)const{
        Matrix res;
        for (int i = 1; i <= 2;i++)
            for (int j = 1; j <= 2;j++)
                for (int k = 1; k <= 2;k++)
                    res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % 7;
        return res;
    }
} base, ans, tmp;

void quick_power(ll power){
    while(power){
        if(power&1)
            ans = ans * base;
        power>>=1;
        base = base * base;
    }
}

void solve(){
    cin >> a >> b >> n;
    /*
    ll r1 = 1, r2 = 1;
    n -= 2;
    while(n--){
        ll t1 = r1, t2 = r2;
        r1 = t2 % 7;
        r2 = (b * t1 + a * t2) % 7;
    }
    cout << r2;
    */
    ans.a[1][1] = 1, ans.a[2][1] = 0, ans.a[1][2] = 0, ans.a[2][2] = 1;
    base.a[1][1] = 0, base.a[1][2] = 1, base.a[2][1] = b, base.a[2][2] = a;
    quick_power(n - 2);
    tmp.a[1][1] = 1, tmp.a[2][1] = 1, tmp.a[1][2] = 0, tmp.a[2][2] = 0;
    ans = ans * tmp;
    //cout << ans.a[1][1] << '\n';
    cout << ans.a[2][1];
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