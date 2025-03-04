#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void modify(vector<vector<int>>& mp, int n) {
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[j][n - 1 - i] = mp[i][j];
        }
    }
    mp = a;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n));
    int value = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans[i][j] = value++;
        }
    }
    modify(ans, n);
    for (auto row : ans) {
        for (auto elem : row) {
            cout << setw(4) << elem;
        }
        cout << '\n';
    }
    return 0;
}