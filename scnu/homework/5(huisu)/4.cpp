#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, pair<int, int>>;
int sp[1005][1005];
int score[1005][1005];
int n, a, b;
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
bool sign;
int dis(pii ap)
{
    int dix = abs(ap.second.first - n / 2);
    int diy = abs(ap.second.second - n / 2);
    return max(dix, diy);
}

bool cmp(pii &ap, pii &bp) // 排序规则，剩余可走点少的情况优先，接着是远离中心点的情况优先，不能通过点的绝对距离判断，比如 x*x + y*y >= x1 * x1 + y1 * y1;
{
    return ap.first < bp.first || (ap.first == bp.first && dis(ap) > dis(bp));
}
int count(int x, int y) // 计算剩余可走点
{
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && sp[nx][ny] == -1)
        {
            cnt++;
        }
    }
    return cnt;
}
void init()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            score[i][j] = count(i, j); // 初始预处理每个点的可走点个数
        }
    }
}
void dfs(int x, int y, int step) // 递归做法，只能过 n <= 200的情况，这里就不细说
{
    sp[x][y] = step;
    if (step == (n * n - 1))
    {
        bool now = 0;
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx == (n / 2 - 1) && ny == n / 2)
            {
                now = 1;
                break;
            }
        }
        if (now)
        {
            int cha = sp[a][b] - sp[n / 2 - 1][n / 2];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; ++j)
                {
                    int ans = (sp[i][j] - cha + n * n) % (n * n) + 1;
                    cout << ans << ' ';
                }
                cout << '\n';
            }
            sign = true;
            return;
        }
        return;
    }
    vector<pii> st;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && sp[nx][ny] == -1)
        {
            int cnt = count(nx, ny);
            st.push_back({cnt, {nx, ny}});
        }
    }
    sort(st.begin(), st.end(), cmp);

    for (auto i : st)
    {
        dfs(i.second.first, i.second.second, step + 1);
        if (sign)
            return;
    }
    sp[x][y] = -1;
}

pair<int, int> p[1000005]; // p[i]表示当前第i层选中的位置，回溯时用到

int main()
{

    int step = 0;
    scanf("%d%d%d", &n, &a, &b);
    memset(sp, -1, sizeof sp);
    init();
    int prelev = 0; // 前一次递归到的层数
    a--;
    b--;
    stack<pii> sk; // 模拟递归过程的栈
    int fx = n / 2 - 1, fy = n / 2;
    sk.push({0, {fx, fy}}); // 第一个参数是当前位置所属的层数
    while (sk.size())       // 模拟递归过程
    {
        auto it = sk.top();
        sk.pop();
        int le = it.first;
        int x = it.second.first;
        int y = it.second.second;
        while (le <= prelev) // 回溯到当前le层，
        {
            sp[p[prelev].first][p[prelev].second] = -1; // 把其中le到prelev之间的位置更改为未走状态
            for (int i = 0; i < 8; i++)
            {
                int nx = p[prelev].first + dx[i];
                int ny = p[prelev].second + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && sp[nx][ny] == -1)
                {
                    score[nx][ny]++; // 这是一个关键点，由于点(p[prelev].first, p[prelev].second) 的状态回溯，其周围8个方向 未走状态 的位置分数 + 1， 表示多一个可走位置
                }
            }
            prelev--;
        }
        prelev = le;
        p[le] = {x, y};
        sp[x][y] = le;
        if (le == (n * n - 1))
        {
            bool now = 0;
            for (int i = 0; i < 8; i++)
            {
                // cout<<step<<' ';
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx == fx && ny == fy)
                {
                    now = 1;
                    break;
                }
            }
            if (now)
            {
                int cha = sp[a][b] - sp[n / 2 - 1][n / 2]; // 计算从中间开始出发的位置到指定位置的偏移量，因为整条路线可以看作一个环。
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; ++j)
                    {
                        int ans = (sp[i][j] - cha + n * n) % (n * n) + 1;
                        cout << ans << ' ';
                    }
                    cout << '\n';
                }
                return 0;
            }
        }
        vector<pii> st;
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && sp[nx][ny] == -1)
            {
                // int cnt = count(nx, ny); //直接计算可走位置只能过 n <= 700的情况
                score[nx][ny]--; // 使用分数记录可走的位置数量，可以把复杂度 / 8, 因此可以过 n >= 1000 的情况
                st.push_back({score[nx][ny], {nx, ny}});
            }
        }
        sort(st.begin(), st.end(), cmp); // 按照规则优先排序并入栈
        int len = st.size();
        for (int i = len - 1; i >= 0; i--)
        {
            pii pi;
            pi.first = le + 1;
            pi.second.first = st[i].second.first;
            pi.second.second = st[i].second.second;
            sk.push(pi);
        }
    }
    // dfs(n / 2 - 1, n / 2, 0);
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1010;
int nex[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
int f[8] = {-15, -6, 10, 17, 15, 6, -10, -17};
int dep = 1;
int print[N][N], a[N * N], n, x_, y_, F[8];
bool tag;
void Print_(){
    for (int i = 0; i < n;i++)
        for (int j = 0; j < n;j++)
            cout << print[i][j] << " \n"[j == n - 1];
}
//对结点n的下一步进行“后续下一步可选择数”的排序，结果存在b[][]里
//c 表示前驱节点在结点n的哪个位置
void Sort(int b[64][3],int pos,int c){
    int i, j, x, y, m1, m2, k, k1, l = 1, xx, yy;
    if(c!=-1)
        c = (c + 8 - 4) % 8;
    for (i = 0; i < 8;i++){
        F[i] = -1;
        m1 = pos + f[i];
        x = pos / 8 + nex[i][0];
        y = pos % 8 + nex[i][1];
        if(c!=i && x >= 0 && x < 8 && y >= 0 && y < 8 && a[m1] == 0){
            F[i]++;
            for (int j = 0; j < 8;j++){
                m2 = m1 + f[j];
                xx = x + nex[j][0];
                yy = y + nex[j][1];
                if(xx >= 0 && xx < 8 && yy >= 0 && yy < 8 && a[m2] == 0)
                    F[i]++;
            }
        }
    }
    b[pos][0] = -1;
    for (int i = 1; i < 3;i++){
        k = 9;
        for (j = 0; j < 8;j++){
            if(F[j]>-1 && F[j]<k){
                k = F[j];
                k1 = j;
            }
        }
        if(k<9){
            b[pos][l++] = k1;
            F[k1] = -1;
            b[pos][0] = 1;
        }
        else{
            b[pos][l++] = -1;
            break;
        }
    }
}
void dfs(int pos){
    if(tag)
        return;
    int i, j, k;
    int b[64][3], s[N * N];
    s[0] = pos;
    Sort(b, pos, -1);
    while(dep >= 0){
        if(b[pos][0] != -1 && b[pos][0] < 3 && b[pos][b[pos][0]] != -1){
            k = b[pos][b[pos][0]];
            b[pos][0]++;
            pos += f[k];
            Sort(b, pos, k);
            a[pos] = ++dep;
            s[dep - 1] = pos;
            if(dep==n*n){
                for (int i = 0; i < n;i++)
                    for (int j = 0; j < n;j++)
                        print[i][j] = a[i * n + j];
                tag = 1;
            }
        }
        else{
            dep--;
            a[pos] = 0;
            pos = s[dep - 1];
        }
    }
}

void solve(){
    cin >> n >> x_ >> y_;
    int pos = x_ * n + y_ - n - 1;
    a[pos] = 1;
    dfs(pos);
    Print_();
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
*/