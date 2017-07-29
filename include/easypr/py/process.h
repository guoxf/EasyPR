#include <string>
#include "easypr/core/plate_recognize.h"
#include <opencv2/opencv.hpp>
using namespace easypr;
using namespace std;
#ifndef _Included_Process
#define _Included_Process

class Process{
	CPlateRecognize *pr;
public:
	~Process(){
		delete pr;
	}
	Process(string path,bool showResult,bool debug,int maxPlate);
	Process();
	string process(char*, int);
	string process(Mat &);
};
#endif