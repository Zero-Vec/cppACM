#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    //cout << log(4) / log(2);
    //double h = (-1.0 / 3) * log(1.0 / 3) / log(2) - (4.0 / 3) * log(2.0 / 3) / log(2);
    //cout << fixed << setprecision(4) << h;
    //cout << log((1.0 / 3)) / log(2);
    //cout << (1.0 / 3);

    /*
    double h;
    for (double i = 0.0; i <= 23333333.0;i+=1.0){
        double a = i * (-i / 23333333) * log(i / 23333333) / log(2);
        double b = (23333333.0 - i) * (23333333.0 - i) / 23333333 * log((23333333.0 - i) / 23333333) / log(2);
        h = a - b;
        if(fabs(h-11625907.5798)<=1e-4){
            cout << int(i) << '\n';
        }
    }
    */
    
    cout << 11027421;
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