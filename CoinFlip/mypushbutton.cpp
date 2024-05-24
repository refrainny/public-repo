
#include "mypushbutton.h"
#include <QDebug>
#include <QPropertyAnimation>
#include <QMouseEvent>
#include <QPushButton>




//MyPushButton::MyPushButton(QWidget *parent)
//    : QPushButton{parent}
//{

//}

MyPushButton::MyPushButton(QString normalImg , QString pressImg )
{
    this->normalImgpath = normalImg;
    this->pressImgpath = pressImg;


    QPixmap pix;
    bool ret = pix.load(normalImg);
    if(!ret)
    {
        qDebug() << "图片加载失败";
        return;
    }
    //设置图片的固定大小
    this->setFixedSize(pix.width(),pix.height());

    //设置图片的不规则样式
    this->setStyleSheet("QPushButton{border:0px;}");

    // 设置图标
    this->setIcon(pix);

    //设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));

}


void MyPushButton::zoom1()
{
    //创建动态对象
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");
    //设置动画时间间隔
    animation->setDuration(200);
    //设置起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置结束位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //执行动画
    animation->start();


}



void MyPushButton::zoom2()
{
    //创建动态对象
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");
    //设置动画时间间隔
    animation->setDuration(200);
    //设置起始位置
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置结束位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //执行动画
    animation->start();
}




void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(this->pressImgpath !="")
    {
        QPixmap pix;
        bool ret = pix.load(this->pressImgpath);
        if(!ret)
        {
            qDebug() << "图片加载失败";
            return;
        }
        //设置图片的固定大小
        this->setFixedSize(pix.width(),pix.height());

        //设置图片的不规则样式
        this->setStyleSheet("QPushButton{border:0px;}");

        // 设置图标
        this->setIcon(pix);

        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    return QPushButton::mousePressEvent(e);


}





void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(this->pressImgpath !="")
    {
        QPixmap pix;
        bool ret = pix.load(this->normalImgpath);
        if(!ret)
        {
            qDebug() << "图片加载失败";
            return;
        }
        //设置图片的固定大小
        this->setFixedSize(pix.width(),pix.height());

        //设置图片的不规则样式
        this->setStyleSheet("QPushButton{border:0px;}");

        // 设置图标
        this->setIcon(pix);

        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    return QPushButton::mouseReleaseEvent(e);

}


























