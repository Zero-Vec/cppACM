#include <iostream>
using namespace std;

unsigned short solve(unsigned short n, unsigned short s) {
    return (n >> s) | (n << (16 - s));
}

int main() {
    unsigned short n, s;
    cin >> n >> s;
    unsigned short ans = solve(n, s);
    cout << ans << '\n';
    return 0;
}