#include <cstring>
#include "easypr/train/ann_train.h"
#include "easypr/export/ann_train.h"
#include <string>
using namespace std;
using namespace easypr;

EXPORT long NewAnnTrain(const char *chars_folder, const char *xml)
{
    AnnTrain *ptr = new AnnTrain(chars_folder, xml);
    long at = (long)ptr;
    return at;
}

EXPORT void AnnTrainTrain(long ptr)
{
    AnnTrain *at = (AnnTrain *)ptr;
    at->train();
}

EXPORT void DeleteAnnTrain(long ptr)
{
    AnnTrain *at = (AnnTrain *)ptr;
    delete at;
}