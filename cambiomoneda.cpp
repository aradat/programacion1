/* Autor: Thaer AbuQamar
 *Programa para mostrar por pantalla de la cifra en euros inroducida por el usuario
 * separando euros y centimos. Y luego convertir el euro a pesetas.
 */
 #include <iostream>

 using namespace std;

  /* Pre: x > 0
  * Post: Muestra por pantalla el desglose de la cifra solicitada al usuario y convertirla en pesetas
  */

  int main() {

  cout << "Escriba una cantidad positiva de dinero en euros: " << flush; // solicitar cifra al operador
  double laCifra;
  cin >> laCifra;
  if (laCifra > 0) {
  double cuenta = laCifra * 1000 ; //para convertir numero real a uno entero
  int convertir = (int) cuenta ;
  int eur = convertir / 1000 ; // Extraer los numeros que corresponden a euros
  int i = convertir % 1000 ; //las minimo 3 cifras para los centimos
  int cent = i / 10 ; // Extraer los dos numero que corresponden a los centimos
  double pst = laCifra * 166.66 ; // Convertir Euros a pesetas
  int j = i % 10 ; // problema redondeo antes de eliminar la tercera cifra de centimos
  if (j > 5 ) {
  cout << "Son " << eur << " Euros y " << ++cent << " centimos que equivalen a " << pst << " Pesetas." << endl;
  }

  if (j < 5 ) {
  cout << "Son " << eur << " Euros y " << cent << " centimos que equivalen a " << pst << " Pesetas." << endl;
  }
  }

  else {
   cout << "La cifra tiene que ser positiva" << endl;
 return 0;
  }

return 0;
  }
