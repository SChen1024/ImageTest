#ifndef IMGCHANGE_H
#define IMGCHANGE_H

#include <QtGui>
#include <QtWidgets>

#include "opencv2/highgui/highgui.hpp"    
#include "opencv2/opencv.hpp"   
#include <opencv2/core/core.hpp>  
using namespace cv;

class QImage;
class ImgChange				// ͼ��ı�
{
public:
	ImgChange();
	~ImgChange();

	QImage cvMat2QImage(const Mat& mat);     // Mat �ĳ� QImage
	Mat QImage2cvMat(QImage image);			// QImage �ĳ� Mat
	
	QImage splitBGR(QImage src, int color);			// ��ȡRGB����
	QImage splitColor(QImage src, String model, int color);		// ��ȡ����

private:
	//int rgb2hsi(Mat &image, Mat &hsi);
	//int rgb2cmyk(Mat &image, Mat &cmyk);
};

#endif // !IMGCHANGE_H

