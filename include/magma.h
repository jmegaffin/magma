#ifndef _MAGMA_H
#define _MAGMA_H

#define MAGMA_STDCALL



// forward declarations
typedef enum _MAGMA_RESULT MAGMA_RESULT;



// functions
MAGMA_STDCALL MAGMA_RESULT magmaInit(void);
MAGMA_STDCALL void magmaTerminate(void);



// enumerations
enum _MAGMA_RESULT {
	MAGMA_SUCCESS,
	MAGMA_ERROR_DLL_NOT_FOUND
};



#endif
