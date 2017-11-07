/*
* 3calibration.cpp -- Calibrate 3 cameras in a horizontal line together.
*/

#include "opencv2/calib3d.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include <opencv2/ccalib/multicalib.hpp>

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <iostream>

using namespace cv;
using namespace cv::xfeatures2d;
using namespace cv::multicalib;


int main(int argc, char** argv)
{
	int camera_count;
	int verbose;
	int minMatch;
	int showExtraction;
	int termCount;
	std::string inputFilename = "";
	std::string outputFilename = "";

	int patternWidth;
	int patternHeight;

	cv::CommandLineParser parser(argc, argv,
		"{m|100|}{c|36|}{v|0|}{e|0|}{w|109|}{h|82|}{tc||}{@output||}"
		"{@input||}");

	camera_count = parser.get<int>("c");
	verbose = parser.get<int>("v");
	showExtraction = parser.get<int>("e");
	patternWidth = parser.get<int>("w");
	patternHeight = parser.get<int>("h");
	minMatch = parser.get<int>("m");
	termCount = parser.get<int>("tc");

	std::cout << "camera_count=" << camera_count << std::endl;
	std::cout << "patternWidth=" << patternWidth << std::endl;
	std::cout << "patternHeight=" << patternHeight << std::endl;

	inputFilename = parser.get<std::string>("@input");
	outputFilename = parser.get<std::string>("@output");
	if (!parser.check())
	{
		std::cout << "Parser error" << std::endl;
		parser.printErrors();
		return -1;
	}

	if (inputFilename.empty())
	{
		std::cout << "Error: the input image list is not specified, or can not be read\n" << std::endl;
		return -1;
	}

	//-- Step 1: Detect the keypoints using SURF Detector, compute the descriptors
	int metrixThreshold = 200; //minHessian
	int numberOfOctaves = 8;
	int numScaleLevels = 4; // nOctavesLayer

	Ptr<SURF> detector = SURF::create(metrixThreshold, numberOfOctaves, numScaleLevels);
	Ptr<SURF> descriptor = detector;

	MultiCameraCalibration multiCalib(
		MultiCameraCalibration::PINHOLE,
		camera_count,
		inputFilename,
		patternWidth,
		patternHeight,
		verbose,
		showExtraction,
		minMatch,
		0,
		cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, termCount, 10e-5),
		detector, 
		descriptor,
		DescriptorMatcher::create(DescriptorMatcher::FLANNBASED)
		/*cv::AKAZE::create(cv::AKAZE::DESCRIPTOR_MLDB, 0, 3, 0.005f),
		cv::AKAZE::create(cv::AKAZE::DESCRIPTOR_MLDB, 0, 3, 0.005f),
		cv::DescriptorMatcher::create("BruteForce-L1")*/
	);
	multiCalib.run();
	multiCalib.writeParameters(outputFilename);
	return 0;
}