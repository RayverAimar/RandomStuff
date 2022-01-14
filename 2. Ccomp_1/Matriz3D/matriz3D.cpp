#include <iostream>
#include "matriz3D.h"

using namespace std;

Matriz::Matriz() {
	matrix = nullptr;
	filas = 3;
	columnas = 4;
	ancho = 2;
	matrix = new int** [filas];
	for (int i = 0; i < filas; i++) {
		matrix[i] = new int* [columnas];
	}
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			matrix[i][j] = new int[ancho];
		}
	}
}
Matriz::~Matriz() {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			delete[]matrix[i][j];
		}
	}
	for (int i = 0; i < filas; i++) {
		delete[]matrix[i];
	}
	delete[]matrix;
}
void Matriz::iniciar() {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			for (int k = 0; k < ancho; k++) {
				matrix[i][j][k] = 0;
			}
		}
	}
}
void Matriz::print() {
	for (int k = 0; k < ancho; k++) {
		for (int i = 0; i < filas; i++) {
			for (int j = 0; j < columnas; j++) {
				cout << matrix[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}

void iniciar_valor(Matriz& matrix, int posi, int posj, int posk, int valor) {
	for (int i = 0; i < matrix.filas; i++) {
		for (int j = 0; j < matrix.columnas; j++) {
			for (int k = 0; k < matrix.ancho; k++) {
				if (posi == i) {
					if (posj == j) {
						if (posk == k) {
							matrix.matrix[i][j][k] = valor;
						}
					}
				}
			}
		}
	}
}
void suma_matrices(Matriz& matrix, Matriz& matrix2) {
	Matriz resultado;
	for (int i = 0; i < matrix.filas; i++) {
		for (int j = 0; j < matrix.columnas; j++) {
			for (int k = 0; k < matrix.ancho; k++) {
				resultado.matrix[i][j][k] = matrix.matrix[i][j][k] + matrix2.matrix[i][j][k];
			}
		}
	}
	resultado.print();
}
void resta_matrices(Matriz& matrix, Matriz& matrix2) {
	Matriz resultado;
	for (int i = 0; i < matrix.filas; i++) {
		for (int j = 0; j < matrix.columnas; j++) {
			for (int k = 0; k < matrix.ancho; k++) {
				resultado.matrix[i][j][k] = matrix.matrix[i][j][k] - matrix2.matrix[i][j][k];
			}
		}
	}
	resultado.print();
}
void mayor_menor(Matriz& matrix) {
	int mayor = matrix.matrix[0][0][0];
	int menor = matrix.matrix[0][0][0];
	for (int i = 0; i < matrix.filas; i++) {
		for (int j = 0; j < matrix.columnas; j++) {
			for (int k = 0; k < matrix.ancho; k++) {
				if (matrix.matrix[i][j][k] > mayor) {
					mayor = matrix.matrix[i][j][k];
				}
				if (matrix.matrix[i][j][k] < menor) {
					menor = matrix.matrix[i][j][k];
				}
			}
		}
	}
	cout << "\nEl mayor elemento encontrado es: " << mayor << endl;
	cout << "El menor elemento encontrado es: " << menor << endl;
}
void buscar_elemento(Matriz& matrix, int elemento) {
	bool encontrado = false;
	for (int i = 0; i < matrix.filas; i++) {
		for (int j = 0; j < matrix.columnas; j++) {
			for (int k = 0; k < matrix.ancho; k++) {
				if (matrix.matrix[i][j][k] == elemento) {
					encontrado = true;
					cout << "El elemento " << elemento << " se encuentra en la posicion (" << i << "," << j << "," << k << ")" << endl;
				}
			}
		}
	}
	if (!encontrado) {
		cout << "El elemento " << elemento << " no se encuentra en la matriz actual" << endl;
	}
}
void valor_repetido(Matriz& matrix, int valor) {
	int contador = 0;
	bool encontrado = false;
	for (int i = 0; i < matrix.filas; i++) {
		for (int j = 0; j < matrix.columnas; j++) {
			for (int k = 0; k < matrix.ancho; k++) {
				if (matrix.matrix[i][j][k] == valor) {
					encontrado = true;
					contador += 1;
				}
			}
		}
	}
	if (encontrado) {
		if (contador == 1) {
			cout << "El valor " << valor << " aparece " << contador << " vez" << endl;
		}
		else {
			cout << "El valor " << valor << " aparece " << contador << " veces" << endl;
		}
	}
	else {
		cout << "El valor " << valor << " no se encuentra en la matriz actual" << endl;
	}

}
void copiar_matriz(Matriz& matrix, Matriz& matrix2) {
	for (int i = 0; i < matrix.filas; i++) {
		for (int j = 0; j < matrix.columnas; j++) {
			for (int k = 0; k < matrix.ancho; k++) {
				matrix2.matrix[i][j][k] = matrix.matrix[i][j][k];
			}
		}
	}
}
void reiniciar(Matriz& matriz, int posi, int posj, int posk) {
	for (int i = 0; i < matriz.filas; i++) {
		for (int j = 0; j < matriz.columnas; j++) {
			delete[]matriz.matrix[i][j];
		}
	}
	for (int i = 0; i < matriz.filas; i++) {
		delete[]matriz.matrix[i];
	}
	delete[]matriz.matrix;
	//creacion
	matriz.filas = posi;
	matriz.columnas = posj;
	matriz.ancho = posk;
	matriz.matrix = new int** [matriz.filas];
	for (int i = 0; i < matriz.filas; i++) {
		matriz.matrix[i] = new int* [matriz.columnas];
	}
	for (int i = 0; i < matriz.filas; i++) {
		for (int j = 0; j < matriz.columnas; j++) {
			matriz.matrix[i][j] = new int[matriz.ancho];
		}
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