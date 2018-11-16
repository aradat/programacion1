﻿/*************************************************************************
 * Curso de Programación 1. Práctica 3
 * Autores: Javier Martínez y Miguel Ángel Latre, Thaer Abu-Qamar
 * Última revisión: 06 de noviembre de 2018
 * Resumen: Fichero de implementación de un módulo «fechas» que ofrece
 *          funciones para
 trabajar con fechas del calendario
 *          Versión con esqueletos de las funciones a implementar por el
 *          alumno, que deberá añadirse como autor y actualizar la fecha
 *          de última revisión al acabar.
 ************************************************************************/

/*
* Pre:  La terna de parámetos «dia», «mes» y «agno» definen una fecha
*       válida del calendario gregoriano, la fecha «dia/mes/agno».
* Post:
El valor del parámetro «f», al ser escrito en base 10, tiene un
*       formato de ocho dígitos «aaaammdd» que representa
*       la fecha «dia/mes/agno» donde los dígitos «aaaa» representan el
*       año de la fecha, los dígitos «mm», el mes y los dígitos «dd», el
*       día.
*/
void componer(int dia, int mes, int agno, int& f)
{
    f = (agno * 10000) + (mes * 100) + dia;
}


/*
 * Pre:  El valor de «f» escrito en base 10 tiene la forma «aaaammdd»
 *       donde los dígitos «aaaa» representan el año de una fecha válida
 *       del calendario gregoriano, los dígitos «mm», el mes y los dígitos
 *       «dd», el día.
 * Post: Los valores de los parámetros «dia», «mes» y «agno» son iguales,
 *       respectivamente, al día, al mes y al año de la fecha «f».
 */
void descomponer(int f, int& dia, int& mes, int& agno)
{
    agno = f / 10000;
    mes = (f % 10000) / 100;
    dia = f % 100;
}


/*
 * Pre:  Los valores de los parámetros «f1» y «f2» escritos en base 10
 *       tienen la forma «aaaammdd», donde los dígitos «aaaa» representan
 *       el año, los dígitos «mm», el mes y los dígitos «dd» el día de
 *       sendas fechas del calendario gregoriano.
 * Post: Ha devuelto true si y solo si la fecha representada por el valor
 *       del parámetro «f1» es anterior a la representada por «f2».
 */
bool esAnterior(int f1, int f2)
{
    if (f1 < f2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
 * Pre:  agno > 1582.
 * Post: Ha devuelto true si y solo si el año «agno» es bisiesto de
 *       acuerdo con las reglas del el calendario gregoriano.
 */
bool esBisiesto(int agno)
{
    bool multiplo4   = (agno %   4 == 0);
    bool multiplo100 = (agno % 100 == 0);
    bool multiplo400 = (agno % 400 == 0);
    return multiplo400 || (multiplo4 && !multiplo100);
}


/*
 * Pre:  1 ≤ mes ≤ 12 y agno > 1582.
 * Post: Ha devuelto el número de días del mes correspondiente al
 *       parámetro «mes» del año correspondiente al parámetro «agno».
 *       Por ejemplo: diasDelMes(10, 2018) devuelve 31,
 *                    diasDelMes(2, 2018) devuelve 28 y
 *                    diasDelMes(2, 2020) devuelve 29.
 */
int diasDelMes (int mes, int agno)
{
    int diasDm;
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        diasDm = 30;
    }
    else
    {
        if (mes == 1 || mes == 3 || mes == 5|| mes == 7 || mes == 8 || mes == 10 || mes == 12)
        {
            diasDm = 31;
        }
        else
        {
            if (esBisiesto(agno) && mes == 2)
            {
                diasDm = 29;
            }
            else
            {

                diasDm = 28;
            }
        }
    }

    return diasDm;
}


/*
 * Pre:  agno > 1582.
 * Post: Ha devuelto el número de días que tiene el año «agno».
 *       Por ejemplo: diasDelAgno(2018) devuelve 365 y
 *                    diasDelAgno(2020) devuelve 366.
 */
int diasDelAgno(int agno)
{
    if (esBisiesto(agno))
    {
        return 366;
    }
    else
    {
        return 365;
    }
}


/*
 * Pre:  1 ≤ dia ≤ 31, 1 ≤ mes ≤ 12 y agno > 1582 y la fecha formada por
 *       «dia/mes/agno» es una fecha válida del calendario gregoriano.
 * Post: Ha devuelto el número de día del año de la fecha formada por
 *       «dia/mes/agno».
 *       Por ejemplo: diaEnElAgno(1, 1, 2019) devuelve 1;
 *                    diaEnElAgno(31, 12, 2018) devuelve 365;
 *                    diaEnElAgno(1, 2, 2019) devuelve 32 y
 *                    diaEnElAgno(31, 12, 2020) devuelve 366.
 */
int diaEnElAgno(int dia, int mes, int agno)
{
    int suma;
    for (int i = 1 ; i <= (mes - 1) ; i++ )
    {
        suma += diasDelMes(i, agno);
    }
    return suma + dia;
}


/*
 * Pre:  El valor de «fecha» escrito en base 10 tiene la forma «aaaammdd»,
 *       donde los dígitos «aaaa» representan el año, los dígitos «mm», el
 *       mes y los dígitos «dd» el día de una fecha válida del calendario
 *       gregoriano.
 * Post: Ha devuelto la fecha correspondiente al día posterior a la fecha
 *       representada por el valor del parámetro «fecha», representada con
 *       el mismo formato «aaaammdd» que «fecha».
 */
int diaSiguiente(int fecha)
{
    int dMes, dia, mes, agno, cDia, cMes, cAgno;
    descomponer(fecha, dia, mes, agno);
    dMes = diasDelMes(mes, agno);
    if (dia == dMes)
    {
        if (mes == 12)
        {
            cMes = 1;
            cDia = 1;
            cAgno = agno + 1;
        }
        else
        {
            cMes = mes + 1;
            cDia = 1;
            cAgno = agno;
        }
    }
    else
    {
        cDia = dia + 1;
        cMes = mes;
        cAgno = agno;
    }

    componer(cDia, cMes, cAgno, fecha);

    return fecha;
}
