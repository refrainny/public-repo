
#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <Qsound> //多媒体下的音效头文件

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    //设置主场景固定大小
    setFixedSize(320,588);
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    setWindowTitle("金银币");
    connect(ui->actionqiut,&QAction::triggered,[=](){
        this->close();

    });
//准备开始按钮的音效
    QSound * starSound = new QSound(":/res/TapButtonSound.wav",this);
//    starSound->setLoops(-1);//设置循环，如果里面的是-1代表无限循环
//    starSound->play();

    //设置开始按钮
    MyPushButton *startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.7);

   //选择关卡的场景
    chooseScene =new  ChooseLevelScene;

    //监听选择关卡的返回按钮的信号
    connect(chooseScene,&ChooseLevelScene::chooseSceneBack,this,[=](){
        this->setGeometry(chooseScene->geometry());
        chooseScene->hide();
        this->show();
    });


    connect(startBtn,&QPushButton::clicked,[=](){
        starSound->play();
        //做弹起特效
        startBtn->zoom1();
        startBtn->zoom2();


        //延时进入下一场景
        QTimer::singleShot(100,this,[=](){
            //设置chooseScene场景的位置
            chooseScene->setGeometry(this->geometry());
            //切换界面
            this->hide();
            chooseScene->show();


        });

    });



}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/MenuSceneBg.png");
    //使用画家设置成同屏幕长宽的背景图
    painter.drawPixmap(0,0,this->width(),this->height(),pix);


    //画图标
    pix.load(":/res/Title.png");
    pix =   pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix);




}

MainScene::~MainScene()
{
    delete ui;
}




















































