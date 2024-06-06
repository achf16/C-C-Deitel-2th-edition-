/* 
*Excercise 5.39 Hanoi Towers 
 ! Es importante tener en cuenta que: 
    *se tendrá inicialmente 3 postes y 4 discos
    *ningún disco mayor puede ser colocado sobre una menor
    *solo se pude mover un disco a la vez  
*
*/



/* Excercise 5.38 Fibonacci non-recursive*/
/* #include<stdio.h>
#include<limits.h>

int Fibonacci(int);
double Fibonacci_double(int);
int userEntry(int);
int menu (void);

int number;

int main() {return menu();}

int menu (void)
{
    while (1)
    {
        userEntry(1);
        switch (number)
        {
        case 1:
            // Inciso A    
            while(userEntry(2) == 1) 
            {
                if(number < 47) printf("Fibonacci(%d) = %d\n", number, Fibonacci(number));
                else printf("Fibonacci(%d) is too big to storage in an Integer\n",number);
            }
            break;
        case 2:
            // Inciso B
            number = 0;
            while ( number++, (unsigned int ) Fibonacci(number) <= INT_MAX);
            printf("The biggest Fibonacci number that can be printed by an integer is Fibonacci (%d) = %d\n", number - 1, Fibonacci( number - 1));
            break;
        case 3:
            // Inciso C
            number = 0;
            while (1) printf("%.0lf\n",Fibonacci_double(number++));
            break;
        case -1:
            goto exit;
        default:
            printf("Logic Error in code!\n");
            break;
        }
    }
    
    exit:
    return 0;
}

int Fibonacci(int n)
{
    int f0 = 0;
    int f1 = 1;
    int temp;
    
    if( n == 0) return 0;
    if( n == 1) return 1;

    for (int i = 2; i <= n; i++)
    {
        temp = f1 + f0;
        f0 = f1;
        f1 = temp;
    }
    return f1;
}

double Fibonacci_double(int n)
{
    double f0 = 0;
    double f1 = 1;
    double temp;
    
    if( n == 0) return 0;
    if( n == 1) return 1;

    for (int i = 2; i <= n; i++)
    {
        temp = f1 + f0;
        f0 = f1;
        f1 = temp;
    }
    return f1;
}

int userEntry(int flag)
{
    jump:
    if(flag == 1)
    {
        // Menu
        printf("Write a number to choose an option:\n1\tFibonacci(n)\n2\tBiggest Fibonacci number that can be printed by an integer\n3\tFibonacci(n) with double return\n-1\tExit\n::::__");
    }
    else printf("Write an integer number to find the Fibonacci(n) (-1 to end): ");
    
    if( (scanf("%d",&number)) == 1)
    {
        if(number < (flag == 1 ? 4 : INT_MAX) && number >= -1)
        {
            if(number == -1) return number; // exit
            else return 1;
        }
        else
        {
            printf("Out of range!\n");
            goto jump;
        }
    }
    else
    {
        printf("Wrong entry!\n");
        int c;
        while( (c = getchar()) != '\n' && c != EOF );
        goto jump;
    }

}
 */

/* Excercise  5.37 potenciación con recursión
*/
/* #include<stdio.h>
#include<limits.h>

long long int power(long, long);
int userEntry(void);
long userEntry_Validation(int);

long base, exponente;

int main()
{
    long long int temp_power;
    while (1)
    {
        
        if (userEntry() == 1)
        {
            temp_power = power(base, exponente);
            
            if(temp_power < LONG_MAX && temp_power > LONG_MIN) printf("The result of power( %ld , %ld ) is %lld\n\n", base, exponente, temp_power);
            else printf("Power is too big.\n");
        }
        else break;  
    }
    
    return 0;
}

int userEntry(void)
{
    printf("Writte two numbers(Negative Exponent two end): \n");
    
    if( (base = userEntry_Validation(1)) == -1) return -1; //parametro 1 significa que tomaré la base
    if ( (exponente = userEntry_Validation(2)) == -1) return -1;    //parametro 2 significa que tomaré el exponente
    
    return 1;   // validación exitosa
}

long userEntry_Validation(int x)
{
    int temp;
    long int number;
    
    scan:
    if( x == 1) { printf("Base: "); temp = scanf("%ld",&base); number = base;}
    else  { printf("Exponente: "); temp = scanf("%ld",&exponente); number = exponente;}

    if(temp == 1)    //comprobación de conversión de formato inválida
    {
        if(number < INT_MAX && number > INT_MIN)   // comprobación de fuera de rango
        {
            if( x == 1) return number;//base
            else if( number > 1) return number; // exponente
            return -1;  //break
        }
        else
        {
            printf("Out of range!\n");
            goto scan;
        }
    }
    else
    {
        printf("Wrong entry!\n");
        int c;
        while( (c = getchar()) != '\n' && c != EOF );
        goto scan;
    }
}

long long int power(long bs, long exp)
{
    if(exp == 1) return bs;
    else return power(bs, 1) * power(bs, exp - 1);
}
 */

/* Excersice 5.36 Búsqueda Binaria  analisis de que cualquier número entre 1-1000 puede lograrse en menos de 10 intentos*/
/* #include<stdio.h>
#include<stdlib.h>
#include<time.h>

void binarieSearch(void);
int User_reset_or_finish_validation(void);
void try_counter(int);

int main()
{   
    srand(time(NULL));
    binarieSearch();
    return 0;
}

void binarieSearch(void)
{
    int temp_number, number;
    int counter = 0;
    while (1)
    {
        number = 1 + rand()%1000;   //generando numero random entre 1-1000
        printf("I have a number between 1 and 1000.\nCan you guess my number?\nPlease type your first guess.");
        jump: printf("\nNumber: ");
        
        if( scanf("%d",&temp_number) == 1 ) //comprobación que la convesión del formato de entrada ha sido correcta
        {
            if (temp_number > 0 && temp_number <= 1000 )
            {
                counter++;  // contador de intentos
                if(temp_number < number){printf("Too low. Try again.\n"); goto jump;}
                if(temp_number > number){printf("Too high. Try again.\n"); goto jump;}
                if(temp_number == number)
                {
                    printf("Excellent! You guessed the number!\n");
                    
                    try_counter(counter);  // validación de si el usuario logró el numbero en menos de 10 intentos

                    printf("Would you like to play again (y or n)?  ");
                    if( User_reset_or_finish_validation() == 1 ) continue;
                    break;
                }
            }
            else{ printf("Out of range! Try again.\n"); goto jump;} //Fuera de rango
            
        }
        else    //limpiar buffer de entrada en caso de conversión de formato de scanf errónea
        {
            int c;
            while( (c = getchar()) != '\n' && c != EOF);
        }
    }
}

int User_reset_or_finish_validation(void)
{
    while (1)
    {   
        int k;
        while( (k = getchar()) != '\n' && k != EOF);    //limpieza del buffer, para evitar errores al recibir con getchar el el switch

        switch (getchar())
        {
            case 'y': case 'Y':
                return 1;
            case 'n': case 'N':
                return 0;
            default:
                printf("\nWrong entry! (y or n)");
                break;
        }
    }
}

void try_counter(int c)
{
    if(c < 10) printf("Either you know the secret or you got lucky!\n");
    else if(c == 10) printf("Ahah! You Know the secret!\n");
    else  printf("You should be able to do better!\n");
    return;
}
 */

/* Excersice 5.35 Búsqueda Binaria 
Para el algoritmo hay que tener en cuenta primeramente
    Primeramente genero un número aleatorio entre 1 - 1000
    Después el programa pide que se escriba un número
    Validación de entradas
    después dada la entrada responder en correspondencia a las 3 obciones dadas
    por lo que parece el programa no permite la salida del mismo hasta que se adivine el número*/
/* #include<stdio.h>
#include<stdlib.h>
#include<time.h>

void binarieSearch(void);
int User_reset_or_finish_validation(void);

int main()
{   
    srand(time(NULL));
    binarieSearch();
    return 0;
}

void binarieSearch(void)
{
    int temp_number, number;
    while (1)
    {
        number = 1 + rand()%1000;   //generando numero random entre 1-1000
        printf("I have a number between 1 and 1000.\nCan you guess my number?\nPlease type your first guess.");
        jump: printf("\nNumber: ");
        
        if( scanf("%d",&temp_number) == 1 ) //comprobación que la convesión del formato de entrada ha sido correcta
        {
            if (temp_number > 0 && temp_number <= 1000 )
            {
                if(temp_number < number){printf("Too low. Try again.\n"); goto jump;}
                if(temp_number > number){printf("Too high. Try again.\n"); goto jump;}
                if(temp_number == number)
                {
                    printf("Excellent! You guessed the number!\nWould you like to play again (y or n)?  ");
                    if( User_reset_or_finish_validation() == 1 ) continue;
                    break;
                }
            }
            else{ printf("Out of range! Try again.\n"); goto jump;} //Fuera de rango
            
        }
        else    //limpiar buffer de entrada en caso de conversión de formato de scanf errónea
        {
            int c;
            while( (c = getchar()) != '\n' && c != EOF);
        }
    }
}

int User_reset_or_finish_validation(void)
{
    while (1)
    {   
        int k;
        while( (k = getchar()) != '\n' && k != EOF);    //limpieza del buffer, para evitar errores al recibir con getchar el el switch

        switch (getchar())
        {
            case 'y': case 'Y':
                return 1;
            case 'n': case 'N':
                return 0;
            default:
                printf("\nWrong entry! (y or n)");
                break;
        }
    }
}
 */

/* *Exercise 5.34 Multiplicación con respuestas ramdon y análisis de las primeras 10 */
/* #include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

int multiplicationTable_checking(int, int, int);
void userEntry_Validation(void);
void random_answers(int);
int percent_rightAnswers(int); 

int a, b;
unsigned long long int UserInput_storage_for_check;

int main()
{
    srand(time(NULL));
    userEntry_Validation();

    return 0;
}

void userEntry_Validation(void)
{   
    int answers_counter = 0;

        while (1)
    {
        a = rand() % 10;
        b = rand() % 10;

        jump:
        printf("How much is %d times %d?(negative number to end):\t",a,b);
        if(scanf("%llu",&UserInput_storage_for_check) == 1)
        {
            if((int)UserInput_storage_for_check < INT_MAX)
            {
                if( (int)UserInput_storage_for_check >= 0 )
                {
                    if( multiplicationTable_checking(a, b, (int) UserInput_storage_for_check) == 1) 
                    {   
                        percent_rightAnswers(1);
                        if(++answers_counter == 10)
                        {
                            printf("The percent of right answers is %d %%.\n", percent_rightAnswers(0) ); 
                            if( percent_rightAnswers(0) < 75 ) {printf("Please ask you instructor for extra help\n"); break;}
                            percent_rightAnswers(-1);
                            answers_counter = 0;
                        }
        
                        random_answers(1);
                        continue;
                    }
                    else
                    { 
                        if(++answers_counter == 10)
                        {
                            printf("------> The percent of right answers is %d %%.\n", percent_rightAnswers(0) ); 
                            if( percent_rightAnswers(0) < 75 ) {printf("Please ask you instructor for extra help\n"); break;}
                            percent_rightAnswers(-1);
                            answers_counter = 0;
                        }

                        random_answers(0); 
                        goto jump;
                    }
                }
                else break;
            }
            else
            {
                printf("Out of range!\n");
                continue;
            }

        }
        else
        {
            printf("Wrong entry!\n");
            int c;
            while( (c = getchar()) != '\n' && c != EOF);
        }

    }
}

int multiplicationTable_checking(int n1, int n2, int result)
{
    return n1 * n2 == result;
}

void random_answers(int ans)
{
    switch ( ans == 1 ? (rand() % 4)+1 : (rand() % 4)+ 5 )
    {
    case 1:
        printf("Very good!\n");
        break;
    case 2:
        printf("Excellent!\n");
        break;
    case 3:
        printf("Nice work!\n");
        break;
    case 4:
        printf("Keep up the good work!\n");
        break;    
    case 5:
        printf("No. Please try again.\n");
        break;
    case 6:
        printf("Wrong. Try once more.\n");
        break;    
    case 7:
        printf("Don't give up!\n");
        break;   
    default:
        printf("No. Keep trying.\n");
        break;
    }
    //printf("\n");
}

int percent_rightAnswers(int n)
{
    static int r_ans = 0;
    if(n == -1) {r_ans = 0; n = 0;}   // reset porciento
    r_ans += n;
    return r_ans*10;
}
 */

/* Exercise 5.33 Multiplicación con respuestas ramdon*/
/* #include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

int multiplicationTable_checking(int, int, int);
void userEntry_and_Validation(void);
void random_answers(int);

int a, b;
unsigned long long int UserInput_storage_for_check;

int main()
{
    srand(time(NULL));
    userEntry_and_Validation();

    return 0;
}

void userEntry_and_Validation(void)
{
        while (1)
    {
        a = rand() % 10;
        b = rand() % 10;

        jump:
        printf("How much is %d times %d?(negative number to end)\t",a,b);
        if(scanf("%llu",&UserInput_storage_for_check) == 1)
        {
            if((int)UserInput_storage_for_check < INT_MAX)
            {
                if( (int)UserInput_storage_for_check >= 0 )
                {
                    if( multiplicationTable_checking(a, b, (int) UserInput_storage_for_check) == 1) { random_answers(1); continue;}
                    else{ random_answers(0); goto jump;}
                }
                else break;
            }
            else
            {
                printf("Out of range!\n");
                continue;
            }

        }
        else
        {
            printf("Wrong entry!\n");
            int c;
            while( (c = getchar()) != '\n' && c != EOF);
        }

    }
}

int multiplicationTable_checking(int n1, int n2, int result)
{
    return n1 * n2 == result;
}

void random_answers(int ans)
{
    switch ( ans == 1 ? (rand() % 4)+1 : (rand() % 4)+ 5 )
    {
    case 1:
        printf("Very good!\n");
        break;
    case 2:
        printf("Excellent!\n");
        break;
    case 3:
        printf("Nice work!\n");
        break;
    case 4:
        printf("Keep up the good work!\n");
        break;    
    case 5:
        printf("No. Please try again.\n");
        break;
    case 6:
        printf("Wrong. Try once more.\n");
        break;    
    case 7:
        printf("Don't give up!\n");
        break;   
    default:
        printf("No. Keep trying.\n");
        break;
    }
}
 */

/* Exercise 5.32 Multiplicación*/
/* Casos a tener en cuenta: respuesta correcta, respuesta incorrecta*/
/* #include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

int multiplicationTable_checking(int, int, int);
void userEntry_and_Validation(void);

int a, b;
unsigned long long int UserInput_storage_for_check;

int main()
{
    srand(time(NULL));
    userEntry_and_Validation();

    return 0;
}

void userEntry_and_Validation(void)
{
        while (1)
    {
        a = rand() % 10;
        b = rand() % 10;

        jump:
        printf("How much is %d times %d?(negative number to end)\t",a,b);
        if(scanf("%llu",&UserInput_storage_for_check) == 1)
        {
            if((int)UserInput_storage_for_check < INT_MAX)
            {
                if( (int)UserInput_storage_for_check >= 0 )
                {
                    if( multiplicationTable_checking(a, b, (int) UserInput_storage_for_check) == 1) { printf("Very good!\n"); continue;}
                    else{printf("No, Please try again.\n"); goto jump;}
                }
                else break;
            }
            else
            {
                printf("Out of range!\n");
                continue;
            }

        }
        else
        {
            printf("Wrong entry!\n");
            int c;
            while( (c = getchar()) != '\n' && c != EOF);
        }

    }
}

int multiplicationTable_checking(int n1, int n2, int result)
{
    return n1 * n2 == result;
}
 */

/* Excercise 5.31 Heads or Tails*/
/* #include<stdio.h>
#include<stdlib.h>
#include<time.h>


int flip(void);

int main()
{
    srand(time(NULL));
    int h,t;
    h = t = 0;

    for (int i = 0; i < 100; i++)
    {
        switch (flip())
        {
        case 0:
            printf("Head\n");
            h++;
            break;
        
        default:
            printf("Tail\n");
            t++;
            break;
        }
    }
    
    printf("--------------------\nTotal--->\tHeads: %d\tTails: %d\n",h,t);

    return 0;
}

int flip(void)
{
    return rand() % 2;
}
 */

/* Exercise 5.30 */
/* #include<stdio.h>

int qualityPoints(int);

int main()
{
    while (1)
    {
        int student_average;
        printf("Write the average of the student(negative to end): ");
        if(scanf("%d",&student_average) == 1)
        {
            if(student_average < 0) break;
            if(student_average > 100){printf("Out of range\n"); continue;}
            printf("The quality point for an average of %d is %d\n", student_average, qualityPoints(student_average) );
        }
        else
        {
            printf("Wrong entry\n");
            int c;
            while( (c = getchar()) != '\n' && c != EOF);
        }
    }
    
    return 0;
}

int qualityPoints(int p)
{
    if(p > 89 )return 4;
    if(p > 79 )return 3;
    if(p > 69 )return 2;
    if(p > 59 )return 1;
    return 0;
    
} */

/* Exercise 5.29 GCD*/
/* #include<stdio.h>
#include<limits.h>

int gcd(int, int);

int main()
{
    while (1)
    {   
        //  letra,negtivo
        int number1, number2;
        printf("Write two number(negative to end): \n");
        if(scanf("%d%d",&number1, &number2) == 2)
        {
            if(number1 < INT_MAX  && number2 < INT_MAX)
            {
                if( number1 < 0 || number2 < 0) break;  //negative case

                printf("The GCD of %d and %d is: %d\n", number1, number2, gcd(number1,number2));
            }
            else {printf("Out of range.\n"); continue;} // out of range case

        }
        else
        {
            printf("Wrong entry\n");
            int c;
            while( (c = getchar()) != '\n' && c != EOF);
        }
    }
    
    return 0;
}

int gcd(int n1, int n2)
{
    if(n1 == 0 || n2 == 0) return 0;
    if(n1 == 1 || n2 == 1) return 1;
    
    int number_gcd;

    for (int i = 2; i <= (n1 <= n2 ? n1 : n2); i++)    
    {
        if ( n1 % i != 0 || n2 % i != 0) continue;;
        number_gcd = i;
    }
    
    return number_gcd;
} */

/* Excersise 5.28 */
/* #include<stdio.h>
#include<limits.h>

int number_reverse(int);

int main()
{
    while (1)
    {
        int number;
        printf("Write an integer number(or write a letter to end):");
        if( (scanf("%d",&number)) == 1 )    //comprobación para saber si la conversión de formato de la entrada fue exitosa
        {
            if (number < 1000000000 && number >= -999999999)    //comprobación para saber si el número introducido es un entero o esta fuera de las dimensiones de un entero con signo,
                                        // no se realiza comparación con INT_MAX, la explicación a esto está dentro de los comentarios de la función number_reverse.
            {
                printf("The reverse of the number %d is %d.\n",number,number_reverse(number));
            }else{printf("Out of range.\n"); continue;}
            
        }else break;
        
    }
    
    return 0;
}

int number_reverse(int n)
{
    if(n == 0) return 0;
    
    int f = 0;
    if (n < 0) {n *= -1; f = 1;}    //caso negativo

    int temp_number = n;
    int temp_reverse = 0;
    
    for (int i = 1; i <= n; i*=10)
    {
        temp_reverse = (temp_reverse*10) + temp_number % 10;
        temp_number /= 10;
        //  Para resolver el problema correpondiente a aquellos números cuyos inversos superan el rango INT_MAX existen posibles vías de solución:
        //     - limitar que el usuario pueda antrar valores mayores a un número de 9 cifras, debido a que la reversa de un número de terminado en
        //       en una cifra mayor que 2 desbordaría la variable INT imprimiendo valores erróneos.
        //     - la otra vía de solución estaría dada por retornar un LONG_INT, no un UINT para no perder aquellos valores negativos
        //     - la otra vía de solución estaría dada en dividir el número introducido por el usuario 10^9 cuestión de quedarme con la cifra 10
        //       las otras nueve las trabajo norma, como si fuese solo un número de 9 cifras y al final imprimo la cifra 10. NOTA: aunque esta
        //       última opción es posible, no cumpliría con el requisito de retornar solo un número entero.
        //     **Por tanto, se utilizará la primera solución. Para esto solo es necesario comparar por 10^9 en vez de por INT_MAX 
        
        //if(i == 1000000000)break; //debido a que el número no va a superar las 10 cifras no es necesario esta condición de parada.
    }
    
    if(f == 1) return temp_reverse * -1;
    return temp_reverse;
}
 */

/* Exercise 5.27 primes numbers */
/* #include <stdio.h>
#include <math.h>

long int prime_n2(long int);
long int prime_sqrt_n(long int);

long int number_counter_n2 = 0;
long int number_counter_sqrt_n = 0;
int main()
{       
    printf("All the prime numbers form 1 to 10,000 are: ");
    long int count = 10000;
    for (long int i = 1; i <= count; i++)
    {
        if( prime_n2(i) != 0 ) printf("%ld\t", prime_n2(i));
    }
    printf("The total test numbers are with n2: %ld", number_counter_n2);

    printf("\n--------------------\nAll the prime numbers form 1 to 10,000 are: ");
    count = 10000;
    for (long int i = 1; i <= count; i++)
    {
        if( prime_sqrt_n(i) != 0 ) printf("%ld\t", prime_sqrt_n(i));
    }
    printf("The total test numbers are with sqrt_n: %ld", number_counter_sqrt_n);

    return 0;
}

long int prime_n2(long int n)    
{   
    //aquí la razon de prueba es n/2 debido a que si el número no es 
    //divisible por la mitad de los número que lo componen, pues tampoco debe ser divisible
    //por la otra mitad.

    for (long int i = 2; i < n/2; i++)
    {
        number_counter_n2++;
        if(n % i == 0) return 0; // el retorno cero indica que no es primo el número
    }
    return n;   //Sino existe retorno dentro del for es porque el número es primo, debido a que no es divisible por la mitad de los número que lo componen
}
long int prime_sqrt_n(long n)
{   
    //aquí la razón de prueba es sqrt de N
    for (long int i = 2; i < (long int)sqrt(n); i++)
    {
        number_counter_sqrt_n++;
        if(n % i == 0) return 0; // el retorno cero indica que no es primo el número
    }
    return n;   //Sino existe retorno dentro del for es porque el número es primo, debido a que no es divisible por la mitad de los número que lo componen
}
 */

/* Ecersice 5.26 Perfect numbers*/
/* #include <stdio.h>

long int perfect(long int, int);
int PerfectNumbersFrom0To1000(void);

long int number;
int flag;

int main()
{
    while (1)
    {   
        if(PerfectNumbersFrom0To1000() == -1) break;
    }
    
    return 0;
}

long int perfect(long int n, int f)
{
    long int temp = 0;
    int firstNumber = 0;

    for (int i = n - 1; i > 0; i--)
    {
        //The first check is to verify that the number is a factor of N.
        if(n % i != 0) continue;    //The current value of i isn't a factor of n.
        temp += i;  //Storage 
        if(firstNumber) printf(" +");   //if flag is 0, the plus never is printed
        if(f != 0) printf("  %d",i), firstNumber = 1;
        
    }

    if (n == temp) return temp; //aquí lo que hace es comparar lo que tengo almacenado en temp(suma de todos los números que son factores de N) con N
    return 0;
}
int PerfectNumbersFrom0To1000(void)
{   
    flag = 0;
    printf("Write an integer number(negative to end):");
    //Aquí es importante analizar:
        //Que pueden existir perfectos fromTo pero, puiesen no existir en el dominio dado por el usuario
    if( scanf("%ld",&number) == 0)
    {
        printf("The entered value is incorrect. Please try again.\n"); 
        // Clear the input buffer to avoid an infinite loop
        int c;
        while ((c = getchar()) != '\n' && c != EOF); 
    }
    else if(number < 0) return -1;
    else
    {
        printf("-------------------------------------\nAll the perfect numbers from 0 to %ld are:\n",number);
        for (long int i = number; i > 0; i--)
        {   
            if( (perfect(i, flag)) != 0)
            {
                printf("\n%ld = ",i);
                perfect(i, 1);
                printf("\n");
            }
        }
    }
    return 0;
}

 */

/* Exercise 5.25 */
/* #include <stdio.h>

float smallest(float,float,float);

int main()
{
    while (1)
    {
        int flag;
        float num1, num2, num3;
        
        printf("Write three floating-point numbers to compare them (write a letter to end): ");
        if(scanf("%f%f%f",&num1,&num2,&num3) != 3) break;

        printf("The smallest number is %f.\n", smallest(num1,num2,num3));
    }
    
    return 0;
}

float smallest(float x,float y,float z)
{
    long int a, b, c, tempInt;
    float tempf;

    a = (long int) x * 1000;
    b = (long int) y * 1000;
    c = (long int) z * 1000;
    
    tempInt = a;
    tempf = x;

    if(a > b) tempInt = b, tempf  = y;
    if(tempInt > c) tempf = z;

    return tempf;

}
 */

/* Exercise 5.24  Temp
Este ejercicio primeramente lo intentaré hacer realizando una tabla para analizar el compartamiento de los valores durante la conversión en ambas direcciones
FaC o CaF. Se disminuirá el número de líneas devidiendo las conversiones en columansa y filas
Después de esto se intentará un rejuego para intentar gráficar con caracteres ASCII. Como propuesta se tiene comenzar por el mayor número en las conversiones
de manera que puedas ser impresa como la primera línea*/
/* #include<stdio.h>

float celsius(float);
float fahrenheit(float);
void header_CF(char,char);
void table_CF(void);
void table_FC(void);
void graphic_CF();
void graphic_FC();

int main()
{       
    int flag = 0;

    while (1)
    {   
        beguin:
        printf("Choose one of the next options:\n\
        1 - Table of Conversions from Celsius to Fahrenheit.\n\
        2 - Table of Conversions from Fahrenheit to Celsius.\n\
        3 - Graphic of Conversions from Celsius to Fahrenheit.\n\
        4 - Graphic of Conversions form Fahrenheit to Celsius.\n\
        5 - To end.\n");
        scanf("%d", &flag);
        
        switch (flag)
        {
            case 1:
                header_CF('C', 'F');    //Imprimir encabezado en la primera iteración
                table_CF();
                break;
            case 2:
                header_CF('F', 'C');    //Imprimir encabezado en la primera iteración
                table_FC();
                break;
            case 3:
                graphic_CF();
                break;
            case 4:
                graphic_FC();
                break;
            case 5:
                goto salir_del_bucle;
                break;
            default:
                printf("It's not a valid options. Try again.\n");
                goto beguin;
        }
    }
        

    salir_del_bucle:
    return 0;
}

float celsius(float f)
{
    return (f - 32) / 1.8;
}
float fahrenheit(float c)
{
    return c * 1.8 +32;
}
void header_CF(char a,char b)
{
    for (int y = 0; y < 10; y++)
    {
        printf ("%-3c - %-7c\t", a, b);
    }
    printf("\n");    //separador de la siguiente línea
}
void table_CF(void)
{
    int i = 0;
    for (int z = i * 10; z < 101; z++, i++)
    {   
        if(z != 0 && z % 10 == 0 ) printf("\n");    //separador de la siguiente línea
        printf("%-3d - %-7.1f\t", z , fahrenheit(z) );
    }
            
}
void table_FC(void)
{
    for (int z = 32; z < 213; z++)
    {   
        if(z != 0 && z % 10 == 0 ) printf("\n");    //separador de la siguiente línea
        printf("%-3d - %-7.1f\t", z , celsius(z) );
    }
}
void graphic_CF()
{
   printf("\n\tGrafic from Celsius to Fahrenheit\nF\n");
   for (int i = 212; i >= 32; i -= 3)
   {
        printf("|%d%*.f\n", i,i-32+5,celsius(i));
   }
   for (int i = 0; i < 212; i++)
   {
    printf("_");
   }
   printf("C\n");
   
}
void graphic_FC()
{
    printf("\n\tGrafic from Celsius to Fahrenheit\nC\n");
    for (int i = 100; i >= 0; i -= 2)
    {
        printf("|%d%*.f\n", i,i+5,fahrenheit(i));
    }
    for (int i = 0; i < 105; i++)
    {
        printf("_");
    }
    printf("F\n");
}
 */

/* Exercise 5.23 */
/* #include <stdio.h>
#include <time.h>

long int seconds_past_twelve(int,int,int);
int Input_validation(int,int);

int main()
{   
    int hours, minutes, seconds;
    long int temp_h1,temp_h2;

    while(1)
    {   
        beguin1:
        printf("Write a time of day in 12-hour format(-1 to end): \n");
        printf("Hours: ");
        scanf("%d",&hours); if(hours == -1) break; else if(hours < -1 || hours > 12) goto beguin1;
        printf("Minutes: ");
        scanf("%d",&minutes); if(minutes == -1) break; else if(minutes < -1 || minutes > 60) goto beguin1;
        printf("Seconds: ");
        scanf("%d",&seconds); if(seconds == -1) break; else if(seconds < -1 || seconds > 60) goto beguin1;
        
        temp_h1 = seconds_past_twelve(hours,minutes,seconds);

        beguin2:
        printf("Write a second time of day in 12-hour format(-1 to end): \nHours: ");
        scanf("%d",&hours); if(hours == -1) break; else if(hours < -1 || hours > 12) goto beguin2;
        printf("Minutes: ");
        scanf("%d",&minutes); if(minutes == -1) break; else if(minutes < -1 || minutes > 60) goto beguin2;
        printf("Seconds: ");
        scanf("%d",&seconds); if(seconds == -1) break; else if(seconds < -1 || seconds > 60) goto beguin2;

        temp_h2 = seconds_past_twelve(hours,minutes,seconds);

        printf("The time in second between the two hours is: %ld",temp_h1 < temp_h2 ? temp_h2-temp_h1 : temp_h1-temp_h2);

        printf("\n----------------------------\n");   //separador de la siguiente línea para cuando se haga el primer pedido de hora no esté en la misma línea
        

    }

    return 0;
}

long int seconds_past_twelve(int h,int m,int s)
{
    return (12*60*60) - ( (h*60 + m)*60 + s);
} */

/* Exercise 5.22 */
/* #include <stdio.h>

int integerAB (int, int);
int residuoAB(int, int);
void separarDigitos(void);

int main()
{   
    int number_A, number_B;
    int end_condition = 1;

    while (end_condition != 0)
    {
       printf("Select which item you want to do (E to end): ");
       
       int c;
       while( (c = getchar()) == '\n'); // This is to discard the '\n' saved in the buffer

       switch (c)
       {
       case 'A': case 'a':
        printf("Write two integers number (A / B): ");
        scanf("%d %d",&number_A,&number_B);
        printf("Answer %d (integer)\n",integerAB(number_A,number_B));
        break;

       case 'B': case 'b':
        printf("Write two integers number (A mod B) : ");
        scanf("%d %d",&number_A,&number_B);
        printf("Answer %d (residuo)\n",residuoAB(number_A,number_B));
        break;

        case 'C': case 'c':
        separarDigitos();
        break;

        case 'E': case 'e':
            end_condition = 0;
        break;

       default:
            printf("Choose a correct options!! (A, B or C)\n");
        break;
       }

    }
    
    return 0;
}

int integerAB (int AA, int BB)
{
    return AA / BB;
}

int residuoAB(int AA, int BB)
{
    return AA % BB;
}

void separarDigitos(void)
{
    int temp1, flag = 0;

    jump: 
    printf("Writte an integer number between 1 to 32767: ");
    scanf("%d",&temp1);
    if(temp1 > 32767 || temp1 < 1) goto jump;

    for (int i = 10000; i > 0; i/=10)
    {   
        //printf("%d\n",i);
        if(integerAB(temp1, i) != 0 ) flag = 1; // Bandera colocada para marcar cuando debe empezar a imprimir en pantalla los valores

        if(flag == 1)
        {
            printf("%d  ",integerAB(temp1, i));
            temp1 = residuoAB(temp1, i);
        }
    }
    
    printf("\n");   //colocado para marcar la separación entre la imprisión en pantalla y la línea del Main que indica volver a escoger que se desea hacer
} */

/* Excercise 5.20 Modified the funtion of 5.19 exercise for make an square with any character contained on FillCharacter */
/* #include <stdio.h>

int fillcharacter(void);
void side( int);

int main()
{
    int side_square;
    while(1)
    {
        printf("Escribe el tamaño del cuadrado(negativo o cero para terminar): ");
        scanf("%d", &side_square);
        
        // Comprobación de la condición de terminación 
        if(side_square < 1) break;

        side(side_square); // Imprimir caracter 
    }
    return 0;
}


void side( int s)
{   
    int character = fillcharacter();    // Recibir por parte del usuario cuál es el caracter a imprimir 

    for (int i = 0; i < s; i++)
    {
        for (int i = 0; i < s; i++)
        {
            printf("%c",character);
        }

        printf("\n");
    }
} 

int fillcharacter(void)
{   
    printf("\nWrite the character that you want to print: ");
    int c;
    while ((c = getchar()) == '\n');  // Descarta los caracteres de nueva línea 
    return c;
} */

/* Exercise 5.19 Desplegar un cuadrado de asteríscos, introduciedo el valor del lado por parte del usuario */
/* #include <stdio.h>

void side( int);

int main()
{
    int side_square;
    while(1)
    {
        printf("Escribe el tamaño del cuadrado(negativo o cero para terminar): ");
        scanf("%d", &side_square);
        if(side_square < 1) break;

        side(side_square);
    }
    return 0;
}


void side( int s)
{
    for (int i = 0; i < s; i++)
    {
        for (int i = 0; i < s; i++)
        {
            printf("*");
        }

        printf("\n");
    }
} */

/* Exercise 5.18 Determinar si una serie de número es par o impar, pasándolos a la función uno a uno */
/* #include <stdio.h>

int even (int);

int main()
{
    int q,w,e,r,t,y, count = 6;
    while(1)
    {
        printf("Write six positive integer numbers (negative or zero to end): ");
        scanf("%d%d%d%d%d%d",&q,&w,&e,&r,&t,&y);
        if (q < 1 || w < 1 || e < 1 || r < 1 || t < 1 || y < 1) break;
    
        for (int i = 0; i < count; i++)
        {
            switch (i)
            {
            case 0 :
                printf("%d es par? %d\n",q, even(q));
                break;
            case 1 :
                printf("%d es par? %d\n",w, even(w));
                break;
            case 2 :
                printf("%d es par? %d\n",e, even(e));
                break;
            case 3 :
                printf("%d es par? %d\n",r, even(r));
                break;
            case 4 :
                printf("%d es par? %d\n",t, even(t));
                break;
            case 5 :
                printf("%d es par? %d\n",y, even(y));
                break;
            }
        }
    }
 return 0;   
}

int even (int x)
{
    if ( x % 2 == 0) return 1;
    return 0;
} */

/* Excersise 5.17 Multiple */
/* #include <stdio.h>

int Multiple(int, int);

int main()
{   
    int number1, number2;
    while (1)
    {
        printf("Write the first number (negative to end): ");
        scanf("%d",&number1);
        if(number1 < 0 ) break; 
        printf("Write the second number (negative to end): ");
        scanf("%d",&number2);
        if(number2 < 0 ) break;

        printf("¿ %d  es multiplo de %d ? : %d\n", number2, number1, Multiple(number1, number2));
    }
    
}

int Multiple(int x, int y)
{
    if ( y % x == 0) return 1;
    return 0;
} */

/* Excersise 5.16 intergerPower(base, expoenent) with "for", without to use a math.h funtion */
/* #include <stdio.h>

double integerPower(int, int );

int main()
{   
    int base, exponent;
    while (1)
    {
        printf("Escribe la base (negativo  o cero para terminar): ");
        scanf("%d",&base);
        if(base < 1) break;
        printf("Escribe el exponente entero positivo: ");
        scanf("%d",&exponent);
        if(base < 1) break;

        printf("La potencia es igual a %lf\n\n", integerPower(base, exponent));
    }
    
    return 0;
}

double integerPower(int b, int exp )
{
    int count = exp;
    int B_temp = b;
    for (int i = 1; i < count; i++)
    {
        B_temp *= b;
        //printf("\n%d",B_temp);
    }
    
    return B_temp;
} */

/* Exercise 5.15 cálculo de la HIPOTENUSA dado los lados */
/* #include <stdio.h>
#include <math.h>

double hypotenuse (double, double);

int main()
{
    double side1 = 1, side2 = 1;

    while (1)
    {
        printf(" \nEscriba el valor del lado 1: ");
        scanf("%lf", &side1);
        if (side1 < 0 ) break;
        printf("lado 2: ");
        scanf("%lf", &side2);

        printf("\n El valor de la hipotenusa del triángulo es %lf____%lf", hypot (side1, side2), hypotenuse(side1,side2));

    }
    
    return 0;
}

double hypotenuse (double s1, double s2)
{
    return sqrt(pow(s1, 2) + pow ( s2, 2));
}
 */

/* Exercise 5.14
para la solución de este ejercicio hay que tener en cuenta dos vías claras:
1- Basado en un bloque Switch que debido aque el número posible de casos es pequeño solo tendríamos que
   dimensionar en correspondencia el número de caso y asignar a cada caso un valor del conjunto.
   ESTA OPCIÓN SOLO ES VIABLE PARA UN NÚMERO DE CASOS PEQUEÑO Y NO CUMPLE EL CRITERIO DE UN SOLO ENUNCIADO
   IMPUESTO POR EL EJERCICIO.
2-  La segunda vía sería una ecuación matemática (cumple el criterio de un solo enunciado) que nos permita
    independientemente del valor de entrada dar una salida acorde al conjunto(es independiente de a cantidad
    de casos tipos, solo se centra en entregar valores conforme a las reglas del conjunto)*/

// a)
/* #include <stdio.h>
#include <stdlib.h>
#include <time.h>

int azar_rest5plus1_X2(void); // (rand()%5 +1) * 2 

int main ()
{
    int count = 15;
    srand(time(NULL));
    for (int i = 0; i < count; i++)
    {
        printf("%d\n",azar_rest5plus1_X2());
    }

    return 0;
}

int azar_rest5plus1_X2(void)
{
    return (rand() % 5 + 1) * 2;
} */

/* // b)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int azar_rest5plus1_X2_plus1(void); // (( rand() % 5 + 1 ) * 2)+1

int main()
{
    int count = 15;
    srand(time(NULL));

    for (int i = 0; i < count; i++)
    {
        printf("%d\n",azar_rest5plus1_X2_plus1());
    }
    
    return 0;
}

int azar_rest5plus1_X2_plus1(void) // (( rand() % 5 + 1 ) * 2)+1
{
    return (( rand() % 5 + 1 ) * 2)+1;
} */

/* // c)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int azar_rest5plus1_X2_plus1_X2(void);

int main()
{
    int count = 15;
    srand(time(NULL));

    for (int i = 0; i < count; i++)
    {
        printf("%d\n", azar_rest5plus1_X2_plus1_X2());
    }
    

    return 0;
}

int azar_rest5plus1_X2_plus1_X2(void)
{

    return ((( rand() % 5 + 1 ) * 2) + 1) * 2;
} */


/*Exercise 5.13 Escribir enunciados que generen números aleatorios dalos los rangos que me dan*/
// a)
/* #include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_1_2 (void);

int main()
{   
    int count = 10;
    srand(time(NULL));

    for (int i = 0;  i < count; i++)
    {
        printf("%d\n", random_1_2());
    }
    

    return 0;
}

int random_1_2 (void)
{
    return ( rand() % 2) + 1;
}
 */

// b)
/* #include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_1_100(void);

int main()
{
    int count = 300;
    srand(time(NULL));

    for (int i = 0; i < count; i++)
    {
        printf("%d\n", random_1_100());
    }
    
    return 0;
}

int random_1_100(void)
{
    return (rand()%100)+1;
} */

// c)
/* #include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_0_9(void);

int main()
{
    int count = 9*3;
    srand(time(NULL));

    for (int i = 0; i < count; i++)
    {
        printf("%d\n",random_0_9());
    }
    

    return 0;
}

int random_0_9(void)
{
    return rand()%10;
} */

// d)
/* #include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_1000_1112(void);

int main()
{
    int count = 13*3;
    srand(time(NULL));

    for (int i = 0; i < count; i++)
    {
        printf("%d\n", random_1000_1112());
    }
    

    return 0;
}

int random_1000_1112(void)
{
    return rand() % 13 + 1000;
} */

// e)
/* #include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_neg1_post1(void);

int main()
{
    int count = 3*3;
    srand(time(NULL));

    for (int i = 0; i < count; i++)
    {
        printf("%d\n", random_neg1_post1());
    }
    
    return 0;
}

int random_neg1_post1(void)
{
    return rand() % 3 - 1;
} */

// f)
/* #include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_neg3_post11(void);

int main()
{
    int count = 15*3;
    srand(time(NULL));

    for (int i = 0; i < count; i++)
    {
        printf("%d\n",random_neg3_post11());
    }
    

    return 0;
}

int random_neg3_post11(void)
{
    return rand() % 15 - 3;
}
 */



/* Exercise 5.12

 1- Seleccionar números "al azar" significa generar números que no siguen un patrón predecible. En la práctica, los números generados por las computadoras son en realidad pseudoaleatorios, ya que se generan mediante algoritmos deterministas, pero son suficientemente impredecibles para la mayoría de los usos.

2- La función `rand` es útil para la simulación de juegos de azar porque puede generar una secuencia de números que parecen ser aleatorios. Esto puede simular eventos aleatorios en los juegos, como lanzar un dado o barajar una baraja de cartas.

3- `srand` se utiliza para inicializar el generador de números aleatorios en C/C++. Si no usas `srand`, `rand` producirá la misma secuencia de números cada vez que se ejecute tu programa. Esto puede ser útil para la depuración, pero no es deseable si necesitas que tu programa produzca resultados diferentes en cada ejecución.

4- A menudo es necesario dimensionar y/o desplazar los valores producidos por `rand` porque `rand` genera un número entero entre 0 y RAND_MAX. Si necesitas un número en un rango diferente, tendrás que ajustar el valor. Por ejemplo, para obtener un número entre 1 y 6 (como en un dado), podrías usar `(rand() % 6) + 1`.

5- La simulación computarizada de situaciones del mundo real es una técnica útil porque permite experimentar y probar escenarios que podrían ser costosos, peligrosos o simplemente imposibles de realizar en la vida real. Por ejemplo, puedes simular el comportamiento de un sistema físico bajo ciertas condiciones, o probar cómo reaccionaría un algoritmo a diferentes entradas. */



/* Excercise 5.11 Round to : Integer, Tenths, Hundreths, Thousandths */

/* #include <stdio.h>
#include <math.h>

double roundtoInteger(double number);
double roundtoTenths(double number);
double roundtoHundreths(double number);
double roundtoThousandths(double number);

int main()
{

    double x;

    while (1)
    {
        printf("Write a number(negative to end): ");
        scanf("%lf",&x);
        if (x < 0) break;
        
        printf("El número original es %lf y redondeado al: \n - entero más cercano %.0lf\n - décima más cercana %.1lf\n - centésima más cercano %.2lf\n - milésima más cercana %.3lf\n\n", x, roundtoInteger(x), roundtoTenths(x), roundtoHundreths(x), roundtoThousandths(x));
    }
    
    return 0;
}

double roundtoInteger(double number)
{
    return floor(number + .5 ); 
}
double roundtoTenths(double number)
{
    return floor(number * 10 + .5 ) / 10;
}
double roundtoHundreths(double number)
{
    return floor(number * 100 + .5 ) / 100;
}
double roundtoThousandths(double number)
{
    return floor(number * 1000 + .5 ) / 1000;
} */



/*Excercise 5.10
*In this excercise qwe use the  propoused statenent " y = floor(x + .5) " to round to the near integer.
*/
/* 
#include <stdio.h>
#include <math.h>



double redondear_05_flow(double num);


int main()
{
    double x;

     while (1)
    {
    
    printf("Writte a numbers(negative to end): ");
    scanf("%lf",&x);
    
    if( x < 0) break;

    printf("El valor original es %.3lf y el entero más cercnao es %.3f\n\n", x, redondear_05_flow(x));
    
    }
    return 0;
} */
/* 
double redondear_05_flow(double num)
{
    return floor(num + .5);

} */







/* #include <stdio.h>
#include <math.h>
#include <time.h>

double numberSelection();
int opSelection();
double Result(int, double);
void calculate_Charges(float, int); 
void calculate_Charges_v1_1(float, int); 
void calculate_Charges_v1_2(float, int); */


/*Exercise 5.9 v1.2*/
/*float charge=0, hoursPrinft = 0;
int main()
{   
    float hours_of_garage1 = 0, hours_of_garage2 = 0, hours_of_garage3 = 0, hoursTEMP;
    int Car_counter = 1;


    while ((int)hours_of_garage1 != EOF && (int)hours_of_garage2 != EOF && (int)hours_of_garage3 != EOF)
    {
        printf("Introduce 3 numbers referencing to garage's hours (-1 to end): ");
        scanf("%f", &hours_of_garage1);
        if(hours_of_garage1 != -1) scanf("%f%f",&hours_of_garage2, &hours_of_garage3);  //comprobación de condición de termianción basado en el primer número pedido
        
        while((int)hours_of_garage1 != EOF && (int)hours_of_garage2 != EOF && (int)hours_of_garage3 != EOF)
        {

            //Seleccionando las horas de garage que se le pasarán a la función calculate_Charge
            if(Car_counter == 1) hoursTEMP = hours_of_garage1;
            else if(Car_counter == 2) hoursTEMP = hours_of_garage2;
            else if(Car_counter == 3)hoursTEMP = hours_of_garage3;
            else {printf("%-7s%8.2f%11.2f\n----------------------------------\n\n", "TOTAL",hoursPrinft,charge); break;}

            calculate_Charges_v1_2(hoursTEMP, Car_counter),++Car_counter;
             
        }
    }
    
    //printf("%-10s%-10f%10f\n", "TOTAL",hoursPrinft,charge);

    return 0;
}
*/

/*Exercise 5.9  v1.1 */
/*float charge=0, hoursPrinft = 0;
int main()
{   
    float hours_of_garage;
    int Car_counter = 1;

    printf("Introduce the number of garage's hours of your car(-1 to end): \n");
    printf("----------------------------------\n%-10s%-10s%10s\n", "Car","Hours","Charge");

    while(1)
    {   
        printf("%-10d",Car_counter);
        scanf("%10f", &hours_of_garage);
        if(hours_of_garage != EOF) calculate_Charges_v1_1(hours_of_garage, Car_counter), ++Car_counter;
        else break;
    }

    printf("%-10s%-10.2f%10.2f\n", "TOTAL",hoursPrinft,charge);

    return 0;
}
*/

/*Exercise 5.9  v1.0
*Es esta versión se imprime los valores uno por uno y al final se imprime el total pero no se logra que todos se visualizen al mismo tiempo
* por tanto, como no se puede trabajar con arreglos para ir almacenando información (pues no se conoce el número máximo de clientes) y para
* evitar un gran número de variables las cuales no sabemos si cumplirán con la demanada de clientes, entonces se propoene un nueva versión
*reutilizando este código y la función calculate_Charges, para lograr ir imprimiendo fila a fila mientras el usuario pone en la columana Hours
*las diferentes horas, y se calcula el total al final. El único problema que visualizo es que se va a necesitar colocar el número -1.
* Hay que pensar en como resolver eso... quizas existe una en la conversión de formato algo que me permita ir al inicio de Línea y sobre escribir
el -1.
v1.1 Fallida
*El problema que se pensaba más dificil, era el asociado con comenzar a escribir al inicio de línea, resultó
* siendo solucionado en la impresion con la secuencia de escape \r la cual coloca el cursor al inicio de la 
*línea. Sin embargo, cuando recibimos un valor de teclado al presionar enter, estamos poniendo el cursor en la
* siguiente línea. Queda pendiente buscar si existe algún modo de regresar a la línea anterior.
*De momento se propone: una v1.2 en la cual se ingresen 3 valores correspondientes ha la hora y entonces se imprima en
* en pantalla lo correspondiente al ejercicio.
* v1.2 Exitosa
* Exitosa para tres valores de horarios, debido a que todavía no se ha estudiado la asignación dinámica de memoria.
* Ahora se propone una v1.3 en la cuál se valide la entrada teniendo en cuenta que alguien pudiese escribir un número mayor que 24 o menor que cero
* y aparte pudiesen escribir una letra u otro caracter erroneo o una cadena de caracteres.
*v1.3 Fallida
*Debido a que todavía no se cuenta con los conocimientos de arreglos nos se puede trabajar con cadenas de datos como las entradas de teclado de manera que se pueda ir 
*sondeando cada posición del arreglo y convirtiendo el valor de la posición en su homologo decimal para comprobar que no es una cadena de letras o caracteres inválidos.
*/
/*
float charge=0, hoursPrinft = 0;
int main()
{   
    float hours_of_garage;
    int Car_counter = 1;

    while(1)
    {
        printf("Introduce the number of garage's hours of your car(-1 to end): ");
        scanf("%f", &hours_of_garage);
        if(hours_of_garage != EOF) calculate_Charges(hours_of_garage, Car_counter), ++Car_counter;
        else break;
    }

    printf("%-10s%-10f%10f\n", "TOTAL",hoursPrinft,charge);

    return 0;
}

*/








/*  Exercise 5.8*/
/*int main()
{
    double x;
    printf("fabs(7.5) = %lf\n",fabs(7.5));
    printf("floor(7.5) = %lf\n",floor(7.5));
    printf("fabs(0) = %lf\n",fabs(0));
    printf("ceil(0) = %lf\n",ceil(0));
    printf("fabs(-6.4) = %lf\n",fabs(-6.4));
    printf("ceil(-6.4) = %lf\n",ceil(-6.4));
    printf("ceil(-fabs(-8+floor(-5.5))) = %lf\n",ceil(-fabs(-8+floor(-5.5))));

    return 0;
}*/


/*  Exercise #5.6
Escribir una declaración para cada una de las variables
* register int count = 0;
* static float lastVal;
*extern int number;
*/


/* Exercise # 5.5
Prototipos de función
*   double hypotenuse(double , double )
*   int smallest(int , int , int )
*   void instuctions()
*   float intToFloat()
*/


/*Exercise # 5.4
Encabezados de funciones
*   double hypotenuse(double side1, double side2)
*   int smallest(int x, int y, int z)
*   void instuctions()
*   float intToFloat(int number)
*/


//Exercise # 5.3
//Probar que los valores representados en la figura 5.2 son correctos
 /*int main()
 {
    double number;
    int temp_of_opNumber; 
     
    while(1)
    {
        number = numberSelection();
        if(number == EOF) break;
        temp_of_opNumber = opSelection();
        printf("The result is %lf.\n\n", Result(temp_of_opNumber,number));
    }

    return 0;
 }*/

/* 
 double numberSelection()
 {
    double temp_number;
    //Selecting the number
        printf("Enter a number(-1 to end): \n");
        scanf("%lf",&temp_number);
        return temp_number;
 }

 int opSelection()
 {  
    int tempOpNumber;

    //Selecting the operation
    printf("Select the operation\n1\tsqrt(x)\n2\texp(x)\n3\tlog(x)\n4\tlog10(x)\n5\tfabs(x)\n6\tceil(x)\n7\tfloor(x)\n8\tpow(x,y)\n9\tfmod(x,y)\n10\tsin(x)\n11\tcos(x)\n12\ttan(x)\n");
    printf("\n-------\nWritte your selection: \n\n");
    scanf("%d",&tempOpNumber);

    return tempOpNumber;
 }

double Result(int op_selector, double n)
{   
    double num;
    switch (op_selector)
    {
    case 1:
        num = sqrt(n);
        break;
    case 2:
        num = exp(n);
       break;
    case 3:
        num = log(n);
       break;
    case 4:
        num = log10(n);
        break;
    case 5:
        num = fabs(n);
        break;
    case 6:
        num = ceil(n);
        break;
    case 7:
        num = floor(n);
        break;
    case 8:
        printf("Write the exponent: \n");
        double exp;
        scanf("%lf",&exp);
        num = pow(n,exp);
       break;
    case 9:
        printf("Write the divisor: \n");
        double div;
        scanf("%lf",&div);
        num = fmod(n,div);
        break;
    case 10:
       num =  sin(n);
       break;
    case 11:
       num =  cos(n);
       break;
    case 12:
       num =  tan(n);
       break;
    default:
        printf("Writte a correct operation's number");
       // flag = 1;
        break;;
    }

    return num;
}

void calculate_Charges(float hours, int carNumber)
{
    printf("----------------------------------\n%-10s%-10s%10s\n", "Car","Hours","Charge");
    
    float temp_charge = 0;
    if(hours<=3) 
    {
        charge += 2;
        printf("%-10d%-10f%10f\n", carNumber,hours,2.0);
    }
    
    else   
    {   
        temp_charge = (2+ceil((hours-3))*0.5) >= 10 ? 10 : 2+ceil((hours-3))*0.5;  //este es el valor que imprimo en cado iteración
        (2+ceil((hours-3))*0.5) >= 10 ? (charge += 10) : (charge += 2+ceil((hours-3))*0.5); // cargo acumulativo
        printf("%-10d%-10f%10f\n", carNumber,hours,temp_charge);
    }

    hoursPrinft += hours; // horas acumulativas
} 

void calculate_Charges_v1_1(float hours, int carNumber)
{
    //printf("----------------------------------\n%-10s%-10s%10s\n", "Car","Hours","Charge");
    
    float temp_charge = 0;
    if(hours<=3) 
    {
        charge += 2;
        printf("%10.2f",2.0);
    }
    
    else   
    {   
        temp_charge = (2+ceil((hours-3))*0.5) >= 10 ? 10 : 2+ceil((hours-3))*0.5;  //este es el valor que imprimo en cado iteración
        (2+ceil((hours-3))*0.5) >= 10 ? (charge += 10) : (charge += 2+ceil((hours-3))*0.5); // cargo acumulativo
        printf("%10.2f\n",temp_charge);
    }

    hoursPrinft += hours; // horas acumulativas
} 

void calculate_Charges_v1_2(float hours, int carNumber)
{
    if(carNumber == 1) printf("----------------------------------\n%-7s%8s%11s\n", "Car","Hours","Charge");
    
    float temp_charge = 0;
    if(hours<=3) 
    {
        charge += 2;  // LLenado del total
        printf("%-7d%8.2f%11.2f\n", carNumber,hours,2.0);
    }
    
    else   
    {   
        temp_charge = (2+ceil((hours-3))*0.5) >= 10 ? 10 : 2+ceil((hours-3))*0.5;  //este es el valor que imprimo en cado iteración
        (2+ceil((hours-3))*0.5) >= 10 ? (charge += 10) : (charge += 2+ceil((hours-3))*0.5); // cargo acumulativo
        printf("%-7d%8.2f%11.2f\n", carNumber,hours,temp_charge);
    }

    hoursPrinft += hours; // horas acumulativas
} 
 */