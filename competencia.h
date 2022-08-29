//clase controladora
#pragma once
#include "carro.h"
#include "misFunciones.h"

class competencia {
private:
	carro** arreglo;
	carro* ObjCarro;
	short meta;

public:
	competencia();
	~competencia();
	void iniciarCompetencia();
	void dibujarMeta();
};

competencia::competencia() {
	arreglo = new carro * [3];
	float posx;
	short posy;
	posx = 1; posy = 1;
	meta = 72;

	for (int i = 0; i < 3; i++) {
		ObjCarro = new carro(posx, posy);
		arreglo[i] = ObjCarro;
		posy += 5;
	}
}
competencia::~competencia() {}

void competencia::iniciarCompetencia() {
	arreglo[0]->imprimirCarro();
	arreglo[1]->imprimirCarro();
	arreglo[2]->imprimirCarro();
	dibujarMeta();

	short i = 0;
	while (1) {
		arreglo[i]->borrar();
		arreglo[i]->moverCarro();
		arreglo[i]->imprimirCarro();
		i++;
		if (i > 2) i = 0;
		if (arreglo[i]->get_X() > meta) {
			movexy(30, 35); cout << "GANA el carro " << i + 1;
			movexy(20, 36); cout << "Presione una tecla para terminar...";
			system("pause>0");
			break;
		}
		_sleep(100);
	}
}

void competencia::dibujarMeta() {
	for (int y = 1; y < 38; y++) {
		Console::SetCursorPosition(meta, y); cout << char(179);
		y++;
	}
}
