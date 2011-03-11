#include "cv.h"
#include "highgui.h"
using namespace cv;

int main(int argc, char* argv[]) {
	//Init camera feed and GUI output
	VideoCapture capture(0);
	if (!capture.isOpened()) return -1;
	namedWindow("display", 1);
	Mat frame;

	//Loop outputing collected data
	while (true) {
		capture >> frame;
		imshow("display", frame);
		if (waitKey(30) >= 0 ) break;
	}

}