#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int k = 1;
    for (int i = s.size() - 1; i >= 0; --i) {
        int digit = s[i] - '0' + k;
        if (digit == 10) {
            s[i] = '0';
            k = 1;
        } else {
            s[i] = digit + '0';
            k = 0;
            break;
        }
    }
    if (k == 1) {
        s.insert(s.begin(), '1');
    }
    cout << s << '\n';
    return 0;
}