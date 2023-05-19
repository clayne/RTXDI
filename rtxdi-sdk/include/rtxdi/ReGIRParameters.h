#ifndef RTXDI_REGIR_PARAMETERS_H
#define RTXDI_REGIR_PARAMETERS_H

#include "RtxdiTypes.h"

#define RTXDI_ONION_MAX_LAYER_GROUPS 8
#define RTXDI_ONION_MAX_RINGS 52

#define RTXDI_REGIR_DISABLED 0
#define RTXDI_REGIR_GRID 1
#define RTXDI_REGIR_ONION 2

#ifndef RTXDI_REGIR_MODE
#define RTXDI_REGIR_MODE RTXDI_REGIR_DISABLED
#endif 

struct RTXDI_OnionLayerGroup
{
    float innerRadius;
    float outerRadius;
    float invLogLayerScale;
    int layerCount;

    float invEquatorialCellAngle;
    int cellsPerLayer;
    int ringOffset;
    int ringCount;

    float equatorialCellAngle;
    float layerScale;
    int layerCellOffset;
    int pad;
};

struct RTXDI_OnionRing
{
    float cellAngle;
    float invCellAngle;
    int cellOffset;
    int cellCount;
};

#define REGIR_LOCAL_LIGHT_PRESAMPLING_MODE_UNIFORM 0
#define REGIR_LOCAL_LIGHT_PRESAMPLING_MODE_POWER_RIS 1

#define REGIR_LOCAL_LIGHT_FALLBACK_MODE_UNIFORM 0
#define REGIR_LOCAL_LIGHT_FALLBACK_MODE_POWER_RIS 1

struct RTXDI_ReGIRCommonParameters
{
    uint32_t localLightSamplingFallbackMode;
    float centerX;
    float centerY;
    float centerZ;

    uint32_t risBufferOffset;
    uint32_t lightsPerCell;
    float cellSize;
    float samplingJitter;

    uint32_t localLightPresamplingMode;
    uint32_t numRegirBuildSamples; // PresampleReGIR.hlsl -> RTXDI_PresampleLocalLightsForReGIR
    uint32_t pad0;
    uint32_t pad1;
};

struct RTXDI_ReGIRGridParameters
{
    uint32_t cellsX;
    uint32_t cellsY;
    uint32_t cellsZ;
    uint32_t pad;
};

struct RTXDI_ReGIROnionParameters
{
    RTXDI_OnionLayerGroup layers[RTXDI_ONION_MAX_LAYER_GROUPS];
    RTXDI_OnionRing rings[RTXDI_ONION_MAX_RINGS];

    uint32_t numLayerGroups;
    float cubicRootFactor;
    float linearFactor;
    float pad;
};

#endif // RTXDI_REGIR_PARAMETERS_H