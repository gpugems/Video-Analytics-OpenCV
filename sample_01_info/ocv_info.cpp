/**
*
*/

//include
#include<iostream>
#include<string>
#include<cstdlib>

//include opencv
#include "opencv2/opencv.hpp"


//namespaces
using namespace std;

//pragma
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS


int print_evn_variable(string name,string env_name) {
	char* varval = std::getenv(env_name.c_str());
	if (NULL != varval) {
		cout <<name << " Environment Variable - "<< env_name << " : " << varval << endl;
	}
	return 0;
}

int main() {

	print_evn_variable("OpenCV","OPENCV_DIR");
	cout << "OpenCV version : " << CV_VERSION << endl;
	cout << "Major version : " << CV_MAJOR_VERSION << endl;
	cout << "Minor version : " << CV_MINOR_VERSION << endl;
	cout << "Subminor version : " << CV_SUBMINOR_VERSION << endl;
	return 0;

}