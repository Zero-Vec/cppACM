#include<bits/stdc++.h>
using namespace std;
int S(int x){
    if(!x)
        return 1;
    else if(x%2==0){
        return S(x / 2);
    }
    else{
        return S(x - 1) + 1;
    }
}
int main()
{
    int x;
    cin >> x;
    cout << S(x) << '\n';
    return 0;
}