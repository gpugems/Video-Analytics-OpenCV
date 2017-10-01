/**
*
*/

//include
#include<iostream>
#include<string>
#include<cstdlib>

//include opencv
#include "opencv2/opencv.hpp"
#include <opencv2/core/utility.hpp>



//namespaces
using namespace std;

//pragma
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS



int main() {

	std::cout << cv::getBuildInformation() << std::endl;
	return 0;

}