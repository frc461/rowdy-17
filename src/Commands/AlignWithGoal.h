// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef ALIGN_WITH_GOAL_H
#define ALIGN_WITH_GOAL_H

#include <ctime>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <unistd.h>
#include <pthread.h>

#include "../SettablePIDSource.hpp"
#include "../SettablePIDOut.hpp"

#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */

using namespace cv;
using namespace std;

class AlignWithGoal: public Command {
public:
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
	AlignWithGoal();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES

	int hLow = 50;
	int hHigh = 255;
	int sLow = 150;
	int sHigh = 255;
	int vLow = 50;
	int vHigh = 130;

	int minRectWidth = 20;
	int maxRectWidth = 100;
	int minRectHeight = 20;
	int maxRectHeight = 100;

	Mat frame;
	Mat hsv;
	Mat thresholded;
	vector<Mat> contours;
	vector<cv::Rect> filteredContours = vector<cv::Rect>();
	VideoCapture video;
	Image *image;

	SettablePIDSource visionTargetCenter = SettablePIDSource();
	SettablePIDOut driveTrainOut = SettablePIDOut();;

	Timer *t = new Timer();

	PIDController *pid = new PIDController(.05,0,0.05, .1,&visionTargetCenter, &driveTrainOut, .02);

	bool shouldUpdateFrame = true;
	float rectCenter;

	void filterContours();
	void findAndDrawRect();
	void redrawHSV(int pos, void *);
	void visionSetup();
	void vision();
};

#endif