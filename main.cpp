#include "cv.h"
#include "highgui.h"
#include "finder.h"
#include "metriccontainer.h"
#include "neuralnetwork.h"
#include "trainingdata.h"
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
	//Init camera feed and GUI output
	VideoCapture capture(0);
	if (!capture.isOpened()) return -1;
	namedWindow("display", 1);
	Mat frame, gray;

	MetricContainer container;
	TrainingData data;
	Mat image(1, 1, DataType<double>::type);
	data.append(image, true);
	NeuralNetwork ml_network(1, 3, 1, data, container);

	//Loop outputing collected data
	while (true) {
		capture >> frame;
		Finder eyes;
		vector<Rect> eye_frame;
		eye_frame = eyes.detectEyes(frame);
		for (vector<Rect>::iterator it = eye_frame.begin(); it != eye_frame.end(); ++it) {
			Point pt1(it->x,it->y);
			Point pt2(it->x + it->width,it->y + it->height);
			rectangle(frame,pt1,pt2,Scalar(0,0,255));
		}

		vector<Vec3f> circles;
		cvtColor(frame, gray, CV_BGR2GRAY);
		HoughCircles(gray, circles, CV_HOUGH_GRADIENT, 2, gray.rows/50, 50, 200 );
		circle(gray, cvPoint(cvRound(circle[0]),cvRound(circle[1])),cvRound(circle[2]),CV_RGB(255,0,0),-1);*/
		for (vector<Vec<float, 3> >::iterator it = circles.begin(); it != circles.end(); it++) {
			circle(frame, cvPoint((*it)[0], (*it)[1]), (*it)[2], CV_RGB(255,0,0),1);
		}

		imshow("display", frame);
		if (waitKey(30) >= 0 ) break;
	}

}
