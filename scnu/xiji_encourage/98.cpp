#include <bits/stdc++.h>
using namespace std;

// 矩阵乘法
vector<vector<int>> solve(const vector<vector<int>> &A, const vector<vector<int>> &B){
    int rows = A.size();
    int cols = B[0].size();
    int common = B.size();
    vector<vector<int>> res(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            for (int k = 0; k < common; ++k)
                res[i][j] += A[i][k] * B[k][j];
    return res;
}

int main()
{
    vector<vector<int>> ans1;
    vector<vector<int>> ans2;
    vector<vector<int>> ans3;
    char operation;
    int n;
    while (true){
        string line;
        getline(cin, line);
        if (line.length() == 1 && (line[0] == '+' || line[0] == '-' || line[0] == '*')){
            operation = line[0];
            break;
        }
        vector<int> row;
        int num;
        istringstream iss(line);
        while (iss >> num)
            row.push_back(num);
        ans1.push_back(row);
    }

    n = ans1.size(); // 矩阵行数
    for (int i = 0; i < n; ++i){
        vector<int> row;
        for (int j = 0; j < n; ++j){
            int num;
            cin >> num;
            row.push_back(num);
        }
        ans2.push_back(row);
    }
    if (operation == '+'){
        ans3 = vector<vector<int>>(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                ans3[i][j] = ans1[i][j] + ans2[i][j];
    }
    else if (operation == '-'){
        ans3 = vector<vector<int>>(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                ans3[i][j] = ans1[i][j] - ans2[i][j];
    }
    else if (operation == '*')
        ans3 = solve(ans1, ans2);
    for (auto row : ans3){
        for (auto val : row)
            cout << setw(5) << val; // 每个元素占5个字符宽度
        cout << '\n';
    }
    return 0;
}
