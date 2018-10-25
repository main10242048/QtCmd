#include "WaitView.h"
#include <QPainter>

#include "stdafx.h"

WaitView::WaitView(QWidget *parent) :
        QDialog(parent)
{

    if(parent==NULL)
        return;

    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

    setWindowOpacity(0.95);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);


    //窗体居中显示
    myHelper::FormInCenter(this,1,1);

    timer=new QTimer(this);
    timer->setSingleShot(false);
    timer->setInterval(40);

    m_Title=tr("");

    connect(timer,SIGNAL(timeout()),this,SLOT(DoAnimate()));

    m_bShow=true;
    setActive(m_bShow);
}

WaitView::~WaitView()
{
}

void WaitView::DoAnimate()
{
    m_timedata+=timer->interval();
    m_timedata%=1000;
    QSize size=this->size();

    //QRect AnimateRect(0,0,size.height(),size.height());
    update(AnimateRect);
}

void WaitView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QSize size=this->size();
    //画背景
    painter.fillRect(0,0,size.width(),size.height(),QBrush(QColor(60, 60,60,210)));

    if(!m_Title.isEmpty())
    {
//        //画框
//        painter.setPen(QColor(255,255,255));
//        painter.setBrush(QBrush(QColor(120,120,120,210)));
//        //painter.setBrush(Qt::NoBrush);
//        painter.drawRect(MainRect);

        //显示文字信息
        int nTop=AnimateRect.bottom()+5;
        QRect TextRect(0,nTop,size.width(),50);
        painter.setPen(QColor(0,255,0));
        QFont textfont=painter.font();
        textfont.setBold(true);

        long fontsize=TextRect.height()/2;
        textfont.setPointSize(fontsize);
        painter.setFont(textfont);
        painter.drawText(TextRect,Qt::AlignCenter,m_Title);
    }

    painter.setBrush(Qt::NoBrush);
    //显示等待动画
    paintAnimate(&painter,AnimateRect,m_timedata);

}




void WaitView::paintAnimate(QPainter* painter,QRect PosRect,long time)
{
    if(!m_bShow)
    {
        return;
    }

    painter->save();

    qreal brushp=qreal(m_timedata)/1000;
    painter->setRenderHints(QPainter::Antialiasing);
    painter->translate(PosRect.center());
    painter->rotate(brushp*360);
    painter->translate(-PosRect.center().x(),-PosRect.center().y());


    QConicalGradient colorbrush;
    colorbrush.setCenter(PosRect.center());

    //    colorbrush.setColorAt(0,QColor(255,255,255,10));
    //    colorbrush.setColorAt(0.05,QColor(255,255,255));
    //    colorbrush.setColorAt(0.49,QColor(0,255,0));

    //    colorbrush.setColorAt(0.5,QColor(255,255,255,10));
    //    colorbrush.setColorAt(0.55,QColor(255,255,255));
    //    colorbrush.setColorAt(0.99,QColor(0,255,0));

    colorbrush.setColorAt(1.0,QColor(255,255,255,10));
    //    colorbrush.setColorAt(0.05,QColor(255,255,255));
    //    colorbrush.setColorAt(0.49,QColor(0,255,0));

    //    colorbrush.setColorAt(0.5,QColor(255,255,255,10));
    //    colorbrush.setColorAt(0.55,QColor(255,255,255));
    colorbrush.setColorAt(0,QColor(0,255,0));

    colorbrush.setSpread(QGradient::ReflectSpread);

    painter->setRenderHints(QPainter::Antialiasing);
    QPen pen=painter->pen();
    //pen.setStyle(Qt::DotLine);
    //pen.setCapStyle(Qt::RoundCap);
    pen.setWidth(PosRect.size().width()/12);
    pen.setBrush(colorbrush);
    painter->setPen(pen);

    painter->setBrush(Qt::NoBrush);
    painter->drawEllipse(PosRect.center(),PosRect.size().width()/3,PosRect.size().width()/3);

    painter->restore();


}

void WaitView::setActive(bool actived)
{
    if(parent()==NULL)
    {
        setVisible(false);
        return;
    }

    m_timedata=0;
    m_bShow=actived;
    if(m_bShow)
    {
        //m_Title=tr("加载数据中");

        //        QRect prect(0,0,((QWidget*)parent())->size().width(),((QWidget*)parent())->size().height());
        //        long suitdata=prect.height()/2<prect.width()/7?prect.height()/2:prect.width()/7;
        //        QRect tmprect(0,0,suitdata,suitdata);
        //        tmprect.moveCenter(prect.center());
        //        this->AnimateRect=tmprect;

        QSize scrSize=myHelper::ScreenSize();
        QRect prect(0,0,scrSize.width(),scrSize.height());

        //QRect tmprect(0,0,prect.width()/2,prect.height()/2);
        QRect tmprect(0,0,460,250);
        tmprect.moveCenter(prect.center());

        this->MainRect=tmprect;

        int AnimateHeight=MainRect.height()/2;
        QRect tmprect2(0,0,AnimateHeight,AnimateHeight);
        tmprect.setBottom(tmprect.bottom()-60);
        tmprect2.moveCenter(tmprect.center());
        this->AnimateRect=tmprect2;

        timer->start();
    }
    else
    {
        timer->stop();
    }

    setVisible(actived);
}


void WaitView::setTitle(QString title)
{
    m_Title=title;
    if(m_bShow)
    {
        update();
    }
}
