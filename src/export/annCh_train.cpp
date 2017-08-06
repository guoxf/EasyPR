#include <cstring>
#include "easypr/train/annCh_train.h"
#include "easypr/export/annCh_train.h"
#include <string>
using namespace std;
using namespace easypr;

EXPORT long NewAnnChTrain(char *chars_folder, char *xml)
{
    AnnChTrain *ptr = new AnnChTrain(chars_folder, xml);
    long at = (long)ptr;
    return at;
}

EXPORT void AnnChTrainTrain(long ptr)
{
    AnnChTrain *at = (AnnChTrain *)ptr;
    at->train();
}

EXPORT void DeleteAnnChTrain(long ptr)
{
    AnnChTrain *at = (AnnChTrain *)ptr;
    delete at;
}

EXPORT void AnnChTrainSetNumberForCount(long ptr, int n)
{
    AnnChTrain *at = (AnnChTrain *)ptr;
    at->setNumberForCount(n);
}
