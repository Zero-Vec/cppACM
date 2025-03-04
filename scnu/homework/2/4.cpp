#include <iostream>
using namespace std;
int a[105] = {-1};
int sample[105] = {-1};
int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for (int i = 1; i <= N; i++)
        cin >> sample[i];
    if (sample[1] > sample[2])
    { // HeapSort
        int stepnumber = 0;
        for (int i = 3; i <= N; i++)
        {
            if (sample[1] < sample[i])
            {
                stepnumber = i;
                break;
            }
        }
        int temp = sample[1];
        sample[1] = sample[stepnumber - 1];
        sample[stepnumber - 1] = temp;
        stepnumber -= 2;
        int n = 1, max;
        for (; n * 2 <= stepnumber;)
        {
            if (n * 2 == stepnumber)
                max = stepnumber;
            else
                max = sample[n * 2] < sample[n * 2 + 1] ? n * 2 + 1 : n * 2;
            if (sample[n] < sample[max])
            {
                temp = sample[max];
                sample[max] = sample[n];
                sample[n] = temp;
                n = max;
            }
            else
                break;
        }
        cout << "Heap Sort" << endl
             << sample[1];
        for (int i = 2; i <= N; i++)
            cout << " " << sample[i];
    }
    else
    { // 插入排序
        int needsort = 0, temp;
        bool next = false;
        for (int i = 2; i <= N; i++)
        {
            for (int j = i; j > 1; j--)
            {
                if (a[j] < a[j - 1])
                {
                    temp = a[j];
                    a[j] = a[j - 1];
                    a[j - 1] = temp;
                }
                else
                    break;
            }
            if (next)
            {
                cout << "Insertion Sort" << endl
                     << a[1];
                for (int i = 2; i <= N; i++)
                    cout << " " << a[i];
                system("pause");
                return 0;
            }
            for (int i = 1; i <= N; i++)
            {
                if (sample[i] != a[i])
                {
                    next = false;
                    break;
                }
                next = true;
            }
        }
    }
    return 0;
}
