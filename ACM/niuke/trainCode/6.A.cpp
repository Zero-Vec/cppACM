#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool judge(int x){
    for (int i = 2; i <= sqrt(x);i++){
        if(x%i==0)
            return 0;
    }
    return 1;
}
set<int> s;
void sushu(){
    for (int i = 2; i <= 97;i++){
        for (int j = i + 1; j <= 97;j++){
            for (int k = j + 1; k <= 97;k++){
                if(judge(i)&&judge(j)&&judge(k))
                    s.insert(i * j * k);
            }
        }
    }
}
void solve(){
    sushu();
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r;i++){
        if(s.count(i)){
            cout << i;
            return;
        }
    }
    cout << -1;
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