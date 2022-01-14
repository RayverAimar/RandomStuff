#pragma once
class Matriz {
public:
	int** matrix, filas, cols;
	Matriz();
	~Matriz();
	void iniciar();
	void print();
};
void iniciar_valor(Matriz& matrix, int posi, int posj, int valor);
void suma_matrices(Matriz& matrix, Matriz& matrix2);
void resta_matrices(Matriz& matrix, Matriz& matrix2);
void coeficiente(Matriz& matrix, int multiplicador);
void mayor_y_menor(Matriz& matrix);
void buscar_elemento(Matriz& matrix, int elemento);
void valor_repetido(Matriz& matrix, int valor);
void reiniciar(Matriz& matriz, int posi, int posj);
void multiplicacion(Matriz& matriz, Matriz& matriz2);
void transpuesta(Matriz& matrix);
void copiar_matriz(Matriz& matrix, Matriz& matrix2);
void exit(bool& salir);
