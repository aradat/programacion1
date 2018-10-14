/* Programa Cajero informa al usuario del número de billetes que le devolverá un cajero al retirar la cantidad
de dinero por él especificada, que será
positiva y múltiplo de 10
 *
 */
 #include <iostream>
 #include <iomanip>

 using namespace std;

 /* Pre: importe es multilpe de 10 y mayor que cero
  * Post: muestra por pantalla tabla con la cantidad de cada billete
  */

int main() {
cout << "Cantidad a retirar en euros [positiva y múltiplo de 10]: " << flush;
int importe;
cin >> importe;
if (importe % 10 == 0 && importe > 0) { // Condicion para calcular solo numeros positivos y multiplos de 10
int B50 = importe / 50; // cantidad de billetes de 50
int I50 = B50 * 50; // el importe de los billetes de 50
int resto50 = importe - I50; //el resto despues de descontar los billetes de 50
int B20 = resto50 / 20; // cantidad de billetes de 20
int I20 = B20 * 20; // el importe de los billetes de 20
int resto20 = resto50 - I20; // el resto despues de descontar los billetes de 20
int B10 = resto20 / 10; // cantidad de billetes de 10

cout << setw(10) << "Billetes" << setw(10) << "Euros" << endl;
cout << setw(10) << "========" << setw(10) << "=====" << endl;
cout << setw(10) << B50 << setw(10) << "50" << endl;
cout << setw(10) << B20 << setw(10) << "20" << endl;
cout << setw(10) << B10 << setw(10) << "10" << endl;
}
else { cout << "Error, tiene que ser numero positivo y multiplo de 10" << endl;
return 0;
}
return 0;
}
