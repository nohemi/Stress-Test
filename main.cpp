#include "cv.h"
#include "highgui.h"
using namespace cv;

int main(int argc, char* argv[]) {
	VideoCapture capture(0);
	if (!capture.isOpened()) return -1;
	namedWindow("display", 1);
	Mat frame;
        while (true) {
		capture >> frame;
		imshow("display", frame);
		if (waitKey(30) >= 0 ) break;
	}

}