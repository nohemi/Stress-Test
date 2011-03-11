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


#ifndef METRICEXTRACTOR_H
#define METRICEXTRACTOR_H

#include "cv.h"

#include <utility>
#include <string>
using namespace std;

class MetricExtractor {

public:
    MetricExtractor() {};
    virtual ~MetricExtractor() {};
    virtual pair<const string, const int> calculate(cv::Mat const&) = 0;
};

#endif // METRICEXTRACTOR_H
