#include <iostream>
#include "matriz2D.h"

using namespace std;

Matriz::Matriz() {
    matrix = nullptr;
    filas = 3;
    cols = 4;
    matrix = new int* [filas];
    for (int i = 0; i < filas; i++) {
        matrix[i] = new int[cols];
    }
}
Matriz::~Matriz() {
    for (int i = 0; i < filas; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
void Matriz::iniciar() {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }
}
void Matriz::print() {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void iniciar_valor(Matriz& matrix, int y, int x, int valor) {
    for (int i = 0; i < matrix.filas; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            if (y == i) {
                if (x == j) {
                    matrix.matrix[i][j] = valor;
                }
            }
        }
    }
}
void suma_matrices(Matriz& matrix, Matriz& matrix2) {
    Matriz auxiliar;
    for (int i = 0; i < matrix.filas; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            auxiliar.matrix[i][j] = matrix.matrix[i][j] + matrix2.matrix[i][j];
        }
    }
    auxiliar.print();
}
void resta_matrices(Matriz& matrix, Matriz& matrix2) {
    Matriz auxiliar;
    for (int i = 0; i < matrix.filas; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            auxiliar.matrix[i][j] = matrix.matrix[i][j] - matrix2.matrix[i][j];
        }
    }
    auxiliar.print();
}
void coeficiente(Matriz& matrix, int multiplicador) {
    for (int i = 0; i < matrix.filas; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            matrix.matrix[i][j] = matrix.matrix[i][j] * multiplicador;
        }
    }
}
void mayor_y_menor(Matriz& matrix) {
    int mayor = matrix.matrix[0][0];
    int menor = matrix.matrix[0][0];
    for (int i = 0; i < matrix.filas; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            if (matrix.matrix[i][j] > mayor) {
                mayor = matrix.matrix[i][j];
            }
            if (matrix.matrix[i][j] < menor) {
                menor = matrix.matrix[i][j];
            }
        }
    }
    cout << "El mayor numero encontrado es: " << mayor << endl;
    cout << "El menor numero encontrado es: " << menor << endl;
}
void buscar_elemento(Matriz& matrix, int elemento) {
    bool encontrado = false;
    for (int i = 0; i < matrix.filas; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            if (elemento == matrix.matrix[i][j]) {
                encontrado = true;
                cout << "El elemento " << elemento << " se encuentra en la posicion " << "(" << i << "," << j << ")" << endl;
            }
        }
    }
    if (!encontrado) {
        cout << "El elemento " << elemento << " no existe o no se encuentra en la matriz" << endl;
    }
}
void valor_repetido(Matriz& matrix, int valor) {
    int contador = 0;
    for (int i = 0; i < matrix.filas; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            if (matrix.matrix[i][j] == valor) {
                contador++;
            }
        }
    }
    if (contador == 0) {
        cout << "El valor ingresado no se encuentra en la matriz" << endl;
    }
    else {
        cout << "El valor " << valor << "se repite " << contador << " veces" << endl;
    }

}
void reiniciar(Matriz& matriz, int posi, int posj) {
    for (int i = 0; i < matriz.filas; i++) {
        delete[] matriz.matrix[i];
    }
    delete[] matriz.matrix;
    matriz.filas = posi;
    matriz.cols = posj;
    matriz.matrix = new int* [matriz.filas];
    for (int i = 0; i < matriz.filas; i++) {
        matriz.matrix[i] = new int[matriz.cols];
    }
    matriz.iniciar();
}
void multiplicacion(Matriz& matriz, Matriz& matriz2) {
    if (matriz.cols == matriz2.filas) {
        Matriz resultado;
        reiniciar(resultado, matriz.filas, matriz2.cols);
        for (int i = 0; i < resultado.filas; i++) {
            for (int j = 0; j < resultado.cols; j++) {
                for (int k = 0; k < 2; k++) {
                    resultado.matrix[i][j] += matriz.matrix[i][j] * matriz2.matrix[j][i];
                }
            }
        }
        cout << "\nMatriz 1: " << endl;
        matriz.print();
        cout << "Matriz2: " << endl;
        matriz2.print();
        cout << "Resultado: " << endl;
        resultado.print();
    }
    else {
        cout << "Las matrices dadas no pueden multiplicarse" << endl;
    }
}
void transpuesta(Matriz& matrix) {
    Matriz transpuesta;
    reiniciar(transpuesta, matrix.cols, matrix.filas);
    for (int i = 0; i < transpuesta.filas; i++) {
        for (int j = 0; j < transpuesta.cols; j++) {
            transpuesta.matrix[i][j] = matrix.matrix[j][i];
        }
    }
    transpuesta.print();
}
void copiar_matriz(Matriz& matrix, Matriz& matrix2) {
    cout << "La antigua matriz es: " << endl;
    matrix2.print();
    if ((matrix.filas == matrix2.filas) && (matrix.cols == matrix2.cols)) {
        for (int i = 0; i < matrix.filas; i++) {
            for (int j = 0; j < matrix.cols; j++) {
                matrix2.matrix[i][j] = matrix.matrix[i][j];
            }
        }
        cout << "La nueva matriz es: " << endl;
        matrix2.print();
    }
    else {
        cout << "Estas matrices no tienen las mismas dimensiones" << endl;
    }
}
void exit(bool& salir) {
    char salida;
    cout << "\nDigite cualquier tecla para regresar al menu principal" << endl;
    cin >> salida;
    if (salida != '~') {
        salir = true;
    }
    system("cls");
}