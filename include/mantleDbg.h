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
extern GR_RESULT (GR_STDCALL *grCmdDbgMarkerBegin)(
	GR_CMD_BUFFER  cmdBuffer,
	const GR_CHAR *pMarker
);

extern GR_RESULT (GR_STDCALL *grCmdDbgMarkerEnd)(
	GR_CMD_BUFFER  cmdBuffer
);

extern GR_RESULT (GR_STDCALL *grDbgRegisterMsgCallback)(
	GR_DBG_MSG_CALLBACK_FUNCTION pfnMsgCallback,
	GR_VOID                     *pUserData
);

extern GR_RESULT (GR_STDCALL *grDbgSetDeviceOption)(
	GR_DEVICE      device,
	GR_ENUM        dbgOption,
	GR_SIZE        dataSize,
	const GR_VOID *pData
);

extern GR_RESULT (GR_STDCALL *grDbgSetGlobalOption)(
	GR_ENUM        dbgOption,
	GR_SIZE        dataSize,
	const GR_VOID *pData 
);

extern GR_RESULT (GR_STDCALL *grDbgSetMessageFilter)(
	GR_DEVICE device,
	GR_ENUM   msgCode,
	GR_ENUM   filter
);

extern GR_RESULT (GR_STDCALL *grDbgSetObjectTag)(
	GR_BASE_OBJECT object,
	GR_SIZE        tagSize,
	GR_VOID       *pTag
);

extern GR_RESULT (GR_STDCALL *grDbgSetValidationLevel)(
	GR_DEVICE device,
	GR_ENUM   validationLevel
);

extern GR_RESULT (GR_STDCALL *grDbgUnregisterMsgCallback)(
	GR_DBG_MSG_CALLBACK_FUNCTION pfnMsgCallback
);



/* enumerations */
typedef enum _GR_DBG_DATA_TYPE {
	GR_DBG_DATA_OBJECT_TYPE = 0x00020a00,
	GR_DBG_DATA_OBJECT_CREATE_INFO,
	GR_DBG_DATA_OBJECT_TAG,

	GR_DBG_DATA_CMD_BUFFER_API_TRACE = 0x00020b00,

	GR_DBG_DATA_MEMORY_OBJECT_LAYOUT = 0x00020c00,
	GR_DBG_DATA_MEMORY_OBJECT_STATE,

	GR_DBG_DATA_SEMAPHORE_IS_BLOCKED = 0x00020d00
} GR_DBG_DATA_TYPE;

typedef enum _GR_DBG_DEVICE_OPTION {
	GR_DBG_OPTION_DISABLE_PIPELINE_LOADS = 0x00020400,
	GR_DBG_OPTION_FORCE_OBJECT_MEMORY_REQS,
	GR_DBG_OPTION_FORCE_LARGE_IMAGE_ALIGNMENT,
	GR_DBG_OPTION_SKIP_EXECUTION_ON_ERROR
} GR_DBG_DEVICE_OPTION;

typedef enum _GR_DBG_GLOBAL_OPTION {
	GR_DBG_OPTION_DEBUG_ECHO_ENABLE = 0x00020100,
	GR_DBG_OPTION_BREAK_ON_ERROR,
	GR_DBG_OPTION_BREAK_ON_WARNING
} GR_DBG_GLOBAL_OPTION;

typedef enum _GR_DBG_MSG_FILTER {
	GR_DBG_MSG_FILTER_NONE = 0x00020800,
	GR_DBG_MSG_FILTER_REPEATED,
	GR_DBG_MSG_FILTER_ALL
} GR_DBG_MSG_FILTER;

typedef enum _GR_DBG_MSG_TYPE {
	GR_DBG_MSG_UNKNOWN = 0x00020000,
	GR_DBG_MSG_ERROR,
	GR_DBG_MSG_WARNING,
	GR_DBG_MSG_PERF_WARNING
} GR_DBG_MSG_TYPE;

typedef enum _GR_DBG_OBJECT_TYPE {
	GR_DBG_OBJECT_UNKNOWN = 0x00020900,
	GR_DBG_OBJECT_DEVICE,
	GR_DBG_OBJECT_QUEUE,
	GR_DBG_OBJECT_GPU_MEMORY,
	GR_DBG_OBJECT_IMAGE,
	GR_DBG_OBJECT_IMAGE_VIEW,
	GR_DBG_OBJECT_COLOR_TARGET_VIEW,
	GR_DBG_OBJECT_DEPTH_STENCIL_VIEW,
	GR_DBG_OBJECT_SHADER,
	GR_DBG_OBJECT_GRAPHICS_PIPELINE,
	GR_DBG_OBJECT_COMPUTE_PIPELINE,
	GR_DBG_OBJECT_SAMPLER,
	GR_DBG_OBJECT_DESCRIPTOR_SET,
	GR_DBG_OBJECT_VIEWPORT_STATE,
	GR_DBG_OBJECT_RASTER_STATE,
	GR_DBG_OBJECT_MSAA_STATE,
	GR_DBG_OBJECT_COLOR_BLEND_STATE,
	GR_DBG_OBJECT_DEPTH_STENCIL_STATE,
	GR_DBG_OBJECT_CMD_BUFFER,
	GR_DBG_OBJECT_FENCE,
	GR_DBG_OBJECT_QUEUE_SEMAPHORE,
	GR_DBG_OBJECT_EVENT,
	GR_DBG_OBJECT_QUERY_POOL,
	GR_DBG_OBJECT_SHARED_GPU_MEMORY,
	GR_DBG_OBJECT_SHARED_QUEUE_SEMAPHORE,
	GR_DBG_OBJECT_PEER_GPU_MEMORY,
	GR_DBG_OBJECT_PEER_IMAGE,
	GR_DBG_OBJECT_PINNED_GPU_MEMORY,
	GR_DBG_OBJECT_INTERNAL_GPU_MEMORY
} GR_DBG_OBJECT_TYPE;



#ifdef __cplusplus
}
#endif

#endif
