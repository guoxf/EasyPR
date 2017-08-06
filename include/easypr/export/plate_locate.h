#ifndef _EASYPRPY_H_
#define _EASYPRPY_H_

#if _WIN32
#define EXPORT __declspec(dllexport)
#define IMPORT __declspec(dllimport)
#else
#ifndef __has_attribute
#define __has_attribute(x) 0
#endif
#if (defined(__GNUC__) && ((__GNUC__ > 4) || (__GNUC__ == 4) && (__GNUC_MINOR__ > 2))) || __has_attribute(visibility)
#define EXPORT __attribute__((visibility("default")))
#define IMPORT __attribute__((visibility("default")))
#else
#define EXPORT
#define IMPORT
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>
EXPORT long NewPlateLocate();
EXPORT int PlateLocate(long ptr, char *imgPath,char *savePath,int index, bool show);
EXPORT void DeletePlateLocate(long ptr);
EXPORT void PLSetLifeMode(long ptr, bool param);
EXPORT void PLSetDebug(long ptr, bool param);
EXPORT void PLSetGaussianBlurSize(long ptr, int param);
EXPORT void PLSetMorphSizeWidth(long ptr, int param);
EXPORT void PLSetMorphSizeHeight(long ptr, int param);
EXPORT void PLSetVerifyError(long ptr, float param);
EXPORT void PLSetVerifyAspect(long ptr, float param);
EXPORT void PLSetVerifyMin(long ptr, int param);
EXPORT void PLSetVerifyMax(long ptr, int param);
EXPORT void PLSetJudgeAngle(long ptr, int param);
#ifdef __cplusplus
}
#endif
#endif