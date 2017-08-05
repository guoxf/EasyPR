#include <cstring>
#include "easypr/train/svm_train.h"
#include "easypr/export/svm_train.h"
#include <string>
using namespace std;
using namespace easypr;

EXPORT long NewSvmTrain(const char *plates_folder, const char *xml)
{
    SvmTrain *ptr = new SvmTrain(plates_folder, xml);
    long st = (long)ptr;
    return st;
}

EXPORT void SvmTrainTrain(long ptr)
{
    SvmTrain *st = (SvmTrain *)ptr;
    st->train();
}

EXPORT void DeleteSvmTrain(long ptr)
{
    SvmTrain *st = (SvmTrain *)ptr;
    delete st;
}