#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        char c = tolower(s1[0]);
        char k = toupper(s1[0]);
        if(c==s2[0]||s2[0]==k)
            cout << "Yes"<< "\n";
        else
            cout << "No"<< "\n";
    }
    return 0;
}