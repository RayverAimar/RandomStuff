#include <iostream>

using namespace std;


void swap(int* a, int* b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void print(int* Arr, int tam)
{
    for (int* ptr = Arr; ptr < Arr + tam; ptr++)
    {
        cout << *ptr << " ";
    }
    cout << endl;
}

void split(int* Arr, int tam) {
    int impares = 0;
    for (int* p = Arr; p <= Arr + tam; p++)
    {
        if ((*p % 2) == 0) {
            for (int* q = p; q < Arr + tam - 1; q++) {
                swap(q, q + 1);
            }
        }
    }
    for (int* ptr = Arr; ptr < Arr + tam; ptr++)
    {
        if ((*ptr % 2) == 1) {
            impares++;
        }
    }
    for (int* inicio = Arr + impares; inicio < Arr + tam - 1; inicio++) {
        for (int* ini = Arr + impares; ini < Arr + tam - 1; ini++) {
            if (*ini > * (ini + 1))
            {
                swap(*ini, *(ini + 1));
            }
        }


    }
}

int main()
{
	int Arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    int Arrb[] = { 1,2,3,5,7,8,9,11,13 };
    cout << "Array A" << endl;
    cout << "Ordenado sin separar" << endl;
    print(Arr, 9);
    split(Arr, 9);
    cout << "Ordenado Separado" << endl;
    print(Arr, 9);
    cout << endl;
    cout << "Array B" << endl;
    cout << "Ordenado sin separar" << endl;
    print(Arrb, 9);
    split(Arrb, 9);
    cout << "Ordenado Separado" << endl;
    print(Arrb, 9);

}

