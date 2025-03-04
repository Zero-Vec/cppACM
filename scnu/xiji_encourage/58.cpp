#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string w2m(const string &word, const map<char, string> &c2m){
    string s = "";
    for(auto ch :word)
        s += c2m.at(ch);
    return s;
}

void solve(){
    ifstream morse_in;
    ofstream morse_out;
    morse_in.open("morse.in");
    morse_out.open("morse.out");
    map<char, string> c2m;
    char ch;
    string mos1;
    morse_in >> ch;
    while(ch != '*'){
        morse_in >> mos1;
        c2m[ch] = mos1;
        morse_in >> ch;
    }
    map<string,string> m2w;
    vector<string> exmos;
    set<string> eximos;
    set<string> cotmos;
    string w;
    morse_in >> w;
    while(w != "*"){
        string ms = w2m(w, c2m);
        if(!eximos.count(ms)){
            eximos.insert(ms);
            exmos.push_back(ms);
            m2w.insert({ms, w});
        }
        else{
            if(w.length() < m2w[ms].length())
                m2w[ms] = w;
            cotmos.insert(ms);
        }
        morse_in >> w;
    }

    string m;
    morse_in >> m;
    while(m != "*"){
        if(eximos.count(m)){
            if(cotmos.count(m))
                morse_out << m2w[m] << "!" << '\n';
            else
                morse_out << m2w[m] << '\n';
        }
        else{
            size_t best_siz = 0;
            string best_mos = "NO BEST STRING!";
            for(auto exm:exmos){
                size_t exm_len = exm.length();
                size_t m_len = m.length();
                size_t max_len = min(exm_len, m_len);
                size_t match_len;
                for (match_len = 1;match_len <= max_len;match_len++)
                    if(exm[match_len - 1] != m[match_len - 1])
                        break;
                if(match_len > best_siz){
                    best_siz = match_len;
                    best_mos = exm;
                }
            }
            morse_out << m2w[best_mos] << "?" << '\n';
        }
        morse_in >> m;
    }
    morse_in.close();
    morse_out.close();
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}