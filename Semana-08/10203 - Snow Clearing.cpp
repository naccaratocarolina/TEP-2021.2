#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <sstream>
#include <cmath>

using namespace std;

int main (void) {
    int T;
    double soma;
    string s;
    cin >> T;

    while (T--) {
        double x0, y0, x1, y1, x2, y2;
        cin >> x0 >> y0;
        getline(cin, s);

        soma = 0;
        while (getline(cin, s) && s != "") {
            istringstream iss(s);
            iss >> x1 >> y1 >> x2 >> y2;
            double x = x2 - x1, y = y2 - y1;
            soma += 2 * sqrt(x * x + y * y);
        }
        
        double v = 20000.0/60.0;
        double t = soma / v;

        int tmin = rint(t);
        int h = tmin/60, min = (tmin - 60*h);
        printf("%d:%.2d\n", h, min);

        if (T) printf("\n");
    }

    return 0;
}
