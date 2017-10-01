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

int main(int, char**)
{
    Mat frame;
    //--- INITIALIZE VIDEOCAPTURE
    VideoCapture cap;
    // open the default camera using default API
    cap.open(0);
    // OR advance usage: select any API backend
    int deviceID = 0;             // 0 = open default camera
    int apiID = cv::CAP_ANY;      // 0 = autodetect default API
    // open selected camera using selected API
    cap.open(deviceID + apiID);
    // check if we succeeded
    if (!cap.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
        return -1;
    }

    //--- GRAB AND WRITE LOOP
    cout << "Start grabbing" << endl
        << "Press any key to terminate" << endl;
    for (;;)
    {
        // wait for a new frame from camera and store it into 'frame'
        cap.read(frame);
		// Perform operations on the frame here
		// For example convert to Grayscale
		cvtColor(frame, frame, CV_BGR2GRAY);
		// Overlay Text on the video frame 
		putText(frame, "{Real Nomad}", Point2f(100, 100), FONT_HERSHEY_SCRIPT_COMPLEX, 2, Scalar(0, 0, 255, 255));

        // check if we succeeded
        if (frame.empty()) {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        // show live and wait for a key with timeout long enough to show images
        imshow("Live", frame);
        if (waitKey(5) >= 0)
            break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}