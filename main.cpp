#include <iostream>
#include "Calculator.h"

using namespace std;

int main() {
    Calculator calculator("plugins/", " ");
    string expression = "+";
    getline(cin, expression);
    while (!expression.empty()) {
        cout << calculator.calculate(expression) << endl;
        getline(cin, expression);
    }
}
