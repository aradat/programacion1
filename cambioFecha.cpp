/* Programa que transforma una fecha introducida por el usuario de aaaammdd a dd / mm / aaaa
 *
 */
 #include <iostream>

 using namespace std;

 /* Pre: n > 9999999 , n < 99999999
  * Post: Muestra por pantalla la fecha introducida por el usuario en formato dd/mm/aaaa
  */

int main () {

cout << "Escriba una fecha con formato de 8 cifras [aaaammdd]: " << flush; // El usuario introduce el numero
int n;
cin >> n;

if ( n < 99999999 && n > 9999999 ) { // el numero tiene que ser de 8 cifras

int ango ;
ango = n / 10000 ; // elimina el resto de la division y queda el año
int mmdd ;
mmdd = n % 10000 ; // el resto de la division para optener el año es: mes y dia
int mm ;
mm = mmdd / 100 ; // al eliminar el resto de la division queda el mes
int dd ;
dd = mmdd % 100 ; // El resto de la division nos da el dia

cout << "La fecha es: " << dd << "/" << mm << "/" << ango << endl; }

else {

cout << "la fecha no es correcta prueba de nuevo" << endl; // Mensaje a mostrar por pantalla si el usuario introduce numero equivocado

}

return 0;

}
