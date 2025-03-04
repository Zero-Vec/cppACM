#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 550;
ll a[N];
int n;
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll mx = a[1], mn = a[1];
    for (int i = 2; i <= n; i++)
        mn &= a[i], mx |= a[i];
    cout << mx - mn << "\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1000;
int n;
int a1[N],a2[N];//每一位只有1还是只有0还是有1且有0
int b[N];
void solve(){
    cin >> n;
    memset(a1, 0, sizeof a1);
    memset(a2, 0, sizeof a2);
    
    // int id = -1;
    // for (int i = 1; i <= n;i++){
    //     cin >> x;
    //     for (int j = 0; j < 64;j++){
    //         if((x >> j) & 1)
    //             a[j]++;
    //     }
    //     int c = -1;
    //     while(x){
    //         x >>= 1;
    //         c++;
    //     }
    //     id = max(id, c);
    // }
    
    for (int i = 1; i <= n;i++)
        cin >> b[i];
    int id = -1;
    for (int i = 1; i <= n;i++){
        int c = -1;
        int x = b[i];
        while (x){
            x >>= 1;
            c++;
        }
        id = max(id, c);
    }
    set<int> y, z, w;
    for (int i = 1; i <= n;i++){
        int x = b[i];
        for (int j = 0; j <= id;j++){
            if((x >> j) & 1)
                a1[j] = 1;
            else
                a2[j] = 1;
        }
    }
    for (int j = 0; j <= id;j++){
        if(a1[j] && a2[j])
            z.insert(j);
        else
            w.insert(j), y.insert(j);
    }
    ll mx = 0, mn = 0;
    for(auto i:y){
        mx += pow(2, i);
        mn += pow(2, i);
    }
    for(auto i:z)
        mx += pow(2, i);
    cout << mx - mn << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
*/