#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 9;
int a[N];
int n, m;
//判断是否是素数
bool sushu(int x){
    if(x==1)
        return 0;
    if(x==2)
        return 1;
    for (int i = 2; i <= sqrt(x);i++)
        if(x%i==0)
            return 0;
    return 1;
}
//求各位数平方和
void pingfanghe(){
    a[10000] = 1;
    for (int i = 1; i <= 9999;i++){
        int sum = 0;
        int t = i;
        for (int j = 1; j <= 4;j++){
            int k = t % 10;
            sum += k * k;
            t /= 10;
        }
        a[i] = sum;
    }
}
//是否幸福
bool xingfu(int x){
    int t = x;
    set<int> s;
    while(a[t]!=1){
        if(s.count(a[t]))
            return 0;
        s.insert(a[t]);
        t = a[t];
    }
    return 1;
}
//是否独立
bool duli(int x){
    for (int i = n; i <= m;i++){
        if(a[i]==x)
            return 0;
    }
    return 1;
}

void solve(){
    cin >> n >> m;
    pingfanghe();
    bool tag = 0;
    for (int i = n; i <= m;i++){
        int count = 1;
        if(xingfu(i)&&duli(i)){
            tag = 1;
            int t = i;
            while(a[t]!=1){
                count++;
                t = a[t];
            }
            if(sushu(i))
                count *= 2;
            cout << i << ' ' << count << '\n';
        }
    }
    if(!tag)
        cout << "SAD";
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