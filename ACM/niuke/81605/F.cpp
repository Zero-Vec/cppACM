#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
int mp[N][N], n, line[N], row[N];
set<pair<int, int>> st;
bool valid(int x,int y){
    return x >= 1 && y >= 1 && x <= n && y <= n;
}
int gcd(int a,int b){
    return !b ? a : gcd(b, a % b);
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n * n;i++){
        int x, y;
        cin >> x >> y;
        if(mp[x][y]>=1||row[x]>=2||line[y]>=2){
            cout << 0;
            continue;
        }
        cout << 1;
        line[y]++, row[x]++;
        for(auto [a,b]:st){
            int u = x - a, v = y - b;
            if(!u){
                row[x]++;
            }
            else if(!v){
                line[y]++;
            }
            else{
                int g = gcd(u, v);
                u /= g, v /= g;
                int r = x, l = y;
                while(valid(r,l)){
                    mp[r][l]++;
                    r += u, l += v;
                }
                r = x, l = y;
                while(valid(r,l)){
                    mp[r][l]++;
                    r -= u, l -= v;
                }
            }
        }
        st.insert({x, y});
    }
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
/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
struct node{
    int x1, y1, x2, y2;
};
set<pair<int, int>> mp;
map<pair<int, int>, node> st;
int n, line[N], row[N];
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
string ans;
void solve(){
    cin >> n;
    for (int i = 1; i <= n * n;i++){
        int a, b;
        cin >> a >> b;
        if(line[b] >= 2 || row[a] >= 2){
            ans += '0';
            continue;
        }
        bool tag = false;
        for(auto x:mp){
            int tx = x.first - a, ty = x.second - b;
            if(!tx||!ty)continue;
            int g = gcd(abs(tx), abs(ty));
            tx /= g, ty /= g;
            if(st.count({tx,ty}) || st.count({-tx,-ty})){
                node t = st[{tx, ty}];
                if((b-t.y1)*(t.x2-t.x1)-(t.y2-t.y1)*(a-t.x1)==0){
                    tag = true;
                    ans += '0';
                    break;
                }
                // if(t.x1*t.y2+t.x2*b+a*t.y1-t.x1*b-t.x2*t.y1-a*t.y2 == 0){
                //     tag = true;
                //     ans += '0';
                //     break;
                // }
            }
        }
        if(!tag){
            // cout << a << " " << b << '\n';
            for(auto x:mp){
                int tx = x.first - a, ty = x.second - b;
                if (!tx || !ty)
                    continue;
                int g = gcd(abs(tx), abs(ty));
                tx /= g, ty /= g;
                st[{tx, ty}] = {a, b, x.first, x.second};
                st[{-tx, -ty}] = {a, b, x.first, x.second};
            }
            mp.insert({a, b});
            row[a]++, line[b]++;
            ans += '1';
        }
    }
    // cout << "========" << '\n';
    cout << ans;
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