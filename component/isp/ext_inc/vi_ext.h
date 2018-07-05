/******************************************************************************

  Copyright (C), 2016, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : vi_ext.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       :
  Description   :
  History       :
  1.Date        : 2016/10/08
    Author      : c00321909
    Modification: Created file

******************************************************************************/
#ifndef __VI_EXT_H__
#define __VI_EXT_H__

#include "hi_type.h"
#include "hi_common.h"
#include "hi_comm_vi.h"
#include "hi_comm_video.h"
#include "hi_comm_sys.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

/* Pipe work mode */
typedef enum hiVI_PIPE_MODE_E
{
    VI_PIPE_MODE_OFFLINE = 0,                           /* Offline mode */
    VI_PIPE_MODE_ONLINE,                                /* Online mode */
    VI_PIPE_MODE_PARALLEL,                              /* Parallel mode */

    VI_PIPE_MODE_BUTT
} VI_PIPE_MODE_E;


typedef struct hiVI_FLASH_CALLBACK_S
{
    HI_S32  (*pfnViGetFlashStatus) (HI_VOID);
} VI_FLASH_CALLBACK_S;

typedef struct hiVI_PIPE_HDR_ATTR_S
{
    DYNAMIC_RANGE_E enDynamicRange;
    PIXEL_FORMAT_E  enFormat;
    HI_BOOL         bMirror;
} VI_PIPE_HDR_ATTR_S;

typedef struct hiVI_PIPE_WDR_ATTR_S
{
    VI_DEV              ViDev;
    WDR_MODE_E          enWDRMode;
    VI_DEV_BIND_PIPE_S  stDevBindPipe;
    HI_BOOL             bMastPipe;
} VI_PIPE_WDR_ATTR_S;

/*
Defines the ISP stitch attribute.
*/
typedef struct hiVI_STITCH_ATTR_S
{
    HI_BOOL bStitchEnable;
    HI_BOOL bMainPipe;
    HI_U8   u8StitchPipeNum;
    HI_S8   as8StitchBindId[VI_MAX_PIPE_NUM];
} VI_STITCH_ATTR_S;

typedef struct hiISP_STITCH_SYNC_BE_STATS_S
{
    HI_VOID* pstSyncBeStt[VI_MAX_PIPE_NUM];
} ISP_STITCH_SYNC_BE_STATS_S;

typedef struct hiVI_SNAP_STATUS_S
{
    HI_BOOL bDiscardFrame;
    HI_U32  u32FrameFlag;
}VI_SNAP_STATUS_S;

typedef struct hiVI_PIPE_SPLIT_ATTR_S
{
    VI_VPSS_MODE_E      enMode;
    HI_S32              s32SplitNum;
    HI_U32              u32OverLap;
    RECT_S              astRect[VI_MAX_SPLIT_NODE_NUM];
} VI_PIPE_SPLIT_ATTR_S;

typedef struct hiVI_PROC_MODULE_PARAM_S
{
    HI_BOOL bViProcEn[VIPROC_IP_NUM];
} VI_PROC_MODULE_PARAM_S;

typedef HI_S32  FN_VI_RegisterFlashCallBack(HI_S32 ViDev, VI_FLASH_CALLBACK_S* pstFlashCb);
typedef HI_S32  FN_VI_GetPipeWDRAttr(VI_PIPE ViPipe, VI_PIPE_WDR_ATTR_S *pstWDRAttr);
typedef HI_S32  FN_VI_GetPipeHDRAttr(VI_PIPE ViPipe, VI_PIPE_HDR_ATTR_S *pstHDRAttr);
typedef HI_S32  FN_VI_GetPipeBindDevId(VI_PIPE ViPipe, VI_DEV* ViDev);
typedef HI_S32  FN_VI_GetPipeBindDevId(VI_PIPE ViPipe, VI_DEV* ViDev);
typedef HI_S32  FN_VI_GetBeSttInfo(VI_PIPE ViPipe,HI_U8 u8Block,HI_VOID* pstBeStt);
typedef HI_S32  FN_VI_GetPipeMode(VI_PIPE ViPipe,VI_PIPE_MODE_E *penMode);
typedef HI_S32  FN_VI_GetNeedSplit(VI_PIPE ViPipe,HI_BOOL *pSplitEn);
typedef HI_S32  FN_VI_GetPipeStitchAttr(VI_PIPE ViPipe,VI_STITCH_ATTR_S *pstStitchAttr);
typedef HI_S32  FN_VI_GetStitchSyncBeSttInfo(VI_PIPE ViPipe, ISP_STITCH_SYNC_BE_STATS_S *pstStitchSyncStats);
typedef HI_S32  FN_VI_UpdateViVpssMode(VI_VPSS_MODE_S *pstViVpssMode);
typedef HI_S32  FN_VI_GetPipeSnapStatus(VI_PIPE ViPipe, VI_SNAP_STATUS_S* pstViSnapStatus);
typedef HI_S32  FN_VI_GetSplitAttr(VI_PIPE ViPipe,VI_PIPE_SPLIT_ATTR_S *pstSplitAttr);
typedef HI_S32  FN_VI_GetProcModuleParam(VI_PROC_MODULE_PARAM_S* pstProcModuleParam);
typedef HI_S32  FN_VI_DownSemaphore(VI_PIPE ViPipe);
typedef HI_S32  FN_VI_UpSemaphore(VI_PIPE ViPipe);
typedef HI_BOOL FN_VI_IsPipeExisted(VI_PIPE ViPipe);
typedef HI_S32 FN_VI_GetPipeBindDevSize(VI_PIPE ViPipe, SIZE_S *pstSize);

typedef struct hiVI_EXPORT_FUNC_S
{
    FN_VI_GetStitchSyncBeSttInfo*       pfnViGetStitchSyncBeSttInfo;
    FN_VI_GetPipeStitchAttr*            pfnViGetPipeStitchAttr;
    FN_VI_GetPipeWDRAttr*               pfnViGetPipeWDRAttr;
    FN_VI_GetPipeHDRAttr*               pfnViGetPipeHDRAttr;
    FN_VI_GetPipeHDRAttr*               pfnViGetPipeHDRAttrUnlock;
    FN_VI_GetPipeBindDevId*             pfnViGetPipeBindDevId;
    FN_VI_GetBeSttInfo*                 pfnViGetBeSttInfo;
    FN_VI_GetPipeMode*                  pfnViGetPipeMode;
    FN_VI_GetNeedSplit*                 pfnViGetNeedSplit;
    FN_VI_RegisterFlashCallBack*        pfnViRegisterFlashCallBack;
    FN_VI_UpdateViVpssMode*             pfnVIUpdateViVpssMode;
    FN_VI_GetPipeSnapStatus*            pfnViGetPipeSnapStatus;
    FN_VI_GetSplitAttr*                 pfnViGetSplitAttr;
    FN_VI_GetProcModuleParam*           pfnViGetProcModuleParam;
    FN_VI_DownSemaphore*                pfnViDownSemaphore;
    FN_VI_UpSemaphore*                  pfnViUpSemaphore;
    FN_VI_IsPipeExisted*                pfnViIsPipeExisted;
    FN_VI_GetPipeBindDevSize*           pfnViGetPipeBindDevSize;

} VI_EXPORT_FUNC_S;

#define CKFN_VI_UpdateViVpssMode()\
    (HI_NULL != FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnVIUpdateViVpssMode)
#define CALL_VI_UpdateViVpssMode(pstViVpssMode)\
    FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnVIUpdateViVpssMode(pstViVpssMode)

#define CKFN_VI_GetPipeStitchAttr()\
    (HI_NULL != FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViGetPipeStitchAttr)
#define CALL_VI_GetPipeStitchAttr(ViPipe, pstStitchAttr)\
    FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViGetPipeStitchAttr(ViPipe, pstStitchAttr)

#define CKFN_VI_GetStitchSyncBeSttInfo()\
    (HI_NULL != FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViGetStitchSyncBeSttInfo)
#define CALL_VI_GetStitchSyncBeSttInfo(ViPipe, pstStitchSyncStats)\
    FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViGetStitchSyncBeSttInfo(ViPipe, pstStitchSyncStats)

#define CKFN_VI_GetPipeWDRAttr()\
    (HI_NULL != FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViGetPipeWDRAttr)
#define CALL_VI_GetPipeWDRAttr(ViPipe, pstWDRAttr)\
    FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViGetPipeWDRAttr(ViPipe, pstWDRAttr)

#define CKFN_VI_GetPipeHDRAttr()\
    (HI_NULL != FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViGetPipeHDRAttr)
#define CALL_VI_GetPipeHDRAttr(ViPipe, pstHDRAttr)\
    FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViGetPipeHDRAttr(ViPipe, pstHDRAttr)

#define CKFN_VI_GetPipeHDRAttrUnlock()\
        (HI_NULL != FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViGetPipeHDRAttrUnlock)
#define CALL_VI_GetPipeHDRAttrUnlock(ViPipe, pstHDRAttr)\
        FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViGetPipeHDRAttrUnlock(ViPipe, pstHDRAttr)

#define CKFN_VI_GetPipeBindDevId()\
    (HI_NULL != FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViGetPipeBindDevId)
#define CALL_VI_GetPipeBindDevId(ViPipe, ViDev)\
    FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViGetPipeBindDevId(ViPipe, ViDev)

#define CKFN_VI_GetBeSttInfo()\
    (HI_NULL != FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViGetBeSttInfo)
#define CALL_VI_GetBeSttInfo(ViPipe, u8Block, pstBeStt)\
    FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViGetBeSttInfo(ViPipe, u8Block, pstBeStt)

#define CKFN_VI_GetPipeMode()\
    (HI_NULL != FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViGetPipeMode)
#define CALL_VI_GetPipeMode(ViPipe, penMode)\
    FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViGetPipeMode(ViPipe, penMode)

#define CKFN_VI_GetNeedSplit()\
    (HI_NULL != FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViGetNeedSplit)
#define CALL_VI_GetNeedSplit(ViPipe, pSplitEn)\
    FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViGetNeedSplit(ViPipe, pSplitEn)

#define CKFN_VI_RegisterFlashCallBack()\
    (HI_NULL != FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViRegisterFlashCallBack)
#define CALL_VI_RegisterFlashCallBack(ViDev,pstFlashCb)\
    FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViRegisterFlashCallBack(ViDev,pstFlashCb)

#define CKFN_VI_GetSnapStatus()\
    (HI_NULL != FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViGetPipeSnapStatus)
#define CALL_VI_GetSnapStatus(ViPipe, pstViSnapStatus)\
    FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViGetPipeSnapStatus(ViPipe, pstViSnapStatus)

#define CKFN_VI_GetSplitAttr()\
    (HI_NULL != FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViGetSplitAttr)
#define CALL_VI_GetSplitAttr(ViPipe,pstSplitAttr)\
    FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViGetSplitAttr(ViPipe,pstSplitAttr)

#define CKFN_VI_GetProcModuleParam()\
    (HI_NULL != FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViGetProcModuleParam)
#define CALL_VI_GetProcModuleParam(pstProcModuleParam)\
    FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViGetProcModuleParam(pstProcModuleParam)

#define CKFN_VI_DownSemaphore()\
    (HI_NULL != FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViDownSemaphore)
#define CALL_VI_DownSemaphore(ViPipe)\
    FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViDownSemaphore(ViPipe)

#define CKFN_VI_UpSemaphore()\
    (HI_NULL != FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViUpSemaphore)
#define CALL_VI_UpSemaphore(ViPipe)\
    FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViUpSemaphore(ViPipe)

#define CKFN_VI_IsPipeExisted()\
    (HI_NULL != FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViIsPipeExisted)
#define CALL_VI_IsPipeExisted(ViPipe)\
    FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViIsPipeExisted(ViPipe)

#define CKFN_VI_GetPipeBindDevSize()\
    (HI_NULL != FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViGetPipeBindDevSize)
#define CALL_VI_GetPipeBindDevSize(ViPipe, pstSize)\
    FUNC_ENTRY(VI_EXPORT_FUNC_S, HI_ID_VI)->pfnViGetPipeBindDevSize(ViPipe, pstSize)

typedef struct hi_VI_CAP_PIC_INFO_S
{
    VIDEO_FRAME_INFO_S      stVideoFrame;
    ISP_CONFIG_INFO_S       stIspConfigInfo;
    ISP_DCF_UPDATE_INFO_S   stDCFUpdateInfo;
    HI_U64                  u64StartTime;
    HI_U64                  u64EndTime;
} VI_CAP_PIC_INFO_S;

typedef struct HI_VI_BUF_INFO_S
{
    VI_CAP_PIC_INFO_S   stPicInfo;
    HI_BOOL             bBufOk;
    HI_BOOL             bCapOK;
    HI_BOOL             bSended;
    HI_BOOL             bLost;
} VI_BUF_INFO_S;

typedef enum hiVI_FRAME_INFO_E
{
    FRAME_NORMAL    = 0x0,
    FRAME_LOWDELAY ,
    FRAME_LOWDELAY_FIN,
} VI_FRAME_INFO_E;

typedef struct hi_VI_PIC_INFO_S
{
    VIDEO_FRAME_INFO_S  stVideoFrame;
    VIDEO_FRAME_INFO_S  stSingleYFrame;
    HI_U64              u64StartTime;
    HI_U64              u64EndTime;
    VI_FRAME_INFO_E     enFrameInfo;
} VI_PIC_INFO_S;

typedef struct hi_VI_SEND_INFO_S
{
    VI_PIPE         ViPipe;
    VI_CHN          ViChn;
    VI_PIC_INFO_S*  pstDestPicInfo;
} VI_SEND_INFO_S;

typedef enum hiVI_FPN_WORK_MODE_E
{
    FPN_MODE_NONE    = 0x0,
    FPN_MODE_CORRECTION ,
    FPN_MODE_CALIBRATE,
    FPN_MODE_BUTT
} VI_FPN_WORK_MODE_E;

typedef enum hiVI_FPN_TYPE_E
{
    VI_FPN_TYPE_FRAME = 0,
    VI_FPN_TYPE_LINE = 1,
    VI_FPN_TYPE_BUTT
} VI_FPN_TYPE_E;

typedef enum hiVI_FPN_OP_TYPE_E
{
    VI_FPN_OP_TYPE_AUTO    = 0,
    VI_FPN_OP_TYPE_MANUAL  = 1,
    VI_FPN_OP_TYPE_BUTT
} VI_FPN_OP_TYPE_E;

typedef struct hiVI_FPN_FRAME_INFO_S
{
    HI_U32              u32Iso;             /* FPN CALIBRATE ISO */
    HI_U32              u32Offset[VI_MAX_SPLIT_NODE_NUM];          /* FPN frame u32Offset (agv pixel value) */
    HI_U32              u32FrmSize;         /* FPN frame size (exactly frm size or compress len) */
    VIDEO_FRAME_INFO_S  stFpnFrame;         /* FPN frame info, 8bpp,10bpp,12bpp,16bpp. Compression or not */
} VI_FPN_FRAME_INFO_S;

typedef struct hiVI_FPN_CALIBRATE_ATTR_S
{
    HI_U32                  u32Threshold;        /* white_level,pix value > threshold means defective pixel */
    HI_U32                  u32FrameNum;         /* value is 2^N, range: [0x1, 0x10] */
    VI_FPN_TYPE_E           enFpnType;           /* frame mode or line mode */
    VI_FPN_FRAME_INFO_S     stFpnCaliFrame;      /* output in tune mode. */
} VI_FPN_CALIBRATE_ATTR_S;

typedef struct hiVI_FPN_CORRECTION_ATTR_S
{
    HI_BOOL                 bEnable;
    HI_U32                  u32Gain;             /* RO, only use in manual mode, format 2.8 */
    VI_FPN_OP_TYPE_E        enFpnOpType;
    VI_FPN_FRAME_INFO_S     stFpnFrmInfo;        /* RO, input in correction mode. */
} VI_FPN_CORRECTION_ATTR_S;

typedef struct hiVI_FPN_ATTR_S
{
    VI_FPN_TYPE_E            enFpnType;
    VI_FPN_WORK_MODE_E       enFpnWorkMode;
    union
    {
        VI_FPN_CALIBRATE_ATTR_S     stCalibrate;
        VI_FPN_CORRECTION_ATTR_S    stCorrection;
    };
} VI_FPN_ATTR_S;

HI_S32 MPI_VI_SetFPNAttr(VI_PIPE ViPipe, VI_FPN_ATTR_S* pstFPNAttr);
HI_S32 MPI_VI_GetFPNAttr(VI_PIPE ViPipe, VI_FPN_ATTR_S* pstFPNAttr);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif

