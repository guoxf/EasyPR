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
EXPORT long init(char *modelpath, bool showResult, bool debug, int maxPlate,int detectType);
EXPORT char *plateRecognize(long ptr, char *img, int len,int index);
EXPORT char *plateRecognizeByImagePath(long ptr, char *imgPath,int index);
EXPORT void deleteptr(long ptr);

#ifdef __cplusplus
}
#endif
#endif