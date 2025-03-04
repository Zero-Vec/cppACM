#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1e5+9;
int a[N];
int tag[N];
int n, l, r, cur;
void solve(){
    cin >> n;
    int x;
    for (int i = 1; i <= n;i++){
        cin >> x >> a[i];
    }
    cin >> cur;
    a[x + 1] = cur;
    sort(a + 1, a + n + 2);
    /*
    for (int i = 1; i <= n + 1;i++)
        cout << a[i] << '\n';
    */
    int id;
    for (int i = 1; i <= n + 1;i++){
        if(a[i]==cur)
            id = i;
    }
    tag[id] = 1;
    ll ans = 0;
    for (int i = 1; i <= n;i++){
        l = id - 1, r = id + 1;
        while(tag[l]&&l>=1)
            l--;
        while(tag[r]&&r<=n+1)
            r++;
        if(!l){
            ans += a[r] - a[id];
            id = r;
            tag[r] = 1;
        }
        else if(r==n+2){
            ans += a[id] - a[l];
            id = l;
            tag[l] = 1;
        }
        else{
            ans += min(a[r] - a[id], a[id] - a[l]);
            id = (a[r] - a[id] < a[id] - a[l] ? r : l);
            tag[id] = 1;
        }
    }
    cout << ans;
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
/*
#include <iostream>
#include <cstring>
#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;
int a[100000];
int ans=0,mark=0,flag=0,k=0;
int n,left_,right_;
void find(int l,int r,int now) {  // 开始比较
    if (a[now]-a[l] < a[r]-a[now]) {   //首先，得判断大小的问题
        if (a[l] == -2) {          //第二，得判断边界值，如果到了边界。我们就换一边贪心，且只能换一边贪心；
            ans+=a[r]-a[now];
            k = a[r];             //向右边贪心
            mark++;
            a[now] = -1;
        } else {
            ans+=a[now]-a[l];
            k = a[l];           //向左边贪心
            mark++;
            a[now] = -1;
        }
    } else if (a[r] == -2) {
        ans+=a[now]-a[l];          //向左边贪心
        k = a[l];
        mark++;
        a[now] = -1;
    } else {
        ans+=a[r]-a[now];            //向右边贪心，
        k = a[r];
        mark++;
        a[now] = -1;
    }
}
void change(int www) {
    for (int i=www-1; i>=0; i--) {
        if (a[i] != -1) {
            left_ = i;
        }                //找到第一个不为-1的，且在他左边的数，记录更改left
        break;
    }
    for (int i=www+1; i<=n+2; i++) {
        if (a[i] != -1) {
            right_ = i;  //同理，改变右边；
        }
        break;
    }
}
int main() {
    scanf("%d",&n);
    memset(a,-1,sizeof(a));  //数组初始化，里面的元素全为-1；
    for (int i=1; i<=n; i++) {
        scanf("%d%d",&k,&a[i]);
    }
    scanf("%d",&a[n+1]);
    k = a[n+1];         //丢进去磁盘开始的地方
    sort(a+1,a+n+2);   //排序
    int i=0;
    a[0] = -2;      //边界之外赋值
    a[n+2] = -2;
    while (1) {
        if (mark == n) {  //如果我们的标记值为已经达到了n，我们就退出循环，
            break;
        }
        i++;            //遍历开始
        if (k == a[i]) {   //如果找到目前k在元素中的那个地方
            change(i);    //找到他的左右不为-1的元素下标；
            find(left_,right_,i); //比较的状态；
            i=0;    //因为k的值更新了，所以要从头开始找；
        }
    }
    printf("%d",ans);
    return 0;
}
*/