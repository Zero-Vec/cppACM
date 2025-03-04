#include <bits/stdc++.h>
#define fore(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define fi first
#define se second
#define endl '\n'
#define ull unsigned long long
#define ALL(v) v.begin(), v.end()
#define Debug(x, ed) std::cerr << #x << " = " << x << ed;

const int INF = 0x3f3f3f3f;
const long long INFLL = 1e18;

typedef long long ll;

const int P = 4;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--)
    {
        int n, q;
        std::cin >> n >> q;
        std::vector<std::pair<int, int>> col(n + 1);
        std::vector<std::vector<int>> g(16);
        fore(i, 1, n + 1)
        {
            std::string s;
            std::cin >> s;
            std::array<int, 2> b;
            fore(j, 0, 2)
            {
                if (s[j] == 'B')
                    b[j] = 0;
                else if (s[j] == 'R')
                    b[j] = 1;
                else if (s[j] == 'G')
                    b[j] = 2;
                else
                    b[j] = 3;
            }
            if (b[0] > b[1])
                std::swap(b[0], b[1]);
            int C = b[0] * P + b[1];
            g[C].push_back(i);
            col[i] = {b[0], b[1]};
        }

        while (q--)
        {
            int u, v;
            std::cin >> u >> v;
            auto [cu1, cu2] = col[u];
            auto [cv1, cv2] = col[v];
            std::array<int, 2> b1 = {cu1, cu2};
            std::array<int, 2> b2 = {cv1, cv2};
            if (cu1 == cv1 || cu1 == cv2 || cu2 == cv1 || cu2 == cv2)
            {
                std::cout << std::abs(u - v) << endl;
                continue;
            }
            int ans = INF;
            fore(i, 0, 2)
                fore(j, 0, 2)
            {
                std::array<int, 2> c = {b1[i], b2[j]};
                if (c[0] > c[1])
                    std::swap(c[0], c[1]);
                int C = c[0] * P + c[1];
                if (g[C].empty())
                    continue;
                auto it2 = std::upper_bound(ALL(g[C]), v);
                if (it2 != g[C].end())
                    ans = std::min(ans, *it2 - v + std::abs(*it2 - u));
                if (it2 != g[C].begin())
                {
                    --it2;
                    ans = std::min(ans, std::abs(*it2 - u) + v - *it2);
                }
            }

            std::cout << (ans == INF ? -1 : ans) << endl;
        }
    }
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int n, q;
map<string, ll> mp;
string a[N];
vector<ll> v[10];
bool valid(string a,string b){
    if(a[0]==b[0]||a[0]==b[1]||a[1]==b[0]||a[1]==b[1])
        return true;
    return false;
}
void solve(){
    cin >> n >> q;
    for (ll i = 1; i <= n;i++){
        string s;
        cin >> s;
        a[i] = s;
        if(s[0]=='B')
            v[0].push_back(i);
        if(s[0]=='G')
            v[1].push_back(i);
        if(s[0]=='R')
            v[2].push_back(i);
        if(s[0]=='Y')
            v[3].push_back(i);
        if (s[1] == 'B')
            v[0].push_back(i);
        if (s[1] == 'G')
            v[1].push_back(i);
        if (s[1] == 'R')
            v[2].push_back(i);
        if (s[1] == 'Y')
            v[3].push_back(i);
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        if(x==y){
            cout << 0 << '\n';
        }
        else if(x<y){
            if(valid(a[x],a[y])){
                cout << y - x << '\n';
            }
            else{
                string t = a[x];

            }
        }
        else{
            if(valid(a[x],a[y])){
                cout << x - y << '\n';
            }
            else{

            }
        }
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
*/