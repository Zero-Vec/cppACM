#include <iostream>
#include <vector>
int main()
{
    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> index(N + 1);
    std::vector<int> balls(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        index[i] = i;
        balls[i] = i;
    }
    for (int i = 0; i < Q; ++i)
    {
        int x;
        std::cin >> x;
        int pos = index[x];
        int newPos;
        if (pos == N)
        { 
            newPos = pos - 1;
        }
        else
        {
            newPos = pos + 1;
        }
        std::swap(balls[pos], balls[newPos]);
        index[balls[pos]] = pos;
        index[balls[newPos]] = newPos;
    }

    for (int i = 1; i <= N; ++i)
    {
        std::cout << balls[i] << " \n"[i == N];
    }
    return 0;
}