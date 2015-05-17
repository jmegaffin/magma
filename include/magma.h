#ifndef _MAGMA_H
#define _MAGMA_H

#include "magmaPre.h"

#define MAGMA_STDCALL

#ifdef __cplusplus
extern "C" {
#endif



// forward declarations
MAGMA_ENUM(MAGMA_RESULT);



// functions
MAGMA_STDCALL MAGMA_RESULT magmaInit(void);

MAGMA_STDCALL void magmaTerminate(void);



// enumerations
enum _MAGMA_RESULT {
	MAGMA_SUCCESS,
	MAGMA_ERROR_DLLS_NOT_FOUND
};



#ifdef __cplusplus
}
#endif

#endif
