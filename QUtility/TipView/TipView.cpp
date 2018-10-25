#include "TipView.h"
#include <QPainter>

TipView::TipView(long delay,QWidget *parent) :
    QDialog(parent)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

    setWindowOpacity(0.95);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);


    //窗体居中显示
    myHelper::FormInCenter(this,0.5,0.1);

    m_delayMs=delay;

    timer=new QTimer(this);
    timer->setSingleShot(false);
    timer->setInterval(m_delayMs);

    m_Title="TipView";

    connect(timer,SIGNAL(timeout()),this,SLOT(TimeOut()));

    timer->start();
}

void TipView::TimeOut()
{
    //qDebug()<<"TipView TimeOut";
    QDialog::accept();
}

void TipView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QSize size=this->size();
    //画背景
    painter.fillRect(0,0,size.width(),size.height(),QBrush(QColor(60, 60,60,210)));

    if(!m_Title.isEmpty())
    {
        //显示文字信息
        int nTop=0;
        QRect TextRect(0,nTop,size.width(),size.height());
        //painter.setPen(QColor(255,255,255));
        painter.setPen(QColor(0,255,0));
        QFont textfont=painter.font();
        textfont.setBold(true);

        long fontsize=26;
        textfont.setPointSize(fontsize);
        painter.setFont(textfont);
        painter.drawText(TextRect,Qt::AlignCenter,m_Title);
    }

    painter.setBrush(Qt::NoBrush);
}
