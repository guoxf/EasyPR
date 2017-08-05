#include "easypr/export/process.h"
#include "easypr/core/plate_recognize.h"
#include <opencv2/opencv.hpp>
using namespace easypr;
using namespace cv;
string Process::process(Mat &src, int index)
{
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

string Process::process(char *imagebuffer, int size, int index)
{
	Mat src = imdecode(Mat(1, size, CV_8U, imagebuffer), IMREAD_COLOR);
	if (!src.data)
		return "";
	return this->process(src, index);
}

string Process::process(string imagePath, int index)
{
	Mat src = imread(imagePath);
	if (!src.data)
		return "";
	return this->process(src, index);
}

Process::Process()
{
	pr = new CPlateRecognize();
	pr->setLifemode(true);
	pr->setDebug(false);
	pr->setMaxPlates(4);
	pr->setDetectType(PR_DETECT_COLOR | easypr::PR_DETECT_CMSER);

	pr->LoadSVM(("./model/svm_hist.xml"));
	pr->LoadANN("./model/ann.xml");
	pr->LoadChineseANN("./model/ann_chinese.xml");
	pr->LoadGrayChANN("./model/annCh.xml");
	pr->LoadChineseMapping("./model/province_mapping");
}

Process::Process(string path, bool showResult, bool debug, int maxPlate, int detectType)
{
	pr = new CPlateRecognize();
	pr->setLifemode(true);
	pr->setDebug(debug);
	pr->setResultShow(showResult);
	pr->setMaxPlates(maxPlate);
	pr->setDetectType(detectType);
	pr->setDetectShow(true);

	pr->LoadSVM((path + "/svm_hist.xml"));
	pr->LoadANN(path + "/ann.xml");
	pr->LoadChineseANN(path + "/ann_chinese.xml");
	pr->LoadGrayChANN(path + "/annCh.xml");
	pr->LoadChineseMapping(path + "/province_mapping");
}
