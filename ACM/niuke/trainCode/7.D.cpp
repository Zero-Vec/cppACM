/*
通过率86？
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int cnt;
const int N = 1e5 + 9;
int a[N];
int maxn = 0;
int minn = 1e9 + 1;
set<int> resa, resb;
map<int, int> mp;
bool check_value_between(const set<int> &setA, const set<int> &setB)
{
    int minB = *setB.begin();
    int maxB = *prev(setB.end());
    for (int a : setA){
        if (a > minB && a < maxB){
            return true;
        }
    }
    return false;
}
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        if(a[i]&&mp[a[i]]!=1){
            cnt++;
            mp[a[i]] = 1;
        }
        if(a[i]&&a[i]>=maxn){
            maxn = a[i];
        }
        if(a[i]&&a[i]<=minn){
            minn = a[i];
        }
    }
    for (int i = 1; i <= n; i++){
        if (a[i]==maxn){
            resa.insert(i);
        }
        if (a[i]==minn){
            resb.insert(i);
        }
    }
    if(cnt>2){
        cout << -1;
        return;
    }
    if(maxn-minn>1){
        cout << -1;
        return;
    }
    if(cnt==1){
        bool tag = 0;
        for (int i = 1; i <= n;i++){
            if(!resa.count(i)&&!tag){
                a[i] = maxn + 1;
                tag = 1;
            }
            else
                a[i] = maxn;
        }
        for (int i = 1; i <= n;i++)
            cout << a[i] << ' ';
        return;
    }
    if(cnt==2){
        if(check_value_between(resa,resb)||check_value_between(resb,resa)){
            cout << -1;
            return;
        }
        int maxa = *prev(resa.end());
        int mina = *(resa.begin());
        int maxb = *prev(resb.end());
        int minb = *(resb.begin());
        if(maxa<minb){
            for (int i = 1; i < minb;i++)
                a[i] = maxn;
            for (int i = minb; i <= n;i++)
                a[i] = minn;
            for (int i = 1; i <= n; i++)
                cout << a[i] << ' ';
            return;
        }
        if(mina>maxb){
            for (int i = 1; i < mina;i++)
                a[i] = minn;
            for (int i = mina; i <= n;i++)
                a[i] = maxn;
            for (int i = 1; i <= n; i++)
                cout << a[i] << ' ';
            return;
        }
    }
    if(!cnt){
        for (int i = 1; i < n;i++)
            a[i] = 1;
        a[n] = 2;
        for (int i = 1; i <= n;i++)
            cout << a[i] << ' ';
        return;
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