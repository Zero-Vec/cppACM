#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
double d[N][N];
bool v[N];
int n, m;
void solve(){
    cin >> n >> m;
    while(m--){
        int x;
        cin>>x;
        vector<int> t;
        for (int i = 0; i < x;i++){
            int tmp;
            cin >> tmp;
            t.push_back(tmp);
            if(t[i]<0)
                v[abs(t[i])] = 0;
            else
                v[t[i]] = 1;
        }
        for (int i = 0; i < t.size() - 1;i++){
            for (int j = i + 1; j < t.size();j++){
                if(t[i]>=0){
                    if(t[j]<0){
                        d[t[i]][abs(t[j])] += 1.0 / x;
                        d[abs(t[j])][t[i]] += 1.0 / x;
                    }
                }
                else{
                    if(t[j]>0){
                        d[abs(t[i])][t[j]] += 1.0 / x;
                        d[t[j]][abs(t[i])] += 1.0 / x;
                    }
                }
            }
        }
    }
    int a, b;
    cin >> a >> b;
    set<int> a1, b1;
    double mxa = 0, mxb = 0;
    for (int i = 0; i < n ;i++)
        mxa = max(d[abs(a)][i], mxa);
    for (int i = 0; i < n ; i++)
        mxb = max(d[abs(b)][i], mxb);
    if(a<0){
        for (int i = 0; i < n;i++){
            if(!v[i])continue;
            if(d[abs(a)][i]==mxa)
                a1.insert(i);
        }
        for (int i = 0; i < n; i++){
            if (v[i])
                continue;
            if (d[abs(b)][i] == mxb)
                b1.insert(i);
        }
    }
    else{
        for (int i = 0; i < n; i++){
            if (!v[i])
                continue;
            if (d[abs(b)][i] == mxb)
                b1.insert(i);
        }
        for (int i = 0; i < n; i++){
            if (v[i])
                continue;
            if (d[abs(a)][i] == mxa)
                a1.insert(i);
        }
    }
    if(a1.count(abs(b))&&b1.count(abs(a))){
        cout << a << ' ' << b;
    }
    else{
        if(a<0){
            for(auto i:a1)
                cout << a << ' ' << i << '\n';
            for(auto i:b1)
                cout << b << ' ' << -1 * i << '\n';
        }
        else{
            for(auto i:a1)
                cout << a << ' ' << -1 * i << '\n';
            for(auto i:b1)
                cout << b << ' ' << i << '\n';
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