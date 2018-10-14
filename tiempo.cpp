/* programa que pide al usuario que exprese el tiempo de duración de un deter-
 *minado evento, como una cantidad
 *natural expresada en segundos, para informar a continuación por
 *la pantalla de la equivalencia del tiempo introducido en días, horas, minutos y segundos.
 */
 #include <iostream>

 using namespace std;

 /* Pre: s > 0
  * Post: Muestra por pantalla la duracion en dias horas minutos y segundos.
  */

 int main() {
 cout << "Duración en segundos: " << flush;
 int s;
 cin >> s;
 if (s > 0) {  //Condicion el numero introducido debe de ser positivo.
int dia = s / 86400;  // calcular el numero de dias
int restod = s % 86400;  // el resto despues de descontar los dias
int hora = restod / 3600;  // calcular el numero de horas
int restoh = restod % 3600;  //El resto despues de descontar la horas
int minuto = restoh / 60;  // calcular el numero de minutos
int segundos = restoh % 60; // Calcular el restante los segundos.

cout << "Este tiempo equivale a " << dia << " Dias " << hora << " Horas "  << minuto << " minutos y " << segundos << " segundos" << endl;
 }
 else {
 cout << "El tiempo siembre es numero positivo" << endl;
 return 0;
 }
 return 0;
 }
