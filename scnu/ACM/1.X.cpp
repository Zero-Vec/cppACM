#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, A, B;
    cin >> N >> A >> B;

    int rows = N * A;
    int cols = N * B;
    vector<vector<char>> grid(rows, vector<char>(cols));

    // 遍历每个方格
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // 计算当前方格所在的瓦片的索引
            int tileRow = i / A;
            int tileCol = j / B;

            // 如果瓦片的行数和列数都是偶数，或者都是奇数，则当前方格为白色
            // 否则，当前方格为黑色
            if ((tileRow % 2 == 0 && tileCol % 2 == 0) || (tileRow % 2 == 1 && tileCol % 2 == 1))
            {
                grid[i][j] = '.';
            }
            else
            {
                grid[i][j] = '#';
            }
        }
    }

    // 输出网格
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}