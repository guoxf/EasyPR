#include<cstring>
#include"easypr/py/process.h"
#include"easypr/py/py.h"
#include<string>
using namespace std;

EXPORT long init(char * modelpath,bool showResult,bool debug,int maxPlate){
	Process * ptr = new Process(modelpath,showResult,debug,maxPlate);
	long re = (long)ptr;
	return re;
}

EXPORT char * plateRecognize(long ptr, char *img, int len){
	Process *p = (Process *)ptr;
	string str = p->process(img, len);
	char *buf = new char[str.length()+1];
	strcpy(buf, str.c_str());
	return buf;
}

EXPORT char *plateRecognizeByImagePath(long ptr,char *imagePath){
	Process *p = (Process *)ptr;
	string str = p->process(imagePath);
	char *buf = new char[str.length()+1];
	strcpy(buf, str.c_str());
	return buf;
}

EXPORT void deleteptr(long ptr){
	Process *p = (Process *)ptr;
	delete p;
}