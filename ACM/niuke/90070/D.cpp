#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll a[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    ll sum = 0;
    for (int i = 1; i <= n;i++){
        if(a[i] <= sum + 1){
            sum += a[i];
        }
    }
    if(sum < n){
        cout << sum + 1 << '\n';
    }
    else{
        cout << "Cool!\n";
    }
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

/*
题目大意就是给n个数，任意组合，求n以内最小的不能组成的数，
解题思路用的是动态规划的思想，先排序，维护一个区间[ 1 , sum ] ,表示该区间内的数都可以组成，
如果当前a[ i ]大于sum + 1 , 当前sum + 1就是当前不能组成的数，因为当前a[ i ] 已经大于sum + 1，无论如何都无法组成sum + 1；
相反，如果a[ i ]小于等于sum + 1，则更新sum = sum + a[i]，此时区间为[1,sum + a[ i ] ] ，
为什么sum + 1 到 sum + a[i]可以取到，这是因为[ 1 , sum ] 中的值我们是能取到的。
*/