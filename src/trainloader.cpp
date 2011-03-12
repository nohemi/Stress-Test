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


#include "trainloader.h"

TrainLoader::TrainLoader(string const& filename) {
	datastore = FileStorage(filename, FileStorage::READ);
}

TrainLoader::~TrainLoader() {
}

TrainingData TrainLoader::extract_training_data() const {
	TrainingData data;
	FileNode root = datastore.getFirstTopLevelNode();
	if (root.name() != "TrainingData") throw 0; //FIXME: Use FileException
	for (FileNodeIterator it = root.begin(); it != root.end(); it++) {
		Mat matrix;
		(*it)["matrix"] >> matrix;
		const bool stressed = (bool)(int)(*it)["stressed"];
		data.append(matrix, stressed);
	}
	return data;
}

