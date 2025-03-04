#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    string t[] = {"DFS", "dfs"};
    while(T--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < 2;i++){
            int k = 0;
            for (int j = 0; j < n && k < 3;j++){
                if(t[i][k]==s[j])
                    k++;
            }
            cout << (k == 3) << " \n"[i == 1];
        }
    }
    return 0;
}