#ifndef QDLGKEYNUM_H
#define QDLGKEYNUM_H

#include <QDialog>
#include <QDoubleValidator>
namespace Ui {
    class QDlgKeyNum;
}

class QDlgKeyNum : public QDialog
{
    Q_OBJECT

public:
    explicit QDlgKeyNum(QString title,float oldValue,int dotNum,QWidget *parent = 0);
    explicit QDlgKeyNum(QString title,float oldValue,int dotNum,float minValue=0,float maxValue=9999999,QWidget *parent = 0);
    explicit QDlgKeyNum(QString title,QString oldValue,QWidget *parent = 0);
    ~QDlgKeyNum();

    void SetInit(QString str0="",QString str1="",QString str2="",QString str3="",QString str4="",QString str5="",QString str6="",QString str7="",QString str8="",QString str9="",QString str10="",QString str11="");

    void SetEditMaxLength(int len);
public:
    float retNumValue;
    QString retStrValue;
    float fOldValue;
protected:
    bool eventFilter(QObject *obj, QEvent *e);
private:
    Ui::QDlgKeyNum *ui;

    QDoubleValidator  *Validator;
    bool m_bIsExsitPoint;

    int type;//0:input  1:select
    float minValue;
    float maxValue;
    int dot;
    //
    int m_EditMaxLength;
    QString m_strTitle;
private:
    void init();
    void ChangeValue();
private slots:
    void on_tBtnClear_clicked();
    void on_tBtnCancel_clicked();
    void on_tBtnOK_clicked();
    void on_tBtnBack_clicked();
    void on_tBtnDot_clicked();
    void on_tBtn9_clicked();
    void on_tBtn8_clicked();
    void on_tBtn7_clicked();
    void on_tBtn6_clicked();
    void on_tBtn5_clicked();
    void on_tBtn4_clicked();
    void on_tBtn3_clicked();
    void on_tBtn2_clicked();
    void on_tBtn1_clicked();
    void on_tBtn0_clicked();


};

#endif // QDLGKEYNUM_H
