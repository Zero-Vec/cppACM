#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n%6==0)
            cout << n / 6 << "\n";
        else
            cout << n / 6 * 2 << "\n";
    }
    return 0;
}