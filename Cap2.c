/*
#include <stdio.h>
#include <math.h>
main()
{
    //Ejercicio 2.3
    int a;

    printf("number\tsquare\tcube\n");
    for(a=0;a<=10;a++)
    {
        printf("%d\t%d\t%d\n",a,a*a,a*a*a);
    }










    /*Ejercicio 2.30
    int a,i=5;
    printf("Escriba un nu'mero de 5 digitos ");
    scanf("%d",&a);

    printf("\n %d   %d   %d   %d   %d", a/10000 , a%10000/1000 , a%10000%1000/100 , a%10000%1000%100/10 , a%10000%1000%100%10);
    */















    /*Ejercicio 2.29
    printf("A %d\n",'A');
    printf("a %d\n",'a');
    printf("C %d\n",'C');
    printf("c %d\n",'c');
    printf("B %d\n",'B');
    printf("b %d\n",'b');
    printf("0 %d\n",'0');
    printf("1 %d\n",'1');
    printf("2 %d\n",'2');
    printf("$ %d\n",'3');
    printf("* %d\n",'*');
    printf("+ %d\n",'+');
    printf("/ %d\n",'/');
    */







    /* Ejercicio 2.27
    printf(" * * * * * * * * \n");
    printf("  * * * * * * * *\n");
    printf(" * * * * * * * * \n");
    printf("  * * * * * * * *\n");
    printf(" * * * * * * * * \n");
    printf("  * * * * * * * *\n");
    printf(" * * * * * * * * \n");
    printf("  * * * * * * * *\n\n");

    printf(" * * * * * * * * \n  * * * * * * * *\n * * * * * * * * \n  * * * * * * * *\n * * * * * * * * \n  * * * * * * * *\n * * * * * * * * \n  * * * * * * * *\n");
    */








    /* Ejercicio 2.26
    //reutilizando el código del ejercicio 2.24
    int a,b;

    printf("Escriba dos nu'meros enteros: ");
    scanf("%d%d",&a,&b);

    if(a%b) printf("A no es mu'ltiplo de B"); else printf("A es mu'ltiplo de B");
    */




    /* Ejercicio 2.25
   printf("\tAAAAAAAA\n");
   printf("\t    A   A\n");
   printf("\t    A   A\n");
   printf("\t    A   A\n");
   printf("\tAAAAAAAAA\n\n");

   printf("\tAAAAAAAAA\n");
   printf("\tA       A\n");
   printf("\tA       A\n");
   printf("\tA       A\n");
   printf("\tA       A\n\n");


   printf("\tAAAAAAAAA\n");
   printf("\t    A   A\n");
   printf("\t    A   A\n");
   printf("\t        A\n");
   printf("\t        A\n");*/




   /* Ejercicio 2.24
   int a;

   printf("Escriba un entero: ");
   scanf("%d",&a);

   if(a%2) printf("imPar"); else printf("par");
    */





    /* Ejercicio 2.24
    int M=0,m=pow(2,32),a,i;

    printf("Escriba 5 nu'meros separdos en li'nea\n");

    for(i=1;i<=5;i++)
    {
        scanf("%d",&a);

        if(a>=M) M=a;
        if(a<=m) m=a;
        if(i==5) printf("Mayor %d\nmenor %d\n",M,m);
    }*/




    /* Ejercicio 2.21
    printf("*********              ***                *               *    \n");
    printf("*       *            *     *             ***             * *   \n");
    printf("*       *           *       *           *****           *   *  \n");
    printf("*       *           *       *             *            *     * \n");
    printf("*       *           *       *             *           *       *\n");
    printf("*       *           *       *             *            *     * \n");
    printf("*       *           *       *             *             *   *  \n");
    printf("*       *            *     *              *              * *   \n");
    printf("*********              ***                *               *    \n");
    */



    /* Ejercicio 2.21
    float radio,pi=3.14159;

    printf("Escriba el radio de la circunferencia: \t");
    scanf("%f",&radio);
    printf("Diametro %f\nPerimetro %f\nArea %f",2*radio,2*radio*pi,2*radio*pi*pi);
    */




    /* Ejercicio 2.19
    int a,s,d,i;

    while(i){
        printf("Input three diferent integers:\n(4to numero es 1 para continuar y 0 para realizar la ultima iteracion)\n\n");
        scanf("%d%d%d%d",&a,&s,&d,&i);
        printf("Sum is %d\nAverage is %d\nProduct is %d\n",a+s+d,(a+s+d)/3,a*s*d);

        //me cansé de no usar if anidados (@_@) [ [¨]=__=[¨] ]
        if(a < s){

            if(a < d) printf("Smallest is %d\n",a);
            else printf("Smallest is %d\n",d);

            if(s>d)printf("Largest is %d\n\n\n-------------------------------------------------\n",s);
            else printf("Largest is %d\n\n\n-------------------------------------------------\n",d);

        }else {

            if(s < d)printf("Smallest is %d\n",s);
            else printf("Smallest is %d\n",d);

            if(a > d)printf("Largest is %d\n\n\n-------------------------------------------------\n",a);
            else printf("Largest is %d\n\n\n-------------------------------------------------\n",d);

        }
    }*/












    /* Ejercicio 2.18
    int a,s;
    scanf("%d%d",&a,&s);

    if(a>s) printf("%d is larger %d",a,s);
    if(a<s) printf("%d is larger %d",s,a);
    if(a==s) printf("This number are equal");
    */



    /* Ejercicio 2.17
    int a=1, b=2, c=3, d=4;

    printf("1 2 3 4\n");  //inciso A

    printf("%d %d %d %d\n",a,b,c,d);  //inciso B

    printf("%d ",a);    //inciso C
    printf("%d ",b);
    printf("%d ",c);
    printf("%d",d);*/



    /* Ejercicio 2.16
    int a,b;

    scanf("%d%d",&a,&b);
    printf("suma %d\nproducto %d\ndiferencia %d\ncociente %d\nmo'dulo %d",a+b,a*b,a-b,a/b,a%b);
    */

 /*   return 0;
}*/

