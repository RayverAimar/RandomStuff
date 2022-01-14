#include <iostream>

using namespace std;

void Trim(char* cad) {
    char* auxiliar;
    for (char* q = cad; q < cad + strlen(cad); q++) {
        if (*q == ' ') {
            auxiliar = q;
            while (*auxiliar == ' ') {
                auxiliar++;
            }
            *q = *auxiliar;
            *auxiliar = ' ';
        }
    }
}
bool palindromo(char*cad) {
    Trim(cad);
    for (char* q = cad, *fin = cad + strlen(cad)-1; q < fin; q++, fin--) {
        if (*q != *fin) {
            return false;
        }
    }
    return true;
}

int main()
{
    char cad[] = "amo la paloma", cad2[] = "no es un palindromo";
    bool palindrome = palindromo(cad);
    cout << "amo la paloma --> " << palindromo(cad) << endl;
    cout << "no es un palindromo --> " << palindromo(cad2) << endl;
}