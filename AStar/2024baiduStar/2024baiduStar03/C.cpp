#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 1e5 + 9, base = 131;
int n, q, l1, r1, l2, r2;
char s[N];
int cnt[30][N];
int gsk[30];
ull h[N], b[N];
ull gethash(int l,int r){
    return h[r] - h[l - 1] * b[r - l + 1];
}
void solve(){
    cin >> n >> q;
    cin >> s + 1;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= 26;j++)
            cnt[j][i] = cnt[j][i - 1];
        cnt[s[i] - 'a' + 1][i]++;
    }
    b[0] = 1;
    for (int i = 1; i <= n;i++){
        h[i] = h[i - 1] * base + s[i] - 'a' + 1;
        b[i] = b[i - 1] * base;
    }
    while(q--){
        cin >> l1 >> r1 >> l2 >> r2;
        if(gethash(l1,r1)==gethash(l2,r2)){
            cout << 0 << '\n';
            cout << '\n';
            continue;
        }
        //set<char> st;
        for (int i = 1; i <= 26;i++)
            gsk[i] = 0;
        //map<char, int> mp;
        int res = 0;
        for (int i = 1; i <= 26;i++){
            if(cnt[i][r1]-cnt[i][l1-1]>0||cnt[i][r2]-cnt[i][l2-1]>0)
                res++;
        }
        int gs = r1 - l1 + 1;
        int siz = 0;
        for (int i = 1; i <= gs;i++){
            if(gsk[s[l1+i-1]-'a'+1]&&gsk[s[l2+i-1]-'a'+1] || s[l1+i-1]==s[l2+i-1])
                continue;
            if(s[l1+i-1]!=s[l2+i-1]){
                if (!gsk[s[l1 + i - 1] - 'a' + 1])
                    siz++;
                if (!gsk[s[l2 + i - 1] - 'a' + 1])
                    siz++;
                    //st.insert(s[l1 + i - 1]), st.insert(s[l2 + i - 1]);
                gsk[s[l1 + i - 1] - 'a' + 1]++, gsk[s[l2 + i - 1] - 'a' + 1]++;
            }
            if(siz==res || gethash(i+1,r1)==gethash(i+1,r2))
                break;
        }
        cout << siz << '\n';
        for (int i = 1; i <= 26;i++){
            if(gsk[i])
                cout << char('a' + i - 1);
        }
        cout << '\n';
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