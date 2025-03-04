#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll a[N], b[N];
int n, m, k;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        a[i] += a[i - 1];//求前缀和
    }
    for (int i = 1; i <= m;i++){
        cin >> b[i];
        b[i] += b[i - 1];
    }
    // 枚举x，二分求出y，求x+y的最大值
    int ans = 0;
    for (int i = 0; i <= n;i++){
        //i为通过的x的关卡数
        if(a[i]>k)
            break;
        int res = k - a[i];
        int l = 0, r = m + 1;//是m+1而不是m，因为要让l有取到m的机会
        while(l+1!=r){
            int mid = (l + r) / 2;
            if(b[mid]<=res)
                l = mid;
            else
                r = mid;
        }
        ans = max(ans, i + l);
    }
    cout << ans;
    return 0;
}