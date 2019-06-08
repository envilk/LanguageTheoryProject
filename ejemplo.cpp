#include <iostream>
#include "entorno_dspl.h"
using namespace std;
int main() {
if (entornoIniciar()){
entornoPonerEscenario("Winter");
entornoPonerSensor(25,25,S_temperature,0,"T1");
entornoPonerSensor(250,250,S_temperature,0,"SH");
entornoPonerAct_Switch(400,420,false,"CA");
entornoPulsarTecla();
entornoPonerSensor(25,25, S_temperature, 18.200001, "T1");
entornoPonerAct_Switch(400, 420, true, "CA");
entornoMostrarMensaje("Calefacción encendida");
entornoPausa(3.000000);
entornoPonerSensor(25,25, S_temperature, 28.200001, "T1");
entornoMostrarMensaje("Calefacción");
entornoPulsarTecla();
entornoPonerEscenario("Fire");
entornoPonerSensor(25,25,S_temperature,0,"T1");
entornoPonerSensor(250,250,S_temperature,0,"SH");
entornoPonerAct_Switch(400,420,false,"CA");
entornoPausa(1.000000);
entornoPonerSensor(250,250, S_smoke, 100.000000, "SH");
entornoMostrarMensaje("Alarma. Alta probabilidad de incendio");
for(int i_0=0;i_0<2.000000;i_0++){
entornoAlarma();
entornoPausa(1.000000);
}
entornoBorrarMensaje();
entornoTerminar();
	}
return 0;
}
