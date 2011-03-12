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
	Mat frame, gray, edges;

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
		Mat subframe, threshold;
		for (vector<Rect>::iterator it = eye_frame.begin(); it != eye_frame.end(); ++it) {


			Point pt1(it->x, it->y);
			Point pt2(it->x + it->width, it->y + it->height);
			rectangle(frame,pt1,pt2,Scalar(0,0,255));
			if (it->x + it->width > frame.rows || it->y + it->height > frame.cols) continue;
			subframe = frame(Range(it->y, it->y + it->height), Range(it->x, it->x + it->width)).clone();
			//cvtColor(subframe, subframe, CV_RGB2HSV);
			//inRange(subframe, Scalar(0, 0, 0), Scalar(40, 40, 40), threshold);
                	cvtColor(subframe, gray, CV_RGB2GRAY);
			GaussianBlur(gray, gray, Size(5, 5), 1, 1);
			Canny(gray, edges, 1, 2);
                	//cvtColor(gray, threshold, CV_RGB2GRAY);
			//Sobel(subframe,threshold,1,1,0);
			//vector<Vec3f> circles;
                	//HoughCircles(threshold, circles, CV_HOUGH_GRADIENT, 10.0, threshold.rows/500.0, 50, 150 );
			vector<Vec3f> circles;
                	//cvtColor(subframe, gray, CV_BGR2GRAY);
			//GaussianBlur(gray, gray, Size(0, 0), 1, 1);
                	HoughCircles(edges, circles, CV_HOUGH_GRADIENT, 19.0, edges.rows/38.0, 200, 100 );
                	for (vector<Vec<float, 3> >::iterator it2 = circles.begin(); it2 != circles.end(); ++it2) {
                        	circle(frame, cvPoint((*it2)[0]+it->x, (*it2)[1]+it->y), (*it2)[2], CV_RGB(255,0,0),1);
               		}
			imshow("debug", edges);
		}

		imshow("display", frame);
		if (waitKey(30) >= 0 ) break;
	}

}
