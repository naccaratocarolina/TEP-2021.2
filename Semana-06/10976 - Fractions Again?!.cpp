#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Dupla {
    public:
        int x,y;
        Dupla(int _x, int _y) : x(_x), y(_y){}
};

void imprime (int k) {
    int min_y = k + 1;
    int max_y = 2 * k;
    int range = max_y - min_y + 1;
    vector <Dupla> entradas;
    entradas.reserve(range);

    for (int i = min_y ; i <= max_y ; ++i) {
        div_t resultado = div(i * k, i - k);
        if(!resultado.rem){
            entradas.emplace_back(Dupla(resultado.quot, i));
        }
    }

    cout << entradas.size() << '\n';
    for(const Dupla &dupla : entradas) {
        cout << "1/" << k << " = 1/" << dupla.x << " + 1/" << dupla.y << '\n'; 
    }
}

int main(int argc, char const *argv[]) {
    int k;
    while(cin >> k){
        imprime(k);
    }
    return 0;
}
