#ifndef _MAGMA_H
#define _MAGMA_H

#define MAGMA_STDCALL



/* type aliases */
typedef char MAGMA_RESULT;



/* functions */
MAGMA_STDCALL MAGMA_RESULT magmaInit(void);
MAGMA_STDCALL void magmaTerminate(void);



/* enumerations */
typedef enum _MAGMA_RESULT_CODE {
	MAGMA_SUCCESS,
	MAGMA_ERROR_DLL_NOT_FOUND
} MAGMA_RESULT_CODE;



#endif
