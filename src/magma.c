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

	LOAD(g_mantle, grCreateImageView);
	LOAD(g_mantle, grCreateColorTargetView);
	LOAD(g_mantle, grCreateDepthStencilView);

	LOAD(g_mantle, grCreateShader);
	LOAD(g_mantle, grCreateGraphicsPipeline);
	LOAD(g_mantle, grCreateComputePipeline);
	LOAD(g_mantle, grStorePipeline);
	LOAD(g_mantle, grLoadPipeline);

	LOAD(g_mantle, grCreateDescriptorSet);
	LOAD(g_mantle, grBeginDescriptorSetUpdate);
	LOAD(g_mantle, grEndDescriptorSetUpdate);
	LOAD(g_mantle, grAttachSamplerDescriptors);
	LOAD(g_mantle, grAttachImageViewDescriptors);
	LOAD(g_mantle, grAttachMemoryViewDescriptors);
	LOAD(g_mantle, grAttachNestedDescriptors);
	LOAD(g_mantle, grClearDescriptorSetSlots);

	LOAD(g_mantle, grCreateViewportState);
	LOAD(g_mantle, grCreateRasterState);
	LOAD(g_mantle, grCreateColorBlendState);
	LOAD(g_mantle, grCreateDepthStencilState);
	LOAD(g_mantle, grCreateMsaaState);

	LOAD(g_mantle, grCreateQueryPool);
	LOAD(g_mantle, grGetQueryPoolResults);
	LOAD(g_mantle, grCreateFence);
	LOAD(g_mantle, grGetFenceStatus);
	LOAD(g_mantle, grWaitForFences);
	LOAD(g_mantle, grCreateQueueSemaphore);
	LOAD(g_mantle, grSignalQueueSemaphore);
	LOAD(g_mantle, grWaitQueueSemaphore);
	LOAD(g_mantle, grCreateEvent);
	LOAD(g_mantle, grGetEventStatus);
	LOAD(g_mantle, grSetEvent);
	LOAD(g_mantle, grResetEvent);

	LOAD(g_mantle, grGetMultiGpuCapability);
	LOAD(g_mantle, grOpenSharedMemory);
	LOAD(g_mantle, grOpenSharedQueueSemaphore);
	LOAD(g_mantle, grOpenPeerMemory);
	LOAD(g_mantle, grOpenPeerImage);

	LOAD(g_mantle, grCreateCommandBuffer);
	LOAD(g_mantle, grBeginCommandBuffer);
	LOAD(g_mantle, grEndCommandBuffer);
	LOAD(g_mantle, grResetCommandBuffer);

	LOAD(g_mantle, grCmdBindPipeline);
	LOAD(g_mantle, grCmdBindStateObject);
	LOAD(g_mantle, grCmdBindDescriptorSet);
	LOAD(g_mantle, grCmdBindDynamicMemoryView);
	LOAD(g_mantle, grCmdBindIndexData);
	LOAD(g_mantle, grCmdBindTargets);
	LOAD(g_mantle, grCmdPrepareMemoryRegions);
	LOAD(g_mantle, grCmdPrepareImages);
	LOAD(g_mantle, grCmdDraw);
	LOAD(g_mantle, grCmdDrawIndexed);
	LOAD(g_mantle, grCmdDrawIndirect);
	LOAD(g_mantle, grCmdDrawIndexedIndirect);
	LOAD(g_mantle, grCmdDispatch);
	LOAD(g_mantle, grCmdDispatchIndirect);
	LOAD(g_mantle, grCmdCopyMemory);
	LOAD(g_mantle, grCmdCopyImage);
	LOAD(g_mantle, grCmdCopyMemoryToImage);
	LOAD(g_mantle, grCmdCopyImageToMemory);
	LOAD(g_mantle, grCmdResolveImage);
	LOAD(g_mantle, grCmdCloneImageData);
	LOAD(g_mantle, grCmdUpdateMemory);
	LOAD(g_mantle, grCmdFillMemory);
	LOAD(g_mantle, grCmdClearColorImage);
	LOAD(g_mantle, grCmdClearColorImageRaw);
	LOAD(g_mantle, grCmdClearDepthStencil);
	LOAD(g_mantle, grCmdSetEvent);
	LOAD(g_mantle, grCmdResetEvent);
	LOAD(g_mantle, grCmdMemoryAtomic);
	LOAD(g_mantle, grCmdBeginQuery);
	LOAD(g_mantle, grCmdEndQuery);
	LOAD(g_mantle, grCmdResetQueryPool);
	LOAD(g_mantle, grCmdWriteTimestamp);
	LOAD(g_mantle, grCmdInitAtomicCounters);
	LOAD(g_mantle, grCmdLoadAtomicCounters);
	LOAD(g_mantle, grCmdSaveAtomicCounters);

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

	FREE(grCreateImageView);
	FREE(grCreateColorTargetView);
	FREE(grCreateDepthStencilView);

	FREE(grCreateShader);
	FREE(grCreateGraphicsPipeline);
	FREE(grCreateComputePipeline);
	FREE(grStorePipeline);
	FREE(grLoadPipeline);

	FREE(grCreateDescriptorSet);
	FREE(grBeginDescriptorSetUpdate);
	FREE(grEndDescriptorSetUpdate);
	FREE(grAttachSamplerDescriptors);
	FREE(grAttachImageViewDescriptors);
	FREE(grAttachMemoryViewDescriptors);
	FREE(grAttachNestedDescriptors);
	FREE(grClearDescriptorSetSlots);

	FREE(grCreateViewportState);
	FREE(grCreateRasterState);
	FREE(grCreateColorBlendState);
	FREE(grCreateDepthStencilState);
	FREE(grCreateMsaaState);

	FREE(grCreateQueryPool);
	FREE(grGetQueryPoolResults);
	FREE(grCreateFence);
	FREE(grGetFenceStatus);
	FREE(grWaitForFences);
	FREE(grCreateQueueSemaphore);
	FREE(grSignalQueueSemaphore);
	FREE(grWaitQueueSemaphore);
	FREE(grCreateEvent);
	FREE(grGetEventStatus);
	FREE(grSetEvent);
	FREE(grResetEvent);

	FREE(grGetMultiGpuCapability);
	FREE(grOpenSharedMemory);
	FREE(grOpenSharedQueueSemaphore);
	FREE(grOpenPeerMemory);
	FREE(grOpenPeerImage);

	FREE(grCreateCommandBuffer);
	FREE(grBeginCommandBuffer);
	FREE(grEndCommandBuffer);
	FREE(grResetCommandBuffer);

	FREE(grCmdBindPipeline);
	FREE(grCmdBindStateObject);
	FREE(grCmdBindDescriptorSet);
	FREE(grCmdBindDynamicMemoryView);
	FREE(grCmdBindIndexData);
	FREE(grCmdBindTargets);
	FREE(grCmdPrepareMemoryRegions);
	FREE(grCmdPrepareImages);
	FREE(grCmdDraw);
	FREE(grCmdDrawIndexed);
	FREE(grCmdDrawIndirect);
	FREE(grCmdDrawIndexedIndirect);
	FREE(grCmdDispatch);
	FREE(grCmdDispatchIndirect);
	FREE(grCmdCopyMemory);
	FREE(grCmdCopyImage);
	FREE(grCmdCopyMemoryToImage);
	FREE(grCmdCopyImageToMemory);
	FREE(grCmdResolveImage);
	FREE(grCmdCloneImageData);
	FREE(grCmdUpdateMemory);
	FREE(grCmdFillMemory);
	FREE(grCmdClearColorImage);
	FREE(grCmdClearColorImageRaw);
	FREE(grCmdClearDepthStencil);
	FREE(grCmdSetEvent);
	FREE(grCmdResetEvent);
	FREE(grCmdMemoryAtomic);
	FREE(grCmdBeginQuery);
	FREE(grCmdEndQuery);
	FREE(grCmdResetQueryPool);
	FREE(grCmdWriteTimestamp);
	FREE(grCmdInitAtomicCounters);
	FREE(grCmdLoadAtomicCounters);
	FREE(grCmdSaveAtomicCounters);

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

	if(g_mantleaxl) {
		FreeLibrary(g_mantleaxl);
		g_mantleaxl;
	}
}
