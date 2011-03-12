/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) <year>  <name of author>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "cv.h"
#include "trainingdata.h"
using namespace cv;

TrainingData::TrainingData() {}

TrainingData::~TrainingData() {}

void TrainingData::append(Mat const& image, bool stressed) {
	data.push_back(pair<Mat, bool>(image, stressed));
}

Mat TrainingData::get_inputs(MetricContainer const& container) const {
	Mat ret(data.size(), 1, CV_32FC1); //FIXME: More columns for more data types
	int row = 0;
	for (list<std::pair <Mat, bool > >::const_iterator it = data.begin(); it != data.end(); it++) {
		double* mat_ptr = ret.ptr<double>(row++);
		for (int col = 0; col < ret.cols - 1; col++) {
			mat_ptr[col] = container.calculate(it->first).ptr<double>(0)[col];
		}
	}
	return ret;
}

Mat TrainingData::get_outputs() const {
	Mat ret(data.size(), 1, CV_32FC1);
	int row = 0;
	for (list<pair<Mat, bool> >::const_iterator it = data.begin(); it != data.end(); it++) {
		double* mat_ptr = ret.ptr<double>(row++);
		mat_ptr[0] = (double)it->second;
	}
	return ret;
}

Mat TrainingData::get_weights() const {
	return Mat(container.get_weights());
}