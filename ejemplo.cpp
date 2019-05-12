#include <iostream>
#include "entorno_dspl.h"
using namespace std;
int main() {
if (entornoIniciar()){















entornoPonerEscenario("Winter");

entornoPonerSensor(25,25,S_temperature,0,"T1");
entornoPonerSensor(250,250,S_temperature,0,"SH");
entornoPonerAct_Switch(480,420,false,"CA");
entornoPulsarTecla();
entornoPonerSensor(25,25, S_temperature, 18.200001, "T1");

entornoPonerAct_Switch(480, 420, true, "CA");
entornoMostrarMensaje("Calefacción encendida");



entornoPonerSensor(25,25, S_temperature, 28.200001, "T1");

entornoPonerAct_Switch(480, 420, false, "CA");
entornoMostrarMensaje("Calefacción apagada");







entornoPausa(1);
entornoPonerSensor(250,250, S_smoke, 100.000000, "SH");

entornoMostrarMensaje("Alarma. Alta probabilidad de incendio");
entornoAlarma();

entornoPausa(1);







	}
return 0;
}
