/*
 ============================================================================
 Name        : 22.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define PRECIO 600
#define DESCUENTO 25

int main(void) {
	setbuf(stdin,NULL);
	int numeroCliente;
	    char estadoCivil;
	    int edad;
	    float temperaturaCorporal;
	    char genero;
	    char seguir;
	    int contadorMayoresSesenta;
	    int contadorViudosMayores;
	    int banderaPrimerMujerSoltera;
	    int numeroClienteMenorMujerSoltera;
	    int edadMenorMujerSoltera;
	    float precioFinal;
	    float precioConDescuento;
	    int contadorClientes;
	    float porcentajeMayores;
	    float descuentoEfectuado;

	    contadorMayoresSesenta=0;
	    contadorViudosMayores=0;
	    contadorClientes=0;
	    banderaPrimerMujerSoltera=0;


	    //----------------ingreso de datos
	    do{
	        contadorClientes++;
	        printf("\n ingrese n° cliente: ");
	        scanf("%d",&numeroCliente);

	        printf("\n ingrese estado civil s c v :");
	        fflush(stdin);
	        scanf("%c",&estadoCivil);
	        estadoCivil=tolower(estadoCivil);
	        while(estadoCivil!='s'&&estadoCivil!='c'&&estadoCivil!='v')
	        {
	            printf("\n Reingrese estado civil (s-c-v):");
	            fflush(stdin);
	            scanf("%c",&estadoCivil);
	            estadoCivil=tolower(estadoCivil);

	        }

	        printf("\n ingrese edad: ");
	        scanf("%d",&edad);
	        while(edad<17||edad>110)
	        {
	            printf("\n error revise la edad (debe ser entre 17 y 110)..: ");
	            scanf("%d",&edad);

	        }

	        printf("\n ingrese temperatura corporal: ");
	        scanf("%f",&temperaturaCorporal);
	        while(temperaturaCorporal<34||temperaturaCorporal>45)
	        {
	            printf("\n por favor revise la temperatura, debe estar ente 34° y 45°!!!");
	            scanf("%f",&temperaturaCorporal);
	        }

	        printf("\n ingrese genero  f(femenino)-m(masculino)-o(no binario)");
	        fflush(stdin);
	        scanf("%c", &genero);
	        genero=tolower(genero);
	        while(genero!='f'&&genero!='m'&&genero!='o')
	        {
	            printf("\n Reingrese genero  f(femenino)-m(masculino)-o(no binario)!!!");
	            fflush(stdin);
	            scanf("%c", &genero);
	            genero=tolower(genero);
	        }



	        printf("\n si desea ingresar otro cliente toque  s , para salir n : ");
	         fflush(stdin);
	         scanf("%c",&seguir);
	        seguir=tolower(seguir);
	        while(seguir!='s'&&seguir!='n')
	        {
	            printf("\n ERROR! si desea ingresar otro cliente toque  s , para salir n : ");
	            fflush(stdin);
	            scanf("%c",&seguir);
	            seguir=tolower(seguir);
	        }



	        //----------desarrollo
	        if(edad>59)
	        {
	            contadorMayoresSesenta++;
	            if(estadoCivil=='v')
	            {
	                contadorViudosMayores++;
	            }
	        }

	        if(genero=='f'&&estadoCivil=='s')
	        {

	            numeroClienteMenorMujerSoltera=numeroCliente;
	            edadMenorMujerSoltera=edad;
	            banderaPrimerMujerSoltera=1;
	            if(banderaPrimerMujerSoltera!=0)
	            {
	                numeroClienteMenorMujerSoltera=numeroCliente;
	                edadMenorMujerSoltera=edad;
	            }

	        }


	    }while(seguir=='s');


	    //-----------------------calculo
	    precioFinal=contadorClientes*PRECIO;
	    porcentajeMayores=(contadorMayoresSesenta*100)/contadorClientes;
	    descuentoEfectuado=precioFinal*DESCUENTO/100;
	    precioConDescuento=precioFinal- descuentoEfectuado;


	    //------------------------muestro
	    printf("\n-----------------informes---------------");

	    printf("\n a- La cantidad de mayores de 60 viudos es : %d", contadorViudosMayores);
	    if(banderaPrimerMujerSoltera!=0)
	    {
	        printf("\n b- El n° de cliente de la mujer soltera mas joven es: %d y su edad: %d"
	        ,numeroClienteMenorMujerSoltera,edadMenorMujerSoltera);
	    }
	    else
	    {
	        printf("\n b- No hay datos para mostrar, no se registraron mujeres solteras!");
	    }

	    printf("\n c- El precio total del viaje sin descuento es: %.2f",precioFinal);
	    if(porcentajeMayores>50)
	    {
	        printf("\n d- El precio con descuento es: %.2f",precioConDescuento);

	    }
	    else
	    {
	        printf("\n d- No hay descuento de precio");
	    }




	return EXIT_SUCCESS;
}
