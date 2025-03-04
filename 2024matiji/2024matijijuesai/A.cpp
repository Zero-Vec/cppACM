#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
char a[N], b[N];
void solve(){
    cin >> a + 1;
    cin >> b + 1;
    int l1 = strlen(a + 1), l2 = strlen(b + 1);
    bool tag = false;
    if(l1 >= l2){
        for (int i = 1, j = 1; i <= l1;i++){
            if(a[i]==b[j]){
                j++;
            }
            if(j>l2){
                tag = true;
                break;
            }
        }
    }
    else{
        for (int i = 1, j = 1; i <= l2; i++)
        {
            if (b[i] == a[j])
            {
                j++;
            }
            if (j > l1)
            {
                tag = true;
                break;
            }
        }
    }
    cout << (tag ? "Lucky!" : "QAQ Unlucky!");
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