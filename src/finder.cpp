#include "finder.h"
#include "exceptions/file_not_found_exception.h"
#include "cv.h"
#include <iostream>

using namespace cv;
using namespace std;

vector<Rect> Finder::detectEyes (const Mat& image) {
	//Detect eyes
	CascadeClassifier eyes;
	vector<Rect> objects;
	//string filename("resources/haarcascade_mcs_eyepair_big.xml");
	string filename("/usr/share/opencv/haarcascades/haarcascade_lefteye_2splits.xml");
	if (!eyes.load(filename)) throw FileNotFoundException(filename);
	eyes.detectMultiScale(image,objects);
	return objects;

}
