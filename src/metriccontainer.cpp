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

#include "metricextractor.h"
#include "metriccontainer.h"
using namespace cv;

MetricContainer::MetricContainer() {

}

MetricContainer::~MetricContainer() {
	for (std::list<MetricExtractor*>::iterator it = metrics.begin(); it != metrics.end(); it++) {
		delete *it;
	}
}

void MetricContainer::add_metric_extractor(MetricExtractor* extractor) {
	metrics.push_back(extractor);
}

vector<double> MetricContainer::get_weights() const {
	vector<double> ret;
	for (list<MetricExtractor*>::const_iterator it = metrics.begin(); it != metrics.end(); it++) {
		ret.push_back((*it)->get_weight());
	}
	return ret;
}

/** \brief Generate a set of metrics based on loaded metric extractors
 *  \param input A matrix which represents an image
 *  \return A matrix of one row where each column represents a metric
 */
Mat MetricContainer::calculate(Mat const& input) const {
	Mat ret(input.rows, metrics.size(), CV_32FC1); //FIXME: More columns for more data types
	for (list<MetricExtractor*>::const_iterator it = metrics.begin(); it != metrics.end(); it++) {
		double* mtrx_ptr = ret.ptr<double>(0);
		for (int col = 0; col < ret.cols; col++) {
			mtrx_ptr[col] = ((*it)->calculate(input).second);
		}
	}
	return ret;
}

