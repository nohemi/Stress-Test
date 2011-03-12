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


#include "neuralnetwork.h"
#include "trainingdata.h"
#include "metriccontainer.h"

NeuralNetwork::NeuralNetwork() {

}

NeuralNetwork::NeuralNetwork(unsigned int input_size, unsigned int hidden_size,
							 unsigned int output_size, TrainingData const& train,
							 MetricContainer const& container) {
	Mat neural_layers(3, 1, CV_32S, 0);
	neural_layers.at<int>(0, 0) = input_size;
	neural_layers.at<int>(1, 0) = hidden_size;
	neural_layers.at<int>(2, 0) = output_size;
	network.create(neural_layers);
	network.train(train.get_inputs(container), train.get_outputs(), train.get_weights());
}
NeuralNetwork::~NeuralNetwork() {
}



