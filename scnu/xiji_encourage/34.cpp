#include<bits/stdc++.h>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

void solve(vector<int>& ring, vector<bool>& used, int pos, int N) {
    if (pos == N && isPrime(ring[N - 1] + ring[0])) {
        for (int i = 0; i < N; ++i) {
            cout << ring[i] << (i == N - 1 ? "\n" : " ");
        }
        return;
    }

    for (int i = 2; i <= N; ++i)
        if (!used[i] && isPrime(ring[pos - 1] + i)) {
            ring[pos] = i;
            used[i] = true;
            solve(ring, used, pos + 1, N);
            used[i] = false;
        }
}

int main() {
    int N;
    cin >> N;
    vector<int> ring(N);
    vector<bool> used(N + 1, false);
    ring[0] = 1;
    used[1] = true;
    solve(ring, used, 1, N);
    return 0;
}