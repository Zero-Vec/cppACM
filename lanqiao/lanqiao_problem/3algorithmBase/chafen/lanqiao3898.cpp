#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll a[N], d[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, w;
    cin >> n >> w;
    while(n--){
        int s, t, p;
        cin >> s >> t >> p;
        s += 1, t += 1;
        d[s] += p, d[t] -= p;
    }
    for (int i = 1; i < N;i++){
        a[i] = a[i - 1] + d[i];
    }
    for (int i = 1; i < N;i++){
        if(a[i]>w)
        {
            cout << "No" << '\n';
            return 0;
        }
    }
    cout<<"Yes"<<"\n";
    return 0;
}