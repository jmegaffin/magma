#include <magma.h>

#define extern
#include <mantle.h>
#include <mantleDbg.h>
#include <mantleWsiWinExt.h>
#undef extern

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define LOAD(module, function) *(void **)&function = (void *)GetProcAddress(module, #function)



static HMODULE g_mantle = NULL;

MAGMA_STDCALL MAGMA_RESULT magmaInit(void) {
	if(g_mantle) {
		return MAGMA_ERROR_ALREADY_INITIALIZED;
	}
	g_mantle = LoadLibrary("mantle64.dll");
	if(!g_mantle) {
		return MAGMA_ERROR_INITIALIZATION_FAILED;
	}

	LOAD(g_mantle, grBeginCommandBuffer);
	LOAD(g_mantle, grBindObjectMemory);
	LOAD(g_mantle, grCmdClearColorImage);
	LOAD(g_mantle, grCmdClearColorImageRaw);
	LOAD(g_mantle, grCmdPrepareImages);
	LOAD(g_mantle, grCmdPrepareMemoryRegions);
	LOAD(g_mantle, grCreateCommandBuffer);
	LOAD(g_mantle, grCreateDevice);
	LOAD(g_mantle, grDestroyDevice);
	LOAD(g_mantle, grDestroyObject);
	LOAD(g_mantle, grEndCommandBuffer);
	LOAD(g_mantle, grGetDeviceQueue);
	LOAD(g_mantle, grGetExtensionSupport);
	LOAD(g_mantle, grGetGpuInfo);
	LOAD(g_mantle, grGetObjectInfo);
	LOAD(g_mantle, grInitAndEnumerateGpus);
	LOAD(g_mantle, grQueueSubmit);
	LOAD(g_mantle, grResetCommandBuffer);

	LOAD(g_mantle, grDbgRegisterMsgCallback);
	LOAD(g_mantle, grDbgSetValidationLevel);
	LOAD(g_mantle, grDbgUnregisterMsgCallback);

	LOAD(g_mantle, grWsiWinCreatePresentableImage);
	LOAD(g_mantle, grWsiWinQueuePresent);

	return MAGMA_SUCCESS;
}

MAGMA_STDCALL void magmaTerminate(void) {
	grBeginCommandBuffer      = NULL;
	grBindObjectMemory        = NULL;
	grCmdClearColorImage      = NULL;
	grCmdClearColorImageRaw   = NULL;
	grCmdPrepareImages        = NULL;
	grCmdPrepareMemoryRegions = NULL;
	grCreateCommandBuffer     = NULL;
	grCreateDevice            = NULL;
	grDestroyDevice           = NULL;
	grDestroyObject           = NULL;
	grEndCommandBuffer        = NULL;
	grGetDeviceQueue          = NULL;
	grGetExtensionSupport     = NULL;
	grGetGpuInfo              = NULL;
	grGetObjectInfo           = NULL;
	grInitAndEnumerateGpus    = NULL;
	grQueueSubmit             = NULL;
	grResetCommandBuffer      = NULL;

	grDbgRegisterMsgCallback   = NULL;
	grDbgSetValidationLevel    = NULL;
	grDbgUnregisterMsgCallback = NULL;

	grWsiWinCreatePresentableImage = NULL;
	grWsiWinQueuePresent           = NULL;

	if(g_mantle) {
		FreeLibrary(g_mantle);
		g_mantle = NULL;
	}
}
