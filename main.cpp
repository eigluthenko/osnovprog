#include <iostream>
#include <cmath>
#include <limits>

using namespace std;
double getNumber() {
    double num;
    while (true) {
        cin >> num;
        if (cin.fail()) {
            cout << "Oshibka vvoda. Vvedite chislo: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return num;
        }
    }
}
int main() {
    char operation;
    do {
        cout << "Vvedite pervoe chislo: ";
        double num1 = getNumber();

        cout << "VVedite operatiion (+, *, ^, -, /): ";
        cin >> operation;

        cout << "Vvedite vtoroe chislo: ";
        double num2 = getNumber();

        switch (operation) {
            case '+':
                cout << "Resultat: " << num1 + num2 << endl;
                break;
            case '*':
                cout << "Resultat: " << num1 * num2 << endl;
                break;
            case '^':
                cout << "Resultat: " << pow(num1, num2) << endl;
                break;
            case '-':
                cout << "Resultat: " << num1 - num2 << endl;
                break;
            case '/':
                if (num2 != 0) {
                    cout << "Resultat: " << num1 / num2 << endl;
                } else {
                    cout << "Oshibka: delenie na 0" << endl;
                }
                break;
            default:
                cout << "Oshibka: Nekorektnaya operation" << endl;
                break;
        }
        std::cout << "Prodolshit? (y/n): ";
        char choice;
        std::cin >> choice ;

        if (choice != 'y' && choice != 'Y') {
            break;
        }
    } while (true);
    return 0;
}