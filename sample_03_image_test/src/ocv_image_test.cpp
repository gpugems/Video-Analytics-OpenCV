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
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

//pragma
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS



int main(int argc, char** argv) {

 if( argc != 2)
    {
     cout <<" Usage: ocv_image_test ImageToLoadAndDisplay" << endl;
     return -1;
    }

    Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window", image );                   // Show our image inside it.

    waitKey(0);                                          // Wait for a keystroke in the window
    return 0;

}