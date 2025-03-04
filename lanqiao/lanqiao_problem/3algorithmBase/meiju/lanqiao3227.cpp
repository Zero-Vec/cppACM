#include<bits/stdc++.h>
using namespace std;
map<int, int> mp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int num;
    for (int i = 0; i < n * m; i++)
    {
        cin >> num;
        mp[num]++;
    }
    for(const auto [x,y]:mp)
    {
        if(2*y>n*m)
            cout << x;
    }
        return 0;
}