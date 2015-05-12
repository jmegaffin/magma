#ifndef _MANTLE_DBG_H
#define _MANTLE_DBG_H

#include "mantle.h"

#ifdef __cplusplus
extern "C" {
#endif



/* callbacks */
typedef GR_VOID (GR_STDCALL *GR_DBG_MSG_CALLBACK_FUNCTION)(
	GR_ENUM        msgType,
	GR_ENUM        validationLevel,
	GR_BASE_OBJECT srcObject,
	GR_SIZE        location,
	GR_ENUM        msgCode,
	const GR_CHAR *pMsg,
	GR_VOID       *pUserData
);



/* functions */
extern GR_RESULT (GR_STDCALL *grDbgRegisterMsgCallback)(
	GR_DBG_MSG_CALLBACK_FUNCTION pfnMsgCallback,
	GR_VOID                     *pUserData
);

extern GR_RESULT (GR_STDCALL *grDbgSetValidationLevel)(
	GR_DEVICE device,
	GR_ENUM   validationLevel
);

extern GR_RESULT (GR_STDCALL *grDbgUnregisterMsgCallback)(
	GR_DBG_MSG_CALLBACK_FUNCTION pfnMsgCallback
);



/* enumerations */
typedef enum _GR_DBG_MSG_TYPE {
	GR_DBG_MSG_UNKNOWN = 0x00020000,
	GR_DBG_MSG_ERROR,
	GR_DBG_MSG_WARNING,
	GR_DBG_MSG_PERF_WARNING
} GR_DBG_MSG_TYPE;



#ifdef __cplusplus
}
#endif

#endif
