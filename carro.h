#pragma once
#include "llanta.h"
#include "chasis.h"


class carro {
private:
	float x;
	short y;
	float dx;
	llanta* ObjLlanta;
	llanta** arreglo;//arreglo tipado
	chasis* ObjChasis;

public:
	carro(float px, int y);
	~carro();
	void imprimirCarro();
	void moverCarro();
	void borrar();
	float get_X();
};

carro::carro(float px, int py) {
	x = px;
	y = py;
	//velocidad
	dx = 0.1 + (float)rand() / RAND_MAX; //para obtener un valor minimo, 0.1 es el minimo y la division de rand entre el maximo da un valor muy pequeño
	arreglo = new llanta * [4];
	ObjLlanta = new llanta(x, y, 254);
	arreglo[0] = ObjLlanta;
	ObjLlanta = new llanta(x + 2, y, 254);
	arreglo[1] = ObjLlanta;
	ObjLlanta = new llanta(x, y + 2, 254);
	arreglo[2] = ObjLlanta;
	ObjLlanta = new llanta(x + 2, y + 2, 254);
	arreglo[3] = ObjLlanta;

	ObjChasis = new chasis(x, y + 1, 219);
}
//dx=velocidad

carro::~carro() {}


void carro::imprimirCarro() {
	//imprimir las 4 llanatas
	for (int i = 0; i < 4; i++) {
		arreglo[i]->imprimirLlanta();
	}
	ObjChasis->imprimirChasis();
}

void carro::moverCarro() {
	x += dx;
	arreglo[0]->set_X(x);
	arreglo[1]->set_X(x + 2);
	arreglo[2]->set_X(x);
	arreglo[3]->set_X(x + 2);
	ObjChasis->set_X(x);
	//mover->>actualizar Xs
}

void carro::borrar() {
	//Nota la posicion en los juegos funciona diferente
	// x + 1: mover un espacio a la derecha
	// x - 1: mover un espacio a la izquierda
	// y + 1: mover un espacio a la abajo
	// y - 1: mover un espacio a la arriba
	Console::SetCursorPosition(x, y); cout << "   ";
	Console::SetCursorPosition(x, y + 1); cout << "   ";
	Console::SetCursorPosition(x, y + 2); cout << "   ";
	Console::SetCursorPosition(x, y + 3); cout << "   ";
}

float carro::get_X() {
	return x;
}
