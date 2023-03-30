/*
 Este codigo es el que siempre estamos modificando ya que es el encargado
 de hacer las peticiones al servidor como se observa cambiamos la funcion para que 
 pudiera aceptar dos parametros mas que son los enteros a,b tambien agregamos las variables remotas
 las cuales nos permiten modificar lo que queremos que aparesca en este caso solicitamos 2 numeros 
 al usuario para poder realizar la suma, si el usuario no ingresaba el hots ni los numeros le   aparecia una excepción esperado ya que el usuario no sabira como usar el programa por eso le pediria	dichos parametros, de igual manera se agrega una excepción para que el usuario no pueda colocar 0 en ambos espacios.
 */
#include <stdio.h>
#include "suma.h"


void suma_prog_1(char *host,int a, int b)
{
	CLIENT *clnt;
	int  *result_1;
	dupla_int  suma_1_arg;
	

#ifndef	DEBUG
	clnt = clnt_create (host, SUMA_PROG, SUMA_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	
	//suma_1_arg.a=123;
	//suma_1_arg.b=22;
	//result_1 = suma_1(&suma_1_arg, clnt);
	suma_1_arg.a=a;
	suma_1_arg.b=b;
	result_1 = suma_1(&suma_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}else{
	printf("result = %d\n",*result_1);
}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	
	
}


int
main (int argc, char *argv[])
{
	char *host;
	int a,b;
	if(argc!=4)
	{
		printf("uage: %s server_host num1 num2\n",argv[0]);
	exit(1);
	}
	host=argv[1];
	if((a=atoi(argv[2]))==0&& *argv [2]!='0')
	{
		fprintf(stderr,"invalid value: %s\n",argv[2]);
	exit(1);
	}
if((b=atoi(argv[3]))==0&& *argv [3]!='0')
	{
		fprintf(stderr,"invalid value: %s\n",argv[3]);
	exit(1);
	}
	suma_prog_1(host,a,b);
}
