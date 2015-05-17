#ifndef _MAGMA_PRE_H
#define _MAGMA_PRE_H

#include <stdint.h>

#ifndef MAGMA_EXTERN
#define MAGMA_EXTERN extern
#endif

#define MAGMA_HANDLE(name)         typedef uint64_t name
#define MAGMA_ENUM(name)           typedef uint32_t name
#define MAGMA_STRUCT(name)         typedef struct _##name name
#define MAGMA_CALLBACK(type, name) typedef type (GR_STDCALL *name)
#define MAGMA_FUNCTION(type, name) MAGMA_EXTERN type (GR_STDCALL *name)

#endif
