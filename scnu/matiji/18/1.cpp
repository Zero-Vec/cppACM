    #include<bits/stdc++.h>
    using namespace std;
    using ll = long long;
    double a, b, kt, ans, ta, tb;
    void bonus(){
        tb = tb * 1.2;
    }
    void s1(){
        ans += ta + 0.9 * tb;
        bonus();
    }
    void s2(){
        ans += ta;
        bonus();
        ans += ta + tb * 2.0;
        bonus();
    }
    void s3(){
        for (int i = 1; i <= 4;i++){
            ans += ta + tb * 5.0;
            bonus();
        }
    }
    void s4(){
        ans += 500.0;
        bonus();
    }
    void work(int id){
        if(id == 1)
            s1();
        else if(id == 2)
            s2();
        else if(id == 3)
            s3();
        else
            s4();
    }
    void solve(){
        // 枚举 4! 种攻击顺序，看哪种可以
        cin >> a >> b >> kt;
        for (int i = 1; i <= 4;i++)
            for (int j = 1; j <= 4;j++)
                for (int k = 1; k <= 4;k++)
                    for (int z = 1; z <= 4;z++)
                        if(i!=j&&i!=k&&i!=z&&j!=k&&j!=z&&k!=z){
                            ans = 0.0, ta = a, tb = b;
                            work(i), work(j), work(k), work(z);
                            if(ans >= kt){
                                cout << "You have slain an enemy";
                                return;
                            }
                        }
        cout << "You have been slain";
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