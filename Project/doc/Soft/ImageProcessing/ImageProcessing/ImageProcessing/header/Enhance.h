#ifndef  ENHANCE_H
#define ENHANCE_H

#include <QtGui>
#include <QtWidgets>
#include <QMainWindow>

#include "opencv2/highgui/highgui.hpp"    
#include "opencv2/opencv.hpp"    
#include <opencv2/core/core.hpp> 
#include "opencv2/imgproc.hpp"

#include "header/ImgChange.h"
using namespace cv;

class Enhance			
{
public:
	Enhance();
	~Enhance();

	QImage Normalized(QImage src, int kernel_length);								// ���˲�
	QImage Gaussian(QImage src, int kernel_length);								// ��˹�˲�
	QImage Median(QImage src, int kernel_length);									// ��ֵ�˲�

	QImage Sobel(QImage src, int kernel_length);							// sobel
	QImage Laplacian(QImage src, int kernel_length);						// laplacian
	QImage Canny(QImage src, int kernel_length, int lowThreshold);			// canny
	QImage HoughLine(QImage src, int threshold, double minLineLength, double maxLineGap);			// �߼��
	QImage HoughCircle(QImage src, int minRadius, int maxRadius);		// Բ���

private:
	ImgChange *imgchangeClass;		
};

#endif // ! ENHANCE_H

