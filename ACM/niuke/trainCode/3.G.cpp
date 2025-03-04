#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int a[2], b[2], z[2];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        if(n==1){
            cin >> a[0] >> b[0] >> z[0];
            if(a[0]==b[0]&&z[0]==1)
                cout << "No" << '\n';
            else
                cout << "Yes" << '\n';
        }
        else{
            cin >> a[0] >> b[0] >> z[0];
            cin >> a[1] >> b[1] >> z[1];
            bool flag = false;
            if((z[0]==1&&z[1]==0)||(z[0]==0&&z[1]==1))
                flag = true;
            if(a[0]==a[1]&&b[0]==b[1]&&flag)
                cout << "No" << '\n';
            else if(a[0]==b[1]&&a[1]==b[0]&&z[0]&&z[1])
                cout << "No" << '\n';
            else if(a[0]==b[0]&&z[0]==1)
                cout << "No" << '\n';
            else if(a[1]==b[1]&&z[1]==1)
                cout << "No" << '\n';
            else
                cout << "Yes" << '\n';
        }
    }
    return 0;
}