#include "finder.h"
#include "exceptions/file_not_found_exception.h"
#include "cv.h"

using namespace cv;
using namespace std;

vector<Rect> Finder::detectEyes (const Mat& image) {
	//Detect eyes
	CascadeClassifier eyes;
	vector<Rect> objects;
	const string filename("haarcascade_mcs_eyepair_big.xml");
	if (!eyes.load(filename)) throw FileNotFoundException(filename);
	eyes.detectMultiScale(image,objects);
	return objects;

}
