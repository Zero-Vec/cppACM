#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct node
{
    int id;
    
    bool operator<(const node &u) const
    {
        string a = to_string(id), b = to_string(u.id);
        int l1 = a.size(), l2 = b.size();
        for (int i = 0, j = 0; i < l1 && j < l2; i++, j++)
        {
            if (a[i] == b[j])
                continue;
            if (a[i] > b[j])
                return true;
            else
                return false;
        }
        if(l1>l2)
            return true;
        else
            return false;
    }
    
};
void solve(){
    priority_queue<node> pq;
    for (int i = 1; i <= 40;i++){
        node t;
        t.id = i;
        pq.push(t);
    }
    while(pq.size()){
        node t = pq.top();
        pq.pop();
        cout << t.id << " ";
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