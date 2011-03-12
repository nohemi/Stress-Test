#include "cv.h"
#include "highgui.h"
#include "finder.h"
#include "metriccontainer.h"
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
	//Init camera feed and GUI output
	VideoCapture capture(0);
	if (!capture.isOpened()) return -1;
	namedWindow("display", 1);
	Mat frame;

	MetricContainer container;

	//Loop outputing collected data
	while (true) {
		capture >> frame;
		Finder eyes;
		vector<Rect> eye_frame;
		eye_frame = eyes.detectEyes(frame);
		for (vector<Rect>::iterator it = eye_frame.begin(); it != eye_frame.end(); ++it) {
			cout << it->x << endl;
			cout << it->y << endl;
		}
		//imshow("display", frame);
		if (waitKey(30) >= 0 ) break;
	}

}
