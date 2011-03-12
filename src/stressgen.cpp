#include <string>
#include <iostream>
#include "cv.h"
#include "highgui.h"
#include "cxcore.h"
using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {
	//Init camera feed and GUI output
	VideoCapture capture(0);
	if (!capture.isOpened()) return -1;
	namedWindow("display", 1);
	Mat frame;
	string filename;

	cout << "Store data to file: ";
	cin >> filename;
	FileStorage store(filename, FileStorage::APPEND);

	capture >> frame;
	imshow("display", frame);
	waitKey(100);

	bool running = true;
	while (running) {
		bool stress;
		cout << "Snapping image" << endl;
		capture >> frame;
		capture >> frame;
		capture >> frame;
		capture >> frame;
		capture >> frame;
		imshow("display", frame);
		waitKey(1000);
		bool should_continue;
		cout << "Use picture?" << endl;
		cin >> should_continue;
		if (!should_continue) continue;
		cout << "Is displayed image stressed?" << endl;
		cin >> stress;
		cout << "Acknowledged" << endl;
		store << "matrix" << frame;
		store << "stressed" << stress;
		cout << "More? ";
		cin >> running;
	}
	store.release();

	return 0;
}