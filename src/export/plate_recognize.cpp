#include <cstring>
#include "easypr/export/plate_recognize.h"
#include <string>
#include "easypr/core/plate_recognize.h"
#include <opencv2/opencv.hpp>
using namespace easypr;
using namespace cv;

string process(long ptr, Mat &src, int index)
{
	CPlateRecognize *pr = (CPlateRecognize *)ptr;
	string plate = "";
	if (!src.data)
		return plate;
	vector<CPlate> plateVec;
	int result = pr->plateRecognize(src, plateVec, index);
	if (result == 0)
	{
		size_t num = plateVec.size();
		if (num <= 0)
		{
			return plate;
		}
		plate = plateVec[0].getPlateStr();
		for (size_t i = 1; i < num; i++)
		{
			plate = plate + "," + plateVec[i].getPlateStr();
		}
	}
	return plate;
}

EXPORT long NewPlateRecognize(char *modelpath, bool showResult, bool debug, int maxPlate, int detectType)
{
	CPlateRecognize *pr = new CPlateRecognize();
	pr->setLifemode(true);
	pr->setDebug(debug);
	pr->setResultShow(showResult);
	pr->setMaxPlates(maxPlate);
	pr->setDetectType(detectType);
	pr->setDetectShow(true);
	string path=modelpath;
	pr->LoadSVM((path + "/svm_hist.xml"));
	pr->LoadANN(path + "/ann.xml");
	pr->LoadChineseANN(path + "/ann_chinese.xml");
	pr->LoadGrayChANN(path + "/annCh.xml");
	pr->LoadChineseMapping(path + "/province_mapping");

	return (long)pr;
}

EXPORT char *PlateRecognize(long ptr, char *img, int len, int index)
{
	Mat src = imdecode(Mat(1, len, CV_8U, img), IMREAD_COLOR);
	string str = "";
	if (src.data)
		str = process(ptr, src, index);

	char *buf = new char[str.length() + 1];
	strcpy(buf, str.c_str());
	return buf;
}

EXPORT char *PlateRecognizeByImagePath(long ptr, char *imagePath, int index)
{
	Mat src = imread(imagePath);
	string str = "";
	if (src.data)
		str = process(ptr, src, index);
	char *buf = new char[str.length() + 1];
	strcpy(buf, str.c_str());
	return buf;
}

EXPORT void PRSetLifeMode(long ptr, bool param)
{
	CPlateRecognize *pr = (CPlateRecognize *)ptr;
	pr->setLifemode(param);
}

EXPORT void PRSetDetectType(long ptr, bool param)
{
	CPlateRecognize *pr = (CPlateRecognize *)ptr;
	pr->setDetectType(param);
}

EXPORT void PRSetResultShow(long ptr, bool param)
{
	CPlateRecognize *pr = (CPlateRecognize *)ptr;
	pr->setResultShow(param);
}

EXPORT void PRSetDetectShow(long ptr, bool param)
{
	CPlateRecognize *pr = (CPlateRecognize *)ptr;
	pr->setDetectShow(param);
}

EXPORT void PRSetDebug(long ptr, bool param)
{
	CPlateRecognize *pr = (CPlateRecognize *)ptr;
	pr->setDebug(param);
}

EXPORT void PRLoadSVM(long ptr, char *path)
{
	CPlateRecognize *pr = (CPlateRecognize *)ptr;
	pr->LoadSVM(path);
}

EXPORT void PRLoadANN(long ptr, char *path)
{
	CPlateRecognize *pr = (CPlateRecognize *)ptr;
	pr->LoadANN(path);
}

EXPORT void PRLoadChineseANN(long ptr, char *path)
{
	CPlateRecognize *pr = (CPlateRecognize *)ptr;
	pr->LoadChineseANN(path);
}

EXPORT void PRLoadGrayChANN(long ptr, char *path)
{
	CPlateRecognize *pr = (CPlateRecognize *)ptr;
	pr->LoadGrayChANN(path);
}

EXPORT void PRLoadChineseMapping(long ptr, char *path)
{
	CPlateRecognize *pr = (CPlateRecognize *)ptr;
	pr->LoadChineseMapping(path);
}

EXPORT void DeletePr(long ptr)
{
	CPlateRecognize *pr = (CPlateRecognize *)ptr;
	delete pr;
}