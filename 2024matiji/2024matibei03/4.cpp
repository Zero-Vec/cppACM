#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
int n, a[N];
// WA
void solve(){
    cin >> n;
    for (int i = 1; i <= n + 1;i++)
        cin >> a[i];
    //n - i + 1
    vector<string> ans;
    for (int i = 1; i <= n + 1;i++){
        string t;
        if(a[i] > 0){
            t = "+";
            t += to_string(a[i]);
            if(n - i + 1 != 0){
                t += "x";
                if(n - i + 1 != 1){
                    t += '^';
                    t += to_string(n - i + 1);
                }
            }
        }
        else if(a[i] < 0){
            t += to_string(a[i]);
            if (n - i + 1 != 0){
                t += "x";
                if (n - i + 1 != 1){
                    t += '^';
                    t += to_string(n - i + 1);
                }
            }
        }
        ans.push_back(t);
    }
    string res;
    for(auto i:ans)
        res += i;
    if(res[0]=='+')
        res.erase(res.begin());
    for (int i = 1; i < res.size() - 1;i++){
        if(res[i] == '1' && res[i + 1] =='x' && (res[i - 1] == '+' || res[i - 1] == '-')){
            res[i] = '@';
        }
    }
    string y;
    for (int i = 0; i < res.size();i++){
        if(res[i]!='@')
            y += res[i];
    }
    cout << y;
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