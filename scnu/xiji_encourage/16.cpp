#include <iostream>
#include <vector>

using namespace std;

// 结构体表示多项式的一项
struct Term
{
    int c;
    int e;
};
// 多项式乘法函数
vector<Term> solve(const vector<Term> &poly1, const vector<Term> &poly2)
{
    vector<Term> ans;
    for (const auto &term1 : poly1)
    {
        for (const auto &term2 : poly2)
        {
            Term newTerm;
            newTerm.c = term1.c * term2.c;
            newTerm.e = term1.e + term2.e;
            bool tag = false;
            for (auto &term : ans)
            {
                if (term.e == newTerm.e)
                {
                    term.c += newTerm.c;
                    tag = true;
                    break;
                }
            }
            // 如果结果中没有相同指数的项，则添加新项
            if (!tag && newTerm.c != 0)
                ans.push_back(newTerm);
        }
    }
    for (int i = 0; i < ans.size() - 1; ++i)
        for (int j = 0; j < ans.size() - i - 1; ++j)
            if (ans[j].e < ans[j + 1].e)
                swap(ans[j], ans[j + 1]);
    return ans;
}
int main()
{
    int a, b;
    cin >> a;
    vector<Term> Poly1(a);
    for (int i = 0; i < a; ++i)
        cin >> Poly1[i].c >> Poly1[i].e;
    cin >> b;
    vector<Term> Poly2(b);
    for (int i = 0; i < b; ++i)
        cin >> Poly2[i].c >> Poly2[i].e;
    vector<Term> p = solve(Poly1, Poly2);
    for (const auto &term : p)
        cout << term.c << " " << term.e << " ";
    cout << '\n';
    return 0;
}