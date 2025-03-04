#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int pre;
const int N = 1e3 + 9;
int a[N];
bool judge(int x){
    if(x==1)
        return 0;
    for (int i = 2; i <= sqrt(x);i++){
        if(x%i==0)
            return 0;
    }
    return 1;
}
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        a[i] = i;
    int cur = n;
    while(cur){
        for (int i = 1; i <= cur;i++){
            if(judge(cur+i)){
                pre = i;
                break;
            }
        }
        int prenew = pre;
        while(pre<cur){
            swap(a[pre], a[cur]);
            pre++, cur--;
        }
        cur = prenew - 1;
    }
    for (int i = 1; i <= n;i++)
        cout << a[i] << " ";
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