#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    for(auto &i:s1){
        if(i=='A')
            i = 'T';
        else if(i=='T')
            i = 'A';
        else if(i=='C')
            i = 'G';
        else
            i = 'C';
    }
    int ans = 0;
    for (int i = 0; i < s1.length();i++){
        if(s1[i]==s2[i])continue;
        for (int j = i + 1; j < s1.length();j++){
            if(s1[i]==s2[j]&&s1[j]==s2[i]){
                swap(s1[i], s1[j]);
                ans++;
                break;
            }
        }
    }
    for (int i = 0; i < s1.length();i++){
        if(s1[i]!=s2[i])
            ans++;
    }
    cout << ans;
    return 0;
}