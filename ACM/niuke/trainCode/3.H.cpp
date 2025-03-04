#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int a[28][4];
bool v[28];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    int cnt = 1;
    for (int i = 1; i <= 3;i++){
        for (int j = 1; j <= 3;j++){
            for (int k = 1; k <= 3;k++){
                a[cnt][1] = i;
                a[cnt][2] = j;
                a[cnt][3] = k;
                cnt++;
            }
        }
    }
        while (t--)
        {
            int n;
            cin >> n;
            memset(v, false, sizeof v);
            for (int i = 1; i <= n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                for (int j = 1; j <= 27;j++){
                    if(z&&a[j][x]>=a[j][y])
                        v[j] = 1;
                    if(!z&&a[j][x]<a[j][y])
                        v[j] = 1;
                }
            }
            bool jud = 0;
            for (int i = 1; i <= 27;i++){
                if(!v[i])
                    jud = 1;
            }
            cout << (jud ? "Yes\n" : "No\n");
        }
    return 0;
}