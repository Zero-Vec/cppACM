#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, a, b, c, d;
string ss1[] = {
    "zero", "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine", "ten", "eleven",
    "twelve", "thirteen", "fourteen", "fifteen",
    "sixteen", "seventeen", "eighteen", "nineteen"};
string ss2[] = {
    "0", "0", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
void solve(){
    cin >> n;
    int num = n;
    while(num){
        m++;
        num /= 10;
    }
    a = n / 1000;
    b = n % 1000 / 100;
    c = n % 100 / 10;
    d = n % 10;
    if(m==0){
        cout << ss1[0];
    }
    else if(m==1){
        cout << ss1[d];
    }
    else if(m==2){
        if(c==1){
            cout << ss1[c * 10 + d];
        }
        else{
            if(d==0)
                cout << ss2[c];
            else
                cout << ss2[c] << ' ' << ss1[d];
        }
    }
    else if(m==3){
        cout << ss1[b] << ' ' << "hundred ";
        if(c!=0&&d==0){
            cout << ss2[c];
        }
        else if(c!=0&&d!=0){
            cout << ss2[c] << " " << ss1[d];
        }
        else if(c==0&&d!=0){
            cout << "and " << ss1[d];
        }
    }
    else{
        cout << ss1[a] << " thousand ";
        if(b!=0){
            cout << ss1[b] << " hundred ";
            if (c != 0 && d == 0){
                cout << ss2[c];
            }
            else if (c != 0 && d != 0){
                cout << ss2[c] << " " << ss1[d];
            }
            else if (c == 0 && d != 0){
                cout << "and " << ss1[d];
            }
        }
        else{
            if(c!=0){
                cout << "and " << ss2[c] << ' ';
                if(d!=0)
                    cout << ss1[d];
            }
            else{
                if(d!=0)
                    cout << "and " << ss1[d];
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}