#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void solve(const string &key, const string &in, const string &out)
{
    ifstream inputFile(in);
    ofstream outputFile(out);
    int key_id = 0;
    char c;
    while (inputFile.get(c))
    {
        if (!key.empty())
        {
            c ^= key[key_id];
            key_id = (key_id + 1) % key.length();
        }
        outputFile.put(c);
    }
    inputFile.close();
    outputFile.close();
}

int main()
{
    string key;
    getline(cin, key);
    solve(key, "1txt", "2txt");
    return 0;
}