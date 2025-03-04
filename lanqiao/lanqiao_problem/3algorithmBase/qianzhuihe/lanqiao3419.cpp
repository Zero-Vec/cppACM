#include<bits/stdc++.h>
using namespace std;
int a[1005], prefix[1005];
int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.length();i++){
        if(s[i]=='L')
            a[i+1] = 1;
        else
            a[i+1] = -1;
    }
    prefix[0] = 0;
    for (int i = 1; i <= s.length();i++){
        prefix[i] = prefix[i - 1] + a[i];
    }
    int max1 = 0;
    for (int i = 1; i <=  s.length(); i++){
        for (int j = i; j <= s.length(); j++)
        {
            if (prefix[j] - prefix[i - 1] == 0)
                max1 = max(j - i + 1, max1);
        }
    }
    cout << max1 << '\n';
    return 0;
}