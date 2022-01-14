#pragma once
class Matriz {
public:
	int*** matrix, filas, columnas, ancho;
	Matriz();
	~Matriz();
	void iniciar();
	void print();
};
void iniciar_valor(Matriz& matrix, int posi, int posj, int posk, int valor);
void suma_matrices(Matriz& matrix, Matriz& matrix2);
void resta_matrices(Matriz& matrix, Matriz& matrix2);
void mayor_menor(Matriz& matrix);
void buscar_elemento(Matriz & matrix, int elemento);
void valor_repetido(Matriz & matrix, int valor);
void copiar_matriz(Matriz& matrix, Matriz& matrix2);
void reiniciar(Matriz& matriz, int posi, int posj, int posk);
void exit(bool& salir);
