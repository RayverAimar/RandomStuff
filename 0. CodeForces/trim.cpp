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
int main()
{
    char cad[] = "CADENA DE       CARACTERES        QUE     NO   TIENE         ESPACIOS";
    cout << cad << endl;
    Trim(cad);
    cout << cad << endl;
}
