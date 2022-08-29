#pragma once
using namespace System;
using namespace std;
#include <iostream>

class chasis {
private:
	int x, y;
	short forma;//short: dato mas pequeño

public:
	chasis(int pc, int py, short pforma);
	~chasis();

	void imprimirChasis();
	void set_X(int valor);
};

chasis::chasis(int px, int py, short pforma) {
	x = px;
	y = py;
	forma = pforma;
}

chasis::~chasis() {}

void chasis::imprimirChasis() {
	Console::SetCursorPosition(x, y);
	cout << char(forma);
	Console::SetCursorPosition(x + 1, y); //por cada caracter (cuadrado)
	cout << char(forma);
	Console::SetCursorPosition(x + 2, y);
	cout << char(forma);
	Console::SetCursorPosition(x + 3, y);
	cout << char(forma);
}

void chasis::set_X(int valor) {
	x = valor;
}
