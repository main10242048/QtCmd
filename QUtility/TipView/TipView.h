#ifndef TIPVIEW_H
#define TIPVIEW_H

#include <QDialog>

class TipView : public QDialog
{
    Q_OBJECT
public:
    explicit TipView(long delay=800,QWidget *parent = 0);
public:
    void paintEvent(QPaintEvent *event);
    void setTitle(QString title)
    {m_Title=title;}

    void SetDelayTime(long delay)
    {m_delayMs=delay;}

private:
    QString m_Title;
    QTimer *timer;
    long m_delayMs;
signals:

public slots:
    void TimeOut();

};

#endif // TIPVIEW_H
