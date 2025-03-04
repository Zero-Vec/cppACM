#include <bits/stdc++.h>

using namespace std;

inline void move(ifstream &fileTemp, stringstream &funcTemp)
{
    fileTemp.seekg(-(int)funcTemp.str().length(), ios::cur);
    funcTemp.clear();
    funcTemp.str("");
}

bool _semicolon(ifstream &code, string &token);
bool _comma(ifstream &code, string &token);
bool _left_brace(ifstream &code, string &token);
bool _right_brace(ifstream &code, string &token);
bool _left_bracket(ifstream &code, string &token);
bool _right_bracket(ifstream &code, string &token);
bool _mulop(ifstream &code, string &token);
bool _comparison_op(ifstream &code, string &token);
bool _addop(ifstream &code, string &token);
bool _voluation(ifstream &code, string &token);
bool _keywords(ifstream &code, string &token);
bool _while(ifstream &code, string &token);
bool _if(ifstream &code, string &token);
bool _then(ifstream &code, string &token);
bool _else(ifstream &code, string &token);
bool _end(ifstream &code, string &token);
bool _repeat(ifstream &code, string &token);
bool _until(ifstream &code, string &token);
bool _read(ifstream &code, string &token);
bool _write(ifstream &code, string &token);
bool identifier(ifstream &code, string &token);
bool number(ifstream &code, string &token);
bool letter(ifstream &code, string &token);
bool digit(ifstream &code, string &token);
bool _semicolon(ifstream &code, string &token)
{
    int state = 2;
    char ch;
    stringstream temp;
    set<int> endState = {
        1,
    };
    while (code.get(ch))
    {
        if (ch == '\r')
        {
            continue;
        }
        switch (state)
        {
        case 1:
            code.seekg(-1, ios::cur);
            token = temp.str();
            return true;
            temp << ch;
            break;
        case 2:
            if (ch == ';')
            {
                state = 1;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        default:
            temp << ch;
            move(code, temp);
            return false;
            break;
        }
    }
    if (endState.count(state) > 0)
    {
        token = temp.str();
        return true;
    }
    else
    {
        move(code, temp);
        return false;
    }
}

bool _comma(ifstream &code, string &token)
{
    int state = 2;
    char ch;
    stringstream temp;
    set<int> endState = {
        1,
    };
    while (code.get(ch))
    {
        if (ch == '\r')
        {
            continue;
        }
        switch (state)
        {
        case 1:
            code.seekg(-1, ios::cur);
            token = temp.str();
            return true;
            temp << ch;
            break;
        case 2:
            if (ch == ',')
            {
                state = 1;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        default:
            temp << ch;
            move(code, temp);
            return false;
            break;
        }
    }
    if (endState.count(state) > 0)
    {
        token = temp.str();
        return true;
    }
    else
    {
        move(code, temp);
        return false;
    }
}

bool _left_brace(ifstream &code, string &token)
{
    int state = 2;
    char ch;
    stringstream temp;
    set<int> endState = {
        1,
    };
    while (code.get(ch))
    {
        if (ch == '\r')
        {
            continue;
        }
        switch (state)
        {
        case 1:
            code.seekg(-1, ios::cur);
            token = temp.str();
            return true;
            temp << ch;
            break;
        case 2:
            if (ch == '{')
            {
                state = 1;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        default:
            temp << ch;
            move(code, temp);
            return false;
            break;
        }
    }
    if (endState.count(state) > 0)
    {
        token = temp.str();
        return true;
    }
    else
    {
        move(code, temp);
        return false;
    }
}

bool _right_brace(ifstream &code, string &token)
{
    int state = 2;
    char ch;
    stringstream temp;
    set<int> endState = {
        1,
    };
    while (code.get(ch))
    {
        if (ch == '\r')
        {
            continue;
        }
        switch (state)
        {
        case 1:
            code.seekg(-1, ios::cur);
            token = temp.str();
            return true;
            temp << ch;
            break;
        case 2:
            if (ch == '}')
            {
                state = 1;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        default:
            temp << ch;
            move(code, temp);
            return false;
            break;
        }
    }
    if (endState.count(state) > 0)
    {
        token = temp.str();
        return true;
    }
    else
    {
        move(code, temp);
        return false;
    }
}

bool _left_bracket(ifstream &code, string &token)
{
    int state = 2;
    char ch;
    stringstream temp;
    set<int> endState = {
        1,
    };
    while (code.get(ch))
    {
        if (ch == '\r')
        {
            continue;
        }
        switch (state)
        {
        case 1:
            code.seekg(-1, ios::cur);
            token = temp.str();
            return true;
            temp << ch;
            break;
        case 2:
            if (ch == '(')
            {
                state = 1;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        default:
            temp << ch;
            move(code, temp);
            return false;
            break;
        }
    }
    if (endState.count(state) > 0)
    {
        token = temp.str();
        return true;
    }
    else
    {
        move(code, temp);
        return false;
    }
}

bool _right_bracket(ifstream &code, string &token)
{
    int state = 2;
    char ch;
    stringstream temp;
    set<int> endState = {
        1,
    };
    while (code.get(ch))
    {
        if (ch == '\r')
        {
            continue;
        }
        switch (state)
        {
        case 1:
            code.seekg(-1, ios::cur);
            token = temp.str();
            return true;
            temp << ch;
            break;
        case 2:
            if (ch == ')')
            {
                state = 1;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        default:
            temp << ch;
            move(code, temp);
            return false;
            break;
        }
    }
    if (endState.count(state) > 0)
    {
        token = temp.str();
        return true;
    }
    else
    {
        move(code, temp);
        return false;
    }
}

bool _mulop(ifstream &code, string &token)
{
    int state = 2;
    char ch;
    stringstream temp;
    set<int> endState = {
        1,
    };
    while (code.get(ch))
    {
        if (ch == '\r')
        {
            continue;
        }
        switch (state)
        {
        case 1:
            code.seekg(-1, ios::cur);
            token = temp.str();
            return true;
            temp << ch;
            break;
        case 2:
            if (ch == '%')
            {
                state = 1;
            }
            else if (ch == '*')
            {
                state = 1;
            }
            else if (ch == '/')
            {
                state = 1;
            }
            else if (ch == '^')
            {
                state = 1;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        default:
            temp << ch;
            move(code, temp);
            return false;
            break;
        }
    }
    if (endState.count(state) > 0)
    {
        token = temp.str();
        return true;
    }
    else
    {
        move(code, temp);
        return false;
    }
}

bool _comparison_op(ifstream &code, string &token)
{
    int state = 4;
    char ch;
    stringstream temp;
    set<int> endState = {
        1,
        2,
        3,
    };
    while (code.get(ch))
    {
        if (ch == '\r')
        {
            continue;
        }
        switch (state)
        {
        case 1:
            code.seekg(-1, ios::cur);
            token = temp.str();
            return true;
            temp << ch;
            break;
        case 2:
            if (ch == '=')
            {
                state = 1;
            }
            else if (ch == '>')
            {
                state = 1;
            }
            else
            {
                code.seekg(-1, ios::cur);
                token = temp.str();
                return true;
            }
            temp << ch;
            break;
        case 3:
            if (ch == '=')
            {
                state = 1;
            }
            else
            {
                code.seekg(-1, ios::cur);
                token = temp.str();
                return true;
            }
            temp << ch;
            break;
        case 4:
            if (ch == '<')
            {
                state = 2;
            }
            else if (ch == '=')
            {
                state = 1;
            }
            else if (ch == '>')
            {
                state = 3;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        default:
            temp << ch;
            move(code, temp);
            return false;
            break;
        }
    }
    if (endState.count(state) > 0)
    {
        token = temp.str();
        return true;
    }
    else
    {
        move(code, temp);
        return false;
    }
}

bool _addop(ifstream &code, string &token)
{
    int state = 2;
    char ch;
    stringstream temp;
    set<int> endState = {
        1,
    };
    while (code.get(ch))
    {
        if (ch == '\r')
        {
            continue;
        }
        switch (state)
        {
        case 1:
            code.seekg(-1, ios::cur);
            token = temp.str();
            return true;
            temp << ch;
            break;
        case 2:
            if (ch == '+')
            {
                state = 1;
            }
            else if (ch == '-')
            {
                state = 1;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        default:
            temp << ch;
            move(code, temp);
            return false;
            break;
        }
    }
    if (endState.count(state) > 0)
    {
        token = temp.str();
        return true;
    }
    else
    {
        move(code, temp);
        return false;
    }
}

bool _voluation(ifstream &code, string &token)
{
    int state = 3;
    char ch;
    stringstream temp;
    set<int> endState = {
        1,
    };
    while (code.get(ch))
    {
        if (ch == '\r')
        {
            continue;
        }
        switch (state)
        {
        case 1:
            code.seekg(-1, ios::cur);
            token = temp.str();
            return true;
            temp << ch;
            break;
        case 2:
            if (ch == '=')
            {
                state = 1;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 3:
            if (ch == ':')
            {
                state = 2;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        default:
            temp << ch;
            move(code, temp);
            return false;
            break;
        }
    }
    if (endState.count(state) > 0)
    {
        token = temp.str();
        return true;
    }
    else
    {
        move(code, temp);
        return false;
    }
}

bool _keywords(ifstream &code, string &token)
{
    int state = 2;
    char ch;
    stringstream temp;
    set<int> endState = {
        1,
    };
    while (code.get(ch))
    {
        if (ch == '\r')
        {
            continue;
        }
        switch (state)
        {
        case 1:
            code.seekg(-1, ios::cur);
            token = temp.str();
            return true;
            temp << ch;
            break;
        case 2:
            if (_else(code, token))
            {
                state = 1;
            }
            else if (_end(code, token))
            {
                state = 1;
            }
            else if (_if(code, token))
            {
                state = 1;
            }
            else if (_read(code, token))
            {
                state = 1;
            }
            else if (_repeat(code, token))
            {
                state = 1;
            }
            else if (_then(code, token))
            {
                state = 1;
            }
            else if (_until(code, token))
            {
                state = 1;
            }
            else if (_while(code, token))
            {
                state = 1;
            }
            else if (_write(code, token))
            {
                state = 1;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        default:
            temp << ch;
            move(code, temp);
            return false;
            break;
        }
    }
    if (endState.count(state) > 0)
    {
        token = temp.str();
        return true;
    }
    else
    {
        move(code, temp);
        return false;
    }
}

bool _while(ifstream &code, string &token)
{
    int state = 2;
    char ch;
    stringstream temp;
    set<int> endState = {
        1,
    };
    while (code.get(ch))
    {
        if (ch == '\r')
        {
            continue;
        }
        switch (state)
        {
        case 1:
            code.seekg(-1, ios::cur);
            token = temp.str();
            return true;
            temp << ch;
            break;
        case 2:
            if (ch == 'w')
            {
                state = 5;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 3:
            if (ch == 'l')
            {
                state = 6;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 4:
            if (ch == 'i')
            {
                state = 3;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 5:
            if (ch == 'h')
            {
                state = 4;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 6:
            if (ch == 'e')
            {
                state = 1;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        default:
            temp << ch;
            move(code, temp);
            return false;
            break;
        }
    }
    if (endState.count(state) > 0)
    {
        token = temp.str();
        return true;
    }
    else
    {
        move(code, temp);
        return false;
    }
}

bool _if(ifstream &code, string &token)
{
    int state = 2;
    char ch;
    stringstream temp;
    set<int> endState = {
        1,
    };
    while (code.get(ch))
    {
        if (ch == '\r')
        {
            continue;
        }
        switch (state)
        {
        case 1:
            code.seekg(-1, ios::cur);
            token = temp.str();
            return true;
            temp << ch;
            break;
        case 2:
            if (ch == 'i')
            {
                state = 3;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 3:
            if (ch == 'f')
            {
                state = 1;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        default:
            temp << ch;
            move(code, temp);
            return false;
            break;
        }
    }
    if (endState.count(state) > 0)
    {
        token = temp.str();
        return true;
    }
    else
    {
        move(code, temp);
        return false;
    }
}

bool _then(ifstream &code, string &token)
{
    int state = 2;
    char ch;
    stringstream temp;
    set<int> endState = {
        1,
    };
    while (code.get(ch))
    {
        if (ch == '\r')
        {
            continue;
        }
        switch (state)
        {
        case 1:
            code.seekg(-1, ios::cur);
            token = temp.str();
            return true;
            temp << ch;
            break;
        case 2:
            if (ch == 't')
            {
                state = 4;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 3:
            if (ch == 'n')
            {
                state = 1;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 4:
            if (ch == 'h')
            {
                state = 5;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 5:
            if (ch == 'e')
            {
                state = 3;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        default:
            temp << ch;
            move(code, temp);
            return false;
            break;
        }
    }
    if (endState.count(state) > 0)
    {
        token = temp.str();
        return true;
    }
    else
    {
        move(code, temp);
        return false;
    }
}

bool _else(ifstream &code, string &token)
{
    int state = 4;
    char ch;
    stringstream temp;
    set<int> endState = {
        1,
    };
    while (code.get(ch))
    {
        if (ch == '\r')
        {
            continue;
        }
        switch (state)
        {
        case 1:
            code.seekg(-1, ios::cur);
            token = temp.str();
            return true;
            temp << ch;
            break;
        case 2:
            if (ch == 's')
            {
                state = 5;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 3:
            if (ch == 'l')
            {
                state = 2;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 4:
            if (ch == 'e')
            {
                state = 3;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 5:
            if (ch == 'e')
            {
                state = 1;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        default:
            temp << ch;
            move(code, temp);
            return false;
            break;
        }
    }
    if (endState.count(state) > 0)
    {
        token = temp.str();
        return true;
    }
    else
    {
        move(code, temp);
        return false;
    }
}

bool _end(ifstream &code, string &token)
{
    int state = 3;
    char ch;
    stringstream temp;
    set<int> endState = {
        1,
    };
    while (code.get(ch))
    {
        if (ch == '\r')
        {
            continue;
        }
        switch (state)
        {
        case 1:
            code.seekg(-1, ios::cur);
            token = temp.str();
            return true;
            temp << ch;
            break;
        case 2:
            if (ch == 'n')
            {
                state = 4;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 3:
            if (ch == 'e')
            {
                state = 2;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 4:
            if (ch == 'd')
            {
                state = 1;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        default:
            temp << ch;
            move(code, temp);
            return false;
            break;
        }
    }
    if (endState.count(state) > 0)
    {
        token = temp.str();
        return true;
    }
    else
    {
        move(code, temp);
        return false;
    }
}

bool _repeat(ifstream &code, string &token)
{
    int state = 3;
    char ch;
    stringstream temp;
    set<int> endState = {
        1,
    };
    while (code.get(ch))
    {
        if (ch == '\r')
        {
            continue;
        }
        switch (state)
        {
        case 1:
            code.seekg(-1, ios::cur);
            token = temp.str();
            return true;
            temp << ch;
            break;
        case 2:
            if (ch == 't')
            {
                state = 1;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 3:
            if (ch == 'r')
            {
                state = 5;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 4:
            if (ch == 'p')
            {
                state = 6;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 5:
            if (ch == 'e')
            {
                state = 4;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 6:
            if (ch == 'e')
            {
                state = 7;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 7:
            if (ch == 'a')
            {
                state = 2;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        default:
            temp << ch;
            move(code, temp);
            return false;
            break;
        }
    }
    if (endState.count(state) > 0)
    {
        token = temp.str();
        return true;
    }
    else
    {
        move(code, temp);
        return false;
    }
}

bool _until(ifstream &code, string &token)
{
    int state = 2;
    char ch;
    stringstream temp;
    set<int> endState = {
        1,
    };
    while (code.get(ch))
    {
        if (ch == '\r')
        {
            continue;
        }
        switch (state)
        {
        case 1:
            code.seekg(-1, ios::cur);
            token = temp.str();
            return true;
            temp << ch;
            break;
        case 2:
            if (ch == 'u')
            {
                state = 4;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 3:
            if (ch == 't')
            {
                state = 6;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 4:
            if (ch == 'n')
            {
                state = 3;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 5:
            if (ch == 'l')
            {
                state = 1;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 6:
            if (ch == 'i')
            {
                state = 5;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        default:
            temp << ch;
            move(code, temp);
            return false;
            break;
        }
    }
    if (endState.count(state) > 0)
    {
        token = temp.str();
        return true;
    }
    else
    {
        move(code, temp);
        return false;
    }
}

bool _read(ifstream &code, string &token)
{
    int state = 2;
    char ch;
    stringstream temp;
    set<int> endState = {
        1,
    };
    while (code.get(ch))
    {
        if (ch == '\r')
        {
            continue;
        }
        switch (state)
        {
        case 1:
            code.seekg(-1, ios::cur);
            token = temp.str();
            return true;
            temp << ch;
            break;
        case 2:
            if (ch == 'r')
            {
                state = 3;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 3:
            if (ch == 'e')
            {
                state = 5;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 4:
            if (ch == 'd')
            {
                state = 1;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 5:
            if (ch == 'a')
            {
                state = 4;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        default:
            temp << ch;
            move(code, temp);
            return false;
            break;
        }
    }
    if (endState.count(state) > 0)
    {
        token = temp.str();
        return true;
    }
    else
    {
        move(code, temp);
        return false;
    }
}

bool _write(ifstream &code, string &token)
{
    int state = 2;
    char ch;
    stringstream temp;
    set<int> endState = {
        1,
    };
    while (code.get(ch))
    {
        if (ch == '\r')
        {
            continue;
        }
        switch (state)
        {
        case 1:
            code.seekg(-1, ios::cur);
            token = temp.str();
            return true;
            temp << ch;
            break;
        case 2:
            if (ch == 'w')
            {
                state = 4;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 3:
            if (ch == 't')
            {
                state = 6;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 4:
            if (ch == 'r')
            {
                state = 5;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 5:
            if (ch == 'i')
            {
                state = 3;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 6:
            if (ch == 'e')
            {
                state = 1;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        default:
            temp << ch;
            move(code, temp);
            return false;
            break;
        }
    }
    if (endState.count(state) > 0)
    {
        token = temp.str();
        return true;
    }
    else
    {
        move(code, temp);
        return false;
    }
}

bool identifier(ifstream &code, string &token)
{
    int state = 1;
    char ch;
    stringstream temp;
    set<int> endState = {
        2,
    };
    while (code.get(ch))
    {
        if (ch == '\r')
        {
            continue;
        }
        switch (state)
        {
        case 1:
            if (ch == '_')
            {
                state = 2;
            }
            else if (isalpha(ch))
            {
                state = 2;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 2:
            if (ch == '_')
            {
                state = 2;
            }
            else if (isdigit(ch))
            {
                state = 2;
            }
            else if (isalpha(ch))
            {
                state = 2;
            }
            else
            {
                code.seekg(-1, ios::cur);
                token = temp.str();
                return true;
            }
            temp << ch;
            break;
        default:
            temp << ch;
            move(code, temp);
            return false;
            break;
        }
    }
    if (endState.count(state) > 0)
    {
        token = temp.str();
        return true;
    }
    else
    {
        move(code, temp);
        return false;
    }
}

bool number(ifstream &code, string &token)
{
    int state = 1;
    char ch;
    stringstream temp;
    set<int> endState = {
        2,
    };
    while (code.get(ch))
    {
        if (ch == '\r')
        {
            continue;
        }
        switch (state)
        {
        case 1:
            if (isdigit(ch))
            {
                state = 2;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        case 2:
            if (isdigit(ch))
            {
                state = 2;
            }
            else
            {
                code.seekg(-1, ios::cur);
                token = temp.str();
                return true;
            }
            temp << ch;
            break;
        default:
            temp << ch;
            move(code, temp);
            return false;
            break;
        }
    }
    if (endState.count(state) > 0)
    {
        token = temp.str();
        return true;
    }
    else
    {
        move(code, temp);
        return false;
    }
}

bool letter(ifstream &code, string &token)
{
    int state = 2;
    char ch;
    stringstream temp;
    set<int> endState = {
        1,
    };
    while (code.get(ch))
    {
        if (ch == '\r')
        {
            continue;
        }
        switch (state)
        {
        case 1:
            code.seekg(-1, ios::cur);
            token = temp.str();
            return true;
            temp << ch;
            break;
        case 2:
            if (ch == 'A')
            {
                state = 1;
            }
            else if (ch == 'B')
            {
                state = 1;
            }
            else if (ch == 'C')
            {
                state = 1;
            }
            else if (ch == 'D')
            {
                state = 1;
            }
            else if (ch == 'E')
            {
                state = 1;
            }
            else if (ch == 'F')
            {
                state = 1;
            }
            else if (ch == 'G')
            {
                state = 1;
            }
            else if (ch == 'H')
            {
                state = 1;
            }
            else if (ch == 'I')
            {
                state = 1;
            }
            else if (ch == 'J')
            {
                state = 1;
            }
            else if (ch == 'K')
            {
                state = 1;
            }
            else if (ch == 'L')
            {
                state = 1;
            }
            else if (ch == 'M')
            {
                state = 1;
            }
            else if (ch == 'N')
            {
                state = 1;
            }
            else if (ch == 'O')
            {
                state = 1;
            }
            else if (ch == 'P')
            {
                state = 1;
            }
            else if (ch == 'Q')
            {
                state = 1;
            }
            else if (ch == 'R')
            {
                state = 1;
            }
            else if (ch == 'S')
            {
                state = 1;
            }
            else if (ch == 'T')
            {
                state = 1;
            }
            else if (ch == 'U')
            {
                state = 1;
            }
            else if (ch == 'V')
            {
                state = 1;
            }
            else if (ch == 'W')
            {
                state = 1;
            }
            else if (ch == 'X')
            {
                state = 1;
            }
            else if (ch == 'Y')
            {
                state = 1;
            }
            else if (ch == 'Z')
            {
                state = 1;
            }
            else if (ch == 'a')
            {
                state = 1;
            }
            else if (ch == 'b')
            {
                state = 1;
            }
            else if (ch == 'c')
            {
                state = 1;
            }
            else if (ch == 'd')
            {
                state = 1;
            }
            else if (ch == 'e')
            {
                state = 1;
            }
            else if (ch == 'f')
            {
                state = 1;
            }
            else if (ch == 'g')
            {
                state = 1;
            }
            else if (ch == 'h')
            {
                state = 1;
            }
            else if (ch == 'i')
            {
                state = 1;
            }
            else if (ch == 'j')
            {
                state = 1;
            }
            else if (ch == 'k')
            {
                state = 1;
            }
            else if (ch == 'l')
            {
                state = 1;
            }
            else if (ch == 'm')
            {
                state = 1;
            }
            else if (ch == 'n')
            {
                state = 1;
            }
            else if (ch == 'o')
            {
                state = 1;
            }
            else if (ch == 'p')
            {
                state = 1;
            }
            else if (ch == 'q')
            {
                state = 1;
            }
            else if (ch == 'r')
            {
                state = 1;
            }
            else if (ch == 's')
            {
                state = 1;
            }
            else if (ch == 't')
            {
                state = 1;
            }
            else if (ch == 'u')
            {
                state = 1;
            }
            else if (ch == 'v')
            {
                state = 1;
            }
            else if (ch == 'w')
            {
                state = 1;
            }
            else if (ch == 'x')
            {
                state = 1;
            }
            else if (ch == 'y')
            {
                state = 1;
            }
            else if (ch == 'z')
            {
                state = 1;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        default:
            temp << ch;
            move(code, temp);
            return false;
            break;
        }
    }
    if (endState.count(state) > 0)
    {
        token = temp.str();
        return true;
    }
    else
    {
        move(code, temp);
        return false;
    }
}

bool digit(ifstream &code, string &token)
{
    int state = 2;
    char ch;
    stringstream temp;
    set<int> endState = {
        1,
    };
    while (code.get(ch))
    {
        if (ch == '\r')
        {
            continue;
        }
        switch (state)
        {
        case 1:
            code.seekg(-1, ios::cur);
            token = temp.str();
            return true;
            temp << ch;
            break;
        case 2:
            if (ch == '0')
            {
                state = 1;
            }
            else if (ch == '1')
            {
                state = 1;
            }
            else if (ch == '2')
            {
                state = 1;
            }
            else if (ch == '3')
            {
                state = 1;
            }
            else if (ch == '4')
            {
                state = 1;
            }
            else if (ch == '5')
            {
                state = 1;
            }
            else if (ch == '6')
            {
                state = 1;
            }
            else if (ch == '7')
            {
                state = 1;
            }
            else if (ch == '8')
            {
                state = 1;
            }
            else if (ch == '9')
            {
                state = 1;
            }
            else
            {
                temp << ch;
                move(code, temp);
                return false;
            }
            temp << ch;
            break;
        default:
            temp << ch;
            move(code, temp);
            return false;
            break;
        }
    }
    if (endState.count(state) > 0)
    {
        token = temp.str();
        return true;
    }
    else
    {
        move(code, temp);
        return false;
    }
}

int main()
{
    ifstream ifs("sample.tny", ios::in | ios::binary);
    ofstream ofs("sample.lex", ios::out | ios::binary);
    string token;
    int line = 1;

    while (ifs.peek() != EOF)
    {
        if (ifs.peek() == ' ' || ifs.peek() == '\n')
        {
            ifs.get();
            continue;
        }
        else if (ifs.peek() == '\r')
        {
            ifs.get();
            line++;
            continue;
        }
        if (_semicolon(ifs, token))
        {
            ofs << token << " -> _semicolon" << '\n';
        }
        else if (_comma(ifs, token))
        {
            ofs << token << " -> _comma" << '\n';
        }
        else if (_left_brace(ifs, token))
        {
            ofs << token << " -> _left_brace" << '\n';
        }
        else if (_right_brace(ifs, token))
        {
            ofs << token << " -> _right_brace" << '\n';
        }
        else if (_left_bracket(ifs, token))
        {
            ofs << token << " -> _left_bracket" << '\n';
        }
        else if (_right_bracket(ifs, token))
        {
            ofs << token << " -> _right_bracket" << '\n';
        }
        else if (_mulop(ifs, token))
        {
            ofs << token << " -> _mulop" << '\n';
        }
        else if (_comparison_op(ifs, token))
        {
            ofs << token << " -> _comparison_op" << '\n';
        }
        else if (_addop(ifs, token))
        {
            ofs << token << " -> _addop" << '\n';
        }
        else if (_voluation(ifs, token))
        {
            ofs << token << " -> _voluation" << '\n';
        }
        else if (_keywords(ifs, token))
        {
            ofs << token << " -> _keywords" << '\n';
        }
        else if (_while(ifs, token))
        {
            ofs << token << " -> _while" << '\n';
        }
        else if (_if(ifs, token))
        {
            ofs << token << " -> _if" << '\n';
        }
        else if (_then(ifs, token))
        {
            ofs << token << " -> _then" << '\n';
        }
        else if (_else(ifs, token))
        {
            ofs << token << " -> _else" << '\n';
        }
        else if (_end(ifs, token))
        {
            ofs << token << " -> _end" << '\n';
        }
        else if (_repeat(ifs, token))
        {
            ofs << token << " -> _repeat" << '\n';
        }
        else if (_until(ifs, token))
        {
            ofs << token << " -> _until" << '\n';
        }
        else if (_read(ifs, token))
        {
            ofs << token << " -> _read" << '\n';
        }
        else if (_write(ifs, token))
        {
            ofs << token << " -> _write" << '\n';
        }
        else if (identifier(ifs, token))
        {
            ofs << token << " -> identifier" << '\n';
        }
        else if (number(ifs, token))
        {
            ofs << token << " -> number" << '\n';
        }
        else if (letter(ifs, token))
        {
            ofs << token << " -> letter" << '\n';
        }
        else if (digit(ifs, token))
        {
            ofs << token << " -> digit" << '\n';
        }
        else
        {
            string errorText;
            while (ifs.peek() != ' ' && ifs.peek() != '\n' && ifs.peek() != '\r')
            {
                errorText += char(ifs.get());
            }
            ofs << "error at Line " << line << " near: " << errorText << '\n';
        }
    }
    ifs.close();
    ofs.close();
}
