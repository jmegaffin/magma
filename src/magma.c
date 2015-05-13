#include <magma.h>

#define MAGMA_EXTERN
#include <mantle.h>
#include <mantleDbg.h>
#include <mantleWsiWinExt.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define LOAD(module, function) *(void **)&function = (void *)GetProcAddress(module, #function)
#define FREE(function) function = NULL



static int g_count = 0;

static HMODULE g_mantle    = NULL;
static HMODULE g_mantleaxl = NULL;



MAGMA_STDCALL MAGMA_RESULT magmaInit(void) {
	if(g_count++ > 0) {
		return MAGMA_SUCCESS;
	}

	g_mantle = LoadLibrary("mantle64.dll");
	g_mantleaxl = LoadLibrary("mantleaxl64.dll");
	if(!g_mantle || !g_mantleaxl) {
		--g_count;
		return MAGMA_ERROR_DLL_NOT_FOUND;
	}

	LOAD(g_mantle, grInitAndEnumerateGpus);
	LOAD(g_mantle, grGetGpuInfo);
	LOAD(g_mantle, grCreateDevice);
	LOAD(g_mantle, grDestroyDevice);

	LOAD(g_mantle, grGetExtensionSupport);
	
	LOAD(g_mantle, grGetDeviceQueue);
	LOAD(g_mantle, grQueueWaitIdle);
	LOAD(g_mantle, grDeviceWaitIdle);
	LOAD(g_mantle, grQueueSubmit);
	LOAD(g_mantle, grQueueSetGlobalMemReferences);

	LOAD(g_mantle, grGetMemoryHeapCount);
	LOAD(g_mantle, grGetMemoryHeapInfo);
	LOAD(g_mantle, grAllocMemory);
	LOAD(g_mantle, grFreeMemory);
	LOAD(g_mantle, grSetMemoryPriority);
	LOAD(g_mantle, grMapMemory);
	LOAD(g_mantle, grUnmapMemory);
	LOAD(g_mantle, grRemapVirtualMemoryPages);
	LOAD(g_mantle, grPinSystemMemory);

	LOAD(g_mantle, grDestroyObject);
	LOAD(g_mantle, grGetObjectInfo);
	LOAD(g_mantle, grBindObjectMemory);

	LOAD(g_mantle, grGetFormatInfo);
	LOAD(g_mantle, grCreateImage);
	LOAD(g_mantle, grGetImageSubresourceInfo);
	LOAD(g_mantle, grCreateSampler);

	LOAD(g_mantle, grCreateCommandBuffer);
	LOAD(g_mantle, grBeginCommandBuffer);
	LOAD(g_mantle, grEndCommandBuffer);
	LOAD(g_mantle, grResetCommandBuffer);

	LOAD(g_mantle, grCmdPrepareMemoryRegions);
	LOAD(g_mantle, grCmdPrepareImages);
	LOAD(g_mantle, grCmdClearColorImage);
	LOAD(g_mantle, grCmdClearColorImageRaw);

	LOAD(g_mantle, grDbgSetValidationLevel);
	LOAD(g_mantle, grDbgRegisterMsgCallback);
	LOAD(g_mantle, grDbgUnregisterMsgCallback);
	LOAD(g_mantle, grDbgSetMessageFilter);
	LOAD(g_mantle, grDbgSetObjectTag);
	LOAD(g_mantle, grDbgSetGlobalOption);
	LOAD(g_mantle, grDbgSetDeviceOption);
	LOAD(g_mantle, grCmdDbgMarkerBegin);
	LOAD(g_mantle, grCmdDbgMarkerEnd);

	LOAD(g_mantle, grWsiWinGetDisplays);
	LOAD(g_mantle, grWsiWinGetDisplayModeList);
	LOAD(g_mantle, grWsiWinTakeFullscreenOwnership);
	LOAD(g_mantle, grWsiWinReleaseFullscreenOwnership);
	LOAD(g_mantle, grWsiWinSetGammaRamp);
	LOAD(g_mantle, grWsiWinWaitForVerticalBlank);
	LOAD(g_mantle, grWsiWinGetScanLine);
	LOAD(g_mantle, grWsiWinCreatePresentableImage);
	LOAD(g_mantle, grWsiWinQueuePresent);
	LOAD(g_mantle, grWsiWinSetMaxQueuedFrames);

	return MAGMA_SUCCESS;
}



MAGMA_STDCALL void magmaTerminate(void) {
	if(g_count == 0 || --g_count > 0) {
		return;
	}

	FREE(grInitAndEnumerateGpus);
	FREE(grGetGpuInfo);
	FREE(grCreateDevice);
	FREE(grDestroyDevice);

	FREE(grGetExtensionSupport);
	
	FREE(grGetDeviceQueue);
	FREE(grQueueWaitIdle);
	FREE(grDeviceWaitIdle);
	FREE(grQueueSubmit);
	FREE(grQueueSetGlobalMemReferences);

	FREE(grGetMemoryHeapCount);
	FREE(grGetMemoryHeapInfo);
	FREE(grAllocMemory);
	FREE(grFreeMemory);
	FREE(grSetMemoryPriority);
	FREE(grMapMemory);
	FREE(grUnmapMemory);
	FREE(grRemapVirtualMemoryPages);
	FREE(grPinSystemMemory);

	FREE(grDestroyObject);
	FREE(grGetObjectInfo);
	FREE(grBindObjectMemory);

	FREE(grGetFormatInfo);
	FREE(grCreateImage);
	FREE(grGetImageSubresourceInfo);
	FREE(grCreateSampler);

	FREE(grCreateCommandBuffer);
	FREE(grBeginCommandBuffer);
	FREE(grEndCommandBuffer);
	FREE(grResetCommandBuffer);

	FREE(grCmdPrepareMemoryRegions);
	FREE(grCmdPrepareImages);
	FREE(grCmdClearColorImage);
	FREE(grCmdClearColorImageRaw);

	FREE(grDbgSetValidationLevel);
	FREE(grDbgRegisterMsgCallback);
	FREE(grDbgUnregisterMsgCallback);
	FREE(grDbgSetMessageFilter);
	FREE(grDbgSetObjectTag);
	FREE(grDbgSetGlobalOption);
	FREE(grDbgSetDeviceOption);
	FREE(grCmdDbgMarkerBegin);
	FREE(grCmdDbgMarkerEnd);

	FREE(grWsiWinGetDisplays);
	FREE(grWsiWinGetDisplayModeList);
	FREE(grWsiWinTakeFullscreenOwnership);
	FREE(grWsiWinReleaseFullscreenOwnership);
	FREE(grWsiWinSetGammaRamp);
	FREE(grWsiWinWaitForVerticalBlank);
	FREE(grWsiWinGetScanLine);
	FREE(grWsiWinCreatePresentableImage);
	FREE(grWsiWinQueuePresent);
	FREE(grWsiWinSetMaxQueuedFrames);

	if(g_mantle) {
		FreeLibrary(g_mantle);
		g_mantle = NULL;
	}
}
