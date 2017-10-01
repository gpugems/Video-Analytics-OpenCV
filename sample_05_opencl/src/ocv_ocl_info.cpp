/**
*
*/

//include
#include<iostream>
#include<string>
#include<cstdlib>

//include opencv
#include "opencv2/opencv.hpp"
#include <opencv2/core/ocl.hpp> // check OCL


using namespace cv;
using namespace std;

//pragma
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

int main(int, char**)
{
	if (!cv::ocl::haveOpenCL())
	{
		cout << "OpenCL is not avaiable..." << endl;
		return -1;
	}
	else
	{
		cv::ocl::setUseOpenCL(true);
		if (cv::ocl::useOpenCL()) {
			cout << "Opencl is enabled." << endl;
		}
	}

	cv::ocl::setUseOpenCL(false);
	if (!cv::ocl::useOpenCL()) {
		cout << "Opencl is disabled." << endl;
	}
    return 0;
}