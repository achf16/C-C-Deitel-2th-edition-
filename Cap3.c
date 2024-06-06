/*#include <stdio.h>
#include <math.h>

main()
{*/
    //Ejercicio 3.47
    // A)
/*
    int n=8, almacen = 1;

    while(n > 0)
    {
        if( n == 0)
        {
            n++;
            printf("El factorial es: %d\n-------------------\n",almacen);

        }
        almacen = 1;

        printf("Escriba el n�mero, negativo para salir\n(si el n�mero es mayor que 2147483647 negativo)\n(si n�mero mayor que 4294967295 cero): ");
        scanf("%d",&n);

        if (n == 0) printf("\n\n Si escribi� un numero mayor que 4294967295, el sistema lo asumi� como cero\n----------\n");

        if( n < 0) printf("El n�mero es negativo: %d\n", n);

        while(n > 0 && almacen > 0)
        {
            //printf("%d \n",almacen);
            almacen *= n--;
            //printf("N %d\n------\n",n);
        }

        if(almacen <= 0)
        {
            printf("El factorial es demasiado grande para ser calculado por el sistema.\n Intente con otro n�mero.\n\n");
        }

    }
*/
    // B)
/*
    float n=8, almacen = 1, y, euler = 1;

    while(n > 0)
    {
        printf("Escriba el n�mero, negativo para salir\n(si el n�mero es mayor que 2147483647 negativo)\n(si n�mero mayor que 4294967295 cero): ");
        scanf("%f",&n);

        if (n == 0) printf("\n\n Si escribi� un numero mayor que 4294967295, el sistema lo asumi� como cero\n----------\n");

        if( n < 0) printf("El n�mero es negativo: %f\n", n);

        y = n;
        while(y > 0)
        {
            while(n > 0)
            {
                almacen *= ( 1 / n );
                --n;
            }

            euler += almacen;
            almacen = 1;
            --y;
            n = y;
        }

        if( n == 0 && euler > 1)
        {
            n++;
            printf("El valor de 'e' es: %f\n-------------------\n",euler);

        }

        euler = 1;
    }
*/
/*
    // C
    float almacen = 1, euler = 1;
    int n=8, y;
    while(n > 0)
    {
        printf("Escriba el n�mero del exponente, negativo para salir\n(si el n�mero es mayor que 2147483647 negativo)\n(si n�mero mayor que 4294967295 cero): ");
        scanf("%d",&n);

        if (n == 0) printf("\n\n Si escribi� un numero mayor que 4294967295, el sistema lo asumi� como cero\n----------\n");

        if( n < 0) printf("El n�mero es negativo: %d\n", n);

        y = n;
        while(y > 0)
        {
            while(n > 0)                  //esta estructura de control calcula los factoriales
            {
                almacen *= ((float)y / n );
                --n;
            }

            euler += almacen;
            almacen = 1;
            --y;
            n = y;
        }

        if(euler <= 0) printf("El valor de euler es demasiado grande para ser calculado por el sistema.\n Intente con otro n�mero.\n\n");

        if( n == 0 && euler > 1)
        {
            n++;
            printf("El valor de 'e' es: %f\n-------------------\n",euler);

        }

        euler = 1;
    }
*/















    // Ejercicio 3.46
    //  Cifrado de los datos transmitidos
    /*  Mientras number sea mayor que 1000 y menor que 9999
            - Escriba el entero que desea cifrar, si es mayor o menor de 4 digitos terminar� el programa:
            - Mientras number sea mayor que 1000 y menor que 9999
                | d1 = ((number/100) % 10 + 7) % 10
                | d2 = (number/1000) + 7) % 10
                | d3 = (number%10 + 7) % 10
                | d4 = ((number/100)%10 + 7) % 10
                | number= d1*1000 + d2*100 + d3*10 + d4


    *//*
    int number=1555, d1,d2,d3,d4, digitCounter = 4, estado;

    //printf("%d",digitCounter);
    //printf("%d",digitCounter--);
    //printf("%d",digitCounter);
    while(number >= 1000 && number <= 9999)
    {
        printf("Escriba el n�mero, fuera de este rango number >= 1000 && number <= 9999 para FIN: ");
        scanf("%d",&number);

        if(number >= 1000 && number <= 9999)
        {
            printf("\nEscriba 1 codificar // 2 decodificar: ");
            scanf("%d",&estado);

            if(estado == 1)
            {
                d1 = ((number/1000) + 7) % 10;
                d2 = ((number/100)%10 + 7) % 10;
                d3 = ((number/10) % 10 + 7) % 10;
                d4 = (number%10 + 7) % 10;

                number= d3*1000 + d4*100 + d1*10 + d2;
                printf("El n�mero cifrado es %d\n---------------------\n\n",number);
            }

            while( estado == 2 && digitCounter > 0)
            {   //printf("%d",digitCounter);
                if(digitCounter == 4)  number % 10 < 7 ? (d2 = number % 10 + 3) : (d2 = number % 10 - 7);

                if(digitCounter == 3)  number % 10 < 7 ? (d1 = number % 10 + 3) : (d1 = number % 10 - 7);

                if(digitCounter == 2)  number % 10 < 7 ? (d4 = number % 10 + 3) : (d4 = number % 10 - 7);

                if(digitCounter == 1)  number % 10 < 7 ? (d3 = number % 10 + 3) : (d3 = number % 10 - 7);

                --digitCounter;
                number /= 10;
            }
            //printf("\n%d",digitCounter);

            if(digitCounter == 0)
            {
                number = d1*1000 + d2*100 + d3*10 + d4;
                printf("El n�mero decifrado es: %d\n---------------\n\n", number);
                digitCounter = 4;
            }

        }


    }


*/














   // Ejercicio 3.44
   // Determinar si tres v valores introducidos pueden ser lados de un tri�ngulo
/*
   float hip, cat1, cat2;

   printf("Escriba la hipotenusa ");
   scanf("%f", &hip);
   printf("Cateto 1 ");
   scanf("%f", &cat1);
   printf("Cateto 2 ");
   scanf("%f", &cat2);

   printf("%f\n", hip*hip);
   printf("%f\n",cat1 * cat1 + cat2 * cat2);
   if( hip*hip == cat1 * cat1 + cat2 * cat2) printf("Si");
*/


















    // Ejercicio 3.42
    // Di�metro, circunferencia y �rea
/*
    float r, pi = 3.14159;

    printf("Escriba el radio de una circunferencia ");
    scanf("%f",&r);
    printf("Di�metro %f\nCircunferencia %f\n�rea %f\n", 2*r , 2*pi*r ,pi*r*r);

*/














    // Ejercicio 3.41
    // Ciclo infinito
    /* Lo que sucede es que sale del ciclo de manera autom�tica para el caso que planteo pues como el n�mero m�ximo
    que puede tener un entero positivo es 2147483647 que equivale a 0b(1x31) y hasta 0b(1x32) para los numero negativos,
     cualquier n�mero mayor que ese lo leer� como cero, debido a que la multiplicaci�n por dos es como correr un lugar
     hacia la derecha todos los digitos y ocupar con cero el menos significativo
    int x=1;

    while(x)
    {
        printf("%d\n",x);
        x *= 2;
    }






    // Ejercicio 3.40
    // Desplegar el patron solo usando los tres Printf que me ofrecen
    /* Mientras row sea menor que 8
            -Mientras column++ <= 16
                |  Si column % 2 != 0 imprime '*' sino imprime ' '
            -Si row%2 == 0
                | column = -1
             sino
                | column = 0
            -Imprime '\n'

*/
/*
    int row = 0, column = 0;

    while(row++ < 8)
    {
        while(column++ < 16) column % 2 != 0 ? printf("*") : printf(" ");

        row % 2 != 0 ? (column = -1 ) : (column = 0);

        printf("\n");

    }
*/




















    // Ejercicio 3.39
    // Introducir un entero y buscar cuantos digitos del n�mero son 7
    /* Mientras el numero sea menor que 0b(1x31) y mayor que cero y digitCounter++<10
            -Escriba el n�mero que desea analizar
            -digitCounter = 0;
            -counter7 = 0;
            -Mientras el numero sea menor que 0b(1x31) y mayor que cero y digitCounter++<10
                | Si numero%10 == 7
                    ~contador7 ++
                |n�mero/=10
        Si el numero sea menor que 0b(1x31) y mayor que cero
            -El numero total de 7s es: counter7
    *//*
    int number = 1, digitCounter = 0, counter7 = 0;

    while(number <= 2147483647 && number >= 0)
    {
        printf("Escriba el numero que desea analizar, si escribe un numero negativo o mayor que 2147483647 'FIN': ");
        scanf("%d",&number);
        digitCounter = 0;
        counter7 = 0;

        while(number <= 2147483647 && number >= 0 && digitCounter++ < 10)
        {
            if(number%10 == 7) counter7++;

            number /= 10;
        }

        if(number <= 2147483647 && number >= 0)printf("El numero total de 7s es %d\n",counter7);
    }
*/

















  /*Ejercicio 3.38


  //via 1
    int row = 0, column = 0;

    while(row++ < 10)
    {
        column = 0;

        while(column++ <10)printf("*");

        printf("\n");
    }

    printf("\n-----------------\n");

    //v�a 2 (Sugerida en el ejerciocio)

    int contador=0;

    while(contador++ < 100)
    {
        printf("*");
        if(contador % 10 == 0 ) printf("\n");
    }
*/









    /*Ejercicio 3.7
    int x=0,y=0;
        while(x++ <= 3000000)
        {
            //printf("Y %d\n",y);
            y++;
            (x ==0 | y == 1000000) ? printf("1\n") && ( y == 1000000 )? (y=0) :-7 : -7;
            //printf("Y %d\n---------------\n\n",y);
            //printf("X %d\n",x);
        }
*/











    //Ejercicio 3.36
    //Convertir un # binario en decimal
    /* Como desconosco el tama�o del n�mero que ser� introducido por teclado,tengo q colocar un centinela
       El n�mero recibido debe ser menor q (1x10)1111111111, pues de lo contrario el tipo de dato entero lo lee como negativo
       Mientras n�mero sea menor o igual que (1x10)1111111111 && mayor que 0
            - Escriba el n�mero que desea convertir a binario, si el numero es mayor o igual q (1x10) o menor que cero 'fin'
            - Mientras contador sea menor que 10
                | sum+= ( n�mero%10)*2
                | almacenno n�mero/10 en n�mero
            - Imprimir sum
*/
/*
    int x=1,sum=0, contador;
    //printf("%d",1111111111111111111111111111111111111111111111111111);


    while(x>=0 && x <= 1111111111)
    {
        printf("Escriba el nu'mero Binario -> Decimal, para terminar  0 > numero > 1111111111 : ");
        scanf("%d",&x);

        if(x>=0 && x <= 1111111111)
        {
            contador = 0;
            sum = 0;

            while(contador <= 10 && (x % 10 == 1 || x % 10 == 0))
            {
                sum += (x%10)*pow(2,contador++);
                x /= 10;
                //printf("SUM %d\tX %d\n",sum,x);
            }

            if(x%10 == 1 || x%10 == 0) printf("EL n�mero en decimal es %d\n--------------\n",sum);
            else printf("El n�mero no es binario\n-------------------\n");

       }
    }


*/












    //Ejercicio 3.35
    //Saber si un n�mero de 5 digitos es pal�ndromo
    /* Tomar el n�mero y validar que el numero es de 5 cifras
       Separar la primera y la �ltima cifra del n�mero

       Si son iguales
            |separar la segunda y penultima cifra del n�mero
            |verificar, Si son iguales
                            *palindromo
                        sino *no es un pal�ndromo
        sino No es un palindromo
*/
/*
    int number=12345;


    while(number <= 99999 && number >= 10000)
    {
        printf("Escribe el # de 5 cifras,escribe un # de cifras diferente a 5 para terminar: ");
        scanf("%d",&number);
        if(number <= 99999 && number >= 10000)(number / 10000 == number % 10&& ((number%10000)/1000) == (number%100)/10) ? printf("Pal�ndromo\n\n")
                                                                                                                         : printf("No es pal�ndromo\n\n");

    }
*/






















    //Ejercicio 3.34

/*
    int row = 0, column = 0, a;

    printf("Escriba el valor del lado del cuadrado ");
    scanf("%d",&a);

    while(row++ < a)
    {
        column = 0;
        while(column++ < a)
        {
            row == 1 || row == a ? printf("*"): column == 1 || column == a ? printf("*"): printf(" ");
        }
        printf("\n");
    }
*/










    //Ejercicio 3.33
    /*int row=1, column=1, a;

    printf("Escriba el valor del lado del cuadrado ");
    scanf("%d",&a);

    while(row++ <= a)
    {
        column=1;

        while(column++ <= a) printf("*");

        printf("\n");
    }*/

















    // Ejercicio 3.28
        /*
    int alumnos=0, aprobados = 0, desaprobados = 0, A;

    while(alumnos < 10 )
    {
        printf("Entre 1 aprob/ 2 fallo\n");
        scanf("%d",&A);

       A == 1 ? ++aprobados && ++alumnos : A == 2 ? ++desaprobados && ++alumnos : printf("tu eres mongo\n");

       printf("\n--------------\nALUMNOS REGISTRADOS %d\n-------------\n",alumnos);
    }

    printf("passed %d\n",aprobados);
    printf("failed %d\n",desaprobados);
*/














    // Ejercicio 3.26
/*
    int x=0;
    printf("A\tA+2\tA+4\tA+6\t\n");
    while((x+=3) <= 15) printf("%d\t%d\t%d\t%d\t\n", x, 2+x, 4+x,6+x);

*/












    //Ejercicio 3.25

    /*
    int x=0;
    printf("N\t10*N\t100*N\t1000*N\t\n");
    while(x++ < 10) printf("%d\t%d\t%d\t%d\t\n", x, 10*x, 100*x,1000*x);

*/













    // Ejercicio 3.24
    // Sacar el mayor de un grupo de 10 n�meros introducidos en por teclado
    /* *Mientras cantidad de numeros introducido sea menor que 10
            -Escribe el n�mero
            -Si n�mero es mayor q MAYOR, almacena n�mero en mayor
       *Imprima el Mayor
       */
/*
    int number, largest=0, counter=0;

    while(counter++ < 10)
    {
        printf("Escribe el n�mero ");
        scanf("%d",&number);

        if(number > largest) largest=number;
    }

    printf("El mayor es %d",largest);
*/











    // Ejercicio 3.23
/*
    int x=0;

    while(x++ <10) printf("%d   ",x);

*/
















    // Ejercicio 3.22
    // Diferencia entre --x y x--
/*
    int x=10;

    printf("Posdecrementar\n");
    printf("X %d\n",x);
    printf("X++ %d\n",x--);
    printf("X %d\n",x);

    printf("\nPredecrementar\n");
    printf("X %d\n",x);
    printf("--X %d\n",--x);
    printf("X %d\n",x);
*/















    // Ejercicio 3.21
    // C�lculo de la n�mina bruta
    /* Mientras la cantidad de horas trabajadas sean diferentes de cero
        -Entre el n�mero de horas trabajadas, -1 para terminar
        -Si la cantidad de horas trabajadas es diferente de -1
            | Entre la tasa de pago por hora para este trabajador
            | El salario ser� ----> horas trabajadas + 1.5*(horas trabajadas - 40 > 0 ? return horas trabajadas -40 : return 0);
            */
/*
    float horas_trabajadas=1,tasa;

    while(horas_trabajadas != -1)
    {
        printf("Entre el n�mero de horas trabajadas, -1 para terminar: ");
        scanf("%f",&horas_trabajadas);

        horas_trabajadas != -1 ? printf("Entre la tasa de pago por hora ")
                               && scanf("%f",&tasa)
                               && horas_trabajadas - 40 > 0 ? printf("Salario %.2f\n\n", horas_trabajadas*tasa + tasa*1.5*(horas_trabajadas-40))
                                                              :printf("Salario %.2f\n\n", horas_trabajadas*tasa)
                               :printf("");
    }
*/






















    // Ejercicio 3.20
    // C�lculo del inter�s simple
    /* Minetras cantidad prestada sea distinta de -1
            -Entre cantidad prestada
            -Si cantidad pr�stada es distinta de -1
                | Entre tasa de inter�s
                | Entre los dias para la devoluci�n
                | Imprimir El interes es --->la cantidad prestada*tasa*dias/365
                */
/*
    int principal=1,days;
    float rate;

    while(principal != -1)
    {
        printf("Entre la cantidad prestada ");
        scanf("%d",&principal);

        if(principal != -1)
        {
                printf("Tasa de inter�s ");
                scanf("%f",&rate);
                printf("Dias para la devoluci�n ");
                scanf("%d",&days);
                printf("El inter�s es de %f\n", (float)principal*days*rate/365); //En la imagen que dan en el libro hay errores de c�lculo
        }

    }

*/

















    // Ejercicio 3.19
    // Pago por comisiones en una empresa qu�mica
    /* Mientras las ventas sean distintas de cero
            -Entre las ventas de la �ltima semana. -1 para terminar
            -Si ventas != -1
                |Imprimir el salario, salario = 200 + 9porciento de las ventas
                */
/*
    float ventas=1;

    while(ventas != -1)
    {
        printf("Entre las ventas de la ultima semana,-1 para terminar: ");
        scanf("%f",&ventas);
        if(ventas !=-1) printf("Salario %.2f\n\n", 200+ 0.09*ventas);
    }
*/






















    // Ejercicio 3.18
    // An�lisis si algun cliente ha excedido su cr�dito
    /* -Mientras el n�mero de la cuenta sea diferente que -1
            *Entre el n�mero de su cuenta, o marque -1 para terminar
            *Si el numero de la cuenta es diferente de -1
                | Entre el saldo a pagar inicial en el mes
                | Total de todos los elementos cargados en el mes(cosas compradas)
                | Total de los cr�ditos aplicados a la cuenta este mes
                | L�mite permitido de cr�dito
                | Nuevo Saldo= saldo inicial+creditos aplicados-elementos cargados
                | Si los credit.apl > l�mit del cr�dito o el nuevo saldo > el l�mite de cr�dito permitido
                    �Imprimir limite de cr�dito excedido
    */
/*
    float account=1, begining_balance, charge_elements, total_credit, credit_limit,balance;

    while(account !=-1)
    {
        printf("Enter your account number, -1 to end: ");
        scanf("%f",&account);

        if(account != -1)
        {
            printf("Saldo inicial ");
            scanf("%f",&begining_balance);
            printf("Total cargados ");
            scanf("%f",&charge_elements);
            printf("Total de cr�ditos ");
            scanf("%f",&total_credit);
            printf("Cr�dito permitido ");
            scanf("%f",&credit_limit);
            balance= begining_balance - total_credit + charge_elements;

            if(total_credit > credit_limit) printf("Cr�dito excedido, total de credito > que el l�mite de cr�dito \n");
            else if(balance > credit_limit) printf("Cuenta %.0f\nL�mite del cr�dito %.2f\nNuevo saldo %.2f\nCr�dito excedido\n",account,credit_limit,balance);

            printf("\n");
        }

    }
*/





















    // Ejercicio 3.17
    //Registro de las millas/gal+on de diferentes autom�viles, y c�lculo de la media.
    /* Como no conosco el n�mero de tanques a muestrar por tanto utilizar� un centinela
        -Mientras el gasolina en el tanque no sea -1
            *Escriba la cantiad de galones de gasolina del tanque, use -1 para indicar fin de las muestras
            *Si gasolina del tanque es distinto de -1
                |Escriba las millas recorridads
                |Total de galones de gasolina ser� igual al Total de galones anterior  m�s cantidad de gallones del tanque
                |Total de millas recorridas ser� igual al total de millas anterior m�s la cantidad de millas del nuevo veh�culo
        -Si total de gasolina en el tanque diferente de cero
            *Imprimir la cantidad de millas por galon

        */
/*
    float gasolina_actual, millas_actual,total_gasolina=0,total_millas=0;


    while(gasolina_actual != -1)
    {
        printf("Escriba la cantidad de gasolina, -1 para terminar: ");
        scanf("%f",&gasolina_actual);

        gasolina_actual != -1 ?
                            printf("Escriba la cantidad de millas: ")
                            && scanf("%f",&millas_actual)
                            && (total_gasolina += gasolina_actual)
                            && (total_millas += millas_actual)
                            && printf("La cantidad de millas por gal�n de este tanque es : %f\n\n",millas_actual/gasolina_actual)
                            : printf("");
    }

    if(total_gasolina)printf("La cantidad de millas/galones promedio fue : %f\n",total_millas/total_gasolina);

*/









    /* Ejercicio 3.15

    A)  Defino dos variable(A B), una para cada n�mero
        inicializo una variable suma en cero
        Obtengo de teclado los valores A y B
        Suma ser� igual a A m�s B
        Imprimo en pantalla

    B)  Defino dos variables(A B)
        Obtengo de teclado los valores de las mismas
        Si A es mayor que B imprimo "A mayor que B"
        Sino imprimo "B es mayor o igual q A"

    C)  Inicializo las variables A = 1, sum = 0

        Mientras A sea diferente de cero
            Imprimir en pantalla "escriba un numero entero, -1 para terminar"
            Recoger de teclado el n�mero y almacenarlo en A
            sum ser� igual a lo q tenia acumulado en sum m�s A
    */















    /* Ejercicio 3.14
    printf("Enter two numbers");
    p=x+y+z;

    if(m>=2v);else;

    scanf("%d%d%d",s,r,t);
*/











    /* Ejercicio 3.7 y 3.8

    int x,y,i=1,power=1;
    scanf("%d%d",&x,&y);

    while(i<=y)
    {
        power*=x;
        ++i;
    }

    printf("Power %d",power);
   */








    /* Ejercicio 3.5
    int x=1,
    sum=0;

    while(x<11)
    {
        sum+=x++;
        printf("%d\n",x);
    }
    printf("The sum is: %d",sum);
    */










    /*
    ejercicio 3.4
    int sum, x;

    x=1;
    sum=0;
    sum+=x;
    printf("The sum is: %d",sum);
    */








    /* Ejercicio 3.3
    z= x+y; ++x;
    product *=2;
    if(count > 10) printf("Count is graeter than 10\n");
    total-=--x;
    q%=divisor;
    printf("%.2f",123.4567);
    printf("$.3f",3.14159);

    */






    /* Ejercicio 3.2
    int x=0;

    x=x+1;
    x++
    ++x
    x+=1*/













    /*
    int alumnos=0, aprobados = 0, desaprobados = 0, A;

    while(alumnos < 10 )
    {
        printf("Entre 1 aprob/ 2 fallo\n");
        scanf("%d",&A);

       A == 1 ? ++aprobados && ++alumnos : A == 2 ? ++desaprobados && ++alumnos : printf("tu eres mongo\n");

       printf("\n--------------\nALUMNOS REGISTRADOS %d\n-------------\n",alumnos);
    }

    printf("passed %d\n",aprobados);
    printf("failed %d\n",desaprobados);
*/
    /* algunas pruebas realizadas durante la lectura del cap�tulo
    int a, b=0;

    scanf("%d",&a);
    a <= 50 ?
            printf("menor que 50\n") && printf("dos")
            : printf("mayor q 50 %s\n", a >= 60 ? "mayor que 60\n" : "menor que 60\n");

    while(a)
    {
        printf("escriba el valor de A: \n");
        scanf("%d",&a);

        a <= 80 ? printf("A\n") : a<= 100 ? printf("menor que 100\n") : printf("mayor que 100\n");

        printf("%s\n", a <= 80 ? "A\n" : a <= 100 ? "menor que 100\n" : "mayor que 100\n");
        printf("con dos comillas %d\tcon una comilla %d\n",'a',"a");

        b++ ? printf("\n----------------------\nEL valor de a es %d\n",b) : printf("EL valor de B es %d\n",b);

        printf("EL nuevo valor de a es %d\n-------------------\n\n",b);
    }*/

 /*   return 0;
}*/
