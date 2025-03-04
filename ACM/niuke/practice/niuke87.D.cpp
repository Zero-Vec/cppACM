#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s, op;
void solve()
{
    int n, k;
    cin >> n >> k;
    cin >> s;
    while (k--){
        int cnt = s.find('I');
        cin >> op;
        if (op[0] == 'b'){
            if (cnt - 1 >= 0 && cnt + 1 < s.size() && s[cnt - 1] == '(' && s[cnt + 1] == ')'){
                s.erase(cnt - 1, 1);
                s.erase(cnt, 1);
            }
            else if (cnt - 1 >= 0){
                s.erase(cnt - 1, 1);
            }
        }
        else if(op[1]=='-'){
            if(cnt-1>=0){
                swap(s[cnt], s[cnt - 1]);
            }
        }
        else if(op[0]=='-'){
            if(cnt+1<s.size()){
                swap(s[cnt], s[cnt + 1]);
            }
        }
        else{
            if (cnt + 1 < s.size()){
                s.erase(cnt + 1, 1);
            }
        }
    }
    cout << s << "\n";
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
#include<bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
#define int  long long
#define sz(s) ((int)s.size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pb push_back
#define eb emplace_back
#define pii std::pair<int,int>
#define pll std::pair<ll,ll>
#define yes std::cout << "YES"  << std::endl;
#define no std::cout << "NO" << std::endl;
#define MAXN 1e5+5

//using namespace std;
const int N = 2e6 + 5, mod = 998244353;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'I') {
            pos = i;
            break;
        }
    }
    std::vector<char> l, r;
    for (int i = 0; i < pos; i++) {
        l.pb(s[i]);
    }
    for (int i = pos + 1; i < n; i++) {
        r.pb(s[i]);
    }
    reverse(all(r));
    while (q--) {
        std::string op;
        std::cin >> op;
        if (op == "backspace") {
            if (!l.empty()) {
                if (l.back() == '(' && !r.empty() && r.back() == ')') {
                    l.pop_back();
                    r.pop_back();
                } else {
                    l.pop_back();
                }
            }
        } else if (op == "delete") {
            if (!r.empty()) {
                r.pop_back();
            }
        } else if (op == "<-") {
            if (!l.empty()) {
                r.push_back(l.back());
                l.pop_back();
            }
        } else if (op == "->") {
            if (!r.empty()) {
                l.push_back(r.back());
                r.pop_back();
            }
        }
    }
    for (int i = 0; i < sz(l); i++)std::cout << l[i];
    std::cout << 'I';
    reverse(all(r));
    for (int i = 0; i < sz(r); i++)std::cout << r[i];
    std::cout << std::endl;
}

signed main() {
    IOS
    int T = 1;
//	std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
*/