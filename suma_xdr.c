/*
	este codigo se usa para convertir os dos valores proporcionados  valores enteros
	a un formato estandar
 */

#include "suma.h"

bool_t
xdr_dupla_int (XDR *xdrs, dupla_int *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->a))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->b))
		 return FALSE;
	return TRUE;
}
