//18/20
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll x;
    cin>>x;
    vector<int> v1;
    ll t = x;
    while(t){
        v1.push_back(t % 10);
        t /= 10;
    }
    vector<int> v2 = v1;
    sort(v1.begin(), v1.end(), greater<int>());
    v1.erase(unique(v1.begin(), v1.end()), v1.end());
    /*
    for(auto i:v1)
        cout << i << '\n';
    */
    cout << "int[] arr = new int[]{";
    for (int i = 0; i < v1.size();i++){
        if(i!=v1.size()-1)
            cout << v1[i] << ",";
        else
            cout << v1[i];
    }
    cout << "};\n";
    cout << "int[] index = new int[]{";
    reverse(v2.begin(),v2.end());
    vector<int> v3;
    for (int i = 0; i < 11;i++){
        for (int j = 0; j < v1.size();j++){
            if(v2[i]==v1[j]){
                v3.push_back(j);
                break;
            }
        }
    }
    for (int i = 0; i < v3.size(); i++){
        if (i != v3.size() - 1)
            cout << v3[i] << ",";
        else
            cout << v3[i];
    }
    cout << "};\n";
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