/*
 En el servidor solo colocaremos literal, todo aquello que queremos que muestre el servidor
 */

#include "suma.h"

int *
suma_1_svc(dupla_int *argp, struct svc_req *rqstp)
{
	static int  result;
	printf("Server response to client\n");	
	printf("parameters: %d,%d\n",argp->a,argp->b);
	result=argp->a+argp->b;
	printf("returning: %d\n",result);

	return &result;
}
