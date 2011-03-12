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


#ifndef TRAININGDATA_H
#define TRAININGDATA_H

#include <list>
#include <string>
#include <utility>

#include "cv.h"

#include "metriccontainer.h"
using namespace std;
using namespace cv;

/** \brief Stores true data for network training */
class TrainingData {

public:
	TrainingData();
    virtual ~TrainingData();
	void append(Mat const& image, bool stressed);
    Mat get_inputs(MetricContainer const& container) const;
	Mat get_outputs() const;
	Mat get_weights() const;

protected:
	list<pair<Mat, bool> > data;
	MetricContainer container;
};

#endif // TRAININGDATA_H
