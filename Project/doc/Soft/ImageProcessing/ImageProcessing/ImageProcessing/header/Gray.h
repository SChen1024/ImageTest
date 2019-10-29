#ifndef GRAY_H
#define GRAY_H

#include <QtGui>
#include <QtWidgets>
#include <QMainWindow>

#include "opencv2/highgui/highgui.hpp"    
#include "opencv2/opencv.hpp"    
#include <opencv2/core/core.hpp> 
#include "opencv2/imgproc.hpp"

#include "header/ImgChange.h"
using namespace cv;

class Gray
{
public:
	Gray();
	~Gray();

	QImage Bin(QImage src, int threshold);
	QImage Graylevel(QImage src);
	QImage Reverse(QImage src);								// ͼ��ת
	QImage Linear(QImage src, int alpha, int beta);			// ���Ա任
	QImage Gamma(QImage src, int gamma);					// ٤��任(ָ���任)
	QImage Log(QImage src, int c);							// �����任
	QImage Histeq(QImage src);								// ֱ��ͼ���⻯
		
private:
	ImgChange *imgchangeClass;
};	

#endif// !GRAY_H