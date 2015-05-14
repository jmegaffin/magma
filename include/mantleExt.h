#ifndef _MANTLE_EXT_H
#define _MANTLE_EXT_H

#include "mantle.h"

#ifdef __cplusplus
extern "C" {
#endif



// constants (guessed)
#define GR_AXL_VERSION                 1
#define GR_MAX_MSAA_RASTERIZER_SAMPLES 16



// macros
#define GR_EXT_BORDER_COLOR_TYPE_PALETTE_ENTRY(i) (GR_EXT_BORDER_COLOR_TYPE_PALETTE_ENTRY_0+(i));



// type aliases
MAGMA_HANDLE(GR_BORDER_COLOR_PALETTE);



// forward declarations
MAGMA_ENUM(GR_EXT_BORDER_COLOR_TYPE);
MAGMA_ENUM(GR_EXT_INFO_TYPE);
MAGMA_ENUM(GR_EXT_IMAGE_STATE);
MAGMA_ENUM(GR_EXT_MEMORY_STATE);
MAGMA_ENUM(GR_EXT_OCCLUSION_CONDITION);
MAGMA_ENUM(GR_EXT_QUEUE_TYPE);

MAGMA_ENUM(GR_EXT_CONTROL_FLOW_FEATURE_FLAGS);
MAGMA_ENUM(GR_EXT_ACCESS_CLIENT);

MAGMA_STRUCT(GR_BORDER_COLOR_PALETTE_PROPERTIES);
MAGMA_STRUCT(GR_BORDER_COLOR_PALETTE_CREATE_INFO);
MAGMA_STRUCT(GR_ADVANCED_MSAA_STATE_CREATE_INFO);
MAGMA_STRUCT(GR_FMASK_IMAGE_VIEW_CREATE_INFO);
MAGMA_STRUCT(GR_MSAA_QUAD_SAMPLE_PATTERN);
MAGMA_STRUCT(GR_QUEUE_CONTROL_FLOW_PROPERTIES);
MAGMA_STRUCT(GR_GPU_TIMESTAMP_CALIBRATION);



// extension interface functions
MAGMA_FUNCTION(GR_UINT32, grGetExtensionLibraryVersion)(void);



// border color palette functions
MAGMA_FUNCTION(GR_RESULT, grCreateBorderColorPalette)(
	GR_DEVICE                                  device,
	const GR_BORDER_COLOR_PALETTE_CREATE_INFO *pCreateInfo,
	GR_BORDER_COLOR_PALETTE                   *pPalette
);

MAGMA_FUNCTION(GR_RESULT, grUpdateBorderColorPalette)(
	GR_BORDER_COLOR_PALETTE palette,
	GR_UINT                 firstEntry,
	GR_UINT                 entryCount,
	const GR_FLOAT         *pEntries
);

MAGMA_FUNCTION(GR_RESULT, grCmdBindBorderColorPalette)(
	GR_CMD_BUFFER           cmdBuffer,
	GR_ENUM                 pipelineBindPoint,
	GR_BORDER_COLOR_PALETTE palette
);



// advanced multisampling functions
MAGMA_FUNCTION(GR_RESULT, grCreateAdvancedMsaaState)(
	GR_DEVICE                                 device,
	const GR_ADVANCED_MSAA_STATE_CREATE_INFO *pCreateInfo,
	GR_MSAA_STATE_OBJECT                     *pState
);

MAGMA_FUNCTION(GR_RESULT, grCreateFmaskImageView)(
	GR_DEVICE                              device,
	const GR_FMASK_IMAGE_VIEW_CREATE_INFO *pCreateInfo,
	GR_IMAGE_VIEW                         *pView
);



// copy occlusion query data functions
MAGMA_FUNCTION(GR_RESULT, grCmdCopyOcclusionData)(
	GR_CMD_BUFFER cmdBuffer,
	GR_QUERY_POOL queryPool,
	GR_UINT       startQuery,
	GR_UINT       queryCount,
	GR_GPU_MEMORY destMem,
	GR_GPU_SIZE   destOffset,
	GR_BOOL       accumulateData
);



// command buffer control flow functions
MAGMA_FUNCTION(GR_VOID, grCmdSetOcclusionPredication)(
	GR_CMD_BUFFER cmdBuffer,
	GR_QUERY_POOL queryPool,
	GR_UINT       slot,
	GR_ENUM       condition,
	GR_BOOL       waitResults,
	GR_BOOL       accumulateData
);

MAGMA_FUNCTION(GR_VOID, grCmdResetOcclusionPredication)(
	GR_CMD_BUFFER cmdBuffer
);

MAGMA_FUNCTION(GR_VOID, grCmdSetMemoryPredication)(
	GR_CMD_BUFFER cmdBuffer,
	GR_GPU_MEMORY mem,
	GR_GPU_SIZE   offset
);

MAGMA_FUNCTION(GR_VOID, grCmdResetMemoryPredication)(
	GR_CMD_BUFFER cmdBuffer
);

MAGMA_FUNCTION(GR_VOID, grCmdIf)(
	GR_CMD_BUFFER cmdBuffer,
	GR_GPU_MEMORY srcMem,
	GR_GPU_SIZE   srcOffset,
	GR_UINT64     data,
	GR_UINT64     mask,
	GR_ENUM       func
);

MAGMA_FUNCTION(GR_VOID, grCmdElse)(
	GR_CMD_BUFFER cmdBuffer
);

MAGMA_FUNCTION(GR_VOID, grCmdEndIf)(
	GR_CMD_BUFFER cmdBuffer
);

MAGMA_FUNCTION(GR_VOID, grCmdWhile)(
	GR_CMD_BUFFER cmdBuffer,
	GR_GPU_MEMORY srcMem,
	GR_GPU_SIZE   srcOffset,
	GR_UINT64     data,
	GR_UINT64     mask,
	GR_ENUM       func
);

MAGMA_FUNCTION(GR_VOID, grCmdEndWhile)(
	GR_CMD_BUFFER cmdBuffer
);



// timer queue functions
MAGMA_FUNCTION(GR_RESULT, grQueueDelay)(
	GR_QUEUE queue,
	GR_FLOAT delay
);



// GPU timestamp calibration functions
MAGMA_FUNCTION(GR_RESULT, grCalibrateGpuTimestamp)(
	GR_DEVICE device,
	GR_GPU_TIMESTAMP_CALIBRATION *pCalibrationData
);



// enumerations
enum _GR_EXT_BORDER_COLOR_TYPE {
	GR_EXT_BORDER_COLOR_TYPE_PALETTE_ENTRY_0 = 0x0030a000
};

enum _GR_EXT_INFO_TYPE {
	GR_EXT_INFO_TYPE_QUEUE_BORDER_COLOR_PALETTE_PROPERTIES = 0x00306800,
	GR_EXT_INFO_TYPE_QUEUE_CONTROL_FLOW_PROPERTIES
};

enum _GR_EXT_IMAGE_STATE {
	GR_EXT_IMAGE_STATE_GRAPHICS_SHADER_FMASK_LOOKUP = 0x00300100,
	GR_EXT_IMAGE_STATE_COMPUTE_SHADER_FMASK_LOOKUP,
	GR_EXT_IMAGE_STATE_DATA_TRANSFER_DMA_QUEUE
};

enum _GR_EXT_MEMORY_STATE {
	GR_EXT_MEMORY_STATE_COPY_OCCLUSION_DATA = 0x00300000,
	GR_EXT_MEMORY_STATE_CMD_CONTROL
};

enum _GR_EXT_OCCLUSION_CONDITION {
	GR_EXT_OCCLUSION_CONDITION_VISIBLE = 0x00300300,
	GR_EXT_OCCLUSION_CONDITION_INVISIBLE
};

enum _GR_EXT_QUEUE_TYPE {
	GR_EXT_QUEUE_DMA = 0x00300200,
	GR_EXT_QUEUE_TIMER
};



// flags
enum _GR_EXT_CONTROL_FLOW_FEATURE_FLAGS {
	GR_EXT_CONTROL_FLOW_OCCLUSION_PREDICATION = 1 << 0,
	GR_EXT_CONTROL_FLOW_MEMORY_PREDICATION    = 1 << 1,
	GR_EXT_CONTROL_FLOW_CONDITIONAL_EXECUTION = 1 << 2,
	GR_EXT_CONTROL_FLOW_LOOP_EXECUTION        = 1 << 3
};

enum _GR_EXT_ACCESS_CLIENT {
	GR_EXT_ACCESS_DEFAULT,
	GR_EXT_ACCESS_CPU             = 1 << 24,
	GR_EXT_ACCESS_UNIVERSAL_QUEUE = 1 << 25,
	GR_EXT_ACCESS_COMPUTE_QUEUE   = 1 << 26,
	GR_EXT_ACCESS_DMA_QUEUE       = 1 << 27
};



// primary structures
struct _GR_BORDER_COLOR_PALETTE_PROPERTIES {
	GR_UINT maxPaletteSize;
};

struct _GR_BORDER_COLOR_PALETTE_CREATE_INFO {
	GR_UINT paletteSize;
};

struct _GR_FMASK_IMAGE_VIEW_CREATE_INFO {
	GR_IMAGE image;
	GR_UINT  baseArraySlice;
	GR_UINT  arraySize;
};

struct _GR_MSAA_QUAD_SAMPLE_PATTERN {
	GR_OFFSET2D topLeft[GR_MAX_MSAA_RASTERIZER_SAMPLES];
	GR_OFFSET2D topRight[GR_MAX_MSAA_RASTERIZER_SAMPLES];
	GR_OFFSET2D bottomLeft[GR_MAX_MSAA_RASTERIZER_SAMPLES];
	GR_OFFSET2D bottomRight[GR_MAX_MSAA_RASTERIZER_SAMPLES];
};

struct _GR_QUEUE_CONTROL_FLOW_PROPERTIES {
	GR_UINT  maxNestingLimit;
	GR_FLAGS controlFlowOperations;
};

struct _GR_GPU_TIMESTAMP_CALIBRATION {
	GR_UINT64 gpuTimestamp;
	union {
		GR_UINT64 cpuWinPerfCounter;
		GR_BYTE   _padding[16];
	};
};



// secondary structures
struct _GR_ADVANCED_MSAA_STATE_CREATE_INFO {
	GR_UINT                     coverageSamples;
	GR_UINT                     pixelShaderSamples;
	GR_UINT                     depthStencilSamples;
	GR_UINT                     colorTargetSamples;
	GR_SAMPLE_MASK              sampleMask;
	GR_UINT                     sampleClusters;
	GR_UINT                     alphaToCoverageSamples;
	GR_BOOL                     disableAlphaToCoverageDither;
	GR_MSAA_QUAD_SAMPLE_PATTERN customSamplePattern;
};



#ifdef __cplusplus
}
#endif

#endif
