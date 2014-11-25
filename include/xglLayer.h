/* Need to define dispatch table
 * Core struct can then have ptr to dispatch table at the top
 * Along with object ptrs for current and next OBJ
 */
#pragma once

#include "xgl.h"
#include "xglDbg.h"
#include "xglWsiX11Ext.h"
#if defined(__GNUC__) && __GNUC__ >= 4
#  define XGL_LAYER_EXPORT __attribute__((visibility("default")))
#elif defined(__SUNPRO_C) && (__SUNPRO_C >= 0x590)
#  define XGL_LAYER_EXPORT __attribute__((visibility("default")))
#else
#  define XGL_LAYER_EXPORT
#endif

typedef XGL_RESULT (XGLAPI *InitAndEnumerateGpusType)(const XGL_APPLICATION_INFO* pAppInfo, const XGL_ALLOC_CALLBACKS* pAllocCb, XGL_UINT maxGpus, XGL_UINT* pGpuCount, XGL_PHYSICAL_GPU* pGpus);
typedef XGL_RESULT (XGLAPI *GetGpuInfoType)(XGL_PHYSICAL_GPU gpu, XGL_PHYSICAL_GPU_INFO_TYPE infoType, XGL_SIZE* pDataSize, XGL_VOID* pData);
typedef XGL_VOID * (XGLAPI *GetProcAddrType)(XGL_PHYSICAL_GPU gpu, const XGL_CHAR * pName);
typedef XGL_RESULT (XGLAPI *CreateDeviceType)(XGL_PHYSICAL_GPU gpu, const XGL_DEVICE_CREATE_INFO* pCreateInfo, XGL_DEVICE* pDevice);
typedef XGL_RESULT (XGLAPI *DestroyDeviceType)(XGL_DEVICE device);
typedef XGL_RESULT (XGLAPI *GetExtensionSupportType)(XGL_PHYSICAL_GPU gpu, const XGL_CHAR* pExtName);
typedef XGL_RESULT (XGLAPI *EnumerateLayersType)(XGL_PHYSICAL_GPU gpu, XGL_SIZE maxLayerCount, XGL_SIZE maxStringSize, XGL_CHAR* const* pOutLayers, XGL_SIZE* pOutLayerCount, XGL_VOID* pReserved);
typedef XGL_RESULT (XGLAPI *GetDeviceQueueType)(XGL_DEVICE device, XGL_QUEUE_TYPE queueType, XGL_UINT queueIndex, XGL_QUEUE* pQueue);
typedef XGL_RESULT (XGLAPI *QueueSubmitType)(XGL_QUEUE queue, XGL_UINT cmdBufferCount, const XGL_CMD_BUFFER* pCmdBuffers, XGL_UINT memRefCount, const XGL_MEMORY_REF* pMemRefs, XGL_FENCE fence);
typedef XGL_RESULT (XGLAPI *QueueSetGlobalMemReferencesType)(XGL_QUEUE queue, XGL_UINT memRefCount, const XGL_MEMORY_REF* pMemRefs);
typedef XGL_RESULT (XGLAPI *QueueWaitIdleType)(XGL_QUEUE queue);
typedef XGL_RESULT (XGLAPI *DeviceWaitIdleType)(XGL_DEVICE device);
typedef XGL_RESULT (XGLAPI *GetMemoryHeapCountType)(XGL_DEVICE device, XGL_UINT* pCount);
typedef XGL_RESULT (XGLAPI *GetMemoryHeapInfoType)(XGL_DEVICE device, XGL_UINT heapId, XGL_MEMORY_HEAP_INFO_TYPE infoType, XGL_SIZE* pDataSize, XGL_VOID* pData);
typedef XGL_RESULT (XGLAPI *AllocMemoryType)(XGL_DEVICE device, const XGL_MEMORY_ALLOC_INFO* pAllocInfo, XGL_GPU_MEMORY* pMem);
typedef XGL_RESULT (XGLAPI *FreeMemoryType)(XGL_GPU_MEMORY mem);
typedef XGL_RESULT (XGLAPI *SetMemoryPriorityType)(XGL_GPU_MEMORY mem, XGL_MEMORY_PRIORITY priority);
typedef XGL_RESULT (XGLAPI *MapMemoryType)(XGL_GPU_MEMORY mem, XGL_FLAGS flags, XGL_VOID** ppData);
typedef XGL_RESULT (XGLAPI *UnmapMemoryType)(XGL_GPU_MEMORY mem);
typedef XGL_RESULT (XGLAPI *PinSystemMemoryType)(XGL_DEVICE device, const XGL_VOID* pSysMem, XGL_SIZE memSize, XGL_GPU_MEMORY* pMem);
typedef XGL_RESULT (XGLAPI *RemapVirtualMemoryPagesType)(XGL_DEVICE device, XGL_UINT rangeCount, const XGL_VIRTUAL_MEMORY_REMAP_RANGE* pRanges, XGL_UINT preWaitSemaphoreCount, const XGL_QUEUE_SEMAPHORE* pPreWaitSemaphores, XGL_UINT postSignalSemaphoreCount, const XGL_QUEUE_SEMAPHORE* pPostSignalSemaphores);
typedef XGL_RESULT (XGLAPI *GetMultiGpuCompatibilityType)(XGL_PHYSICAL_GPU gpu0, XGL_PHYSICAL_GPU gpu1, XGL_GPU_COMPATIBILITY_INFO* pInfo);
typedef XGL_RESULT (XGLAPI *OpenSharedMemoryType)(XGL_DEVICE device, const XGL_MEMORY_OPEN_INFO* pOpenInfo, XGL_GPU_MEMORY* pMem);
typedef XGL_RESULT (XGLAPI *OpenSharedQueueSemaphoreType)(XGL_DEVICE device, const XGL_QUEUE_SEMAPHORE_OPEN_INFO* pOpenInfo, XGL_QUEUE_SEMAPHORE* pSemaphore);
typedef XGL_RESULT (XGLAPI *OpenPeerMemoryType)(XGL_DEVICE device, const XGL_PEER_MEMORY_OPEN_INFO* pOpenInfo, XGL_GPU_MEMORY* pMem);
typedef XGL_RESULT (XGLAPI *OpenPeerImageType)(XGL_DEVICE device, const XGL_PEER_IMAGE_OPEN_INFO* pOpenInfo, XGL_IMAGE* pImage, XGL_GPU_MEMORY* pMem);
typedef XGL_RESULT (XGLAPI *DestroyObjectType)(XGL_OBJECT object);
typedef XGL_RESULT (XGLAPI *GetObjectInfoType)(XGL_BASE_OBJECT object, XGL_OBJECT_INFO_TYPE infoType, XGL_SIZE* pDataSize, XGL_VOID* pData);
typedef XGL_RESULT (XGLAPI *BindObjectMemoryType)(XGL_OBJECT object, XGL_GPU_MEMORY mem, XGL_GPU_SIZE offset);
typedef XGL_RESULT (XGLAPI *CreateFenceType)(XGL_DEVICE device, const XGL_FENCE_CREATE_INFO* pCreateInfo, XGL_FENCE* pFence);
typedef XGL_RESULT (XGLAPI *GetFenceStatusType)(XGL_FENCE fence);
typedef XGL_RESULT (XGLAPI *WaitForFencesType)(XGL_DEVICE device, XGL_UINT fenceCount, const XGL_FENCE* pFences, XGL_BOOL waitAll, XGL_UINT64 timeout);
typedef XGL_RESULT (XGLAPI *CreateQueueSemaphoreType)(XGL_DEVICE device, const XGL_QUEUE_SEMAPHORE_CREATE_INFO* pCreateInfo, XGL_QUEUE_SEMAPHORE* pSemaphore);
typedef XGL_RESULT (XGLAPI *SignalQueueSemaphoreType)(XGL_QUEUE queue, XGL_QUEUE_SEMAPHORE semaphore);
typedef XGL_RESULT (XGLAPI *WaitQueueSemaphoreType)(XGL_QUEUE queue, XGL_QUEUE_SEMAPHORE semaphore);
typedef XGL_RESULT (XGLAPI *CreateEventType)(XGL_DEVICE device, const XGL_EVENT_CREATE_INFO* pCreateInfo, XGL_EVENT* pEvent);
typedef XGL_RESULT (XGLAPI *GetEventStatusType)(XGL_EVENT event);
typedef XGL_RESULT (XGLAPI *SetEventType)(XGL_EVENT event);
typedef XGL_RESULT (XGLAPI *ResetEventType)(XGL_EVENT event);
typedef XGL_RESULT (XGLAPI *CreateQueryPoolType)(XGL_DEVICE device, const XGL_QUERY_POOL_CREATE_INFO* pCreateInfo, XGL_QUERY_POOL* pQueryPool);
typedef XGL_RESULT (XGLAPI *GetQueryPoolResultsType)(XGL_QUERY_POOL queryPool, XGL_UINT startQuery, XGL_UINT queryCount, XGL_SIZE* pDataSize, XGL_VOID* pData);
typedef XGL_RESULT (XGLAPI *GetFormatInfoType)(XGL_DEVICE device, XGL_FORMAT format, XGL_FORMAT_INFO_TYPE infoType, XGL_SIZE* pDataSize, XGL_VOID* pData);
typedef XGL_RESULT (XGLAPI *CreateImageType)(XGL_DEVICE device, const XGL_IMAGE_CREATE_INFO* pCreateInfo, XGL_IMAGE* pImage);
typedef XGL_RESULT (XGLAPI *GetImageSubresourceInfoType)(XGL_IMAGE image, const XGL_IMAGE_SUBRESOURCE* pSubresource, XGL_SUBRESOURCE_INFO_TYPE infoType, XGL_SIZE* pDataSize, XGL_VOID* pData);
typedef XGL_RESULT (XGLAPI *CreateImageViewType)(XGL_DEVICE device, const XGL_IMAGE_VIEW_CREATE_INFO* pCreateInfo, XGL_IMAGE_VIEW* pView);
typedef XGL_RESULT (XGLAPI *CreateColorAttachmentViewType)(XGL_DEVICE device, const XGL_COLOR_ATTACHMENT_VIEW_CREATE_INFO* pCreateInfo, XGL_COLOR_ATTACHMENT_VIEW* pView);
typedef XGL_RESULT (XGLAPI *CreateDepthStencilViewType)(XGL_DEVICE device, const XGL_DEPTH_STENCIL_VIEW_CREATE_INFO* pCreateInfo, XGL_DEPTH_STENCIL_VIEW* pView);
typedef XGL_RESULT (XGLAPI *CreateShaderType)(XGL_DEVICE device, const XGL_SHADER_CREATE_INFO* pCreateInfo, XGL_SHADER* pShader);
typedef XGL_RESULT (XGLAPI *CreateGraphicsPipelineType)(XGL_DEVICE device, const XGL_GRAPHICS_PIPELINE_CREATE_INFO* pCreateInfo, XGL_PIPELINE* pPipeline);
typedef XGL_RESULT (XGLAPI *CreateComputePipelineType)(XGL_DEVICE device, const XGL_COMPUTE_PIPELINE_CREATE_INFO* pCreateInfo, XGL_PIPELINE* pPipeline);
typedef XGL_RESULT (XGLAPI *StorePipelineType)(XGL_PIPELINE pipeline, XGL_SIZE* pDataSize, XGL_VOID* pData);
typedef XGL_RESULT (XGLAPI *LoadPipelineType)(XGL_DEVICE device, XGL_SIZE dataSize, const XGL_VOID* pData, XGL_PIPELINE* pPipeline);
typedef XGL_RESULT (XGLAPI *CreatePipelineDeltaType)(XGL_DEVICE device, XGL_PIPELINE p1, XGL_PIPELINE p2, XGL_PIPELINE_DELTA* delta);
typedef XGL_RESULT (XGLAPI *CreateSamplerType)(XGL_DEVICE device, const XGL_SAMPLER_CREATE_INFO* pCreateInfo, XGL_SAMPLER* pSampler);
typedef XGL_RESULT (XGLAPI *CreateDescriptorSetType)(XGL_DEVICE device, const XGL_DESCRIPTOR_SET_CREATE_INFO* pCreateInfo, XGL_DESCRIPTOR_SET* pDescriptorSet);
typedef XGL_VOID (XGLAPI *BeginDescriptorSetUpdateType)(XGL_DESCRIPTOR_SET descriptorSet);
typedef XGL_VOID (XGLAPI *EndDescriptorSetUpdateType)(XGL_DESCRIPTOR_SET descriptorSet);
typedef XGL_VOID (XGLAPI *AttachSamplerDescriptorsType)(XGL_DESCRIPTOR_SET descriptorSet, XGL_UINT startSlot, XGL_UINT slotCount, const XGL_SAMPLER* pSamplers);
typedef XGL_VOID (XGLAPI *AttachImageViewDescriptorsType)(XGL_DESCRIPTOR_SET descriptorSet, XGL_UINT startSlot, XGL_UINT slotCount, const XGL_IMAGE_VIEW_ATTACH_INFO* pImageViews);
typedef XGL_VOID (XGLAPI *AttachMemoryViewDescriptorsType)(XGL_DESCRIPTOR_SET descriptorSet, XGL_UINT startSlot, XGL_UINT slotCount, const XGL_MEMORY_VIEW_ATTACH_INFO* pMemViews);
typedef XGL_VOID (XGLAPI *AttachNestedDescriptorsType)(XGL_DESCRIPTOR_SET descriptorSet, XGL_UINT startSlot, XGL_UINT slotCount, const XGL_DESCRIPTOR_SET_ATTACH_INFO* pNestedDescriptorSets);
typedef XGL_VOID (XGLAPI *ClearDescriptorSetSlotsType)(XGL_DESCRIPTOR_SET descriptorSet, XGL_UINT startSlot, XGL_UINT slotCount);
typedef XGL_RESULT (XGLAPI *CreateViewportStateType)(XGL_DEVICE device, const XGL_VIEWPORT_STATE_CREATE_INFO* pCreateInfo, XGL_VIEWPORT_STATE_OBJECT* pState);
typedef XGL_RESULT (XGLAPI *CreateRasterStateType)(XGL_DEVICE device, const XGL_RASTER_STATE_CREATE_INFO* pCreateInfo, XGL_RASTER_STATE_OBJECT* pState);
typedef XGL_RESULT (XGLAPI *CreateMsaaStateType)(XGL_DEVICE device, const XGL_MSAA_STATE_CREATE_INFO* pCreateInfo, XGL_MSAA_STATE_OBJECT* pState);
typedef XGL_RESULT (XGLAPI *CreateColorBlendStateType)(XGL_DEVICE device, const XGL_COLOR_BLEND_STATE_CREATE_INFO* pCreateInfo, XGL_COLOR_BLEND_STATE_OBJECT* pState);
typedef XGL_RESULT (XGLAPI *CreateDepthStencilStateType)(XGL_DEVICE device, const XGL_DEPTH_STENCIL_STATE_CREATE_INFO* pCreateInfo, XGL_DEPTH_STENCIL_STATE_OBJECT* pState);
typedef XGL_RESULT (XGLAPI *CreateCommandBufferType)(XGL_DEVICE device, const XGL_CMD_BUFFER_CREATE_INFO* pCreateInfo, XGL_CMD_BUFFER* pCmdBuffer);
typedef XGL_RESULT (XGLAPI *BeginCommandBufferType)(XGL_CMD_BUFFER cmdBuffer, XGL_FLAGS flags);
typedef XGL_RESULT (XGLAPI *EndCommandBufferType)(XGL_CMD_BUFFER cmdBuffer);
typedef XGL_RESULT (XGLAPI *ResetCommandBufferType)(XGL_CMD_BUFFER cmdBuffer);
typedef XGL_VOID (XGLAPI *CmdBindPipelineType)(XGL_CMD_BUFFER cmdBuffer, XGL_PIPELINE_BIND_POINT pipelineBindPoint, XGL_PIPELINE pipeline);
typedef XGL_VOID (XGLAPI *CmdBindPipelineDeltaType)(XGL_CMD_BUFFER cmdBuffer, XGL_PIPELINE_BIND_POINT pipelineBindPoint, XGL_PIPELINE_DELTA delta);
typedef XGL_VOID (XGLAPI *CmdBindStateObjectType)(XGL_CMD_BUFFER cmdBuffer, XGL_STATE_BIND_POINT stateBindPoint, XGL_STATE_OBJECT state);
typedef XGL_VOID (XGLAPI *CmdBindDescriptorSetType)(XGL_CMD_BUFFER cmdBuffer, XGL_PIPELINE_BIND_POINT pipelineBindPoint, XGL_UINT index, XGL_DESCRIPTOR_SET descriptorSet, XGL_UINT slotOffset);
typedef XGL_VOID (XGLAPI *CmdBindDynamicMemoryViewType)(XGL_CMD_BUFFER cmdBuffer, XGL_PIPELINE_BIND_POINT pipelineBindPoint, const XGL_MEMORY_VIEW_ATTACH_INFO* pMemView);
typedef XGL_VOID (XGLAPI *CmdBindVertexDataType)(XGL_CMD_BUFFER cmdBuffer, XGL_GPU_MEMORY mem, XGL_GPU_SIZE offset, XGL_UINT binding);
typedef XGL_VOID (XGLAPI *CmdBindIndexDataType)(XGL_CMD_BUFFER cmdBuffer, XGL_GPU_MEMORY mem, XGL_GPU_SIZE offset, XGL_INDEX_TYPE indexType);
typedef XGL_VOID (XGLAPI *CmdBindAttachmentsType)(XGL_CMD_BUFFER cmdBuffer, XGL_UINT colorAttachmentCount, const XGL_COLOR_ATTACHMENT_BIND_INFO* pColorAttachments, const XGL_DEPTH_STENCIL_BIND_INFO* pDepthStencilAttachment);
typedef XGL_VOID (XGLAPI *CmdPrepareMemoryRegionsType)(XGL_CMD_BUFFER cmdBuffer, XGL_UINT transitionCount, const XGL_MEMORY_STATE_TRANSITION* pStateTransitions);
typedef XGL_VOID (XGLAPI *CmdPrepareImagesType)(XGL_CMD_BUFFER cmdBuffer, XGL_UINT transitionCount, const XGL_IMAGE_STATE_TRANSITION* pStateTransitions);
typedef XGL_VOID (XGLAPI *CmdDrawType)(XGL_CMD_BUFFER cmdBuffer, XGL_UINT firstVertex, XGL_UINT vertexCount, XGL_UINT firstInstance, XGL_UINT instanceCount);
typedef XGL_VOID (XGLAPI *CmdDrawIndexedType)(XGL_CMD_BUFFER cmdBuffer, XGL_UINT firstIndex, XGL_UINT indexCount, XGL_INT vertexOffset, XGL_UINT firstInstance, XGL_UINT instanceCount);
typedef XGL_VOID (XGLAPI *CmdDrawIndirectType)(XGL_CMD_BUFFER cmdBuffer, XGL_GPU_MEMORY mem, XGL_GPU_SIZE offset, XGL_UINT32 count, XGL_UINT32 stride);
typedef XGL_VOID (XGLAPI *CmdDrawIndexedIndirectType)(XGL_CMD_BUFFER cmdBuffer, XGL_GPU_MEMORY mem, XGL_GPU_SIZE offset, XGL_UINT32 count, XGL_UINT32 stride);
typedef XGL_VOID (XGLAPI *CmdDispatchType)(XGL_CMD_BUFFER cmdBuffer, XGL_UINT x, XGL_UINT y, XGL_UINT z);
typedef XGL_VOID (XGLAPI *CmdDispatchIndirectType)(XGL_CMD_BUFFER cmdBuffer, XGL_GPU_MEMORY mem, XGL_GPU_SIZE offset);
typedef XGL_VOID (XGLAPI *CmdCopyMemoryType)(XGL_CMD_BUFFER cmdBuffer, XGL_GPU_MEMORY srcMem, XGL_GPU_MEMORY destMem, XGL_UINT regionCount, const XGL_MEMORY_COPY* pRegions);
typedef XGL_VOID (XGLAPI *CmdCopyImageType)(XGL_CMD_BUFFER cmdBuffer, XGL_IMAGE srcImage, XGL_IMAGE destImage, XGL_UINT regionCount, const XGL_IMAGE_COPY* pRegions);
typedef XGL_VOID (XGLAPI *CmdCopyMemoryToImageType)(XGL_CMD_BUFFER cmdBuffer, XGL_GPU_MEMORY srcMem, XGL_IMAGE destImage, XGL_UINT regionCount, const XGL_MEMORY_IMAGE_COPY* pRegions);
typedef XGL_VOID (XGLAPI *CmdCopyImageToMemoryType)(XGL_CMD_BUFFER cmdBuffer, XGL_IMAGE srcImage, XGL_GPU_MEMORY destMem, XGL_UINT regionCount, const XGL_MEMORY_IMAGE_COPY* pRegions);
typedef XGL_VOID (XGLAPI *CmdCloneImageDataType)(XGL_CMD_BUFFER cmdBuffer, XGL_IMAGE srcImage, XGL_IMAGE_STATE srcImageState, XGL_IMAGE destImage, XGL_IMAGE_STATE destImageState);
typedef XGL_VOID (XGLAPI *CmdUpdateMemoryType)(XGL_CMD_BUFFER cmdBuffer, XGL_GPU_MEMORY destMem, XGL_GPU_SIZE destOffset, XGL_GPU_SIZE dataSize, const XGL_UINT32* pData);
typedef XGL_VOID (XGLAPI *CmdFillMemoryType)(XGL_CMD_BUFFER cmdBuffer, XGL_GPU_MEMORY destMem, XGL_GPU_SIZE destOffset, XGL_GPU_SIZE fillSize, XGL_UINT32 data);
typedef XGL_VOID (XGLAPI *CmdClearColorImageType)(XGL_CMD_BUFFER cmdBuffer, XGL_IMAGE image, const XGL_FLOAT color[4], XGL_UINT rangeCount, const XGL_IMAGE_SUBRESOURCE_RANGE* pRanges);
typedef XGL_VOID (XGLAPI *CmdClearColorImageRawType)(XGL_CMD_BUFFER cmdBuffer, XGL_IMAGE image, const XGL_UINT32 color[4], XGL_UINT rangeCount, const XGL_IMAGE_SUBRESOURCE_RANGE* pRanges);
typedef XGL_VOID (XGLAPI *CmdClearDepthStencilType)(XGL_CMD_BUFFER cmdBuffer, XGL_IMAGE image, XGL_FLOAT depth, XGL_UINT32 stencil, XGL_UINT rangeCount, const XGL_IMAGE_SUBRESOURCE_RANGE* pRanges);
typedef XGL_VOID (XGLAPI *CmdResolveImageType)(XGL_CMD_BUFFER cmdBuffer, XGL_IMAGE srcImage, XGL_IMAGE destImage, XGL_UINT rectCount, const XGL_IMAGE_RESOLVE* pRects);
typedef XGL_VOID (XGLAPI *CmdSetEventType)(XGL_CMD_BUFFER cmdBuffer, XGL_EVENT event);
typedef XGL_VOID (XGLAPI *CmdResetEventType)(XGL_CMD_BUFFER cmdBuffer, XGL_EVENT event);
typedef XGL_VOID (XGLAPI *CmdMemoryAtomicType)(XGL_CMD_BUFFER cmdBuffer, XGL_GPU_MEMORY destMem, XGL_GPU_SIZE destOffset, XGL_UINT64 srcData, XGL_ATOMIC_OP atomicOp);
typedef XGL_VOID (XGLAPI *CmdBeginQueryType)(XGL_CMD_BUFFER cmdBuffer, XGL_QUERY_POOL queryPool, XGL_UINT slot, XGL_FLAGS flags);
typedef XGL_VOID (XGLAPI *CmdEndQueryType)(XGL_CMD_BUFFER cmdBuffer, XGL_QUERY_POOL queryPool, XGL_UINT slot);
typedef XGL_VOID (XGLAPI *CmdResetQueryPoolType)(XGL_CMD_BUFFER cmdBuffer, XGL_QUERY_POOL queryPool, XGL_UINT startQuery, XGL_UINT queryCount);
typedef XGL_VOID (XGLAPI *CmdWriteTimestampType)(XGL_CMD_BUFFER cmdBuffer, XGL_TIMESTAMP_TYPE timestampType, XGL_GPU_MEMORY destMem, XGL_GPU_SIZE destOffset);
typedef XGL_VOID (XGLAPI *CmdInitAtomicCountersType)(XGL_CMD_BUFFER cmdBuffer, XGL_PIPELINE_BIND_POINT pipelineBindPoint, XGL_UINT startCounter, XGL_UINT counterCount, const XGL_UINT32* pData);
typedef XGL_VOID (XGLAPI *CmdLoadAtomicCountersType)(XGL_CMD_BUFFER cmdBuffer, XGL_PIPELINE_BIND_POINT pipelineBindPoint, XGL_UINT startCounter, XGL_UINT counterCount, XGL_GPU_MEMORY srcMem, XGL_GPU_SIZE srcOffset);
typedef XGL_VOID (XGLAPI *CmdSaveAtomicCountersType)(XGL_CMD_BUFFER cmdBuffer, XGL_PIPELINE_BIND_POINT pipelineBindPoint, XGL_UINT startCounter, XGL_UINT counterCount, XGL_GPU_MEMORY destMem, XGL_GPU_SIZE destOffset);
typedef XGL_RESULT (XGLAPI *DbgSetValidationLevelType)(XGL_DEVICE device, XGL_VALIDATION_LEVEL validationLevel);
typedef XGL_RESULT (XGLAPI *DbgRegisterMsgCallbackType)(XGL_DBG_MSG_CALLBACK_FUNCTION pfnMsgCallback, XGL_VOID* pUserData);
typedef XGL_RESULT (XGLAPI *DbgUnregisterMsgCallbackType)(XGL_DBG_MSG_CALLBACK_FUNCTION pfnMsgCallback);
typedef XGL_RESULT (XGLAPI *DbgSetMessageFilterType)(XGL_DEVICE device, XGL_INT msgCode, XGL_DBG_MSG_FILTER filter);
typedef XGL_RESULT (XGLAPI *DbgSetObjectTagType)(XGL_BASE_OBJECT object, XGL_SIZE tagSize, const XGL_VOID* pTag);
typedef XGL_RESULT (XGLAPI *DbgSetGlobalOptionType)(XGL_DBG_GLOBAL_OPTION dbgOption, XGL_SIZE dataSize, const XGL_VOID* pData);
typedef XGL_RESULT (XGLAPI *DbgSetDeviceOptionType)(XGL_DEVICE device, XGL_DBG_DEVICE_OPTION dbgOption, XGL_SIZE dataSize, const XGL_VOID* pData);
typedef XGL_VOID (XGLAPI *CmdDbgMarkerBeginType)(XGL_CMD_BUFFER cmdBuffer, const XGL_CHAR* pMarker);
typedef XGL_VOID (XGLAPI *CmdDbgMarkerEndType)(XGL_CMD_BUFFER cmdBuffer);
typedef XGL_RESULT (XGLAPI *WsiX11AssociateConnectionType)(XGL_PHYSICAL_GPU gpu, const XGL_WSI_X11_CONNECTION_INFO* pConnectionInfo);
typedef XGL_RESULT (XGLAPI *WsiX11GetMSCType)(XGL_DEVICE device, xcb_window_t window, xcb_randr_crtc_t crtc, XGL_UINT64* pMsc);
typedef XGL_RESULT (XGLAPI *WsiX11CreatePresentableImageType)(XGL_DEVICE device, const XGL_WSI_X11_PRESENTABLE_IMAGE_CREATE_INFO* pCreateInfo, XGL_IMAGE* pImage, XGL_GPU_MEMORY* pMem);
typedef XGL_RESULT (XGLAPI *WsiX11QueuePresentType)(XGL_QUEUE queue, const XGL_WSI_X11_PRESENT_INFO* pPresentInfo, XGL_FENCE fence);

typedef struct _XGL_BASE_LAYER_OBJECT
{
    GetProcAddrType pGPA;
    XGL_BASE_OBJECT nextObject;
    XGL_BASE_OBJECT baseObject;
} XGL_BASE_LAYER_OBJECT;

typedef struct _XGL_LAYER_DISPATCH_TABLE
{
    GetProcAddrType GetProcAddr;
    InitAndEnumerateGpusType InitAndEnumerateGpus;
    GetGpuInfoType GetGpuInfo;
    CreateDeviceType CreateDevice;
    DestroyDeviceType DestroyDevice;
    GetExtensionSupportType GetExtensionSupport;
    EnumerateLayersType EnumerateLayers;
    GetDeviceQueueType GetDeviceQueue;
    QueueSubmitType QueueSubmit;
    QueueSetGlobalMemReferencesType QueueSetGlobalMemReferences;
    QueueWaitIdleType QueueWaitIdle;
    DeviceWaitIdleType DeviceWaitIdle;
    GetMemoryHeapCountType GetMemoryHeapCount;
    GetMemoryHeapInfoType GetMemoryHeapInfo;
    AllocMemoryType AllocMemory;
    FreeMemoryType FreeMemory;
    SetMemoryPriorityType SetMemoryPriority;
    MapMemoryType MapMemory;
    UnmapMemoryType UnmapMemory;
    PinSystemMemoryType PinSystemMemory;
    RemapVirtualMemoryPagesType RemapVirtualMemoryPages;
    GetMultiGpuCompatibilityType GetMultiGpuCompatibility;
    OpenSharedMemoryType OpenSharedMemory;
    OpenSharedQueueSemaphoreType OpenSharedQueueSemaphore;
    OpenPeerMemoryType OpenPeerMemory;
    OpenPeerImageType OpenPeerImage;
    DestroyObjectType DestroyObject;
    GetObjectInfoType GetObjectInfo;
    BindObjectMemoryType BindObjectMemory;
    CreateFenceType CreateFence;
    GetFenceStatusType GetFenceStatus;
    WaitForFencesType WaitForFences;
    CreateQueueSemaphoreType CreateQueueSemaphore;
    SignalQueueSemaphoreType SignalQueueSemaphore;
    WaitQueueSemaphoreType WaitQueueSemaphore;
    CreateEventType CreateEvent;
    GetEventStatusType GetEventStatus;
    SetEventType SetEvent;
    ResetEventType ResetEvent;
    CreateQueryPoolType CreateQueryPool;
    GetQueryPoolResultsType GetQueryPoolResults;
    GetFormatInfoType GetFormatInfo;
    CreateImageType CreateImage;
    GetImageSubresourceInfoType GetImageSubresourceInfo;
    CreateImageViewType CreateImageView;
    CreateColorAttachmentViewType CreateColorAttachmentView;
    CreateDepthStencilViewType CreateDepthStencilView;
    CreateShaderType CreateShader;
    CreateGraphicsPipelineType CreateGraphicsPipeline;
    CreateComputePipelineType CreateComputePipeline;
    StorePipelineType StorePipeline;
    LoadPipelineType LoadPipeline;
    CreatePipelineDeltaType CreatePipelineDelta;
    CreateSamplerType CreateSampler;
    CreateDescriptorSetType CreateDescriptorSet;
    BeginDescriptorSetUpdateType BeginDescriptorSetUpdate;
    EndDescriptorSetUpdateType EndDescriptorSetUpdate;
    AttachSamplerDescriptorsType AttachSamplerDescriptors;
    AttachImageViewDescriptorsType AttachImageViewDescriptors;
    AttachMemoryViewDescriptorsType AttachMemoryViewDescriptors;
    AttachNestedDescriptorsType AttachNestedDescriptors;
    ClearDescriptorSetSlotsType ClearDescriptorSetSlots;
    CreateViewportStateType CreateViewportState;
    CreateRasterStateType CreateRasterState;
    CreateMsaaStateType CreateMsaaState;
    CreateColorBlendStateType CreateColorBlendState;
    CreateDepthStencilStateType CreateDepthStencilState;
    CreateCommandBufferType CreateCommandBuffer;
    BeginCommandBufferType BeginCommandBuffer;
    EndCommandBufferType EndCommandBuffer;
    ResetCommandBufferType ResetCommandBuffer;
    CmdBindPipelineType CmdBindPipeline;
    CmdBindPipelineDeltaType CmdBindPipelineDelta;
    CmdBindStateObjectType CmdBindStateObject;
    CmdBindDescriptorSetType CmdBindDescriptorSet;
    CmdBindDynamicMemoryViewType CmdBindDynamicMemoryView;
    CmdBindVertexDataType CmdBindVertexData;
    CmdBindIndexDataType CmdBindIndexData;
    CmdBindAttachmentsType CmdBindAttachments;
    CmdPrepareMemoryRegionsType CmdPrepareMemoryRegions;
    CmdPrepareImagesType CmdPrepareImages;
    CmdDrawType CmdDraw;
    CmdDrawIndexedType CmdDrawIndexed;
    CmdDrawIndirectType CmdDrawIndirect;
    CmdDrawIndexedIndirectType CmdDrawIndexedIndirect;
    CmdDispatchType CmdDispatch;
    CmdDispatchIndirectType CmdDispatchIndirect;
    CmdCopyMemoryType CmdCopyMemory;
    CmdCopyImageType CmdCopyImage;
    CmdCopyMemoryToImageType CmdCopyMemoryToImage;
    CmdCopyImageToMemoryType CmdCopyImageToMemory;
    CmdCloneImageDataType CmdCloneImageData;
    CmdUpdateMemoryType CmdUpdateMemory;
    CmdFillMemoryType CmdFillMemory;
    CmdClearColorImageType CmdClearColorImage;
    CmdClearColorImageRawType CmdClearColorImageRaw;
    CmdClearDepthStencilType CmdClearDepthStencil;
    CmdResolveImageType CmdResolveImage;
    CmdSetEventType CmdSetEvent;
    CmdResetEventType CmdResetEvent;
    CmdMemoryAtomicType CmdMemoryAtomic;
    CmdBeginQueryType CmdBeginQuery;
    CmdEndQueryType CmdEndQuery;
    CmdResetQueryPoolType CmdResetQueryPool;
    CmdWriteTimestampType CmdWriteTimestamp;
    CmdInitAtomicCountersType CmdInitAtomicCounters;
    CmdLoadAtomicCountersType CmdLoadAtomicCounters;
    CmdSaveAtomicCountersType CmdSaveAtomicCounters;
    DbgSetValidationLevelType DbgSetValidationLevel;
    DbgRegisterMsgCallbackType DbgRegisterMsgCallback;
    DbgUnregisterMsgCallbackType DbgUnregisterMsgCallback;
    DbgSetMessageFilterType DbgSetMessageFilter;
    DbgSetObjectTagType DbgSetObjectTag;
    DbgSetGlobalOptionType DbgSetGlobalOption;
    DbgSetDeviceOptionType DbgSetDeviceOption;
    CmdDbgMarkerBeginType CmdDbgMarkerBegin;
    CmdDbgMarkerEndType CmdDbgMarkerEnd;
    WsiX11AssociateConnectionType WsiX11AssociateConnection;
    WsiX11GetMSCType WsiX11GetMSC;
    WsiX11CreatePresentableImageType WsiX11CreatePresentableImage;
    WsiX11QueuePresentType WsiX11QueuePresent;
} XGL_LAYER_DISPATCH_TABLE;

// LL node for tree of dbg callback functions
typedef struct _XGL_LAYER_DBG_FUNCTION_NODE
{
    XGL_DBG_MSG_CALLBACK_FUNCTION pfnMsgCallback;
    XGL_VOID *pUserData;
    struct _XGL_LAYER_DBG_FUNCTION_NODE *pNext;
} XGL_LAYER_DBG_FUNCTION_NODE;

// ------------------------------------------------------------------------------------------------
// API functions
