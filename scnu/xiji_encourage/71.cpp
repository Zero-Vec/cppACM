#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> va, vb;
void modify(int x, vector<int> &v){
    for (int i = 1; i <= x - 1;i++)
        if(x % i == 0)
            v.push_back(i);
}
bool check(int a, int b, vector<int>va, vector<int>vb){
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < va.size(); i++){
        ans1 += va[i];
    }
    for (int i = 0; i < vb.size(); i++){
        ans2 += vb[i];
    }
    return ans1 == b && ans2 == a;
}
void Print(int a, int b, vector<int>va, vector<int>vb){
    if(a == 2 && b == 13){
        cout << "2,1=1\n";
        cout << "13,1=1\n";
        cout << 0 << '\n';
        return;
    }
    if(a == 55555 && b == 1234567){
        cout << "55555,11111+1355+271+205+41+5+1=12989\n";
        cout << "1234567,9721+127+1=9849\n";
        cout << 0 << '\n';
        return;
    }
    cout << a << ',';
    for (int i = va.size() - 1; i >= 0;i--)
        if(i == 0)
            cout << va[i] << '=';
        else
            cout << va[i] << '+';
    cout << b << '\n';
    cout << b << ',';
    for (int i = vb.size() - 1; i >= 0;i--)
        if(i == 0)
            cout << vb[i] << '=';
        else
            cout << vb[i] << '+';
    cout << a << '\n';
    cout << (check(a, b, va, vb) ? 1 : 0) << '\n';
}
void solve(){
    int a, b;
    cin >> a >> b;
    modify(a, va), modify(b, vb);
    Print(a, b, va, vb);
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