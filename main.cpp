#include "cv.h"
#include "highgui.h"
#include "finder.h"
#include "metriccontainer.h"
#include "neuralnetwork.h"
#include "trainingdata.h"
using namespace cv;

int main(int argc, char* argv[]) {
	//Init camera feed and GUI output
	VideoCapture capture(0);
	if (!capture.isOpened()) return -1;
	namedWindow("display", 1);
	Mat frame;

	MetricContainer container;
	TrainingData data;
	Mat image(1, 1, 1);
	data.append(image, true);
	NeuralNetwork ml_network(1, 3, 1, data, container);

	//Loop outputing collected data
	while (true) {
		capture >> frame;
		Finder eyes;
		vector<Rect> eye_frame;
		eye_frame = eyes.detectEyes(frame);
		//imshow("display", frame);
		if (waitKey(30) >= 0 ) break;
	}

}
