#ifndef _MANTLE_H
#define _MANTLE_H

#include "magmaPre.h"

#include <stdint.h>

#define GR_STDCALL

#ifdef __cplusplus
extern "C" {
#endif



// constants (some guessed)
#define GR_API_VERSION           1
#define GR_MAX_COLOR_TARGETS     16
#define GR_MAX_DESCRIPTOR_SETS   2
#define GR_MAX_MEMORY_HEAPS      8
#define GR_MAX_PHYSICAL_GPUS     4
#define GR_MAX_PHYSICAL_GPU_NAME 256
#define GR_MAX_VIEWPORTS         16
#define GR_NULL_HANDLE           0



// type aliases
typedef void     GR_VOID;
typedef int32_t  GR_BOOL;
typedef uint8_t  GR_BYTE;
typedef char     GR_CHAR;
typedef uint32_t GR_UINT;
typedef uint8_t  GR_UINT8;
typedef uint32_t GR_UINT32;
typedef uint64_t GR_UINT64;
typedef int32_t  GR_INT;
typedef int32_t  GR_INT32;
typedef float    GR_FLOAT;
typedef size_t   GR_SIZE;
typedef uint64_t GR_GPU_SIZE;
typedef int32_t  GR_ENUM;
typedef int32_t  GR_FLAGS;
typedef uint32_t GR_SAMPLE_MASK;

MAGMA_HANDLE(GR_BASE_OBJECT);
MAGMA_HANDLE(GR_CMD_BUFFER);
MAGMA_HANDLE(GR_COLOR_BLEND_STATE_OBJECT);
MAGMA_HANDLE(GR_COLOR_TARGET_VIEW);
MAGMA_HANDLE(GR_DEPTH_STENCIL_STATE_OBJECT);
MAGMA_HANDLE(GR_DEPTH_STENCIL_VIEW);
MAGMA_HANDLE(GR_DESCRIPTOR_SET);
MAGMA_HANDLE(GR_DEVICE);
MAGMA_HANDLE(GR_EVENT);
MAGMA_HANDLE(GR_FENCE);
MAGMA_HANDLE(GR_IMAGE);
MAGMA_HANDLE(GR_IMAGE_VIEW);
MAGMA_HANDLE(GR_GPU_MEMORY);
MAGMA_HANDLE(GR_MSAA_STATE_OBJECT);
MAGMA_HANDLE(GR_OBJECT);
MAGMA_HANDLE(GR_PHYSICAL_GPU);
MAGMA_HANDLE(GR_PIPELINE);
MAGMA_HANDLE(GR_QUERY_POOL);
MAGMA_HANDLE(GR_QUEUE);
MAGMA_HANDLE(GR_QUEUE_SEMAPHORE);
MAGMA_HANDLE(GR_RASTER_STATE_OBJECT);
MAGMA_HANDLE(GR_SAMPLER);
MAGMA_HANDLE(GR_SHADER);
MAGMA_HANDLE(GR_STATE_OBJECT);
MAGMA_HANDLE(GR_VIEWPORT_STATE_OBJECT);



// forward declarations
MAGMA_ENUM(GR_ATOMIC_OP);
MAGMA_ENUM(GR_BORDER_COLOR_TYPE);
MAGMA_ENUM(GR_BLEND);
MAGMA_ENUM(GR_BLEND_FUNC);
MAGMA_ENUM(GR_CHANNEL_FORMAT);
MAGMA_ENUM(GR_CHANNEL_SWIZZLE);
MAGMA_ENUM(GR_COMPARE_FUNC);
MAGMA_ENUM(GR_CULL_MODE);
MAGMA_ENUM(GR_DESCRIPTOR_SET_SLOT_TYPE);
MAGMA_ENUM(GR_FACE_ORIENTATION);
MAGMA_ENUM(GR_FILL_MODE);
MAGMA_ENUM(GR_HEAP_MEMORY_TYPE);
MAGMA_ENUM(GR_IMAGE_ASPECT);
MAGMA_ENUM(GR_IMAGE_STATE);
MAGMA_ENUM(GR_IMAGE_TILING);
MAGMA_ENUM(GR_IMAGE_TYPE);
MAGMA_ENUM(GR_IMAGE_VIEW_TYPE);
MAGMA_ENUM(GR_INFO_TYPE);
MAGMA_ENUM(GR_LOGIC_OP);
MAGMA_ENUM(GR_MEMORY_PRIORITY);
MAGMA_ENUM(GR_MEMORY_STATE);
MAGMA_ENUM(GR_NUM_FORMAT);
MAGMA_ENUM(GR_PHYSICAL_GPU_TYPE);
MAGMA_ENUM(GR_PIPELINE_BIND_POINT);
MAGMA_ENUM(GR_PRIMITIVE_TOPOLOGY);
MAGMA_ENUM(GR_QUERY_TYPE);
MAGMA_ENUM(GR_QUEUE_TYPE);
MAGMA_ENUM(GR_RESULT);
MAGMA_ENUM(GR_STATE_BIND_POINT);
MAGMA_ENUM(GR_STENCIL_OP);
MAGMA_ENUM(GR_SYSTEM_ALLOC_TYPE);
MAGMA_ENUM(GR_TEX_ADDRESS);
MAGMA_ENUM(GR_TEX_FILTER);
MAGMA_ENUM(GR_TIMESTAMP_TYPE);
MAGMA_ENUM(GR_VALIDATION_LEVEL);

MAGMA_ENUM(GR_CMD_BUFFER_BUILD_FLAGS);
MAGMA_ENUM(GR_DEPTH_STENCIL_VIEW_CREATE_FLAGS);
MAGMA_ENUM(GR_DEVICE_CREATE_FLAGS);
MAGMA_ENUM(GR_FORMAT_FEATURE_FLAGS);
MAGMA_ENUM(GR_GPU_COMPATIBILITY_FLAGS);
MAGMA_ENUM(GR_IMAGE_CREATE_FLAGS);
MAGMA_ENUM(GR_IMAGE_USAGE_FLAGS);
MAGMA_ENUM(GR_MEMORY_ALLOC_FLAGS);
MAGMA_ENUM(GR_MEMORY_HEAP_FLAGS);
MAGMA_ENUM(GR_MEMORY_PROPERTY_FLAGS);
MAGMA_ENUM(GR_MEMORY_REF_FLAGS);
MAGMA_ENUM(GR_PIPELINE_CREATE_FLAGS);
MAGMA_ENUM(GR_QUERY_CONTROL_FLAGS);
MAGMA_ENUM(GR_SEMAPHORE_CREATE_FLAGS);
MAGMA_ENUM(GR_SHADER_CREATE_FLAGS);

MAGMA_STRUCT(GR_ALLOC_CALLBACKS);
MAGMA_STRUCT(GR_APPLICATION_INFO);
MAGMA_STRUCT(GR_CHANNEL_MAPPING);
MAGMA_STRUCT(GR_CMD_BUFFER_CREATE_INFO);
MAGMA_STRUCT(GR_COLOR_BLEND_STATE_CREATE_INFO);
MAGMA_STRUCT(GR_COLOR_TARGET_BIND_INFO);
MAGMA_STRUCT(GR_COLOR_TARGET_BLEND_STATE);
MAGMA_STRUCT(GR_COLOR_TARGET_VIEW_CREATE_INFO);
MAGMA_STRUCT(GR_COMPUTE_PIPELINE_CREATE_INFO);
MAGMA_STRUCT(GR_DEPTH_STENCIL_BIND_INFO);
MAGMA_STRUCT(GR_DEPTH_STENCIL_OP);
MAGMA_STRUCT(GR_DEPTH_STENCIL_STATE_CREATE_INFO);
MAGMA_STRUCT(GR_DEPTH_STENCIL_VIEW_CREATE_INFO);
MAGMA_STRUCT(GR_DESCRIPTOR_SET_ATTACH_INFO);
MAGMA_STRUCT(GR_DESCRIPTOR_SET_CREATE_INFO);
MAGMA_STRUCT(GR_DESCRIPTOR_SET_MAPPING);
MAGMA_STRUCT(GR_DESCRIPTOR_SLOT_INFO);
MAGMA_STRUCT(GR_DEVICE_CREATE_INFO);
MAGMA_STRUCT(GR_DEVICE_QUEUE_CREATE_INFO);
MAGMA_STRUCT(GR_DISPATCH_INDIRECT_ARG);
MAGMA_STRUCT(GR_DRAW_INDEXED_INDIRECT_ARG);
MAGMA_STRUCT(GR_DRAW_INDIRECT_ARG);
MAGMA_STRUCT(GR_DYNAMIC_MEMORY_VIEW_SLOT_INFO);
MAGMA_STRUCT(GR_EVENT_CREATE_INFO);
MAGMA_STRUCT(GR_EXTENT2D);
MAGMA_STRUCT(GR_EXTENT3D);
MAGMA_STRUCT(GR_FENCE_CREATE_INFO);
MAGMA_STRUCT(GR_FORMAT);
MAGMA_STRUCT(GR_FORMAT_PROPERTIES);
MAGMA_STRUCT(GR_GPU_COMPATIBILITY_INFO);
MAGMA_STRUCT(GR_GRAPHICS_PIPELINE_CREATE_INFO);
MAGMA_STRUCT(GR_IMAGE_COPY);
MAGMA_STRUCT(GR_IMAGE_CREATE_INFO);
MAGMA_STRUCT(GR_IMAGE_RESOLVE);
MAGMA_STRUCT(GR_IMAGE_STATE_TRANSITION);
MAGMA_STRUCT(GR_IMAGE_SUBRESOURCE);
MAGMA_STRUCT(GR_IMAGE_SUBRESOURCE_RANGE);
MAGMA_STRUCT(GR_IMAGE_VIEW_ATTACH_INFO);
MAGMA_STRUCT(GR_IMAGE_VIEW_CREATE_INFO);
MAGMA_STRUCT(GR_LINK_CONST_BUFFER);
MAGMA_STRUCT(GR_MEMORY_ALLOC_INFO);
MAGMA_STRUCT(GR_MEMORY_COPY);
MAGMA_STRUCT(GR_MEMORY_IMAGE_COPY);
MAGMA_STRUCT(GR_MEMORY_HEAP_PROPERTIES);
MAGMA_STRUCT(GR_MEMORY_OPEN_INFO);
MAGMA_STRUCT(GR_MEMORY_REF);
MAGMA_STRUCT(GR_MEMORY_STATE_TRANSITION);
MAGMA_STRUCT(GR_MEMORY_VIEW_ATTACH_INFO);
MAGMA_STRUCT(GR_MSAA_STATE_CREATE_INFO);
MAGMA_STRUCT(GR_OFFSET2D);
MAGMA_STRUCT(GR_OFFSET3D);
MAGMA_STRUCT(GR_PARENT_DEVICE);
MAGMA_STRUCT(GR_PARENT_PHYSICAL_GPU);
MAGMA_STRUCT(GR_PEER_IMAGE_OPEN_INFO);
MAGMA_STRUCT(GR_PEER_MEMORY_OPEN_INFO);
MAGMA_STRUCT(GR_PHYSICAL_GPU_IMAGE_PROPERTIES);
MAGMA_STRUCT(GR_PHYSICAL_GPU_MEMORY_PROPERTIES);
MAGMA_STRUCT(GR_PHYSICAL_GPU_PERFORMANCE);
MAGMA_STRUCT(GR_PHYSICAL_GPU_PROPERTIES);
MAGMA_STRUCT(GR_PHYSICAL_GPU_QUEUE_PROPERTIES);
MAGMA_STRUCT(GR_PIPELINE_CB_STATE);
MAGMA_STRUCT(GR_PIPELINE_CB_TARGET_STATE);
MAGMA_STRUCT(GR_PIPELINE_DB_STATE);
MAGMA_STRUCT(GR_PIPELINE_IA_STATE);
MAGMA_STRUCT(GR_PIPELINE_RS_STATE);
MAGMA_STRUCT(GR_PIPELINE_SHADER);
MAGMA_STRUCT(GR_PIPELINE_STATISTICS_DATA);
MAGMA_STRUCT(GR_PIPELINE_TESS_STATE);
MAGMA_STRUCT(GR_QUERY_POOL_CREATE_INFO);
MAGMA_STRUCT(GR_QUEUE_SEMAPHORE_CREATE_INFO);
MAGMA_STRUCT(GR_QUEUE_SEMAPHORE_OPEN_INFO);
MAGMA_STRUCT(GR_RASTER_STATE_CREATE_INFO);
MAGMA_STRUCT(GR_RECT);
MAGMA_STRUCT(GR_SAMPLER_CREATE_INFO);
MAGMA_STRUCT(GR_SHADER_CREATE_INFO);
MAGMA_STRUCT(GR_SUBRESOURCE_LAYOUT);
MAGMA_STRUCT(GR_VIEWPORT);
MAGMA_STRUCT(GR_VIEWPORT_STATE_CREATE_INFO);
MAGMA_STRUCT(GR_VIRTUAL_MEMORY_REMAP_RANGE);



// callbacks
MAGMA_CALLBACK(GR_VOID *, GR_ALLOC_FUNCTION)(
    GR_SIZE size,
    GR_SIZE alignment,
    GR_ENUM allocType
);

MAGMA_CALLBACK(GR_VOID, GR_FREE_FUNCTION)(
    GR_VOID *pMem
);



// initialization and device functions
MAGMA_FUNCTION(GR_RESULT, grInitAndEnumerateGpus)(
    const GR_APPLICATION_INFO *pAppInfo,
    const GR_ALLOC_CALLBACKS  *pAllocCb,
    GR_UINT                   *pGpuCount,
    GR_PHYSICAL_GPU            gpus[GR_MAX_PHYSICAL_GPUS]
);

MAGMA_FUNCTION(GR_RESULT, grGetGpuInfo)(
    GR_PHYSICAL_GPU gpu,
    GR_ENUM         infoType,
    GR_SIZE        *pDataSize,
    GR_VOID        *pData
);

MAGMA_FUNCTION(GR_RESULT, grCreateDevice)(
    GR_PHYSICAL_GPU              gpu,
    const GR_DEVICE_CREATE_INFO *pCreateInfo,
    GR_DEVICE                   *pDevice
);

MAGMA_FUNCTION(GR_RESULT, grDestroyDevice)(
    GR_DEVICE device
);



// extension discovery functions
MAGMA_FUNCTION(GR_RESULT, grGetExtensionSupport)(
    GR_PHYSICAL_GPU gpu,
    const GR_CHAR  *pExtName
);



// queue functions
MAGMA_FUNCTION(GR_RESULT, grGetDeviceQueue)(
    GR_DEVICE device,
    GR_ENUM   queueType,
    GR_UINT   queueId,
    GR_QUEUE *pQueue
);

MAGMA_FUNCTION(GR_RESULT, grQueueWaitIdle)(
    GR_QUEUE queue
);

MAGMA_FUNCTION(GR_RESULT, grDeviceWaitIdle)(
    GR_DEVICE device
);

MAGMA_FUNCTION(GR_RESULT, grQueueSubmit)(
    GR_QUEUE             queue,
    GR_UINT              cmdBufferCount,
    const GR_CMD_BUFFER *pCmdBuffers,
    GR_UINT              memRefCount,
    const GR_MEMORY_REF *pMemRefs,
    GR_FENCE             fence
);

MAGMA_FUNCTION(GR_RESULT, grQueueSetGlobalMemReferences)(
    GR_QUEUE             queue,
    GR_UINT              memRefCount,
    const GR_MEMORY_REF *pMemRefs
);



// memory management functions
MAGMA_FUNCTION(GR_RESULT, grGetMemoryHeapCount)(
    GR_DEVICE device,
    GR_UINT  *pCount
);

MAGMA_FUNCTION(GR_RESULT, grGetMemoryHeapInfo)(
    GR_DEVICE device,
    GR_UINT   heapId,
    GR_ENUM   infoType,
    GR_SIZE  *pDataSize,
    GR_VOID  *pData
);

MAGMA_FUNCTION(GR_RESULT, grAllocMemory)(
    GR_DEVICE                   device,
    const GR_MEMORY_ALLOC_INFO *pAllocInfo,
    GR_GPU_MEMORY              *pMem
);

MAGMA_FUNCTION(GR_RESULT, grFreeMemory)(
    GR_GPU_MEMORY mem
);

MAGMA_FUNCTION(GR_RESULT, grSetMemoryPriority)(
    GR_GPU_MEMORY mem,
    GR_ENUM       priority
);

MAGMA_FUNCTION(GR_RESULT, grMapMemory)(
    GR_GPU_MEMORY mem,
    GR_FLAGS      flags,
    GR_VOID     **ppData
);

MAGMA_FUNCTION(GR_RESULT, grUnmapMemory)(
    GR_GPU_MEMORY mem
);

MAGMA_FUNCTION(GR_RESULT, grRemapVirtualMemoryPages)(
    GR_DEVICE                            device,
    GR_UINT                              rangeCount,
    const GR_VIRTUAL_MEMORY_REMAP_RANGE *pRanges,
    GR_UINT                              preWaitSemaphoreCount,
    const GR_QUEUE_SEMAPHORE            *pPreWaitSemaphores,
    GR_UINT                              postSignalSemaphoreCount,
    const GR_QUEUE_SEMAPHORE            *pPostSignalSemaphores
);

MAGMA_FUNCTION(GR_RESULT, grPinSystemMemory)(
    GR_DEVICE      device,
    const GR_VOID *pSystem,
    GR_SIZE        memSize,
    GR_GPU_MEMORY *pMem
);



// generic API object management functions
MAGMA_FUNCTION(GR_RESULT, grDestroyObject)(
    GR_OBJECT object
);

MAGMA_FUNCTION(GR_RESULT, grGetObjectInfo)(
    GR_BASE_OBJECT object,
    GR_ENUM        infoType,
    GR_SIZE       *pDataSize,
    GR_VOID       *pData
);

MAGMA_FUNCTION(GR_RESULT, grBindObjectMemory)(
    GR_OBJECT     object,
    GR_GPU_MEMORY mem,
    GR_GPU_SIZE   offset
);



// image and sampler functions
MAGMA_FUNCTION(GR_RESULT, grGetFormatInfo)(
    GR_DEVICE device,
    GR_FORMAT format,
    GR_ENUM   infoType,
    GR_SIZE  *pDataSize,
    GR_VOID  *pData
);

MAGMA_FUNCTION(GR_RESULT, grCreateImage)(
    GR_DEVICE                   device,
    const GR_IMAGE_CREATE_INFO *pCreateInfo,
    GR_IMAGE                   *pImage
);

MAGMA_FUNCTION(GR_RESULT, grGetImageSubresourceInfo)(
    GR_IMAGE                    image,
    const GR_IMAGE_SUBRESOURCE *pSubresource,
    GR_ENUM                     infoType,
    GR_SIZE                    *pDataSize,
    GR_VOID                    *pData
);

MAGMA_FUNCTION(GR_RESULT, grCreateSampler)(
    GR_DEVICE                     device,
    const GR_SAMPLER_CREATE_INFO *pCreateInfo,
    GR_SAMPLER                   *pSampler
);



// image view functions
MAGMA_FUNCTION(GR_RESULT, grCreateImageView)(
    GR_DEVICE                        device,
    const GR_IMAGE_VIEW_CREATE_INFO *pCreateInfo,
    GR_IMAGE_VIEW                   *pView
);

MAGMA_FUNCTION(GR_RESULT, grCreateColorTargetView)(
    GR_DEVICE                               device,
    const GR_COLOR_TARGET_VIEW_CREATE_INFO *pCreateInfo,
    GR_COLOR_TARGET_VIEW                   *pView
);

MAGMA_FUNCTION(GR_RESULT, grCreateDepthStencilView)(
    GR_DEVICE                                device,
    const GR_DEPTH_STENCIL_VIEW_CREATE_INFO *pCreateInfo,
    GR_DEPTH_STENCIL_VIEW                   *pView
);



// shader and pipeline functions
MAGMA_FUNCTION(GR_RESULT, grCreateShader)(
    GR_DEVICE                    device,
    const GR_SHADER_CREATE_INFO *pCreateInfo,
    GR_SHADER                   *pShader
);

MAGMA_FUNCTION(GR_RESULT, grCreateGraphicsPipeline)(
    GR_DEVICE                               device,
    const GR_GRAPHICS_PIPELINE_CREATE_INFO *pCreateInfo,
    GR_PIPELINE                            *pPipeline
);

MAGMA_FUNCTION(GR_RESULT, grCreateComputePipeline)(
    GR_DEVICE                              device,
    const GR_COMPUTE_PIPELINE_CREATE_INFO *pCreateInfo,
    GR_PIPELINE                           *pPipeline
);

MAGMA_FUNCTION(GR_RESULT, grStorePipeline)(
    GR_PIPELINE pipeline,
    GR_SIZE    *pDataSize,
    GR_VOID    *pData
);

MAGMA_FUNCTION(GR_RESULT, grLoadPipeline)(
    GR_DEVICE      device,
    GR_SIZE        dataSize,
    const GR_VOID *data,
    GR_PIPELINE   *pPipeline
);



// descriptor set functions
MAGMA_FUNCTION(GR_RESULT, grCreateDescriptorSet)(
    GR_DEVICE                            device,
    const GR_DESCRIPTOR_SET_CREATE_INFO *pCreateInfo,
    GR_DESCRIPTOR_SET                   *pDescriptorSet
);

MAGMA_FUNCTION(GR_RESULT, grBeginDescriptorSetUpdate)(
    GR_DESCRIPTOR_SET descriptorSet
);

MAGMA_FUNCTION(GR_RESULT, grEndDescriptorSetUpdate)(
    GR_DESCRIPTOR_SET descriptorSet
);

MAGMA_FUNCTION(GR_RESULT, grAttachSamplerDescriptors)(
    GR_DESCRIPTOR_SET descriptorSet,
    GR_UINT           startSlot,
    GR_UINT           slotCount,
    const GR_SAMPLER *pSamplers
);

MAGMA_FUNCTION(GR_RESULT, grAttachImageViewDescriptors)(
    GR_DESCRIPTOR_SET                descriptorSet,
    GR_UINT                          startSlot,
    GR_UINT                          slotCount,
    const GR_IMAGE_VIEW_ATTACH_INFO *pImageViews
);

MAGMA_FUNCTION(GR_RESULT, grAttachMemoryViewDescriptors)(
    GR_DESCRIPTOR_SET                 descriptorSet,
    GR_UINT                           startSlot,
    GR_UINT                           slotCount,
    const GR_MEMORY_VIEW_ATTACH_INFO *pMemViews
);

MAGMA_FUNCTION(GR_RESULT, grAttachNestedDescriptors)(
    GR_DESCRIPTOR_SET                    descriptorSet,
    GR_UINT                              startSlot,
    GR_UINT                              slotCount,
    const GR_DESCRIPTOR_SET_ATTACH_INFO *pImageViews
);

MAGMA_FUNCTION(GR_RESULT, grClearDescriptorSetSlots)(
    GR_DESCRIPTOR_SET descriptorSet,
    GR_UINT           startSlot,
    GR_UINT           slotCount
);



// state object functions
MAGMA_FUNCTION(GR_RESULT, grCreateViewportState)(
    GR_DEVICE                            device,
    const GR_VIEWPORT_STATE_CREATE_INFO *pCreateInfo,
    GR_VIEWPORT_STATE_OBJECT            *pState
);

MAGMA_FUNCTION(GR_RESULT, grCreateRasterState)(
    GR_DEVICE                          device,
    const GR_RASTER_STATE_CREATE_INFO *pCreateInfo,
    GR_RASTER_STATE_OBJECT            *pState
);

MAGMA_FUNCTION(GR_RESULT, grCreateColorBlendState)(
    GR_DEVICE                               device,
    const GR_COLOR_BLEND_STATE_CREATE_INFO *pCreateInfo,
    GR_COLOR_BLEND_STATE_OBJECT            *pState
);

MAGMA_FUNCTION(GR_RESULT, grCreateDepthStencilState)(
    GR_DEVICE                                 device,
    const GR_DEPTH_STENCIL_STATE_CREATE_INFO *pCreateInfo,
    GR_DEPTH_STENCIL_STATE_OBJECT            *pState
);

MAGMA_FUNCTION(GR_RESULT, grCreateMsaaState)(
    GR_DEVICE                        device,
    const GR_MSAA_STATE_CREATE_INFO *pCreateInfo,
    GR_MSAA_STATE_OBJECT            *pState
);



// query and synchronization functions
MAGMA_FUNCTION(GR_RESULT, grCreateQueryPool)(
    GR_DEVICE                        device,
    const GR_QUERY_POOL_CREATE_INFO *pCreateInfo,
    GR_QUERY_POOL                   *pQueryPool
);

MAGMA_FUNCTION(GR_RESULT, grGetQueryPoolResults)(
    GR_QUERY_POOL queryPool,
    GR_UINT       startQuery,
    GR_UINT       queryCount,
    GR_SIZE      *pDataSize,
    GR_VOID      *pData
);

MAGMA_FUNCTION(GR_RESULT, grCreateFence)(
    GR_DEVICE                   device,
    const GR_FENCE_CREATE_INFO *pCreateInfo,
    GR_FENCE                   *pFence
);

MAGMA_FUNCTION(GR_RESULT, grGetFenceStatus)(
    GR_FENCE fence
);

MAGMA_FUNCTION(GR_RESULT, grWaitForFences)(
    GR_DEVICE       device,
    GR_UINT         fenceCount,
    const GR_FENCE *pFences,
    GR_BOOL         waitAll,
    GR_FLOAT        timeout
);

MAGMA_FUNCTION(GR_RESULT, grCreateQueueSemaphore)(
    GR_DEVICE                             device,
    const GR_QUEUE_SEMAPHORE_CREATE_INFO *pCreateInfo,
    GR_QUEUE_SEMAPHORE                   *pSemaphore
);

MAGMA_FUNCTION(GR_RESULT, grSignalQueueSemaphore)(
    GR_QUEUE           queue,
    GR_QUEUE_SEMAPHORE semaphore
);

MAGMA_FUNCTION(GR_RESULT, grWaitQueueSemaphore)(
    GR_QUEUE           queue,
    GR_QUEUE_SEMAPHORE semaphore
);

MAGMA_FUNCTION(GR_RESULT, grCreateEvent)(
    GR_DEVICE                   device,
    const GR_EVENT_CREATE_INFO *pCreateInfo,
    GR_EVENT                   *pEvent
);

MAGMA_FUNCTION(GR_RESULT, grGetEventStatus)(
    GR_EVENT event
);

MAGMA_FUNCTION(GR_RESULT, grSetEvent)(
    GR_EVENT event
);

MAGMA_FUNCTION(GR_RESULT, grResetEvent)(
    GR_EVENT event
);



// multi-device management functions
MAGMA_FUNCTION(GR_RESULT, grGetMultiGpuCapability)(
    GR_PHYSICAL_GPU            gpu0,
    GR_PHYSICAL_GPU            gpu1,
    GR_GPU_COMPATIBILITY_INFO *pInfo
);

MAGMA_FUNCTION(GR_RESULT, grOpenSharedMemory)(
    GR_DEVICE                  device,
    const GR_MEMORY_OPEN_INFO *pOpenInfo,
    GR_GPU_MEMORY             *pMem
);

MAGMA_FUNCTION(GR_RESULT, grOpenSharedQueueSemaphore)(
    GR_DEVICE                           device,
    const GR_QUEUE_SEMAPHORE_OPEN_INFO *pOpenInfo,
    GR_QUEUE_SEMAPHORE                 *pSemaphore
);

MAGMA_FUNCTION(GR_RESULT, grOpenPeerMemory)(
    GR_DEVICE                       device,
    const GR_PEER_MEMORY_OPEN_INFO *pOpenInfo,
    GR_GPU_MEMORY                  *pMem
);

MAGMA_FUNCTION(GR_RESULT, grOpenPeerImage)(
    GR_DEVICE                      device,
    const GR_PEER_IMAGE_OPEN_INFO *pOpenInfo,
    GR_GPU_MEMORY                 *pMem
);



// command buffer management functions
MAGMA_FUNCTION(GR_RESULT, grCreateCommandBuffer)(
    GR_DEVICE                        device,
    const GR_CMD_BUFFER_CREATE_INFO *pCreateInfo,
    GR_CMD_BUFFER                   *pCmdBuffer
);

MAGMA_FUNCTION(GR_RESULT, grBeginCommandBuffer)(
    GR_CMD_BUFFER cmdBuffer,
    GR_FLAGS      flags
);

MAGMA_FUNCTION(GR_RESULT, grEndCommandBuffer)(
    GR_CMD_BUFFER cmdBuffer
);

MAGMA_FUNCTION(GR_RESULT, grResetCommandBuffer)(
    GR_CMD_BUFFER cmdBuffer
);



// command buffer building functions
MAGMA_FUNCTION(GR_RESULT, grCmdBindPipeline)(
    GR_CMD_BUFFER cmdBuffer,
    GR_ENUM       pipelineBindPoint,
    GR_PIPELINE   pipeline
);

MAGMA_FUNCTION(GR_RESULT, grCmdBindStateObject)(
    GR_CMD_BUFFER   cmdBuffer,
    GR_ENUM         stateBindPoint,
    GR_STATE_OBJECT state
);

MAGMA_FUNCTION(GR_RESULT, grCmdBindDescriptorSet)(
    GR_CMD_BUFFER     cmdBuffer,
    GR_ENUM           pipelineBindPoint,
    GR_UINT           index,
    GR_DESCRIPTOR_SET descriptorSet,
    GR_UINT           slotOffset
);

MAGMA_FUNCTION(GR_RESULT, grCmdBindDynamicMemoryView)(
    GR_CMD_BUFFER                     cmdBuffer,
    GR_ENUM                           pipelineBindPoint,
    const GR_MEMORY_VIEW_ATTACH_INFO *pMemView
);

MAGMA_FUNCTION(GR_RESULT, grCmdBindIndexData)(
    GR_CMD_BUFFER cmdBuffer,
    GR_GPU_MEMORY mem,
    GR_GPU_SIZE   offset,
    GR_ENUM       indexType
);

MAGMA_FUNCTION(GR_RESULT, grCmdBindTargets)(
    GR_CMD_BUFFER                     cmdBuffer,
    GR_UINT                           colorTargetCount,
    const GR_COLOR_TARGET_BIND_INFO  *pColorTargets,
    const GR_DEPTH_STENCIL_BIND_INFO *pDepthTarget
);

MAGMA_FUNCTION(GR_RESULT, grCmdPrepareMemoryRegions)(
    GR_CMD_BUFFER                     cmdBuffer,
    GR_UINT                           transitionCount,
    const GR_MEMORY_STATE_TRANSITION *pStateTransitions
);

MAGMA_FUNCTION(GR_RESULT, grCmdPrepareImages)(
    GR_CMD_BUFFER                    cmdBuffer,
    GR_UINT                          transitionCount,
    const GR_IMAGE_STATE_TRANSITION *pStateTransitions
);

MAGMA_FUNCTION(GR_RESULT, grCmdDraw)(
    GR_CMD_BUFFER cmdBuffer,
    GR_UINT       firstVertex,
    GR_UINT       vertexCount,
    GR_UINT       firstInstance,
    GR_UINT       instanceCount
);

MAGMA_FUNCTION(GR_RESULT, grCmdDrawIndexed)(
    GR_CMD_BUFFER cmdBuffer,
    GR_UINT       firstIndex,
    GR_UINT       indexCount,
    GR_INT        vertexOffset,
    GR_UINT       firstInstance,
    GR_UINT       instanceCount
);

MAGMA_FUNCTION(GR_RESULT, grCmdDrawIndirect)(
    GR_CMD_BUFFER cmdBuffer,
    GR_GPU_MEMORY mem,
    GR_GPU_SIZE   offset
);

MAGMA_FUNCTION(GR_RESULT, grCmdDrawIndexedIndirect)(
    GR_CMD_BUFFER cmdBuffer,
    GR_GPU_MEMORY mem,
    GR_GPU_SIZE   offset
);

MAGMA_FUNCTION(GR_RESULT, grCmdDispatch)(
    GR_CMD_BUFFER cmdBuffer,
    GR_UINT       x,
    GR_UINT       y,
    GR_UINT       z
);

MAGMA_FUNCTION(GR_RESULT, grCmdDispatchIndirect)(
    GR_CMD_BUFFER cmdBuffer,
    GR_GPU_MEMORY mem,
    GR_GPU_SIZE   offset
);

MAGMA_FUNCTION(GR_RESULT, grCmdCopyMemory)(
    GR_CMD_BUFFER         cmdBuffer,
    GR_GPU_MEMORY         srcMem,
    GR_GPU_MEMORY         destMem,
    GR_UINT               regionCount,
    const GR_MEMORY_COPY *pRegions
);

MAGMA_FUNCTION(GR_RESULT, grCmdCopyImage)(
    GR_CMD_BUFFER        cmdBuffer,
    GR_IMAGE             srcImage,
    GR_IMAGE             destImage,
    GR_UINT              regionCount,
    const GR_IMAGE_COPY *pRegions
);

MAGMA_FUNCTION(GR_RESULT, grCmdCopyMemoryToImage)(
    GR_CMD_BUFFER               cmdBuffer,
    GR_GPU_MEMORY               srcMem,
    GR_IMAGE                    destImage,
    GR_UINT                     regionCount,
    const GR_MEMORY_IMAGE_COPY *pRegions
);

MAGMA_FUNCTION(GR_RESULT, grCmdCopyImageToMemory)(
    GR_CMD_BUFFER               cmdBuffer,
    GR_IMAGE                    srcImage,
    GR_GPU_MEMORY               destMem,
    GR_UINT                     regionCount,
    const GR_MEMORY_IMAGE_COPY *pRegions
);

MAGMA_FUNCTION(GR_RESULT, grCmdResolveImage)(
    GR_CMD_BUFFER           cmdBuffer,
    GR_IMAGE                srcImage,
    GR_IMAGE                destImage,
    GR_UINT                 regionCount,
    const GR_IMAGE_RESOLVE *pRegions
);

MAGMA_FUNCTION(GR_RESULT, grCmdCloneImageData)(
    GR_CMD_BUFFER cmdBuffer,
    GR_IMAGE      srcImage,
    GR_ENUM       srcImageState,
    GR_IMAGE      destImage,
    GR_ENUM       destImageState
);

MAGMA_FUNCTION(GR_RESULT, grCmdUpdateMemory)(
    GR_CMD_BUFFER    cmdBuffer,
    GR_GPU_MEMORY    destMem,
    GR_GPU_SIZE      destOffset,
    GR_GPU_SIZE      dataSize,
    const GR_UINT32 *pData
);

MAGMA_FUNCTION(GR_RESULT, grCmdFillMemory)(
    GR_CMD_BUFFER cmdBuffer,
    GR_GPU_MEMORY destMem,
    GR_GPU_SIZE   destOffset,
    GR_GPU_SIZE   fillSize,
    GR_UINT32     data
);

MAGMA_FUNCTION(GR_RESULT, grCmdClearColorImage)(
    GR_CMD_BUFFER                     cmdBuffer,
    GR_IMAGE                          image,
    const GR_FLOAT                    color[4],
    GR_UINT                           rangeCount,
    const GR_IMAGE_SUBRESOURCE_RANGE *pRanges
);

MAGMA_FUNCTION(GR_RESULT, grCmdClearColorImageRaw)(
    GR_CMD_BUFFER                     cmdBuffer,
    GR_IMAGE                          image,
    const GR_UINT32                   color[4],
    GR_UINT                           rangeCount,
    const GR_IMAGE_SUBRESOURCE_RANGE *pRanges
);

MAGMA_FUNCTION(GR_RESULT, grCmdClearDepthStencil)(
    GR_CMD_BUFFER                     cmdBuffer,
    GR_IMAGE                          image,
    GR_FLOAT                          depth,
    GR_UINT8                          stencil,
    GR_UINT                           rangeCount,
    const GR_IMAGE_SUBRESOURCE_RANGE *pRanges
);

MAGMA_FUNCTION(GR_RESULT, grCmdSetEvent)(
    GR_CMD_BUFFER cmdBuffer,
    GR_EVENT      event
);

MAGMA_FUNCTION(GR_RESULT, grCmdResetEvent)(
    GR_CMD_BUFFER cmdBuffer,
    GR_EVENT      event
);

MAGMA_FUNCTION(GR_RESULT, grCmdMemoryAtomic)(
    GR_CMD_BUFFER cmdBuffer,
    GR_GPU_MEMORY destMem,
    GR_GPU_SIZE   destOffset,
    GR_UINT64     srcData,
    GR_ENUM       atomicOp
);

MAGMA_FUNCTION(GR_RESULT, grCmdBeginQuery)(
    GR_CMD_BUFFER cmdBuffer,
    GR_QUERY_POOL queryPool,
    GR_UINT       slot,
    GR_FLAGS      flags
);

MAGMA_FUNCTION(GR_RESULT, grCmdEndQuery)(
    GR_CMD_BUFFER cmdBuffer,
    GR_QUERY_POOL queryPool,
    GR_UINT       slot
);

MAGMA_FUNCTION(GR_RESULT, grCmdResetQueryPool)(
    GR_CMD_BUFFER cmdBuffer,
    GR_QUERY_POOL queryPool,
    GR_UINT       startQuery,
    GR_UINT       queryCount
);

MAGMA_FUNCTION(GR_RESULT, grCmdWriteTimestamp)(
    GR_CMD_BUFFER cmdBuffer,
    GR_ENUM       timestampType,
    GR_GPU_MEMORY destMem,
    GR_GPU_SIZE   destOffset
);

MAGMA_FUNCTION(GR_RESULT, grCmdInitAtomicCounters)(
    GR_CMD_BUFFER    cmdBuffer,
    GR_ENUM          pipelineBindPoint,
    GR_UINT          startCounter,
    GR_UINT          counterCount,
    const GR_UINT32 *pData
);

MAGMA_FUNCTION(GR_RESULT, grCmdLoadAtomicCounters)(
    GR_CMD_BUFFER cmdBuffer,
    GR_ENUM       pipelineBindPoint,
    GR_UINT       startCounter,
    GR_UINT       counterCount,
    GR_GPU_MEMORY srcMem,
    GR_GPU_SIZE   srcOffset
);

MAGMA_FUNCTION(GR_RESULT, grCmdSaveAtomicCounters)(
    GR_CMD_BUFFER cmdBuffer,
    GR_ENUM       pipelineBindPoint,
    GR_UINT       startCounter,
    GR_UINT       counterCount,
    GR_GPU_MEMORY destMem,
    GR_GPU_SIZE   destOffset
);



// enumerations
enum _GR_ATOMIC_OP {
    GR_ATOMIC_ADD_INT32 = 0x2d00,
    GR_ATOMIC_SUB_INT32,
    GR_ATOMIC_MIN_UINT32,
    GR_ATOMIC_MAX_UINT32,
    GR_ATOMIC_MIN_SINT32,
    GR_ATOMIC_MAX_SINT32,
    GR_ATOMIC_AND_INT32,
    GR_ATOMIC_OR_INT32,
    GR_ATOMIC_XOR_INT32,
    GR_ATOMIC_INC_UINT32,
    GR_ATOMIC_DEC_UINT32,
    GR_ATOMIC_ADD_INT64,
    GR_ATOMIC_SUB_INT64,
    GR_ATOMIC_MIN_UINT64,
    GR_ATOMIC_MAX_UINT64,
    GR_ATOMIC_MIN_SINT64,
    GR_ATOMIC_MAX_SINT64,
    GR_ATOMIC_AND_INT64,
    GR_ATOMIC_OR_INT64,
    GR_ATOMIC_XOR_INT64,
    GR_ATOMIC_INC_UINT64,
    GR_ATOMIC_DEC_UINT64
};

enum _GR_BORDER_COLOR_TYPE {
    GR_BORDER_COLOR_WHITE = 0x1c00,
    GR_BORDER_COLOR_TRANSPARENT_BLACK,
    GR_BORDER_COLOR_OPAQUE_BLACK
};

enum _GR_BLEND {
    GR_BLEND_ZERO = 0x2900,
    GR_BLEND_ONE,
    GR_BLEND_SRC_COLOR,
    GR_BLEND_ONE_MINUS_SRC_COLOR,
    GR_BLEND_DEST_COLOR,
    GR_BLEND_ONE_MINUS_DEST_COLOR,
    GR_BLEND_SRC_ALPHA,
    GR_BLEND_ONE_MINUS_SRC_ALPHA,
    GR_BLEND_DEST_ALPHA,
    GR_BLEND_ONE_MINUS_DEST_ALPHA,
    GR_BLEND_CONSTANT_COLOR,
    GR_BLEND_ONE_MINUS_CONSTANT_COLOR,
    GR_BLEND_CONSTANT_ALPHA,
    GR_BLEND_ONE_MINUS_CONSTANT_ALPHA,
    GR_BLEND_SRC_ALPHA_SATURATE,
    GR_BLEND_SRC1_COLOR,
    GR_BLEND_ONE_MINUS_SRC1_COLOR,
    GR_BLEND_SRC1_ALPHA,
    GR_BLEND_ONE_MINUS_SRC1_ALPHA
};

enum _GR_BLEND_FUNC {
    GR_BLEND_FUNC_ADD = 0x2a00,
    GR_BLEND_FUNC_SUBTRACT,
    GR_BLEND_FUNC_REVERSE_SUBTRACT,
    GR_BLEND_FUNC_MIN,
    GR_BLEND_FUNC_MAX
};

enum _GR_CHANNEL_FORMAT {
    GR_CH_FMT_UNDEFINED,
    GR_CH_FMT_R4G4,
    GR_CH_FMT_R4G4B4A4,
    GR_CH_FMT_R5G6B5,
    GR_CH_FMT_B5G6R5,
    GR_CH_FMT_R5G5B5A1,
    GR_CH_FMT_R8,
    GR_CH_FMT_R8G8,
    GR_CH_FMT_R8G8B8A8,
    GR_CH_FMT_B8G8R8A8,
    GR_CH_FMT_R10G11B11,
    GR_CH_FMT_R11G11B10,
    GR_CH_FMT_R10G10B10A2,
    GR_CH_FMT_R16,
    GR_CH_FMT_R16G16,
    GR_CH_FMT_R16G16B16A16,
    GR_CH_FMT_R32,
    GR_CH_FMT_R32G32,
    GR_CH_FMT_R32G32B32,
    GR_CH_FMT_R32G32B32A32,
    GR_CH_FMT_R16G8,
    GR_CH_FMT_R32G8,
    GR_CH_FMT_R9G9B9E5,
    GR_CH_FMT_BC1,
    GR_CH_FMT_BC2,
    GR_CH_FMT_BC3,
    GR_CH_FMT_BC4,
    GR_CH_FMT_BC5,
    GR_CH_FMT_BC6U,
    GR_CH_FMT_BC6S,
    GR_CH_FMT_BC7
};

enum _GR_CHANNEL_SWIZZLE {
    GR_CHANNEL_SWIZZLE_ZERO = 0x1800,
    GR_CHANNEL_SWIZZLE_ONE,
    GR_CHANNEL_SWIZZLE_R,
    GR_CHANNEL_SWIZZLE_G,
    GR_CHANNEL_SWIZZLE_B,
    GR_CHANNEL_SWIZZLE_A
};

enum _GR_COMPARE_FUNC {
    GR_COMPARE_NEVER = 0x2500,
    GR_COMPARE_LESS,
    GR_COMPARE_EQUAL,
    GR_COMPARE_LESS_EQUAL,
    GR_COMPARE_GREATER,
    GR_COMPARE_NOT_EQUAL,
    GR_COMPARE_GREATER_EQUAL,
    GR_COMPARE_ALWAYS
};

enum _GR_CULL_MODE {
    GR_CULL_NONE = 0x2700,
    GR_CULL_FRONT,
    GR_CULL_BACK
};

enum _GR_DESCRIPTOR_SET_SLOT_TYPE {
    GR_SLOT_UNUSED = 0x1900,
    GR_SLOT_SHADER_RESOURCE,
    GR_SLOT_SHADER_UAV,
    GR_SLOT_SHADER_SAMPLER,
    GR_SLOT_NEXT_DESCRIPTOR_SET
};

enum _GR_FACE_ORIENTATION {
    GR_FRONT_FACE_CCW = 0x2800,
    GR_FRONT_FACE_CW
};

enum _GR_FILL_MODE {
    GR_FILL_SOLID = 0x2600,
    GR_FILL_WIREFRAME
};

enum _GR_HEAP_MEMORY_TYPE {
    GR_HEAP_MEMORY_OTHER = 0x2f00,
    GR_HEAP_MEMORY_LOCAL,
    GR_HEAP_MEMORY_REMOTE,
    GR_HEAP_MEMORY_EMBEDDED
};

enum _GR_IMAGE_ASPECT {
    GR_IMAGE_ASPECT_COLOR = 0x1700,
    GR_IMAGE_ASPECT_DEPTH,
    GR_IMAGE_ASPECT_STENCIL
};

enum _GR_IMAGE_STATE {
    GR_IMAGE_STATE_DATA_TRANSFER = 0x1300,
    GR_IMAGE_STATE_GRAPHICS_SHADER_READ_ONLY,
    GR_IMAGE_STATE_GRAPHICS_SHADER_WRITE_ONLY,
    GR_IMAGE_STATE_GRAPHICS_SHADER_READ_WRITE,
    GR_IMAGE_STATE_COMPUTE_SHADER_READ_ONLY,
    GR_IMAGE_STATE_COMPUTE_SHADER_WRITE_ONLY,
    GR_IMAGE_STATE_COMPUTE_SHADER_READ_WRITE,
    GR_IMAGE_STATE_MULTI_SHADER_READ_ONLY,
    GR_IMAGE_STATE_TARGET_AND_SHADER_READ_ONLY,
    GR_IMAGE_STATE_UNINITIALIZED,
    GR_IMAGE_STATE_TARGET_RENDER_ACCESS_OPTIMAL,
    GR_IMAGE_STATE_TARGET_SHADER_ACCESS_OPTIMAL,
    GR_IMAGE_STATE_CLEAR,
    GR_IMAGE_STATE_RESOLVE_SOURCE,
    GR_IMAGE_STATE_RESOLVE_DESTINATION,
    GR_IMAGE_STATE_DISCARD,
    GR_IMAGE_STATE_DATA_TRANSFER_SOURCE,
    GR_IMAGE_STATE_DATA_TRANSFER_DESTINATION
};

enum _GR_IMAGE_TILING {
    GR_LINEAR_TILING = 0x1500,
    GR_OPTIMAL_TILING
};

enum _GR_IMAGE_TYPE {
    GR_IMAGE_1D = 0x1400,
    GR_IMAGE_2D,
    GR_IMAGE_3D
};

enum _GR_IMAGE_VIEW_TYPE {
    GR_IMAGE_VIEW_1D = 0x1600,
    GR_IMAGE_VIEW_2D,
    GR_IMAGE_VIEW_3D,
    GR_IMAGE_VIEW_CUBE
};

enum _GR_INDEX_TYPE {
    GR_INDEX_16 = 0x2100,
    GR_INDEX_32
};

enum _GR_INFO_TYPE {
    GR_INFO_TYPE_PHYSICAL_GPU_PROPERTIES = 0x6100,
    GR_INFO_TYPE_PHYSICAL_GPU_PERFORMANCE,
    GR_INFO_TYPE_PHYSICAL_GPU_QUEUE_PROPERTIES,
    GR_INFO_TYPE_PHYSICAL_GPU_MEMORY_PROPERTIES,
    GR_INFO_TYPE_PHYSICAL_GPU_IMAGE_PROPERTIES,

    GR_INFO_TYPE_MEMORY_HEAP_PROPERTIES = 0x6200,

    GR_INFO_TYPE_FORMAT_PROPERTIES = 0x6300,

    GR_INFO_TYPE_SUBRESOURCE_LAYOUT = 0x6400,

    GR_INFO_TYPE_MEMORY_REQUIREMENTS = 0x6800,
    GR_INFO_TYPE_PARENT_DEVICE,
    GR_INFO_TYPE_PARENT_PHYSICAL_GPU
};

enum _GR_LOGIC_OP {
    GR_LOGIC_OP_COPY = 0x2c00,
    GR_LOGIC_OP_CLEAR,
    GR_LOGIC_OP_AND,
    GR_LOGIC_OP_AND_REVERSE,
    GR_LOGIC_OP_AND_INVERTED,
    GR_LOGIC_OP_NOOP,
    GR_LOGIC_OP_XOR,
    GR_LOGIC_OP_OR,
    GR_LOGIC_OP_NOR,
    GR_LOGIC_OP_EQUIV,
    GR_LOGIC_OP_INVERT,
    GR_LOGIC_OP_OR_REVERSE,
    GR_LOGIC_OP_COPY_INVERTED,
    GR_LOGIC_OP_OR_INVERTED,
    GR_LOGIC_OP_NAND,
    GR_LOGIC_OP_SET
};

enum _GR_MEMORY_PRIORITY {
    GR_MEMORY_PRIORITY_NORMAL = 0x1100,
    GR_MEMORY_PRIORITY_HIGH,
    GR_MEMORY_PRIORITY_LOW,
    GR_MEMORY_PRIORITY_UNUSED,
    GR_MEMORY_PRIORITY_VERY_HIGH,
    GR_MEMORY_PRIORITY_VERY_LOW
};

enum _GR_MEMORY_STATE {
    GR_MEMORY_STATE_DATA_TRANSFER = 0x1200,
    GR_MEMORY_STATE_GRAPHICS_SHADER_READ_ONLY,
    GR_MEMORY_STATE_GRAPHICS_SHADER_WRITE_ONLY,
    GR_MEMORY_STATE_GRAPHICS_SHADER_READ_WRITE,
    GR_MEMORY_STATE_COMPUTE_SHADER_READ_ONLY,
    GR_MEMORY_STATE_COMPUTE_SHADER_WRITE_ONLY,
    GR_MEMORY_STATE_COMPUTE_SHADER_READ_WRITE,
    GR_MEMORY_STATE_MULTI_USE_READ_ONLY,
    GR_MEMORY_STATE_INDEX_DATA,
    GR_MEMORY_STATE_INDIRECT_ARG,
    GR_MEMORY_STATE_WRITE_TIMESTAMP,
    GR_MEMORY_STATE_QUEUE_ATOMIC,
    GR_MEMORY_STATE_DISCARD,
    GR_MEMORY_STATE_DATA_TRANSFER_SOURCE,
    GR_MEMORY_STATE_DATA_TRANSFER_DESTINATION
};

enum _GR_NUM_FORMAT {
    GR_NUM_FMT_UNDEFINED,
    GR_NUM_FMT_UNORM,
    GR_NUM_FMT_SNORM,
    GR_NUM_FMT_UINT,
    GR_NUM_FMT_SINT,
    GR_NUM_FMT_FLOAT,
    GR_NUM_FMT_SRGB,
    GR_NUM_FMT_DS
};

enum _GR_PHYSICAL_GPU_TYPE {
    GR_GPU_TYPE_OTHER = 0x3000,
    GR_GPU_TYPE_INTEGRATED,
    GR_GPU_TYPE_DISCRETE,
    GR_GPU_TYPE_VIRTUAL
};

enum _GR_PIPELINE_BIND_POINT {
    GR_PIPELINE_BIND_POINT_COMPUTE = 0x1e00,
    GR_PIPELINE_BIND_POINT_GRAPHICS
};

enum _GR_PRIMITIVE_TOPOLOGY {
    GR_TOPOLOGY_POINT_LIST = 0x2000,
    GR_TOPOLOGY_LINE_LIST,
    GR_TOPOLOGY_LINE_STRIP,
    GR_TOPOLOGY_TRIANGLE_LIST,
    GR_TOPOLOGY_TRIANGLE_STRIP,
    GR_TOPOLOGY_RECT_LIST,
    GR_TOPOLOGY_QUAD_LIST,
    GR_TOPOLOGY_QUAD_STRIP,
    GR_TOPOLOGY_LINE_LIST_ADJ,
    GR_TOPOLOGY_LINE_STIP_ADJ,
    GR_TOPOLOGY_TRIANGLE_LIST_ADJ,
    GR_TOPOLOGY_TRIANGLE_STRIP_ADJ,
    GR_TOPOLOGY_PATCH
};

enum _GR_QUERY_TYPE {
    GR_QUERY_OCCLUSION = 0x1a00,
    GR_QUERY_PIPELINE_STATISTICS
};

enum _GR_QUEUE_TYPE {
    GR_QUEUE_UNIVERSAL = 0x1000,
    GR_QUEUE_COMPUTE
};

enum _GR_RESULT {
    GR_SUCCESS = 0x10000,
    GR_UNSUPPORTED,
    GR_NOT_READY,
    GR_TIMEOUT,
    GR_EVENT_SET,
    GR_EVENT_RESET,

    GR_ERROR_UNKNOWN = 0x11000,
    GR_ERROR_UNAVAILABLE,
    GR_ERROR_INITIALIZATION_FAILED,
    GR_ERROR_OUT_OF_MEMORY,
    GR_ERROR_OUT_OF_GPU_MEMORY,
    GR_ERROR_DEVICE_ALREADY_CREATED,
    GR_ERROR_DEVICE_LOST,
    GR_ERROR_INVALID_POINTER,
    GR_ERROR_INVALID_VALUE,
    GR_ERROR_INVALID_HANDLE,
    GR_ERROR_INVALID_ORDINAL,
    GR_ERROR_INVALID_MEMORY_SIZE,
    GR_ERROR_INVALID_EXTENSION,
    GR_ERROR_INVALID_FLAGS,
    GR_ERROR_INVALID_ALIGNMENT,
    GR_ERROR_INVALID_FORMAT,
    GR_ERROR_INVALID_IMAGE,
    GR_ERROR_INVALID_DESCRIPTOR_SET_DATA,
    GR_ERROR_INVALID_QUEUE_TYPE,
    GR_ERROR_INVALID_OBJECT_TYPE,
    GR_ERROR_UNSUPPORTED_SHADER_IL_VERSION,
    GR_ERROR_BAD_SHADER_CODE,
    GR_ERROR_BAD_PIPELINE_DATA,
    GR_ERROR_TOO_MANY_MEMORY_REFERENCES,
    GR_ERROR_NOT_MAPPABLE,
    GR_ERROR_MEMORY_MAP_FAILED,
    GR_ERROR_MEMORY_UNMAP_FAILED,
    GR_ERROR_INCOMPATIBLE_DEVICE,
    GR_ERROR_INCOMPATIBLE_DRIVER,
    GR_ERROR_INCOMPLETE_COMMAND_BUFFER,
    GR_ERROR_BUILDING_COMMAND_BUFFER,
    GR_ERROR_MEMORY_NOT_BOUND,
    GR_ERROR_INCOMPATIBLE_QUEUE,
    GR_ERROR_NOT_SHAREABLE
};

enum _GR_STATE_BIND_POINT {
    GR_STATE_BIND_VIEWPORT = 0x1f00,
    GR_STATE_BIND_RASTER,
    GR_STATE_BIND_DEPTH_STENCIL,
    GR_STATE_BIND_COLOR_BLEND,
    GR_STATE_BIND_MSAA
};

enum _GR_STENCIL_OP {
    GR_STENCIL_OP_KEEP = 0x2b00,
    GR_STENCIL_OP_ZERO,
    GR_STENCIL_OP_REPLACE,
    GR_STENCIL_OP_INC_CLAMP,
    GR_STENCIL_OP_DEC_CLAMP,
    GR_STENCIL_OP_INVERT,
    GR_STENCIL_OP_INC_WRAP,
    GR_STENCIL_OP_DEC_WRAP
};

enum _GR_SYSTEM_ALLOC_TYPE {
    GR_SYSTEM_ALLOC_API_OBJECT = 0x2e00,
    GR_SYSTEM_ALLOC_INTERNAL,
    GR_SYSTEM_ALLOC_INTERNAL_TEMP,
    GR_SYSTEM_ALLOC_INTERNAL_SHADER,
    GR_SYSTEM_ALLOC_DEBUG
};

enum _GR_TEX_ADDRESS {
    GR_TEX_ADDRESS_WRAP = 0x2400,
    GR_TEX_ADDRESS_MIRROR,
    GR_TEX_ADDRESS_CLAMP,
    GR_TEX_ADDRESS_MIRROR_ONCE,
    GR_TEX_ADDRESS_CLAMP_BORDER
};

enum _GR_TEX_FILTER {
    GR_TEX_FILTER_MAG_POINT_MIN_POINT_MIP_POINT    = 0x2340,
    GR_TEX_FILTER_MAG_LINEAR_MIN_POINT_MIP_POINT   = 0x2341,
    GR_TEX_FILTER_MAG_POINT_MIN_LINEAR_MIP_POINT   = 0x2344,
    GR_TEX_FILTER_MAG_LINEAR_MIN_LINEAR_MIP_POINT  = 0x2345,
    GR_TEX_FILTER_MAG_POINT_MIN_POINT_MIP_LINEAR   = 0x2380,
    GR_TEX_FILTER_MAG_LINEAR_MIN_POINT_MIP_LINEAR  = 0x2381,
    GR_TEX_FILTER_MAG_POINT_MIN_LINEAR_MIP_LINEAR  = 0x2384,
    GR_TEX_FILTER_MAG_LINEAR_MIN_LINEAR_MIP_LINEAR = 0x2385,
    GR_TEX_FILTER_ANISOTROPIC                      = 0x238f
};

enum _GR_TIMESTAMP_TYPE {
    GR_TIMESTAMP_TOP = 0x1b00,
    GR_TIMESTAMP_BOTTOM
};

enum _GR_VALIDATION_LEVEL {
    GR_VALIDATION_LEVEL_0 = 0x8000,
    GR_VALIDATION_LEVEL_1,
    GR_VALIDATION_LEVEL_2,
    GR_VALIDATION_LEVEL_3,
    GR_VALIDATION_LEVEL_4
};



// flags
enum _GR_CMD_BUFFER_BUILD_FLAGS {
    GR_CMD_BUFFER_OPTIMIZE_GPU_SMALL_BATCH       = 1 << 0,
    GR_CMD_BUFFER_OPTIMIZE_PIPELINE_SWITCH       = 1 << 1,
    GR_CMD_BUFFER_OPTIMIZE_ONE_TIME_SUBMIT       = 1 << 2,
    GR_CMD_BUFFER_OPTIMIZE_DESCRIPTOR_SET_SWITCH = 1 << 3
};

enum _GR_DEPTH_STENCIL_VIEW_CREATE_FLAGS {
    GR_DEPTH_STENCIL_VIEW_CREATE_READ_ONLY_DEPTH   = 1 << 0,
    GR_DEPTH_STENCIL_VIEW_CREATE_READ_ONLY_STENCIL = 1 << 1
};

enum _GR_DEVICE_CREATE_FLAGS {
    GR_DEVICE_CREATE_VALIDATION = 1 << 0
};

enum _GR_FORMAT_FEATURE_FLAGS {
    GR_FORMAT_IMAGE_SHADER_READ    = 1 << 0,
    GR_FORMAT_IMAGE_SHADER_WRITE   = 1 << 1,
    GR_FORMAT_IMAGE_COPY           = 1 << 2,
    GR_FORMAT_MEMORY_SHADER_ACCESS = 1 << 3,
    GR_FORMAT_COLOR_TARGET_WRITE   = 1 << 4,
    GR_FORMAT_COLOR_TARGET_BLEND   = 1 << 5,
    GR_FORMAT_DEPTH_TARGET         = 1 << 6,
    GR_FORMAT_STENCIL_TARGET       = 1 << 7,
    GR_FORMAT_MSAA_TARGET          = 1 << 8,
    GR_FORMAT_CONVERSION           = 1 << 9
};

enum _GR_GPU_COMPATIBILITY_FLAGS {
    GR_GPU_COMPAT_ASIC_FEATURES       = 1 << 0,
    GR_GPU_COMPAT_IQ_MATCH            = 1 << 1,
    GR_GPU_COMPAT_PEER_WRITE_TRANSFER = 1 << 2,
    GR_GPU_COMPAT_SHARED_MEMORY       = 1 << 3,
    GR_GPU_COMPAT_SHARED_SYNC         = 1 << 4,
    GR_GPU_COMPAT_SHARED_GPU0_DISPLAY = 1 << 5,
    GR_GPU_COMPAT_SHARED_GPU1_DISPLAY = 1 << 6
};

enum _GR_IMAGE_CREATE_FLAGS {
    GR_IMAGE_CREATE_INVARIANT_DATA     = 1 << 0,
    GR_IMAGE_CREATE_CLONEABLE          = 1 << 1,
    GR_IMAGE_CREATE_SHAREABLE          = 1 << 2,
    GR_IMAGE_CREATE_VIEW_FORMAT_CHANGE = 1 << 3
};

enum _GR_IMAGE_USAGE_FLAGS {
    GR_IMAGE_USAGE_SHADER_ACCESS_READ  = 1 << 0,
    GR_IMAGE_USAGE_SHADER_ACCESS_WRITE = 1 << 1,
    GR_IMAGE_USAGE_COLOR_TARGET        = 1 << 2,
    GR_IMAGE_USAGE_DEPTH_STENCIL       = 1 << 3
};

enum _GR_MEMORY_ALLOC_FLAGS {
    GR_MEMORY_ALLOC_VIRTUAL   = 1 << 0,
    GR_MEMORY_ALLOC_SHAREABLE = 1 << 1
};

enum _GR_MEMORY_HEAP_FLAGS {
    GR_MEMORY_HEAP_CPU_VISIBLE        = 1 << 0,
    GR_MEMORY_HEAP_CPU_GPU_COHERENT   = 1 << 1,
    GR_MEMORY_HEAP_CPU_UNCACHED       = 1 << 2,
    GR_MEMORY_HEAP_CPU_WRITE_COMBINED = 1 << 3,
    GR_MEMORY_HEAP_HOLDS_PINNED       = 1 << 4,
    GR_MEMORY_HEAP_HEAP_SHAREABLE     = 1 << 5
};

enum _GR_MEMORY_PROPERTY_FLAGS {
    GR_MEMORY_MIGRATION_SUPPORT         = 1 << 0,
    GR_MEMORY_VIRTUAL_REMAPPING_SUPPORT = 1 << 1,
    GR_MEMORY_PINNING_SUPPORT           = 1 << 2,
    GR_MEMORY_PREFER_GLOBAL_REFS        = 1 << 3
};

enum _GR_MEMORY_REF_FLAGS {
    GR_MEMORY_REF_READ_ONLY = 1 << 0
};

enum _GR_PIPELINE_CREATE_FLAGS {
    GR_PIPELINE_CREATE_DISABLE_OPTIMIZATION = 1 << 0
};

enum _GR_QUERY_CONTROL_FLAGS {
    GR_QUERY_IMPRECISE_DATA = 1 << 0
};

enum _GR_SEMAPHORE_CREATE_FLAGS {
    GR_SEMAPHORE_CREATE_SHAREABLE = 1 << 0
};

enum _GR_SHADER_CREATE_FLAGS {
    GR_SHADER_CREATE_ALLOW_RE_Z = 1 << 0
};



// primary structures
struct _GR_ALLOC_CALLBACKS {
    GR_ALLOC_FUNCTION pfnAlloc;
    GR_FREE_FUNCTION  pfnFree;
};

struct _GR_APPLICATION_INFO {
    const GR_CHAR *pAppName;
    GR_UINT32      appVersion;
    const GR_CHAR *pEngineName;
    GR_UINT32      engineVersion;
    GR_UINT32      apiVersion;
};

struct _GR_CHANNEL_MAPPING {
    GR_ENUM r;
    GR_ENUM g;
    GR_ENUM b;
    GR_ENUM a;
};

struct _GR_CMD_BUFFER_CREATE_INFO {
    GR_ENUM  queueType;
    GR_FLAGS flags;
};

struct _GR_COLOR_TARGET_BIND_INFO {
    GR_COLOR_TARGET_VIEW view;
    GR_ENUM              colorTargetState;
};

struct _GR_COLOR_TARGET_BLEND_STATE {
    GR_BOOL blendEnable;
    GR_ENUM srcBlendColor;
    GR_ENUM destBlendColor;
    GR_ENUM blendFuncColor;
    GR_ENUM srcBlendAlpha;
    GR_ENUM destBlendAlpha;
    GR_ENUM blendFuncAlpha;
};

struct _GR_DEPTH_STENCIL_BIND_INFO {
    GR_DEPTH_STENCIL_VIEW view;
    GR_ENUM               depthState;
    GR_ENUM               stencilState;
};

struct _GR_DEPTH_STENCIL_CREATE_INFO {
    GR_IMAGE image;
    GR_UINT  mipLevel;
    GR_UINT  baseArraySlice;
    GR_UINT  arraySize;
    GR_FLAGS flags;
};

struct _GR_DEPTH_STENCIL_OP {
    GR_ENUM  stencilFailOp;
    GR_ENUM  stencilPassOp;
    GR_ENUM  stencilDepthFailOp;
    GR_ENUM  stencilFunc;
    GR_UINT8 stencilRef;
};

struct _GR_DEPTH_STENCIL_VIEW_CREATE_INFO {
    GR_IMAGE image;
    GR_UINT  mipLevel;
    GR_UINT  baseArraySlice;
    GR_UINT  arraySize;
    GR_FLAGS flags;
};

struct _GR_DESCRIPTOR_SET_ATTACH_INFO {
    GR_DESCRIPTOR_SET descriptorSet;
    GR_UINT           slotOffset;
};

struct _GR_DESCRIPTOR_SET_CREATE_INFO {
    GR_UINT slots;
};

struct _GR_DESCRIPTOR_SET_MAPPING {
    GR_UINT                        descriptorCount;
    const GR_DESCRIPTOR_SLOT_INFO *pDescriptorInfo;
};

struct _GR_DESCRIPTOR_SLOT_INFO {
    GR_ENUM slotObjectType;
    union {
        GR_UINT                                  shaderEntityIndex;
        const struct _GR_DESCRIPTOR_SET_MAPPING *pNextLevelSet;
    };
};

struct _GR_DEVICE_CREATE_INFO {
    GR_UINT                            queueRecordCount;
    const GR_DEVICE_QUEUE_CREATE_INFO *pRequestedQueues;
    GR_UINT                            extensionCount;
    const GR_CHAR *const              *ppEnabledExtensionNames;
    GR_ENUM                            maxValidationLevel;
    GR_FLAGS                           flags;
};

struct _GR_DEVICE_QUEUE_CREATE_INFO {
    GR_ENUM queueType;
    GR_UINT queueCount;
};

struct _GR_DISPATCH_INDIRECT_ARG {
    GR_UINT32 x;
    GR_UINT32 y;
    GR_UINT32 z;
};

struct _GR_DRAW_INDEXED_INDIRECT_ARG {
    GR_UINT32 indexCount;
    GR_UINT32 instanceCount;
    GR_UINT32 firstIndex;
    GR_INT32  vertexOffset;
    GR_UINT32 firstINstance;
};

struct _GR_DRAW_INDIRECT_ARG {
    GR_UINT32 vertexCount;
    GR_UINT32 instanceCount;
    GR_UINT32 firstVertex;
    GR_UINT32 firstInstance;
};

struct _GR_DYNAMIC_MEMORY_VIEW_SLOT_INFO {
    GR_ENUM slotObjectType;
    GR_UINT shaderEntityIndex;
};

struct _GR_EVENT_CREATE_INFO {
    GR_FLAGS flags;
};

struct _GR_EXTENT2D {
    GR_INT width;
    GR_INT height;
};

struct _GR_EXTENT3D {
    GR_INT width;
    GR_INT height;
    GR_INT depth;
};

struct _GR_FENCE_CREATE_INFO {
    GR_FLAGS flags;
};

struct _GR_FORMAT {
    GR_UINT32 channelFormat : 16;
    GR_UINT32 numericFormat : 16;
};

struct _GR_FORMAT_PROPERTIES {
    GR_FLAGS linearTilingFeatures;
    GR_FLAGS optimalTilingFeatures;
};

struct _GR_GPU_COMPATIBILITY_INFO {
    GR_FLAGS compatibilityFlags;
};

struct _GR_IMAGE_SUBRESOURCE {
    GR_ENUM aspect;
    GR_UINT mipLevel;
    GR_UINT arraySlice;
};

struct _GR_IMAGE_SUBRESOURCE_RANGE {
    GR_ENUM aspect;
    GR_UINT baseMipLevel;
    GR_UINT mipLevels;
    GR_UINT baseArraySlice;
    GR_UINT arraySize;
};

struct _GR_IMAGE_VIEW_ATTACH_INFO {
    GR_IMAGE_VIEW view;
    GR_ENUM       state;
};

struct _GR_LINK_CONST_BUFFER {
    GR_UINT        bufferId;
    GR_SIZE        bufferSize;
    const GR_VOID *pBufferData;
};

struct _GR_MEMORY_ALLOC_INFO {
    GR_GPU_SIZE size;
    GR_GPU_SIZE alignment;
    GR_FLAGS    flags;
    GR_UINT     heapCount;
    GR_UINT     heaps[GR_MAX_MEMORY_HEAPS];
    GR_ENUM     memPriority;
};

struct _GR_MEMORY_COPY {
    GR_GPU_SIZE srcOffset;
    GR_GPU_SIZE destOffset;
    GR_GPU_SIZE copySize;
};

struct _GR_MEMORY_HEAP_PROPERTIES {
    GR_ENUM     heapMemoryType;
    GR_GPU_SIZE heapSize;
    GR_GPU_SIZE pageSize;
    GR_FLAGS    flags;
    GR_FLOAT    gpuReadPerfRating;
    GR_FLOAT    gpuWritePerfRating;
    GR_FLOAT    cpuReadPerfRating;
    GR_FLOAT    cpuWritePerfRating;
};

struct _GR_MEMORY_REF {
    GR_GPU_MEMORY mem;
    GR_FLAGS      flags;
};

struct _GR_MEMORY_REQUIREMENTS {
    GR_GPU_SIZE size;
    GR_GPU_SIZE alignment;
    GR_UINT     heapCount;
    GR_UINT     heaps[GR_MAX_MEMORY_HEAPS];
};

struct _GR_MEMORY_STATE_TRANSITION {
    GR_GPU_MEMORY mem;
    GR_ENUM       oldState;
    GR_ENUM       newState;
    GR_GPU_SIZE   offset;
    GR_GPU_SIZE   regionSize;
};

struct _GR_MSAA_STATE_CREATE_INFO {
    GR_UINT        samples;
    GR_SAMPLE_MASK sampleMask;
};

struct _GR_OFFSET2D {
    GR_INT x;
    GR_INT y;
};

struct _GR_OFFSET3D {
    GR_INT x;
    GR_INT y;
    GR_INT z;
};

struct _GR_PARENT_DEVICE {
    GR_DEVICE device;
};

struct _GR_PARENT_PHYSICAL_GPU {
    GR_PHYSICAL_GPU gpu;
};

struct _GR_PEER_IMAGE_OPEN_INFO {
    GR_IMAGE originalImage;
};

struct _GR_PEER_MEMORY_OPEN_INFO {
    GR_GPU_MEMORY originalMem;
};

struct _GR_PHYSICAL_GPU_IMAGE_PROPERTIES {
    GR_UINT     maxSliceWidth;
    GR_UINT     maxSliceHeight;
    GR_UINT     maxDepth;
    GR_UINT     maxArraySlices;
    GR_UINT     reserved1;
    GR_UINT     reserved2;
    GR_GPU_SIZE maxMemoryAlignment;
    GR_UINT32   sparseImageSupportLevel;
    GR_FLAGS    flags;
};

struct _GR_PHYSICAL_GPU_MEMORY_PROPERTIES {
    GR_FLAGS    flags;
    GR_GPU_SIZE virtualMemPageSize;
    GR_GPU_SIZE maxVirtualMemSize;
    GR_GPU_SIZE maxPhysicalMemSize;
};

struct _GR_PHYSICAL_GPU_PERFORMANCE {
    GR_FLOAT maxGpuClock;
    GR_FLOAT aluPerClock;
    GR_FLOAT texPerClock;
    GR_FLOAT primsPerClock;
    GR_FLOAT pixelsPerClock;
};

struct _GR_PHYSICAL_GPU_PROPERTIES {
    GR_UINT32   apiVersion;
    GR_UINT32   driverVersion;
    GR_UINT32   vendorId;
    GR_UINT32   deviceId;
    GR_ENUM     gpuType;
    GR_CHAR     gpuName[GR_MAX_PHYSICAL_GPU_NAME];
    GR_UINT     maxMemRefsPerSubmission;
    GR_GPU_SIZE reserved;
    GR_GPU_SIZE maxInlineMemoryUpdateSize;
    GR_UINT     maxBoundDescriptorSets;
    GR_UINT     maxThreadGroupSize;
    GR_UINT64   timestampFrequency;
    GR_BOOL     multiColorTargetClears;
};

struct _GR_PHYSICAL_GPU_QUEUE_PROPERTIES {
    GR_ENUM queueType;
    GR_UINT queueCount;
    GR_UINT maxAtomicCounters;
    GR_BOOL supportsTimestamps;
};

struct _GR_PIPELINE_IA_STATE {
    GR_ENUM topology;
    GR_BOOL disableVertexReuse;
};

struct _GR_PIPELINE_RS_STATE {
    GR_BOOL depthClipEnable;
};

struct _GR_PIPELINE_STATISTICS_DATA {
    GR_UINT64 psInvocations;
    GR_UINT64 cPrimitives;
    GR_UINT64 cInvocations;
    GR_UINT64 vsInvocations;
    GR_UINT64 gsInvocations;
    GR_UINT64 gsPrimitives;
    GR_UINT64 iaPrimitives;
    GR_UINT64 iaVertices;
    GR_UINT64 hsInvocations;
    GR_UINT64 dsInvocations;
    GR_UINT64 csInvocations;
};

struct _GR_PIPELINE_TESS_STATE {
    GR_UINT  patchControlPoints;
    GR_FLOAT optimalTessFactor;
};

struct _GR_QUERY_POOL_CREATE_INFO {
    GR_ENUM queryType;
    GR_UINT slots;
};

struct _GR_QUEUE_SEMAPHORE_CREATE_INFO {
    GR_UINT  initialCount;
    GR_FLAGS flags;
};

struct _GR_QUEUE_SEMAPHORE_OPEN_INFO {
    GR_QUEUE_SEMAPHORE sharedSemaphore;
};

struct _GR_RASTER_STATE_CREATE_INFO {
    GR_ENUM  fillMode;
    GR_ENUM  cullMode;
    GR_ENUM  frontFace;
    GR_INT   depthBias;
    GR_FLOAT depthBiasClamp;
    GR_FLOAT slopeScaledDepthBias;
};

struct _GR_SAMPLER_CREATE_INFO {
    GR_ENUM  filter;
    GR_ENUM  addressU;
    GR_ENUM  addressV;
    GR_ENUM  addressW;
    GR_FLOAT mipLodBias;
    GR_UINT  maxAnisotropy;
    GR_ENUM  compareFunc;
    GR_FLOAT minLod;
    GR_FLOAT maxLod;
    GR_ENUM  borderColor;
};

struct _GR_SHADER_CREATE_INFO {
    GR_SIZE        codeSize;
    const GR_VOID *pCode;
    GR_FLAGS       flags;
};

struct _GR_SUBRESOURCE_LAYOUT {
    GR_GPU_SIZE offset;
    GR_GPU_SIZE size;
    GR_GPU_SIZE rowPitch;
    GR_GPU_SIZE depthPitch;
};

struct _GR_VIEWPORT {
    GR_FLOAT originX;
    GR_FLOAT originY;
    GR_FLOAT width;
    GR_FLOAT height;
    GR_FLOAT minDepth;
    GR_FLOAT maxDepth;
};

struct _GR_VIRTUAL_MEMORY_REMAP_RANGE {
    GR_GPU_MEMORY virtualMem;
    GR_GPU_SIZE   virtualStartPage;
    GR_GPU_MEMORY realMem;
    GR_GPU_SIZE   realStartPage;
    GR_GPU_SIZE   pageCount;
};



// secondary structures
struct _GR_COLOR_BLEND_STATE_CREATE_INFO {
    GR_COLOR_TARGET_BLEND_STATE target[GR_MAX_COLOR_TARGETS];
    GR_FLOAT                    blendConst[4];
};

struct _GR_COLOR_TARGET_VIEW_CREATE_INFO {
    GR_IMAGE  image;
    GR_FORMAT format;
    GR_UINT   mipLevel;
    GR_UINT   baseArraySlice;
    GR_UINT   arraySize;
};

struct _GR_DEPTH_STENCIL_STATE_CREATE_INFO {
    GR_BOOL             depthEnable;
    GR_BOOL             depthWriteEnable;
    GR_ENUM             depthFunc;
    GR_BOOL             depthBoundsEnable;
    GR_FLOAT            minDepth;
    GR_FLOAT            maxDepth;
    GR_BOOL             stencilEnable;
    GR_UINT8            stencilReadMask;
    GR_UINT8            stencilWriteMask;
    GR_DEPTH_STENCIL_OP front;
    GR_DEPTH_STENCIL_OP back;
};

struct _GR_IMAGE_COPY {
    GR_IMAGE_SUBRESOURCE srcSubresource;
    GR_OFFSET3D          srcOffset;
    GR_IMAGE_SUBRESOURCE destSubresource;
    GR_OFFSET3D          destOffset;
    GR_EXTENT3D          extent;
};

struct _GR_IMAGE_CREATE_INFO {
    GR_ENUM     imageType;
    GR_FORMAT   format;
    GR_EXTENT3D extent;
    GR_UINT     mipLevels;
    GR_UINT     arraySize;
    GR_UINT     samples;
    GR_ENUM     tiling;
    GR_FLAGS    usage;
    GR_FLAGS    flags;
};

struct _GR_IMAGE_RESOLVE {
    GR_IMAGE_SUBRESOURCE srcSubresource;
    GR_OFFSET2D          srcOffset;
    GR_IMAGE_SUBRESOURCE destSubresource;
    GR_OFFSET2D          destOffset;
    GR_EXTENT2D          extent;
};

struct _GR_IMAGE_STATE_TRANSITION {
    GR_IMAGE                   image;
    GR_ENUM                    oldState;
    GR_ENUM                    newState;
    GR_IMAGE_SUBRESOURCE_RANGE subresourceRange;
};

struct _GR_IMAGE_VIEW_CREATE_INFO {
    GR_IMAGE                   image;
    GR_ENUM                    viewType;
    GR_FORMAT                  format;
    GR_CHANNEL_MAPPING         channels;
    GR_IMAGE_SUBRESOURCE_RANGE subresourceRange;
    GR_FLOAT                   minLod;
};

struct _GR_MEMORY_IMAGE_COPY {
    GR_GPU_SIZE          memOffset;
    GR_IMAGE_SUBRESOURCE imageSubresource;
    GR_OFFSET3D          imageOffset;
    GR_EXTENT3D          imageExtent;
};

struct _GR_MEMORY_VIEW_ATTACH_INFO {
    GR_GPU_MEMORY mem;
    GR_GPU_SIZE   offset;
    GR_GPU_SIZE   range;
    GR_GPU_SIZE   stride;
    GR_FORMAT     format;
    GR_ENUM       state;
};

struct _GR_PIPELINE_CB_TARGET_STATE {
    GR_BOOL   blendEnable;
    GR_FORMAT format;
    GR_UINT8  channelWriteMask;
};

struct _GR_PIPELINE_DB_STATE {
    GR_FORMAT format;
};

struct _GR_PIPELINE_SHADER {
    GR_SHADER                        shader;
    GR_DESCRIPTOR_SET_MAPPING        descriptorSetMapping[GR_MAX_DESCRIPTOR_SETS];
    GR_UINT                          linkConstBufferCount;
    const GR_LINK_CONST_BUFFER      *pLinkConstBufferInfo;
    GR_DYNAMIC_MEMORY_VIEW_SLOT_INFO dynamicMemoryViewMapping;
};

struct _GR_RECT {
    GR_OFFSET2D offset;
    GR_EXTENT2D extent;
};



// tertiary structures
struct _GR_COMPUTE_PIPELINE_CREATE_INFO {
    GR_PIPELINE_SHADER cs;
    GR_FLAGS           flags;
};

struct _GR_PIPELINE_CB_STATE {
    GR_BOOL                     alphaToCoverageEnable;
    GR_BOOL                     dualSourceBlendEnable;
    GR_ENUM                     logicOp;
    GR_PIPELINE_CB_TARGET_STATE target[GR_MAX_COLOR_TARGETS];
};

struct _GR_VIEWPORT_STATE_CREATE_INFO {
    GR_UINT     viewportCount;
    GR_BOOL     scissorEnable;
    GR_VIEWPORT viewports[GR_MAX_VIEWPORTS];
    GR_RECT     scissors[GR_MAX_VIEWPORTS];
};



// quaternary structures
struct _GR_GRAPHICS_PIPELINE_CREATE_INFO {
    GR_PIPELINE_SHADER     vs;
    GR_PIPELINE_SHADER     hs;
    GR_PIPELINE_SHADER     ds;
    GR_PIPELINE_SHADER     gs;
    GR_PIPELINE_SHADER     ps;
    GR_PIPELINE_IA_STATE   iaState;
    GR_PIPELINE_TESS_STATE tessState;
    GR_PIPELINE_RS_STATE   rsState;
    GR_PIPELINE_CB_STATE   cbState;
    GR_PIPELINE_DB_STATE   dbState;
    GR_FLAGS               flags;
};



#ifdef __cplusplus
}
#endif

#endif
