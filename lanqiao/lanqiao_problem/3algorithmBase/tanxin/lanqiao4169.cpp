#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    long long sum = 0;
    int len = 0;
    int k1,k2;
    bool flag = false;
    for (int i = 1; i <= n;i++){
        if (a[i] > 0){
            if(!flag){
            sum += a[i];
            len++;
            flag = true;
            k1 = a[i];
            k2 = a[i - 1];
            }
            else{
                sum += a[i];
                len++;
            }
        }
    }
    if(len%2==0){
        cout << sum;
    }
    else{
        cout << max(sum - k1, sum + k2);
    }
        return 0;
}