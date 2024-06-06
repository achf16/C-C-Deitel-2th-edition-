/*#include <stdio.h>
#include <math.h>


main()
{

    // 4.36
    // Imprimir calendario

    /*     Mientras año esté entre 1994 y 1999
            Escriba un año entre 1994 y 1999
            if (año % 4 == 0) bisiesto, cantidad de días 366
            sino cantidad de días 365

            para Año
                case 1994
                    espacio en blanco 6
                case 1995
                    espacio en blanco 0
                case 1996
                    espacio en blanco 1
                case 1997
                    espacio en blanco 3
                case 1998
                    espacio en blanco 4
                case 1999
                    espacio en blanco 5

            Para mes <= 12; mes++
                if (mes == 2)
                    if (cantidad de días 366 ) cantidadDIAS_mes = 28
                    else cantidadDIAS_mes = 28
                else if (mes % 2 == 1) cantidadDIAS_mes = 31
                else cantidadDIAS_mes = 30

                para mes
                    case 1: enero, Su Mo Tu We Th Fr Sa
                    case 2: febrero, Su Mo Tu We Th Fr Sa
                    ....
                    case 12: diciembre, Su Mo Tu We Th Fr Sa


                for dia == , column == 0; dia <= cantidadDIAS_mes + espacio en blanco; dia++, column++
                    si dia menor o igual que espacio en blanco
                        printf " "
                    sino
                        printf dia - 7
                        si dia == 7
                            printf "\n"

                    si column == 7
                        column = 0;

                espacio en blanco = 7 - column

            */
/*
    int year = 1994, daysYEAR, espacio_en_Blanco, moth, day, daysMoth = 0, column;

    while( 1 )
    {
        printf("Escriba un año entre 1994 y 1999, número mayor o menor para FIN: ");
        if( scanf("%d", &year), year < 1994 || year > 1999 ) break;

        // Asigna la cantidad de espacios en blanco al inicio de un año
        switch( year )
        {
            case 1994: espacio_en_Blanco = 6; break;
            case 1995: espacio_en_Blanco = 0; break;
            case 1996: espacio_en_Blanco = 1; break;
            case 1997: espacio_en_Blanco = 3; break;
            case 1998: espacio_en_Blanco = 4; break;
            case 1999: espacio_en_Blanco = 5; break;
        }

        for ( moth = 1; moth <= 12; moth++)
        {
            // Asignación de los días del mes
            if( moth == 2 )
            {
                if( year % 4 != 0 ) daysMoth = 28;
                else daysMoth = 29;
            }
            else if( moth % 2 == 1 ) daysMoth = 31;
            else daysMoth = 30;

            // Imprime mes y dias de las semanas
            switch( moth )
            {
                case 1: printf("%21s\n%21s\n", "Enero", "Su Mo Tu We Th Fr Sa"); break;
                case 2: printf("%21s\n%21s\n", "Febrero", "Su Mo Tu We Th Fr Sa"); break;
                case 3: printf("%21s\n%21s\n", "Marzo", "Su Mo Tu We Th Fr Sa"); break;
                case 4: printf("%21s\n%21s\n", "Abril", "Su Mo Tu We Th Fr Sa"); break;
                case 5: printf("%21s\n%21s\n", "Mayo", "Su Mo Tu We Th Fr Sa"); break;
                case 6: printf("%21s\n%21s\n", "Junio", "Su Mo Tu We Th Fr Sa"); break;
                case 7: printf("%21s\n%21s\n", "Julio", "Su Mo Tu We Th Fr Sa"); break;
                case 8: printf("%21s\n%21s\n", "Agosto", "Su Mo Tu We Th Fr Sa"); break;
                case 9: printf("%21s\n%21s\n", "Septiembre", "Su Mo Tu We Th Fr Sa"); break;
                case 10: printf("%21s\n%21s\n", "Octubre", "Su Mo Tu We Th Fr Sa"); break;
                case 11: printf("%21s\n%21s\n", "Noviembre", "Su Mo Tu We Th Fr Sa"); break;
                case 12: printf("%21s\n%21s\n", "Diciembre", "Su Mo Tu We Th Fr Sa"); break;
            }

            // Imprimir el mes
            for( day = 1, column = 1; day <= (daysMoth + espacio_en_Blanco); day++, column++)
            {
                //printf("gato\n");
                if( day <= espacio_en_Blanco ) printf("   ");
                else printf("%3d", day - espacio_en_Blanco);

                if( column == 7) printf("\n"), column = 0;
            }

            // Espacio en blanco para el inicio siguiente mes
            espacio_en_Blanco = column-1;

            // Nueva línea al final de mes
            printf("\n");
        }

    }*/
























    // 4.38
   /* int i, j, k;

    for(i = 1; i <= 5; i++)
    {
        for(j = 1; j <= 3; j++)
        {
            for(k = 1; k <= 4; k++) printf("*");
            printf("\n");
        }

        printf("\n");
    }*/


































    //4.34
    //Escribir un programa que imprima los binarios decimales y octales del rango de 1 a 256
/*
    int number, temp, almacen_binario, exponente;

    printf("Decimales    Binario    Octales    Hexagecimales\n");

    for(number = 1; number <= 256; number++)
    {
        printf("%-9d    ", number);

        for(temp = number, exponente = 1, almacen_binario = 0; temp / 2 != 0 || temp % 2 != 0; temp /= 2, exponente *= 10) almacen_binario += temp % 2 * exponente;
        printf("%-7d", almacen_binario);

        printf("    %-7o",number);
        printf("    %X\n",number);

    }
*/
























    // 4.33
    // Escribir todos los numeros romanos del 1 al 100
    /* Notación:
            I - 1
            V - 5
            X - 10
            L - 50
            C - 100
            D - 500
            M - 1000

        Para numberPrincipal = 1 hasta number <= 100
            Mientras(number = numberPrincipal, number != 0)
                - number igual a 100
                    | imprime C
                - number mayor que 50
                    | imprime L    // aquí debería ir que si se repite 2 veces hay un error en el número, pero como los números serán menores que 100 no es un caso posible
                    | number -= 50
                - number / 10 > 3
                    | imprime XL
                    | number -= 40
                  sino si number / 10 < 3 && number / 10 > 0
                    | for (number; number / 10 != 0; number -= 10) imprime X
                - si number == 9
                    | imprime IX
                    | number -= 9
                - si number >= 5
                    | imprime V
                    | for(number -= 5; number >= 0; number--) imprimir I
                  sino si number == 4 imprime IV, number -= 4
                  sino for(number; number >= 0; number--) imprimir I


    */
/*
    int number, numberPrincipal;

    printf("Decimal    Romano\n");
    for(numberPrincipal = 1; numberPrincipal <= 100; numberPrincipal++)
    {
        printf("%7d    ",numberPrincipal);
        number = numberPrincipal;

        while(number != 0)
        {
            if(number == 100)   printf("C"), number -= 100;
            if(number >= 50)    printf("L"), number -= 50;

            if(number / 10 > 3) printf("XL"), number -= 40;
            else if(number / 10 <= 3 && number / 10 > 0)
                {
                    for (number; number / 10 != 0; number -= 10) printf("X");
                }

            if(number == 9) printf("IX"), number -= 9;
            if (number >= 5)
            {
                printf("V");
                for(number -= 5; number > 0; number--) printf("I");
            }
            else if(number == 4) printf("IV"), number -= 4;
            else for(number; number > 0; number--) printf("I");
        }

        printf("\n");
    }
*/






































   // 4.32
   // desplegar un diamante como el ejercicio anterior pero el tamaño lo especifica un usuario
/*
    int space_counter, aster_counter, row, temp, large, middle;

    while(large != EOF)
    {
        switch( printf("Escriba el tamaño que desea para el diamante entre 1 y 19, -1 para finalizar: "), scanf("%d",&large), large > 0 && large <= 19)
        {
            case 1:
                //printf("prueba\n");
                for( large % 2 == 0 ? (middle = large /2) : (middle = large / 2 +1), temp = middle, row = 1; row <= large; row++)
                {
                    row <= middle ? temp-- : temp ++;
                    for(space_counter = temp ; space_counter  > 0; space_counter--) printf(" ");
                    for(aster_counter = large - 2 * temp; aster_counter > 0; aster_counter--) printf("*");
                    printf("\n");
                }
                break;
            default:
                printf("Tas tirando merma!!! \n\n");
        }
    }
   */


























    // 4.31
    // Imprimir un rombo con For anidados
/*
    int space_counter, aster_counter, row, temp = 5;

    // vía 1
    for(row = 1; row <= 9; row++)
    {
        switch(row <=5)
        {
            case 1:
                temp--;
                for(space_counter = temp ; space_counter  > 0; space_counter--) printf(" ");
                for(aster_counter = 9 - 2 * temp; aster_counter > 0; aster_counter--) printf("*");
                printf("\n");
                break;
            default:
                temp++;
                for(space_counter = temp ; space_counter  > 0; space_counter--) printf(" ");
                for(aster_counter = 9 - 2 * temp; aster_counter > 0; aster_counter--) printf("*");
                printf("\n");
        }
    }
*/
    // vía 2
/*    printf("\n\n");

    temp = 5;

    for(row = 1; row <= 9; row++)
    {
        row <= 5 ? temp-- : temp ++;
        for(space_counter = temp ; space_counter  > 0; space_counter--) printf(" ");
        for(aster_counter = 9 - 2 * temp; aster_counter > 0; aster_counter--) printf("*");
        printf("\n");
    }
 */



























    //4.30
    // Figura 4.7 bajo la condiciones que me dan

    // caso if/else
   /* int grade;
    int aCount = 0, bCount = 0, cCount = 0,
        dCount = 0, fCount = 0;

    printf("Enter the letter grades.\n");
    printf("Enter the EOF character to end input.\n");

    while( ( grade = getchar() ) != EOF)
    {*/
        //vía 1
        /*
        if (grade == 'A' || grade == 'a') ++aCount;
        else if (grade == 'B' || grade =='b') ++bCount;
        else if (grade == 'C' || grade == 'c') ++cCount;
        else if (grade == 'D' || grade == 'd') ++dCount;
        else if (grade == 'F' || grade == 'f') ++fCount;
        else if (grade == '\n' || grade == ' ');
        else printf("Incorrect letter grade entered. Enter a new grade. \n");
    */
        // via 2.... no la voy a hacer

/*}*/
/*
    printf("\nTotals for each letter grade are:\n");
    printf("A: %d\n", aCount);
    printf("B: %d\n", bCount);
    printf("C: %d\n", cCount);
    printf("D: %d\n", dCount);
    printf("F: %d\n", fCount);
*/




























    // 4.28
    // Nómina semanal de una empresa donde desconosco el número de trabajadores
    /*
        - secuencia controlada por centinela
        - switch codigo de nómina
            1 genretes
            2 trabajadores horarios
            3 trabajadores por comision
            4 trabajadores a destajo


    MIentras (cod_nomina != EOF)
        - Escriba el código de su nómina de pago, EOF para terminar:
        - switch (cod_nomina)
            | case 1
                ~ escriba salario semanal fijo
                ~ su salario es ...
                break;
            | case 2
                ~ escriba el salario fijo por las primeras 40 horas de trabajo
                ~ cantidad de horas total trabajadas en la semana
                ~ el salrio semanal es Salario_40 horas + (Salario_40 horas / Cant_Horas)* 1.5 * (Cantidad de horas en la semana - 40)
                ~ break;
            | case 3
                ~ Escriba ventas semanales brutas
                ~ su salario es de 250 + 5.7 * ventasBrutas
                ~ break;
            | case 4
                ~ escriba la cantidad de piezas producidas
                ~ escriba el pago por unidad producida
                ~ su salario es Cant_item * Pago_item
                ~ break
            | case -1 break;
            | default el código escrito no es valido

    */
/*
   int cod_nomina, horas_trabajadas = 1, cantidad_item;
   float almacen;

   do
   {
        printf("Escriba el código de su nómina de pago, -1 para terminar: ");

        switch ( scanf("%d",&cod_nomina), cod_nomina )
        {
            case 1:
                printf("Escriba salario semanal fijo: "), scanf("%f", &almacen);
                printf("Su salario semanal es de %.2f\n", almacen);
                break;
            case 2:
                printf("Escriba el salario fijo por las primeras 40 horas trabajadas: "), scanf("%f",&almacen);

                while(horas_trabajadas < 40)
                {
                    printf("Escriba la cantidad de horas total trabajadas en la semana, [horas >= 40]: "), scanf("%d",&horas_trabajadas);

                }

                printf("El salario semanal es: %.2f\n", almacen + ( almacen / 40 ) * 1.5 * ( (float)horas_trabajadas - 40) );
                horas_trabajadas = 1;
                break;
            case 3:
                printf("Escriba las ventas semanales brutas: "), scanf("%f", &almacen);
                printf("Su salario es de %.2f\n", 250 + 5.7 * almacen);
                break;
            case 4:
                printf("Escriba la cantidad de piezas producidas: "), scanf("%d", &cantidad_item); // reutilizando la variable 'horas_trabajadas' para almacenar el valor entero con la cantidad de horas trabajadas
                printf("Esciba le pago por unidad producida: "), scanf("%f",&almacen);
                printf("Su salario es %.2f\n", (float)cantidad_item * almacen);
                break;
            case EOF:
                break;
            default:
                printf("\n==================\nEl código escrito no es válido\n=================\n\n");
        }

        printf("\n");

   } while (cod_nomina != EOF);

*/


























    // 4.27
    // Ternas pitagóricas menores que 500, utilizando un for de triple anidamiento
/*
    int lado1, lado2, hipotenusa;

    printf("Valores para los cuales las tenrnas pitagóricas menores que 500 son válidos");
    printf("\nHipotenusa    Cateto1    Cateto2\n");
    for(hipotenusa = 1; hipotenusa <= 500; hipotenusa++)
    {
        for(lado1 = 1; lado1 <= 500; lado1++)
        {
            for(lado2 = 1; lado2 <= 500; lado2++)
            {
                if(hipotenusa*hipotenusa == lado1*lado1 + lado2*lado2) printf("%13d    %7d    %7d\n",hipotenusa, lado1, lado2);
            }
        }
    }

*/




























    //4.26
    // Calcular el valor de la serie infinita para el cálculo de pi
    /*  const float numerador = 4, denomidaror = 1, signo = -1, number

        Mientras numero sea mayor que 3.14
            - Number += signo * numerador / denomidador
            - signo *= -1
            -  denomidador += 2
            - Imprimir counter_item y valor de number
            - If(number < 3.14159) temp314159 = counter_item -1
              sino si (number < 3.1415)  temp31415 = counter_item -1
              sino si (number < 3.141) temp3141 = counter_item -1
            - counter_item++
    */
/*
    const long double numerador = 4;
    long double denominador = 1, signo = 1;
    int  number = 0, counter_item = 0, bandera = 0, temp314159 = 0, temp31415 = 0, temp3141 = 0, temp314 = 0;
    int a, b, c, d;

    a = b = c = d = 0;

    printf("Terminos    Aproximacion\n");

    do
    {
        number += (int)signo * numerador / denominador * 1000000;
        signo *= -1;
        denominador += 2;

        printf("%8d    %d.%d\n", counter_item, number/1000000, number % 1000000 );

        if (number / 10 == 314159 && a == 0) temp314159 = counter_item , bandera++, a++;
        if (number / 100 == 31415 && b == 0) temp31415 = counter_item , bandera++, b++;
        if (number / 1000 == 3141 && c == 0) temp3141 = counter_item , bandera++, c++;
        if (number / 10000 == 314 && d == 0) temp314 = counter_item , bandera++, d++;
        if (bandera == 4) break;
        counter_item++;

    }while(1);

    printf("Se tienen que utilizar %d para lograr una aproximacion menor que 3.14159\n", temp314159);
    printf("Se tienen que utilizar %d para lograr una aproximacion menor que 3.1415\n", temp31415);
    printf("Se tienen que utilizar %d para lograr una aproximacion menor que 3.141\n", temp3141);
    printf("Se tienen que utilizar %d para lograr una aproximacion menor que 3.14\n", temp314);
*/





























    // 4.25
    // Escribir tabla de equivalentes decimales, bianrios, octales y hexagecimales
/*
    int decimal = 0, number, exponente, almacenamiento_binario = 0, almacenamiento_octal = 0, almacenamiento_hexagecimal = 0, temporal_octal = 0;

    printf("Decimal    Binario    Octal    Hexagecimales\n");

    while (decimal <= 16)
    {
        printf("%-7d",decimal);

        for(number = decimal, exponente = almacenamiento_binario = 0; number / 2 != 0 || number % 2 != 0; number /= 2, exponente++ )
            almacenamiento_binario += number % 2 * (int)pow(10, exponente);
        printf("    %-7d",almacenamiento_binario);

        printf("    %5o", decimal);
        printf("    %13X", decimal);
        printf("\n");
        decimal++;
    }
*/
























    // 4.23
    //  Cálculo del interés compuesto utilizando solamente enteros y las operaciones de división y resto
/*
    int year, amount, principal = 1000, rate =  5;

    printf("%4s%21s\n", "Year", "Amount on deposit");

    for(year = 1; year <= 10; year++)
    {
        amount = (int) ( principal * pow(1 + (float)rate/100, year) * 100 );
        //printf("%d\n",amount);
        printf("%4d%10d%c%-10d\n",year, amount/100, '.', amount%100);
    }
*/




























    // 4.22
    // Cambiar el programa de la figura 4.7, de forma que se pueda calcular el promedio
/*
    int grade;
    int aCount = 0, bCount = 0, cCount = 0, dCount = 0, fCount = 0;
    double prom;

    printf("Enter the letter grades.\n");
    printf("Enter the EOF character to end input.\n");

    while( (grade = getchar() ) != EOF)
    {
        switch (grade)
        {
            case 'A': case 'a':
                ++aCount;
                break;
            case 'B': case 'b':
                ++bCount;
                break;
            case 'C': case 'c':
                ++cCount;
                break;
            case 'D': case 'd':
                ++dCount;
                break;
            case 'F': case 'f':
                ++fCount;
                break;
            case '\n': case ' ':
                break;
            default:
                printf("Incorrect letter grade entered.");
                printf(" Enter a new grade.\n");
                break;
        }
    }

    printf("\nTotals for each letter grade are:\n");
    printf("A: %d\n",aCount);
    printf("B: %d\n",bCount);
    printf("C: %d\n",cCount);
    printf("D: %d\n",dCount);
    printf("F: %d\n",fCount);


    // para calcular el promedio voy a asignar a cada nota un valor numérico del 1 al 5, de ese modo al hallar el promedio
    // tendré una aproximación de entre cuales notas está la nota promedio
    // si numero < n.5 donde n = [1 2 3 4] entoncecs la nota promedio es la que corresponde a n, sino pues n+1
    // Secuencia de prueba: A B C C A D F C E D A B
    prom = (1 * (float)aCount + 2 * bCount + 3 * cCount + 4 * dCount + 5 * fCount)/(aCount + bCount + cCount + dCount + fCount);

//  printf("%lf", prom);
    prom *= 10;
//  printf("%lf", prom);

    if( (int)prom < 15 ) printf("La nota promedio es A");
    else if( (int)prom < 25 ) printf("La nota promedio es B");
    else if( (int)prom < 35 ) printf("La nota promedio es C");
    else if( (int)prom < 45 ) printf("La nota promedio es D");
    else if( (int)prom <= 50) printf("La nota promedio es F");

   */




















    // 4.21
    /*int counter = 1;

    for(; counter <= 10; counter++) printf("%d\n",counter);
    */




















    // 4.19
    // Calcular el valor de menudeo de todos los producto de la semana mediante un enunciado stwich
    /* Mientras numberProducto sea distinto de EOF
            - Escriba el numeroProducto, -1 para terminar
            - Escriba la cantidad vendida en el día
            - stwich(numeroProducto)
                    ~ case 1: total1 += precio* cantVendida
                    ~ case 2: total2 += precio* cantVendida
                    ~ case 3: total3 += precio* cantVendida
                    ~ case 4: total4 += precio* cantVendida
                    ~ case 5: total5 += precio*
                    ~ case -1: total += total1 + total2....
                    ~ default
       IMprimir tabla con valores
    */
/*
    int productID = 1, buys, buys1, buys2, buys3, buys4, buys5, buys_all;
    float total1, total2, total3, total4, total5, total_all;

    total1 = total2 = total3 = total4 = total5 = total_all = 0;
    buys1 = buys2 = buys3 = buys4 = buys5 = buys_all = 0;

    while(productID != EOF)
    {
        printf("\nEscriba el ID del producto[1 2 3 4 5] y la cantidad vendida, '-1 -1' para finalizar: "), scanf("%d%d", &productID,&buys);

        if(buys < -1) productID = 6;

        switch(productID)
        {
            case 1:
                buys1 += buys;
                total1 = 2.98 *  buys;
                break;
            case 2:
                buys2 += buys;
                total2 = 4.50 * buys;
                break;
            case 3:
                buys3 += buys;
                total3 = 9.98 * buys;
                break;
            case 4:
                buys4 += buys;
                total4 = 4.49 * buys;
                break;
            case 5:
                buys5 += buys;
                total5 = 6.87 *  buys;
                break;
            case -1:
                total_all = total1 + total2 + total3 + total4 + total5;
                printf("Product_ID\tPrecio al menudeo\tCantidad vendida\tTotal_menudeo\n");
                printf("%10d\t%17.2f\t%16d\t%13.3f\n",1, 2.98, buys1, total1);
                printf("%10d\t%17.2f\t%16d\t%13.3f\n",2, 4.50, buys2, total2);
                printf("%10d\t%17.2f\t%16d\t%13.3f\n",3, 9.98, buys3, total3);
                printf("%10d\t%17.2f\t%16d\t%13.3f\n",4, 4.49, buys4, total4);
                printf("%10d\t%17.2f\t%16d\t%13.3f\n",5, 6.87, buys5, total5);
                printf("\t\t\t|| Total menudeo semana anterior: %.3f", total_all);
                break;
            default:
                printf("El número escrito no coincide con ninguna de las opciones");
        }


    }
*/































    // 4.18
    // Crear gráfico de barra con asteríscos
    /*  Escriba 5 números entre 1 y 30(&numberAster)
        Mientras contadorBarras sea menor que 5:
            - si numberASter está dentro del rango [1 <= numberAster <= 30]
                | para numberAster , mientras mumberAster >= 0; numberAster--
                    ~ Imprimer '*'
              sino 'Numero fuera del rango', contadorBarras = 5, continue

    */
/*
    int stickCounter = 0, numberAster=1;

    printf("Write 5 numbers between 1 to 30: ");

    do
    {
        scanf("%d", &numberAster);
        if(numberAster < 1 || numberAster > 30) continue;

        while(printf("*"), --numberAster > 0);

        printf("\n");
        numberAster = 1;
    }while(++stickCounter < 5);
*/
    //if(scanf("%d",&numberAster) || !(scanf("%d",&numberAster))) printf("You wrote more than 5 numbers\n");




























    // 4.17
    // Clientes con límite de crédito excedido
    /* Mientras cantCLientes <=3
            - escriba el número de la cuentad del cliente (%LLU)
            - escriba el crédito del clientes antes de la recesión
            - escriba el saldo actual del cliente
            - Sí saldo actual mayor que créditoRecesión/2
                | El saldo del cliente excede el nuevo límite de crédito
    */
/*
   unsigned long long idAccount;
   int numberClients = 1;
   float credit_before_recesion, to_pay;

   do
   {
    printf("Write the account's ID: "), scanf("%llu", &idAccount);
    printf("Write the client's credit before recesion: "), scanf("%f",&credit_before_recesion);
    printf("Write the client's amount to pay: "), scanf("%f", &to_pay);
    printf("The new credit limit is %.2f\n\n", credit_before_recesion/2);

    if(to_pay > credit_before_recesion/2) printf("Credit limit exceded\n\n");

   } while (numberClients++ < 3);
   */































    // IMprimir secuencias de aster�scos
    // vía 1
 /*
    int contadorAster, contadorEspacio, contadorFilas, contadorBloque, a, b;

    for(contadorBloque = 1; contadorBloque <= 4; contadorBloque++)
    {

        for(printf("\n"), contadorFilas = 1; contadorFilas <= 10; contadorFilas++)
        {
            switch(contadorBloque)
            {
                case 1:
                    for(contadorAster = 1; contadorAster <= contadorFilas; contadorAster++ ) printf("*");
                    break;
                case 2:
                    for(contadorAster = 10, contadorEspacio = contadorFilas - 1; contadorAster > contadorEspacio ; contadorAster-- ) printf("*");
                    break;
                case 3:
                    for(contadorEspacio = contadorFilas - 1; contadorEspacio > 0; contadorEspacio--) printf(" ");
                    for(contadorAster = 10 - contadorFilas + 1; contadorAster > 0 ; contadorAster-- ) printf("*");   // es un caracter y ponerle a la cadena de conversion de formato %-10c
                    break;
                case 4:
                    for(contadorEspacio = 10 - contadorFilas; contadorEspacio > 0; contadorEspacio--) printf(" ");
                    for(contadorAster = contadorFilas; contadorAster > 0 ; contadorAster-- ) printf("*");   // es un caracter y ponerle a la cadena de conversion de formato %-10c
                    break;
            }

            printf("\n");
        }
        printf("\n");
    }
*/































    // 4.15
    // Calcular la tasa anual de inter�s en un per�odo de 10 a�os en una cuenta de ahorros
    /* Mientras dinero >=0
            - Escriba la cantidad de dinero a invertido, n�mero negativo para finalizar:
            - Escriba la tasa anual de inter�s que escogi�, escriba -1 para solicitar todas el c�lculo con todas las tazas
            - Escriba la cantidad de a�os


*/
/*
    int year = 1,tasa;
    float dinero,a;

    do
    {
        printf("Escriba la cantidad de  dinero invertido, n�mero negativo para finalizar: "), scanf("%f",&dinero);

        if(dinero >= 0)
        {
            printf("Escriba la tasa anual de inter�s, -1 para calcular todas la tasas [5 6 7 8 9 10 -1]: "), scanf("%d",&tasa);
            printf("Escriba la cantidad de a�os: ");

            if (tasa == 5 || tasa == 6 || tasa == 7 || tasa == 8 || tasa == 9 || tasa == 10 || tasa < 0)
            {
                scanf("%d",&year);

                tasa < 0 ? printf("Annos\tdepFin_5\tdepFin_6\tdepFin_7\tdepFin_8\tdepFin_9\tdepFin_10\n") : printf("Annos\tdepFin_%.2d\n",tasa);

                for(printf("\n"); year >=1 ; --year )
                {
                    if(tasa < 0)
                    {
                        for(tasa = 5, printf("%3d\t",year); tasa <= 10; printf("%-10.2f\t",dinero * pow(1 + (float)tasa/100, year)), ++tasa);
                        tasa = -1;
                        printf("\n");
                    }

                    else printf("%d\t%-10.2f\n",year, dinero * pow(1 + (float)tasa/100, year));
                }
                printf("\n");
            }
            else {printf("\n======================\nLa tasa escrita no est� permitida\n====================\n\n"); continue;}

        }

    }while(dinero >= 0);
*/































    // 4.14
    // Calcular el factorial de los enteros del 1 al 5
/*//Modo 1
    long long number = 1, product =1;

    do
    {
        printf("Write a # between 1 to 5, -1 to end: ");

        for(scanf("%Lu",&number); number > 0; product *= number, number--)
        {
            if(product < 0) {printf("El factorial es demasiado grande para el tipo de dato entero\n\n"); number = 1; break;}
        }


        if(number != EOF && number == 0) printf("El factorial es: %Lu\n", product);


    }while(product = 1, number != EOF);
*/

    //Modo 2
/*
    int number = 1, product =1;

    printf("No\tFactoriales\n");
    for(number; number <= 5; number++,product *= number)
    {
            printf("%d\t%d\n",number,product);
    }
*/

















    // 4.13
    // Calcular el producto de los enteros impares del 1 al 15
/*
    int number  = 1, product = 1;

    do
      {
        product *= number;
        number += 2;
      }
    while(number <= 15);

    printf("%d", product);
*/




















    // 4.12
    // Suma todos los n�meros del 2 al 30
/*
    int number = 2, sum = 0;

    do
        sum += number;
    while(++number <= 30);

    printf("Sum %d\n",sum);
*/
























    // 4.11
    // Localizar el valor m�s peque�o de un grupo de enteros, donde el primer n�mero especifica la cantidad de elementos de la lista
    /* Mientras n�mero sea diferentes de EOF
            -Escriba los n�meros enteros donde el primer n�mero va a identificar la cantidad de enteros  analizar
             Si escribe un n�mero mayor que 2147483647 el sistema lo leer� como negativo
             Si number > 4294967295 el sistema lo leer� como cero
             Escriba -1 para finalizar las iteraciones
            -Para el n�mero le�do,counter = number que tiene que ser distinto de -1, menor que 2147483647 y  counter > 0, counter--
                | si minNumber > number -----> minNumber = number

*/
/*
    int number = 1, counter, minNumber = 2147483646;

    while(number != EOF)
    {
        counter = number = 0;
        minNumber = 2147483647;

        printf("Escriba los n�meros enteros donde el primer n�mero va a identificar la cantidad de enteros  analizar\n");
        printf("Si escribe un n�mero mayor que 2147483647 el sistema lo leer� como negativo\n");
        printf("Si number > 4294967295 el sistema lo leer� como cero\n");
        printf("Escriba -1 para finalizar las iteraciones: \n");

        for(scanf("%d",&number), counter = number, printf("Escriba %d n�meros, si escriba m�s de esa cifra pasar�n como la siguiente iteraci�n como valores\n",counter); number >= 0 && counter > 0; counter--)
        {
            scanf("%d",&number);

            if(minNumber > number) minNumber = number;
        }

        if(number == EOF) continue;

        if( number >= 0) printf("El menor n�mero es %d\n\n", minNumber);
        else printf("Los numeros negativos no est�n permitidos, vuelva a escribir la lista\n\n");

    }
*/



















    //4.10
    // Leo una serie de n�meros el �ltimo n�mero es el centinela 9999
    /* mientras n�mero sea distinto de 9999
            - sum += n�mero
            -  countador++
            - tomar valor de teclado
       Imprimir promedio igual a sum/contador

    */
/*
    int number=1, contador = 0, sum = 0;

    while( number != EOF)
    {
        printf("Escriba la serie de n�meros a los cuales desea hayarle el promedio,\n (al teminar la secuencia escriba 9999 y -1 para fin): ");

        for(scanf("%d",&number); number != 9999; )
        {
            if(number == EOF) break;
            sum += number;
            scanf("%d",&number);
            contador++;

            if(number < 0 && number != EOF)
            {
                printf("Los n�meros negativos no son v�lidos\n\n");
                sum = contador = 0;
                break;
            }

        }

        if(number == EOF)continue;

        if(number == 9999)
        {
            if(contador != 0) printf("\nEl promedio es %.2f\n\n", (float)sum/contador), sum = contador = number = 0;
            else printf("Fin\n");
        }

    }
*/














    // 4.9
/*
    unsigned long int counter, number, sum = 0;

    for(scanf("%d", &counter); counter > 0; scanf("%d",&number), printf(" %3d",number), sum += number, counter--);

    printf("\n%d", sum);
*/














   /* // 4.7
    int x;

    // a
    for (x = 1; x <= 7; printf("%3d", x), x++);

    // b
    for (printf("\n\n"), x = 3; x <= 23; printf("%3d",x), x += 5);

    // c
    for (printf("\n\n"), x = 20; x >= -10; printf("%3d",x), x -= 6);

    // d
    for (printf("\n\n"), x = 19; x <= 51; printf("%3d",x), x += 8);
*/










    // 4.5
    // C
    /*int intVal;
    char charVal;

    scanf("%d",&intVal);
    charVal = getchar();
    printf("INteger: %d\nCharacter: %c\n",intVal,charVal);
    */
/*
    float x;

    for (x = .000001 ; x <= .0001; x += .000001)
        printf("%.7f\n",x);
*/













    // Ejercicio 4.3
    // A)
/*
    int count, sum;

    for(count = 1, sum = 0 ; 99 >= count ; printf("count %d\n",count), sum += count, count += 2);

    printf("%d",sum);

    // B)
    printf("\n\n%15.1f\n",333.546372);
    printf("%15.2f\n",333.546372);
    printf("%15.3f\n",333.546372);
    printf("%15.4f\n",333.546372);
    printf("%15.5f\n",333.546372);
    printf("\n\n%-15.1f\n",333.546372);
    printf("%-15.2f\n",333.546372);
    printf("%-15.3f\n",333.546372);
    printf("%-15.4f\n",333.546372);
    printf("%-15.5f\n",333.546372);

    // C)
    printf("\n\n\n%10.2f", pow(2.5,3));

    // D)
    /*int x=0;
    printf("\n\n\n\n");
    while(x++ < 20)
    {
        x % 5 != 0 ? printf("%3d",x) : printf("%3d\n",x);
    }
*//*
    // D)
    printf("\n\n\n\n");
    int x;
    for( x = 1; x <= 20; x % 5 != 0 ? printf("%3d",x) : printf("%3d\n",x), ++x);

*/








   /* int n;
    int p,r,a;
*/

/*    printf("Escriba la cantidad invertida: ");
    scanf("%f",&p);
    printf("Escriba la taza de inter�s: ");
    scanf("%f",&r);
    printf("Escriba la cantidad de a�os: ");
    scanf("%d",&n);

    for( n += 1, a = 0 ; n > 0; a != 0 ? printf("%-20d\t%-20f\n",n,a): printf("Year\tAmount on deposit\n"), --n, a = p * pow(1+r,n));
*/
/*
 for(p = 0; p < 10; p++  )
 {
     if(p== 5) continue;
     printf("%10d",p);
 }
*/
/*

    return 0;
}
*/
