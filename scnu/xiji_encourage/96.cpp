#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ifstream infile("poly.in");
    ofstream outfile("poly.out");

    map<int, int> poly;

    for (int i = 0; i < 2; ++i) {
        int coeff, exp;
        while (infile >> coeff >> exp) {
            poly[exp] += coeff;
            if (infile.peek() == '\n') break;
        }
    }

    vector<pair<int, int>> result(poly.begin(), poly.end());
    sort(result.rbegin(), result.rend());

    for (const auto& term : result) {
        if (term.second != 0) {
            outfile << term.second << " " << term.first << " ";
        }
    }
    outfile << endl;

    infile.close();
    outfile.close();

    return 0;
}