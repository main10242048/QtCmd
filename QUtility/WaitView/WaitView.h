#ifndef WAITVIEW_H
#define WAITVIEW_H

#include <QDialog>
#include <QTimer>

namespace Ui {
    class WaitView;
}

class WaitView : public QDialog
{
    Q_OBJECT

public:
    explicit WaitView(QWidget *parent = 0);
    ~WaitView();
public:
    void paintEvent(QPaintEvent *event);
    void setActive(bool actived);
    void setTitle(QString title);

private:
    long m_timedata;
    bool m_bShow;
    QString m_Title;
    void paintAnimate(QPainter* painter,QRect PosRect,long time);
    QTimer *timer;

    QRect MainRect;
    QRect AnimateRect;
private slots:
    void DoAnimate();
};

#endif // WAITVIEW_H
