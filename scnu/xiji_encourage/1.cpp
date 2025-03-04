#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(int y){
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int daysInMonth(int y, int m){
    const int mons[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(m == 2 && check(y))
        return 29;
    return mons[m];
}

string addDays(string &s, int n){
    int y = stoi(s.substr(0, 4)), m = stoi(s.substr(4, 2)), d = stoi(s.substr(6, 2));
    while(n > 0){
        int d_cur = daysInMonth(y, m);
        if(d + n <= d_cur){
            d += n;
            n = 0;
        }
        else{
            n -= d_cur - d + 1;
            d = 1;
            if(++m > 12){
                m = 1;
                ++y;
                if(y > 9999)
                    return "out of limitation!";
            }
        }
    }
    ostringstream os;
    os << setw(4) << setfill('0') << y
       << setw(2) << setfill('0') << m
       << setw(2) << setfill('0') << d;
    return os.str();
}

void solve(){
    string s;
    int n;
    cin >> s >> n;
    cout << addDays(s, n) << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}