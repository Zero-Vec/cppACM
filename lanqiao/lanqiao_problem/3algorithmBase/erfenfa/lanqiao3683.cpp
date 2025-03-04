#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int a[N];
int n, m;
int check(int mid){
    //用于求解最近距离为mid时返回可以最多种多少棵树
    int ans = 0;
    for (int i = 1, last = 0; i <= n;i++){
        if(!last||a[i]-a[last]>=mid){
            ans++;
            last = i;
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int l = 1, r = 1e9;
    while (l+1!=r){
        int mid = (l + r) / 2;
        if(check(mid)>=m)
            l = mid;
        else
            r = mid;
    }
    cout << l;
    return 0;
}