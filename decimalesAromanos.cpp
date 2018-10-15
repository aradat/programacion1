/* El programa pregunta al usuario por un número entero del intervalo [1, 10] y le informa por pantalla
 *de su equivalencia como número romano.
 */
 #include <iostream>
 using namespace std;

 /* Pre: r > 0 , r <= 10
  *
  * Post: Muestra por pantalla la equivalencia en numeros romanos.
  */

  int main() {
 cout << "Escriba un entero entre 1 y 10: " << flush;
 int z;
 cin >> z;
 if (z > 10 || z < 1) {
 cout << "Numero fuera del intervalo" << endl;
 return 0;
 }

 else {
  if (z >= 10) { cout << z << " = X" << endl; } else {
  if (z >= 9) { cout << z << " = IX" << endl; } else {
  if (z >= 8) { cout << z << " = VIII"  << endl; } else {
  if (z >= 7) { cout << z << " = VII"  << endl; } else {
  if (z >= 6) { cout << z << " = VI"  << endl; } else {
  if (z >= 5) { cout << z << " = V"  << endl; } else {
  if (z >= 4) { cout << z << " = IV" << endl; } else {
  if (z >= 3) { cout << z << " = III" << endl; } else {
  if (z >= 2) { cout << z << " = II" << endl; } else {
  if (z >= 1) { cout << z << " = I"  << endl; }
}
}
}
}
}
}
}
}
}
}

 return 0;

  }
