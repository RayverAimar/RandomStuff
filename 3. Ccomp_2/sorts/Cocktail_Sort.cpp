#include <iostream>

using namespace std;

void print(int* Arr, int tam)
{
    for (int *ptr = Arr; ptr < Arr+tam; ptr++)
    {
        cout <<*ptr<<" ";
    }
    cout << endl;
}
void cocktail_sort(int* Arr, int tam) 
{
    bool swapping = true;
    int counter = 0;
    while (swapping) //Si no existe intermcabio, el array está ordenado y se sale del while
    { 
        swapping = false;
        for (int* inicio = Arr+counter; inicio < Arr + tam - 1; inicio++) //Se hace uso de Arr+contador para iniciar "inicio" puesto que en cada bucle while existirá un máximo y un mínimo en el array y ya no se necesitará empezar el bucle for desde el inicio del array
        { 
            if (*inicio > *(inicio + 1)) 
            { 
                swapping = true; //Si existe al menos un intercambio, la variable swapping cambia a true, permitiendo saber que aun no está ordenado el array
                swap(*inicio, *(inicio + 1));
            }
        }
        if (!swapping) //Si no existe intercambios, significa que el array ya ha sido ordenado al igual que en la linea 17
        {  
            break;
        }
        swapping = false;
        for (int* fin = Arr + tam - (1 + counter); fin > Arr ; fin--) { //Se inicia "fin" en Arr+tam-(1 + contador) por la razón ya expliacada en la linea 20
            if (*fin < * (fin-1)) 
            {
                swapping = true;
                swap(*fin, *(fin- 1));
            }
        }
        counter++; //El contador permite saber desde qué posición dentro del array empezará a iterar cada bucle for
    }
}

int main()
{
    int Arr[] = { 16,26,19,21,52,91,1210,2,16,4,67,11,85,12,17 };
    cout << "Array -> ";
    print(Arr, 15);
    cocktail_sort(Arr, 15);
    cout << "Sorted array :-> ";
    print(Arr, 15);
}