#include <cstring>
#include "easypr/export/plate_locate.h"
#include <string>
#include "easypr/core/plate_locate.h"
#include <opencv2/opencv.hpp>
using namespace easypr;
using namespace cv;
using namespace std;

EXPORT long NewPlateLocate()
{
    CPlateLocate *pl = new CPlateLocate();
    return (long)pl;
}

EXPORT int PlateLocate(long ptr, char *imgPath, char *savePath, int index, bool show)
{
    cv::Mat src = imread(imgPath);

    vector<cv::Mat> resultVec;
    CPlateLocate *pl = (CPlateLocate *)ptr;

    int result = pl->plateLocate(src, resultVec, index);
    if (result == 0)
    {
        size_t num = resultVec.size();
        for (size_t j = 0; j < num; j++)
        {
            cv::Mat resultMat = resultVec[j];
            
            std::stringstream ss(std::stringstream::in | std::stringstream::out);
            ss << savePath << "/" << j << ".jpg";
            imwrite(ss.str(), resultMat);

            if (show){
                imshow("plate_locate", resultMat);
                waitKey(0);
            }
            
        }
        destroyWindow("plate_locate");
    }

    return result;
}

EXPORT void DeletePlateLocate(long ptr)
{
    CPlateLocate *pl = (CPlateLocate *)ptr;
    delete pl;
}

EXPORT void PLSetLifeMode(long ptr, bool param)
{
    CPlateLocate *pl = (CPlateLocate *)ptr;
    pl->setLifemode(param);
}
EXPORT void PLSetDebug(long ptr, bool param)
{
    CPlateLocate *pl = (CPlateLocate *)ptr;
    pl->setDebug(param);
}
EXPORT void PLSetGaussianBlurSize(long ptr, int param)
{
    CPlateLocate *pl = (CPlateLocate *)ptr;
    pl->setGaussianBlurSize(param);
}
EXPORT void PLSetMorphSizeWidth(long ptr, int param)
{
    CPlateLocate *pl = (CPlateLocate *)ptr;
    pl->setMorphSizeWidth(param);
}
EXPORT void PLSetMorphSizeHeight(long ptr, int param)
{
    CPlateLocate *pl = (CPlateLocate *)ptr;
    pl->setMorphSizeHeight(param);
}
EXPORT void PLSetVerifyError(long ptr, float param)
{
    CPlateLocate *pl = (CPlateLocate *)ptr;
    pl->setVerifyError(param);
}
EXPORT void PLSetVerifyAspect(long ptr, float param)
{
    CPlateLocate *pl = (CPlateLocate *)ptr;
    pl->setVerifyAspect(param);
}
EXPORT void PLSetVerifyMin(long ptr, int param)
{
    CPlateLocate *pl = (CPlateLocate *)ptr;
    pl->setVerifyMin(param);
}
EXPORT void PLSetVerifyMax(long ptr, int param)
{
    CPlateLocate *pl = (CPlateLocate *)ptr;
    pl->setVerifyMax(param);
}
EXPORT void PLSetJudgeAngle(long ptr, int param)
{
    CPlateLocate *pl = (CPlateLocate *)ptr;
    pl->setJudgeAngle(param);
}