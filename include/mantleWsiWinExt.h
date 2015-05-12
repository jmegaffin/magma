#ifndef _MANTLE_WSI_WIN_EXT_H
#define _MANTLE_WSI_WIN_EXT_H

#include "mantle.h"

#ifdef __cplusplus
extern "C" {
#endif



/* type aliases */
typedef uint64_t GR_WSI_WIN_DISPLAY;



/* structures */
typedef struct _GR_WSI_WIN_PRESENT_INFO GR_WSI_WIN_PRESENT_INFO;
typedef struct _GR_WSI_WIN_PRESENTABLE_IMAGE_CREATE_INFO GR_WSI_WIN_PRESENTABLE_IMAGE_CREATE_INFO;

struct _GR_WSI_WIN_PRESENT_INFO {
	void    *hWndDest;
	GR_IMAGE srcImage;
	GR_ENUM  presentMode;
	GR_UINT  presentInterval;
	GR_FLAGS flags;
};

struct _GR_WSI_WIN_PRESENTABLE_IMAGE_CREATE_INFO {
	GR_FORMAT          format;
	GR_FLAGS           usage;
	GR_EXTENT2D        extent;
	GR_WSI_WIN_DISPLAY display;
	GR_FLAGS           flags;
};



/* functions */
extern GR_RESULT (GR_STDCALL *grWsiWinCreatePresentableImage)(
	GR_DEVICE                                       device,
	const GR_WSI_WIN_PRESENTABLE_IMAGE_CREATE_INFO *pCreateInfo,
	GR_IMAGE                                       *pImage,
	GR_GPU_MEMORY                                  *pMem
);

extern GR_RESULT (GR_STDCALL *grWsiWinQueuePresent)(
	GR_QUEUE                       queue,
	const GR_WSI_WIN_PRESENT_INFO *pPresentInfo
);



/* enumerations */
typedef enum _GR_WSI_WIN_IMAGE_STATE {
	GR_WSI_WIN_IMAGE_STATE_PRESENT_WINDOWED = 0x00200000,
	GR_WSI_WIN_IMAGE_STATE_PRESENT_FULLSCREEN
} GR_WSI_WIN_IMAGE_STATE;

typedef enum _GR_WSI_WIN_PRESENT_MODE {
	GR_WSI_WIN_PRESENT_MODE_WINDOWED = 0x00200200,
	GR_WSI_WIN_PRESENT_MODE_FULLSCREEN
} GR_WSI_WIN_PRESENT_MODE;



/* flags */
typedef enum _GR_WSI_WIN_IMAGE_CREATE_FLAGS {
	GR_WSI_WIN_IMAGE_CREATE_FULLSCREEN_PRESENT = 1 << 0,
	GR_WSI_WIN_IMAGE_CREATE_STEREO             = 1 << 1
} GR_WSI_WIN_IMAGE_CREATE_FLAGS;

typedef enum _GR_WSI_WIN_PRESENT_FLAGS {
	GR_WSI_WIN_PRESENT_FULLSCREEN_DONOTWAIT = 1 << 0,
	GR_WSI_WIN_PRESENT_FULLSCREEN_STEREO    = 1 << 1
} GR_WSI_WIN_PRESENT_FLAGS;



#ifdef __cplusplus
}
#endif

#endif
