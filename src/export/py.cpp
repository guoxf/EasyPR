#include <cstring>
#include "easypr/export/process.h"
#include "easypr/export/py.h"
#include <string>
using namespace std;

EXPORT long init(char *modelpath, bool showResult, bool debug, int maxPlate, int detectType)
{
	Process *ptr = new Process(modelpath, showResult, debug, maxPlate, detectType);
	long re = (long)ptr;
	return re;
}

EXPORT char *plateRecognize(long ptr, char *img, int len, int index)
{
	Process *p = (Process *)ptr;
	string str = p->process(img, len, index);
	char *buf = new char[str.length() + 1];
	strcpy(buf, str.c_str());
	return buf;
}

EXPORT char *plateRecognizeByImagePath(long ptr, char *imagePath, int index)
{
	Process *p = (Process *)ptr;
	string str = p->process(imagePath, index);
	char *buf = new char[str.length() + 1];
	strcpy(buf, str.c_str());
	return buf;
}

EXPORT void deleteptr(long ptr)
{
	Process *p = (Process *)ptr;
	delete p;
}