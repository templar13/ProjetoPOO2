#include "Campanha.h"

using namespace std;

int main() {
	Campanha e("Worldwide Harmonized Light Vehicles Test Procedure");

	//Inscricao sem data marcada nem consumo registado
	e.addTeste("Joao", 2, Misto());
	e.addTeste("Joao", 2, Urbano());
	e.addTeste("Rui", 3, ExtraUrbano());
	e.addTeste("Rui", 5, Misto());
	e.addTeste("Ze", 4, Misto());
	e.addTeste("Jonas", 15, Misto());
	//Registar teste ja efetuado com a sua data e o consumo
	e.addTeste("Ruben", 12, "29/06/2022", Urbano(20));
	e.addTeste("Mario", 9, "28/06/2022", ExtraUrbano(19));
	//Dar data ao teste
	e.setData(3, "25/06/2022");
	e.setData(2, "26/06/2022");
	e.setData(4, "26/06/2022");
	e.setData(15, "29/06/2022");
	//Registar Consumo do condutor por numero de TestDrive
	e.setConsumo(2, 20);
	e.setConsumo(3, 21);
	e.setConsumo(4, 18);
	e.setConsumo(15, 15);

	e.mostrarConsumosCMisto();
	e.mostrarConsumosCUrbano();
	e.mostrarConsumosCExtraurbano();
	e.melhorConsumoCMisto();
	e.melhorConsumoCUrbano();
	e.melhorConsumoCExtraurbano();
	e.mostrarTodosTestDrives();
	e.mostrarTestDrive(6);
	e.mostrarTestDrive(2);

}