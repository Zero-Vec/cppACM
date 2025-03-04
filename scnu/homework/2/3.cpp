#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e6;
int a[N], b[N], n, m;
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int index = 0, end = (n + m + 1) / 2, i = 0, j = 0;
    int cur1 = 0, cur2 = 0, flag = 0;
    while (index != end)
    {
        if (i < n && a[i] < b[j])
        {
            cur1 = i++;
            flag = 1;
        }
        else if (j < m)
        {
            cur2 = j++;
            flag = 2;
        }
        index++;
    }
    if (flag == 1)
    {
        cout << a[cur1];
    }
    else
    {
        cout << b[cur2];
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
/*
最后一个测试点mle
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    vector<int> v;
    int n, m, x;
    cin>>n;
    for (int i = 1;i<=n;i++){
        cin>>x;
        v.push_back(x);
    }
    cin >> m;
    for (int i = 1; i <= m;i++){
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    cout << v[(v.size() - 1) / 2];
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