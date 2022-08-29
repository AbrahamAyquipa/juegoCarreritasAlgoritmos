#pragma once
#include <iostream>

using namespace System;
using namespace std;

class llanta {
private:
	int x, y;
	short forma;

public:
	llanta(int px, int py, short pforma);
	~llanta();
	void imprimirLlanta();
	void set_X(int valor);
};

llanta::llanta(int px, int py, short pforma) {
	x = px;
	y = py;
	forma = pforma;
}

llanta::~llanta() {}

void llanta::imprimirLlanta() {
	Console::SetCursorPosition(x, y);
	cout << char(forma);
}

void llanta::set_X(int valor) {
	x = valor;
}
