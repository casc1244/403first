#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main(int argc, const char * argv[]) {


	VideoCapture cap(0);


	while (1)
	{
		Mat InMat;
		Mat xMat;
		Mat yMat;
		Mat OutMat;
		Mat OutMat2;
		cap >> InMat;
		Canny(InMat, OutMat, 50, 150);
		Sobel(InMat, xMat, CV_16SC1, 1, 0, 3);
		Sobel(InMat, yMat, CV_16SC1, 0, 1, 3);
		Canny(xMat, yMat, OutMat2, 50, 150);
		convertScaleAbs(OutMat, OutMat);
		imshow("InMat", InMat);
		imshow("OutMat", OutMat);
		imshow("OutMat2", OutMat2);
		waitKey(30);

	}
}