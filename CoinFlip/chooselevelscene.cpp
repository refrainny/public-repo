
#include "chooselevelscene.h"
#include <QMenuBar>
#include <QAction>
#include <QPainter>
#include "mypushbutton.h"
#include <QLabel>
#include <QDebug>
#include <QSound>

ChooseLevelScene::ChooseLevelScene(QWidget *parent)
    : QMainWindow{parent}
{
    //设置选择关卡场景
    this->setFixedSize(320,588);
    //设置图标
    this->setWindowIcon(QPixmap(";/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("选择关卡场景");

    //创建菜单烂
    QMenuBar * bar = menuBar();
    setMenuBar(bar);

    //创建开始菜单
    QMenu * startMenu = bar ->addMenu("开始");

    //创建退出菜单项
    QAction * quitAction = startMenu->addAction("退出");

    //点击退出实现退出游戏
    connect(quitAction,&QAction::triggered,[=](){
        this->close();

    });

    //选择关卡按钮音效
    QSound *chooseSound = new QSound(":/res/TapButtonSound.wav",this);
    //返回按钮音效
    QSound *backSound = new QSound(":/res/BackButtonSound.wav",this);

    MyPushButton * backBtn = new MyPushButton(":/res/BackButton.png" , ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width(),this->height()-backBtn->height());
    //点击返回
    connect(backBtn,&MyPushButton::clicked,[=](){
        //播放返回按钮的音效
        backSound->play();
        emit this->chooseSceneBack();
    });

    //创建选择关卡的按钮
    for(int i = 0 ; i<20 ; i++)
    {

        //将按钮放到相应的位置
        MyPushButton * menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25 + i%4 * 70,130 + i/4 * 70);

        //监听每个按钮的点击事件]
        connect(menuBtn,&MyPushButton::clicked,[=](){
            //播放选择关卡音效
            chooseSound->play();
            QString str = QString("anxial").arg(i+1);
            qDebug() << str;


            //进入到Playscene
            this->hide();
            play = new PlayScene(i+1);
            //设置playScene场景的位置
            play->setGeometry(this->geometry());
            play->show();


            connect(play,&PlayScene::chooseSceneBack,[=](){
                this->setGeometry(play->geometry());
                this->show();
                delete play;
                play = NULL;

            });

        });




        //将数字放到按钮上
        QLabel * label = new QLabel;
        label->setParent(menuBtn);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText(QString::number(i+1));
//        设置Label上的文字对齐方式，水平居中和垂直居中
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //设置鼠标穿透Label，可以按下按钮             51号属性
        label->setAttribute(Qt::WA_TransparentForMouseEvents);



    }

}

void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    //利用画家设置背景二
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);


    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width()-pix.width())*0.5,30,pix.width(),pix.height(),pix);






}











