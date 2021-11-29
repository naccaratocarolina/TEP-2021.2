#include <iostream>
#include <string>

using namespace std;

int calculaTotal(const string &str1, const string &str2) {
    int difGeral = 0;
    int dif = 0;
    int umParaZero = 0, zeroParaUm = 0;
    
    for (int i = 0; i < str1.size(); ++i)
    {
        if (str1[i] != str2[i])
            ++difGeral;
        if (str1[i] == '?' && str2[i] == '1')
            --dif;
        else if (str1[i] == '0' && str2[i] == '1')
        {
            ++zeroParaUm;
            --dif;
        }
        else if (str1[i] == '1' && str2[i] == '0')
        {
            ++umParaZero;
            ++dif;
        }
    }
    
    if (dif > 0)
        return -1;
    
    return difGeral - min(umParaZero, zeroParaUm);
}

int calculaContador(const string &str, char chr) {
    int cont = 0;
    for (int i = 0; i < str.size(); ++i)
        if (str[i] == chr)
            ++cont;
    return cont;
}

int main() {
    string str1, str2;
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        cin >> str1 >> str2;
        
        cout << "Case " << t << ": " << calculaTotal(str1, str2) << '\n';
    }
}
