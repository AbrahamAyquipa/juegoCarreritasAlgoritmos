#include "pch.h"
#include "carro.h"
#include "competencia.h"

int main() {
	srand((unsigned)time(NULL));//pequenia semilla tomando valores aleatorios distintos de acuerdo al sistema
	Console::CursorVisible = false; //no mostrar palito palpitando
	competencia* ObjCompetencia;

	ObjCompetencia = new competencia();
	ObjCompetencia->iniciarCompetencia();
	return 0;
	system("pause>0");
}
