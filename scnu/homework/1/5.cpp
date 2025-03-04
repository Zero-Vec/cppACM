#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> v1;
vector<ll> v2;
vector<ll> v3;
void solve(){
    int x;
    while(cin>>x&&x!=-1){
        v1.push_back(x);
    }
    while(cin>>x&&x!=-1){
        v2.push_back(x);
    }
    int i = 0, j = 0;
    while(i<v1.size()&&j<v2.size()){
        if(v1[i]==v2[j]){
            v3.push_back(v1[i]);
            i++, j++;
        }
        else if(v1[i]<v2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    int cnt = 0;
    for(auto num:v3){
        if(!cnt){
            cnt++;
            cout << num;
        }
        else
            cout << " " << num;
    }
    if(!cnt)
        cout << "NULL";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}//原来最后一个点是相同元素也可以在链表中
/*最后一个测试点没过
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
map<ll, ll> mp;
void solve(){
    int x, y;
    while(cin>>x&&x!=-1){
        mp[x]++;
    }
    while(cin>>y&&y!=-1){
        mp[y]++;
    }
    bool tag = 0;
    int cnt = 0;
    for(const auto i:mp){
        if(i.second>=2){
            if(!cnt){
                tag = 1;
                cnt++;
                cout << i.first;
            }
            else
                cout << " " << i.first;
        }
    }
    if(!tag)
        cout << "NULL";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}*/