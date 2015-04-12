//============================================================================
// Name        : DisplayImage.cpp
// Author      : wx
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>

using namespace std;


int main( int argc, char** argv )
{
		cv::Mat image;
	    image = cv::imread("/home/wxia/workspace/input/flower.jpg", CV_LOAD_IMAGE_COLOR);   // Read the file

	    if(! image.data )                              // Check for invalid input
	    {
	        cout <<  "Could not open or find the image" << std::endl ;
	        return -1;
	    }

	    cv::ORB orb(500, 1.2f, 8, 31, 0, 2, cv::ORB::HARRIS_SCORE, 31);
	    vector<cv::KeyPoint> keypoints;
	    orb.operator ()(image,cv::Mat(), keypoints, cv::noArray(), false);

	    vector<cv::Point2f> points;
	    cv::KeyPoint::convert(keypoints, points, vector<int>());
	    if(!points.empty()) {
	    	for(int i=0; i<points.size(); i++) {
	    		cv::circle(image, points[i], 5, cv::Scalar(0, 255, 0), 1, 8, 0);
	    	}
	    }

	    cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );// Create a window for display.
	    cv::imshow( "Display window", image );                   // Show our image inside it.

	    cv::waitKey(0);                                          // Wait for a keystroke in the window
	    return 0;
}

