#include <iostream>
#include "matriz2D.h"
using namespace std;

int main()
{
    int funcion, i, j, valor, aux;
    bool salir = false, endwhile = true;
    Matriz matriz, matriz_2;
    matriz.iniciar();
    matriz_2.iniciar();
    cout << "Matrices 1 y 2 inicializadas!" << endl;
    do {
        cout << "\nQue desea realizar?\n\n1. Ingresar valor por posiciones\n2. Sumar matriz 1 y 2\n3. Restar matrices" << endl;
        cout << "4. Obtener el mayor y menor numero de una matriz\n5. Buscar elemento en una matriz\n6. Obtener las veces de repeticion de un valor en una matriz" << endl;
        cout << "7. Reiniciar las dimensiones de una matriz y su contenido\n8. Copiar una matriz hacia otra \n9. Imprimir las 2 matrices" << endl;
        cout << "10. Multiplicar una matriz por un coeficiente \n11. Multiplicar matrices \n12. Transpuesta de una matriz \n0. Salir del programa" << endl;
        cin >> funcion;
        switch (funcion) {
        case 1:
            system("cls");
            cout << "\n1. Ingresar valor en la Matriz 1 " << endl;
            cout << "\n2. Ingresar valor en la Matriz 2 " << endl;
            cin >> valor;
            system("cls");
            if (valor == 1) {
                cout << "\nEscogio la matriz 1!\n" << endl;
                cout << "Ingrese la posicion i: ";
                cin >> i;
                cout << "\nIngrese la posicion j: ";
                cin >> j;
                cout << "\nDigite el valor a ingresar en la matriz: ";
                cin >> aux;
                iniciar_valor(matriz, i, j, aux);
                cout << "\nLa matriz se ha actualizado!\n" << endl;
                matriz.print();
            }
            if (valor == 2) {
                cout << "\nEscogio la matriz 2! \n" << endl;
                cout << "Ingrese la posicion i: ";
                cin >> i;
                cout << "\nIngrese la posicion j: ";
                cin >> j;
                cout << "\nDigite el valor a ingresar en la matriz: ";
                cin >> aux;
                iniciar_valor(matriz_2, i, j, aux);
                cout << "\nLa matriz se ha actualizado!\n" << endl;
                matriz_2.print();
            }
            exit(salir);
            if (salir) { break; }
        case 2:
            system("cls");
            suma_matrices(matriz, matriz_2);
            exit(salir);
            if (salir) { break; }
        case 3:
            system("cls");
            cout << "\n1. Matriz 1 menos Matriz 2 " << endl;
            cout << "\n2. Matriz 2 menos Matriz 1 " << endl;
            cin >> valor;
            if (valor == 1) {
                cout << "Resultado \n" << endl;
                resta_matrices(matriz, matriz_2);
            }
            if (valor == 2) {
                cout << "Resultado: \n" << endl;
                resta_matrices(matriz_2, matriz);
            }
            exit(salir);
            if (salir) { break; }
        case 4: // mayor y menor
            system("cls");
            cout << "Para la matriz 1: " << endl;
            mayor_y_menor(matriz);
            cout << "\nPara la matriz 2: " << endl;
            mayor_y_menor(matriz_2);
            exit(salir);
            if (salir) { break; }

        case 5:
            system("cls");
            cout << "Digite el elemento a buscar" << endl;
            cin >> valor;
            cout << "Para la matriz 1: " << endl;
            buscar_elemento(matriz, valor);
            cout << "\nPara la matriz 2: " << endl;
            buscar_elemento(matriz_2, valor);
            exit(salir);
            if (salir) { break; }
        case 6:
            system("cls");
            cout << "Digite el elemento a buscar" << endl;
            cin >> valor;
            cout << "Para la matriz 1: " << endl;
            valor_repetido(matriz, valor);
            cout << "\nPara la matriz 2: " << endl;
            valor_repetido(matriz_2, valor);
            exit(salir);
            if (salir) { break; }
        case 7:
            system("cls");
            cout << "\n1. Modificar la matriz 1 " << endl;
            cout << "\n2. Modificar la matriz 2 " << endl;
            cin >> valor;
            cout << "\nIngrese la nueva dimension i: ";
            cin >> i;
            cout << "\nIngrese la nueva dimension j: ";
            cin >> j;
            if (valor == 1) {
                reiniciar(matriz, i, j);
                matriz.iniciar();
                cout << "\nMatriz reiniciada con exito!" << endl;

            }
            if (valor == 2) {
                reiniciar(matriz_2, i, j);
                cout << "\nMatriz reiniciada con exito!" << endl;
                matriz_2.iniciar();
            }
            exit(salir);
            if (salir) { break; }
        case 8:
            system("cls");
            cout << "\n1. Copiar la matriz 1 en la matriz 2 " << endl;
            cout << "\n2. Copiar la matriz 2 en la matriz 1 " << endl;
            cin >> valor;
            if (valor == 1) {
                copiar_matriz(matriz, matriz_2);

            }
            if (valor == 2) {
                copiar_matriz(matriz_2, matriz);
            }
            exit(salir);
            if (salir) { break; }
        case 9:
            system("cls");
            cout << "Matriz 1: \n" << endl;
            matriz.print();
            cout << "\nMatriz 2: \n" << endl;
            matriz_2.print();
            exit(salir);
            if (salir) { break; }
        case 10:
            system("cls");
            cout << "\n1. Multiplicar la matriz 1" << endl;
            cout << "\n2. Multiplicar la matriz 2" << endl;
            cin >> valor;
            cout << "Por que valor desea multiplicar la matriz?" << endl;
            cin >> aux;
            if (valor == 1) {
                coeficiente(matriz, aux);
                matriz.print();
            }
            if (valor == 2) {
                coeficiente(matriz_2, aux);
                matriz_2.print();
            }
            exit(salir);
            if (salir) { break; }
        case 11:
            system("cls");
            cout << "\n1. Matriz 1  por Matriz 2 " << endl;
            cout << "\n2. Matriz 2 por Matriz 1 " << endl;
            cin >> valor;
            if (valor == 1) {
                multiplicacion(matriz, matriz_2);
            }
            if (valor == 2) {
                multiplicacion(matriz_2, matriz);
            }
            exit(salir);
            if (salir) { break; }
        case 12:
            system("cls");
            cout << "\nTranspuesta de la matriz 1 " << endl;
            cout << "\nTranspuesta de la matriz 2" << endl;
            cin >> valor;
            if (valor == 1) {
                transpuesta(matriz);
            }
            if (valor == 2) {
                transpuesta(matriz_2);
            }
            exit(salir);
            if (salir) { break; }
        case 0:
            endwhile = false;
        default:system("cls");
        }
    } while (endwhile);
    return 0;
}
