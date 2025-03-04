#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, k, n;
    string s;
    cin >> s >> n;
    for (i = 0; i < n; i++)
    {
        int a, b;
        string s1, s2;
        cin >> a >> b >> s1 >> s2;
        string item = s.substr(a - 1, b - a + 1);
        s = s.substr(0, a - 1) + s.substr(b, s.length() - b);
        string s3 = s1 + s2;
        int index = s.find(s3);
        if (index == -1)
            s += item;
        else
        {
            s.insert(index + s1.length(), item);
        }
    }
    cout << s << endl;
    return 0;
}