#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string ch = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int n, k;
int main()
{
    cin >> n >> k;
    string ans;
    while(n){
        ans += ch[n % k];
        n /= k;
    }
    for(int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
    return 0;
}