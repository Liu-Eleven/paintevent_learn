#include "widget.h"
#include <QPainter>
#include <QStringList>
#include <QPainterPath>
#include <QPaintEvent>
#include <QFont>
#include <QPen>
#include <QTimer>
#include <QTime>
#include <QPainter>
#include <QString>
#include <QMouseEvent>
#include <QToolTip>
#include <QDebug>
#include <QPushButton>

#define RECT_WIDTH 120
#define RECT_HEIGHT 30

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(400 ,300);

    QPushButton *btn = new QPushButton(this);
    btn->setGeometry(280 , 270 , 120 , 30);
    btn->setText("刷新");
    connect(btn , SIGNAL(clicked(bool)) , this  , SLOT(update()));
}

Widget::~Widget()
{

}
void Widget::paintEvent( QPaintEvent* ev )
{
    static int angle = 0 ;
    QPainter painter(this);
    // 去除画笔
    painter.setPen(Qt::NoPen);
    // 设置反锯齿
    painter.setRenderHint(QPainter::Antialiasing);

#if 1
    QStringList strList;
    strList<<"L"<<"S"<<"Y";

    painter.setPen(Qt::darkGreen);
    painter.setPen(Qt::DashLine);
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(10, 10, RECT_WIDTH, RECT_HEIGHT);

    QPainterPath path1 , path2 ,path3;

    QFont font;
    font.setBold(true);
    font.setPixelSize(30);
    QRect rect2(0 , 0 , 10 , 10);
    QRect fontBoundingRect = QFontMetrics(font).boundingRect(strList[0]);

    //path1.addRect(rect2);
    path1.addText(-QPointF(fontBoundingRect.center()), font, strList[0]);

    fontBoundingRect = QFontMetrics(font).boundingRect(strList[1]);
    path2.addText(-QPointF(fontBoundingRect.center()), font, strList[1]);
    //path2.addRect(rect2);
    fontBoundingRect = QFontMetrics(font).boundingRect(strList[2]);
    path3.addText(-QPointF(fontBoundingRect.center()), font, strList[2]);
   // path3.addRect(rect2);

    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    int i_rand ;

    painter.translate(10 , 10);
    QPen pen;
    pen.setBrush(QColor(255,0,0));
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawPoint(0 , 0);

//1
    painter.save();
    painter.translate(RECT_WIDTH/2 - (2 *10), RECT_HEIGHT/2);
    i_rand = qrand() % 60;
    //画出原点位置
    painter.drawPoint(0 , 0);

    path1.translate(-path1.boundingRect().center().x() , -path1.boundingRect().center().y());
    if (qrand() % 2)
        painter.rotate(i_rand);
    else
        painter.rotate(-i_rand);

    painter.fillPath(path1, QBrush(QColor(27,88,222)));
   // painter.drawPath(path1);

    painter.restore();

//2
    painter.save();
    painter.translate(RECT_WIDTH/2 - (2 *10)+20, RECT_HEIGHT/2);
    //画出原点位置
    painter.drawPoint(0 , 0);

    time = QTime::currentTime();
    qsrand((uint)time.msec());
    i_rand = qrand() % 360;
    //painter.translate(-path2.boundingRect().center().x() , -path2.boundingRect().center().y());
    if (qrand() % 2)
        painter.rotate(i_rand);
    else
        painter.rotate(-i_rand);

    painter.fillPath(path2, QBrush(QColor(27,88,222)));
    //painter.drawPath(path2);
    painter.restore();

//3
    painter.save();
    painter.translate(RECT_WIDTH/2 - (2 *10)+40, RECT_HEIGHT/2);
    //画出原点位置
    painter.drawPoint(0 , 0);


    time = QTime::currentTime();
    qsrand((uint)time.msec());
    i_rand = qrand() % 60;

    painter.translate(-path3.boundingRect().center().x() , -path3.boundingRect().center().y());
    if (qrand() % 2)
        painter.rotate(i_rand);
    else
        painter.rotate(-i_rand);

    painter.fillPath(path3, QBrush(QColor(27,88,222)));
   // painter.drawPath(path3);

    painter.restore();

#endif

#if 0
    QPen pen;
    pen.setBrush(QColor(255,0,0));
    pen.setWidth(2);
    painter.setPen(pen);
    painter.translate(100 , 100);
    painter.drawEllipse(-50 , -50 , 100 , 100);
    //painter.translate(0 , 0);
    painter.rotate(angle);
    angle+=1;
    qDebug()<<angle;
    painter.drawLine(-53 , 0 , 50 , 0 );
#endif

    QWidget::paintEvent(ev);
}
