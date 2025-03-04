#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> v;
    for (int i = 1; i <= n;i++)
        v.push_back(i);
    while(m--){
        int x, y, z;
        cin >> x >> y >> z;
        auto it = find(v.begin(), v.end(), x);
        v.erase(it);
        auto po = find(v.begin(), v.end(), y);
        if(z){
            v.insert(po, x);
        }
        else{
            v.insert(po + 1, x);
        }
    }
    for(auto i:v)
        cout << i << ' ';
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
const int N = 1e4 + 9;
//双链表
int e[N], p[N];
int n, m;
void del(int x){
    if(e[x]==-1){
        e[p[x]] = -1;
    }
    else{
        e[p[x]] = e[x];
        p[e[x]] = p[x];
    }
}
void insert_front(int y,int x){
    e[x] = y, p[x] = p[y], p[e[x]] = x, e[p[x]] = x;
}
void insert_back(int y ,int x){
    if(e[y]==-1){
        e[x] = -1;
        p[x] = y;
        e[y] = x;
    }
    else{
        e[x] = e[y], p[x] = y, p[e[y]] = x, e[y] = x;
    }
}
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        e[i] = i + 1;
        p[i] = i - 1;
    }
    e[0] = 1, e[n] = -1;
    while(m--){
        int x, y, z;
        cin >> x >> y >> z;
        if(z){
            del(x);
            insert_front(y, x);
        }
        else{
            del(x);
            insert_back(y, x);
        }
    }
    for (int i = e[0]; i != -1;i=e[i]){
        cout << i << ' ';
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
*/