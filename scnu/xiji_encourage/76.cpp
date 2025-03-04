#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> ReadFile(string file)
{
    ifstream fin;
    fin.open(file);
    if (!fin.is_open())
    {
        exit(100);
    }
    vector<string> word;
    while (!fin.eof())
    {
        char str[100];
        fin.getline(str, '\r\n');
        word.push_back(str);
    }
    fin.close();
    return word;
}

void WriteFile(string file, vector<string> word)
{
    ofstream fout;
    fout.open(file);
    if (!fout.is_open())
    {
        exit(100);
    }

    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] != "")
        {
            fout << i + 1 << ":" << word[i];
        }
    }
    fout.close();
}

void SolveString(string str, int tab[])
{
    for (int i = 0; i < str.length(); i++)
    {
        switch (str[i])
        {
        case '^':
            tab[0] = 1;
            break;
        case '*':
            tab[1] = i;
            break;
        case '[':
            tab[2] = i;
            break;
        case ']':
            tab[3] = i;
            break;
        }
    }
}

char tolower(char ch)
{
    if (ch <= 'Z' && ch >= 'A')
    {
        return ch + 32;
    }
    else
    {
        return ch;
    }
}

vector<string> KMP(vector<string> word, string str)
{
    int tab[4];
    memset(tab, -1, 4 * sizeof(int));
    // tab[0]代表"^",[1]"*",[2][3]“[]”在str中开始和结束处
    SolveString(str, tab);
    vector<string> result;
    for (int i = 0; i < word.size(); i++)
    {
        int n = word[i].length();
        int w = 0, s = 0; // w代表主串位置，s代表模式串位置
        string str1 = "";
        string temp = "";
        while (w < word[i].length())
        {

            if (tolower(word[i][w]) == tolower(str[s]))
            {
                temp += word[i][w];
                w++;
                s++;
            }
            else if (s == tab[1])
            { // 遇到*
                s++;
                char c = tolower(str[s]);
                while (w < word[i].length() && tolower(word[i][w]) != c)
                {
                    temp += word[i][w];
                    w++;
                }
                if (tolower(word[i][w]) == c)
                {
                    temp += word[i][w];
                    s++;
                    w++;
                }
                else
                {
                    temp = "";
                    s++;
                }
                if (w == word[i].length() - 1)
                { // 如果到一行结尾还是没有找到
                    break;
                }
            }
            else if (s == tab[2])
            { // 遇到[]
                if (tab[0] == 1)
                { //[]中存在“^”
                    for (int s1 = tab[2] + 2; s1 < tab[3]; s1++)
                    { // 读取括号中的内容
                        if (tolower(word[i][w]) == tolower(str[s1]))
                        { // 未匹配成功

                            w = w - temp.size() + 1;
                            temp = "";
                            s = 0;
                            break;
                        }
                        else if (s1 == tab[3] - 1)
                        {
                            temp += word[i][w]; // 匹配成功
                            s = tab[3] + 1;
                            w++;
                        }
                    } // for
                }
                else
                { // 没有“^”
                    for (int s1 = tab[2] + 1; s1 < tab[3]; s1++)
                    {
                        if (tolower(word[i][w]) == tolower(str[s1]))
                        {
                            temp += word[i][w];
                            s = tab[3] + 1;
                            w++;
                            break;
                        }
                        else if (s1 == tab[3] - 1)
                        { // 未匹配成功
                            w = w - temp.length() + 1;
                            temp = "";
                            s = 0;
                        }
                    } // for

                } // else
            } // elif
            else
            {
                w = w - temp.length() + 1;
                temp = "";
                s = 0;
            }
            if (s == str.length() && temp != "")
            {
                w = w - temp.length() + 1;
                s = 0;
                str1 += temp + ",";
                temp = "";
            }
        }

        if (str1 != "")
        {
            str1[str1.length() - 1] = '\n';
        }
        result.push_back(str1);
    }
    return result;
}

int main()
{
    string str;
    cin >> str;
    vector<string> word = ReadFile("string.in");
    word = KMP(word, str);
    WriteFile("string.out", word);
}
