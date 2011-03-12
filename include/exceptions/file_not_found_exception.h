#include <exception>
#include <string>
using namespace std;

class FileNotFoundException : public exception {
public:
	FileNotFoundException(string const& file) throw() {this->file = file;};
	virtual ~FileNotFoundException() throw() {};
	virtual const char* what() const throw() {
		return string("File '" + file + "' not found").c_str();
	};
protected:
	string file;
};
