#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N];
vector<int> L;//离散化数组
int getidx(int x){
    return lower_bound(L.begin(), L.end(), x) - L.begin();
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //离散化板子题：给定a数组，求出a的离散化数组，并可以通过值找到下标
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= n;i++)
        L.push_back(a[i]);
    sort(L.begin(), L.end());
    L.erase(unique(L.begin(), L.end()), L.end());
    cout << "离散化数组为：";
    for(auto i:L){
        cout << i << " ";
    }
    cout << '\n';
    int val;
    cin >> val;
    cout << getidx(val);
    return 0;
}