/*********************************************************************************
 * Curso de Programación 1. Tema 7 y prueba voluntaria de evaluación 1
 * Autores: Miguel Ángel Latre, Javier Martínez y
 *          THAER ABU-QAMAR MOUSA, NIP: 773637
 * Última revisión: 16 de noviembre de 2018
 *
 * Resumen: Programa que escribe en la pantalla el calendario de un determinado
 *          mes de un año, que se solicitan al usuario. El programa se asegura de
 *          que el mes introducido está comprendido entre 1 y 12 y de que el año
 *          es igual o posterior a 1900.
 *          Clase de problemas correspondiente al tema 7 (diseño modular y
 *          descendente) y 1ª prueba voluntaria de evaluación (curso 2018-19).
\********************************************************************************/

#include <iostream>
#include <iomanip>
#include "../../Biblioteca/fechas.h"
using namespace std;


/*
 * Pre:  ---
 * Post: Ha solicitado reiteradamente al usuario un mes de un año igual o
 *       posterior a 1900, leyéndolos en los parámetros «mes» y «agno», hasta que
 *       1 ≤ mes ≤ 12 y hasta que agno ≥ 1900.
 */
void pedirDatos(int& mes, int& agno)
{

    cout << " Escribe el mes para ver el calendario : " << flush;
    cin >> mes;
    while ((mes < 1 || mes > 12))
    {
        cout << " El agno tiene 12 meses del 1 al 12 vuelve a probar: " << endl;
        cout << " Escribe el mes para ver el calendario : " << flush;
        cin >> mes;
    }
    // mes >= 1 && mes <= 12

    if (mes != 0)
    {
        cout << " Escribe el agno: " << flush;
        cin >> agno;

        while (agno < 1900)
        {
            cout << " Tiene que ser un agno posterior al 1900." << endl;
            cout << " Escribe el agno: " << flush;
            cin >> agno;
        }
    }

}


/*
 * Pre:  Los valores de los parámetros «dia», «mes» y «agno» representan
 *       conjuntamente una fecha válida del calendario gregoriano igual o
 *       posterior al 1 de enero de 1900.
 * Post: Ha devuelto un entero que codifica el día de la semana de la fecha
 *       representada por los valores de los parámetros «dia», «mes» y «agno», de
 *       acuerdo con la siguiente codificación: el 0 codifica el lunes, el 1
 *       codifica martes y así sucesivamente hasta el 6, que codifica el domingo.
 */
int diaDeLaSemana(const int dia, const int mes, const int agno)
{
    int sumas = 0;
    for (int i = 1900 ; i < agno ; i++)
    {
        sumas += diasDelAgno(i) ;
    }

    for (int j = 1 ; j < mes ; j++ )
    {
        sumas += diasDelMes(j, agno);
    }
    if (dia > 0)
    {
        sumas = ((sumas + dia) - 1) % 7;
    }
    else
    {
        sumas = sumas % 7;
    }

    return sumas;
}
/*
 * Pre:  1 ≤ mes ≤ 12
 * Post: Ha escrito en la pantalla el nombre (en mayúsculas) del mes
 *       correspondiente al valor del parámetro «mes».
 * Nota: Este código se explicará adecuadamente en el tema 10 (cadenas de
 *       caracteres).
 */
void escribirNombreMes(const int mes)
{
    const int NUM_MESES = 12;
    const int MAX_LONG_NOMBRE_MES = 10;
    const char NOMBRES_MES[NUM_MESES][MAX_LONG_NOMBRE_MES + 1] = { "ENERO",
                                                                   "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO",
                                                                   "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"
                                                                 };
    cout << NOMBRES_MES[mes - 1];
}

/*
 * Pre:  1 ≤ mes ≤ 12
 * Post: Ha escrito en la pantalla la cabecera del calendario del mes «mes» del
 *       año «agno» con un el formato del siguiente ejemplo:
 *
 *                     NOVIEMBRE 2018
 *          L   M   X   J   V   S   D
 *       ----------------------------
 */
void escribirCabecera(const int mes, const int agno)
{
    cout << setw(24) << endl;
    escribirNombreMes(mes);
    cout << " - " << agno << endl;
    cout << endl;
    cout << setw(5) << "   " << "L   M   X   J   V   S   D" << endl;
    cout << setw(3) << " " << "----------------------------" << endl;
}


/*
 * Pre:  1 ≤ mes ≤ 12 y agno ≥ 1900
 * Post: Ha escrito en la pantalla el calendario del mes «mes» del año «agno» con
 *       el formato del siguiente ejemplo:
 *
 *                     NOVIEMBRE 2018
 *          L   M   X   J   V   S   D
 *       ----------------------------
 *                      1   2   3   4
 *          5   6   7   8   9  10  11
 *         12  13  14  15  16  17  18
 *         19  20  21  22  23  24  25
 *         26  27  28  29  30
 */
void escribirCalendario(const int mes, const int agno)
{
    int dia = 0;

    escribirCabecera(mes, agno);

    int diasemana = diaDeLaSemana(dia, mes, agno);

    cout << setw(4*(diasemana + 1)) << " " << flush;

    for (int f = 1 ; f <= diasDelMes(mes, agno) ; f++)
    {

        if (f > 9)
        {
            cout << f << setw(2) << " " << flush;

        }
        else
        {
            cout << setw(2) << f << "  " << flush;
        }

        diasemana ++;

        if (diasemana > 6)
        {
            cout << endl;
            cout << setw(4) << " " << flush;
            diasemana = 0;
        }

    }

}

/*
 * Pre:  ---
 * Post: Ha solicitado al usuario un mes de un año igual o posterior a 1900, se
 *       ha asegurado de que el mes introducido está comprendido entre 1 y 12 y
 *       de que el año es igual o posterior a 1900 y ha terminado escribiendo el
 *       calendario del mes solicitado en la pantalla.
 */
int main()
{
    int mes, agno;
    pedirDatos(mes, agno);
    escribirCalendario(mes, agno);
    return 0;
}
