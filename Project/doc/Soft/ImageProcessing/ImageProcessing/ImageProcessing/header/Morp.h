#ifndef MORP_H
#define MORP_H

#include <QtGui>
#include <QtWidgets>
#include <QMainWindow>

#include "opencv2/highgui/highgui.hpp"    
#include "opencv2/opencv.hpp"    
#include <opencv2/core/core.hpp> 
#include "opencv2/imgproc.hpp"

#include "header/ImgChange.h"
using namespace cv;

class Morp
{
public:
	Morp();
	~Morp();

	QImage Erode(QImage src, int elem,int kernel,int times);		// ��ʴ
	QImage Dilate(QImage src, int elem, int kernel, int times);		// ����
	QImage Open(QImage src, int elem, int kernel, int times);		// ������
	QImage Close(QImage src, int elem, int kernel, int times);		// ������
	QImage Grad(QImage src, int elem, int kernel);					// ��̬ѧ�ݶ�
	QImage Tophat(QImage src, int elem, int kernel);				// ��ñ����
	QImage Blackhat(QImage src, int elem, int kernel);				// ��ñ����

private:
	ImgChange *imgchangeClass;
};

#endif// !MORP_H