// https://ac.nowcoder.com/acm/contest/73854/A
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 105;
int a[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    if(n&1)
        cout << "Alice" << '\n';
    else{
        bool tag = false;
        for (int i = 1; i <= n / 2;i+=2){
            if(a[i]<a[i+1])
                tag = true;
        }
        cout << (tag ? "Alice\n" : "Bob\n");
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
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;
    cin >> n;
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        pq.push(x);
    }
    if(n&1)
        cout << "Alice" << '\n';
    else{
        int a = 0, b = 0;
        while(pq.size()){
            a += pq.top();
            pq.pop();
            b += pq.top();
            pq.pop();
        }
        if(a>b)
            cout << "Alice" << '\n';
        else
            cout << "Bob" << '\n';
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