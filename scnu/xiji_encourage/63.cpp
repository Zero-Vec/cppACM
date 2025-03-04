#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int h, m, s;
    char ch;
    cin >> h >> ch >> m >> ch >> s;
    s++;
    if (s == 60) {
        s = 0;
        m++;
    }
    if (m == 60) {
        m = 0;
        h++;
    }
    if (h == 24) {
        h = 0;
    }
    cout << h << ":" << m << ":" << s << endl;
    return 0;
}