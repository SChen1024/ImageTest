#ifndef CLABEL_H
#define CLABEL_H

#include <QWidget>
#include <QLabel>
#include <mutex>
#include "opencv.hpp"


class CLabel : public QWidget
{
    Q_OBJECT

private:
    std::mutex m_DrawMutex_;
    cv::Mat *m_image_;

public:
    explicit CLabel(QWidget *parent = nullptr);

signals:

public slots:
    void ShowImage(const cv::Mat &img);
};

#endif // CLABEL_H
