/**
  思路：1.首先贪心的策略是每次最优，那么结果就是最优的
        2.那么这道题我们可以每次删除序列中 升序的结尾，重复上述操作k次，这样的话我们就能可以
         这个结果的最优解了

         解释：因为在一串数中，我们想要其删完某个数后其剩下的值最小，我们总想删除大的数
              那么剩下的数肯定要小呀 比如 12345  删除5剩下的数是最小的


        3.当然我们也可以删除每次发生降序的时候 就把前一个数删除
**/

// 100012 2  1

#include <bits/stdc++.h>
using namespace std;

int main()
{

    string str;
    int k, flag = 0;
    vector<char> v;

    cin >> str >> k;

    for (int i = 0; i < str.size(); i++)
    {
        v.push_back(str[i]);
    }

    while (k--)
    {

        int i = 0;
        flag = 0;
        vector<char>::iterator t = v.begin(); // 这里主要是为了调用  v.erase()的库函数删除元素

        while (i != v.size() - 1)
        { // 注意这里的减一 因为下方的v[i+1] 否则会出现段错误

            if (v[i] > v[i + 1])
            { // 如果出现后一个数小于前一个数那么这就是这一趟的递增的终点
                v.erase(t);
                flag = 1;
                break;
            }

            i++;
            t++;
        }

        if (flag == 0)
        { // 如果是一个递增序列那么的话就要删除最后一个数
            v.erase(t);
        }
    }

    int i = 0;

    // 这么输出是为了防止前置'0'的输出
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != '0')
            break;
    }

    int j = i;

    for (; j < v.size(); j++)
    {
        cout << v[j];
    }
}
