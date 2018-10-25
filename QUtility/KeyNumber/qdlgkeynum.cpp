#include "qdlgkeynum.h"
#include "ui_qdlgkeynum.h"
#include <QDesktopWidget>

#include "../myhelper.h"


QDlgKeyNum::QDlgKeyNum(QString title,float oldValue,int dotNum,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QDlgKeyNum)
{
    ui->setupUi(this);
    m_strTitle=title;
    //
    retNumValue = oldValue;
    fOldValue = oldValue;
    Validator=new QDoubleValidator(this);
    Validator->setDecimals(dotNum);
    ui->editValue->setValidator(Validator);

    ui->editValue->setText(QString("%1").arg(oldValue,0,'f',dotNum));
    type=0;
    minValue = 0;
    maxValue = 9999999;
    dot = dotNum;

    init();
}


QDlgKeyNum::QDlgKeyNum(QString title,float oldValue,int dotNum,float min,float max,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QDlgKeyNum)
{
    ui->setupUi(this);
    m_strTitle=title;
    //
    retNumValue = oldValue;
    fOldValue = oldValue;
    Validator=new QDoubleValidator(this);
    Validator->setDecimals(dotNum);
    ui->editValue->setValidator(Validator);

    ui->editValue->setText(QString("%1").arg(oldValue,0,'f',dotNum));

    type=0;
    minValue = min;
    maxValue = max;
    dot = dotNum;

    init();
}

QDlgKeyNum::QDlgKeyNum(QString title,QString oldValue,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QDlgKeyNum)
{
    //数字型选择框:
    ui->setupUi(this);

    m_strTitle=title;
    //
    retStrValue = oldValue;
    fOldValue = oldValue.toFloat();
    ui->editValue->setText(oldValue);

    type=0;
    dot = -1;

    init();
}

void QDlgKeyNum::init()
{
    //setStyleSheet("QWidget{color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 20pt ;}QPushButton{color: rgb(0, 0, 0);border-width: 2px;border-color: rgb(0, 0, 0);border-style: solid;}QLineEdit{border-width: 2px;border-color: rgb(0, 0, 0);border-style: solid;}QToolButton{color: rgb(0, 0, 0);border-width: 2px;border-color: rgb(0, 0, 0);border-style: solid;font: 40pt ;}");
    //setWindowFlags(Qt::FramelessWindowHint);

    //myHelper::FormInCenter(this,0.6,0.7);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

    setWindowOpacity(0.95);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);


    //窗体居中显示
    myHelper::FormInCenter(ui->widget_main,0.6,0.7);
    myHelper::FormInCenter(this,1,1);


    m_EditMaxLength=10;

    ui->lbTitle->setText(m_strTitle);
    ui->editValue->setMaxLength(m_EditMaxLength);
    ui->editValue->selectAll();

    if(dot<=0)
    {
        ui->tBtnDot->setText(tr(""));
        ui->tBtnDot->setEnabled(false);
    }

    ui->tBtnOK->setText(R.strOK);
    ui->tBtnCancel->setText(R.strEsc);
    ui->tBtnClear->setText(R.strClear);
    ui->tBtnBack->setText(R.strBackspace);

    ui->widget_background->installEventFilter(this);

    return;
}

QDlgKeyNum::~QDlgKeyNum()
{
    delete ui;
}

void QDlgKeyNum::on_tBtn0_clicked()
{
    ChangeValue();
}

void QDlgKeyNum::on_tBtn1_clicked()
{
    ChangeValue();
}

void QDlgKeyNum::on_tBtn2_clicked()
{
    ChangeValue();
}

void QDlgKeyNum::on_tBtn3_clicked()
{
    ChangeValue();
}

void QDlgKeyNum::on_tBtn4_clicked()
{
    ChangeValue();
}

void QDlgKeyNum::on_tBtn5_clicked()
{
    ChangeValue();
}

void QDlgKeyNum::on_tBtn6_clicked()
{
    ChangeValue();
}

void QDlgKeyNum::on_tBtn7_clicked()
{
    ChangeValue();
}

void QDlgKeyNum::on_tBtn8_clicked()
{
    ChangeValue();
}

void QDlgKeyNum::on_tBtn9_clicked()
{
    ChangeValue();
}

void QDlgKeyNum::on_tBtnDot_clicked()
{
    ChangeValue();
}

void QDlgKeyNum::ChangeValue()
{
    QToolButton* CurInsertButton=(QToolButton*)sender();
    if(type == 0)
    {
        ui->editValue->insert(CurInsertButton->text());
    }
    else
    {
        ui->editValue->setText(CurInsertButton->text());
    }
}


void QDlgKeyNum::on_tBtnBack_clicked()
{
    ui->editValue->backspace();
}

void QDlgKeyNum::on_tBtnClear_clicked()
{
    ui->editValue->setText("");
}

void QDlgKeyNum::on_tBtnOK_clicked()
{
    if(type==0)
    {
       retNumValue = ui->editValue->text().toFloat();

       if(retNumValue < minValue || retNumValue > maxValue)
       {
           QString str;
           if(dot>=0)
           {
               str = R.strInputbetween+QString(tr("%1-%2").arg(minValue,0,'f',dot).arg(maxValue,0,'f',dot));
           }
           else
           {
               str = R.strInputbetween+QString(tr("%1-%2").arg(minValue).arg(maxValue));
           }

           myHelper::ShowMessageBoxInfo(str);
           {
               if(dot<0)
               {
                   ui->editValue->setText(QString("%1").arg(fOldValue));
               }
               else
               {
                    ui->editValue->setText(QString("%1").arg(fOldValue,0,'f',dot));
               }
           }
           return;
       }
    }
    else
    {
       retNumValue = ui->editValue->text().toFloat();
       retStrValue = ui->editValue->text();
    }
    this->accept();
}

void QDlgKeyNum::on_tBtnCancel_clicked()
{
    this->reject();
}


void QDlgKeyNum::SetInit(QString str0,QString str1,QString str2,QString str3,QString str4,QString str5,QString str6,QString str7,QString str8,QString str9,QString str10,QString str11)
{
    type =1;
    QToolButton* pBtn[12] = {ui->tBtn0,ui->tBtn1,ui->tBtn2,ui->tBtn3,ui->tBtn4,ui->tBtn5,ui->tBtn6,ui->tBtn7,ui->tBtn8,ui->tBtn9,ui->tBtnDot,ui->tBtnBack} ;
    QString str[12]={str0,str1,str2,str3,str4,str5,str6,str7,str8,str9,str10,str11};
    for(int i=0;i<12;i++)
    {
         pBtn[i]->setText(str[i]);

         if(str[i] == "")
         {
              pBtn[i]->setEnabled(false);
         }
    }
}

void QDlgKeyNum::SetEditMaxLength(int len)
{
    m_EditMaxLength=len;
    ui->editValue->setMaxLength(m_EditMaxLength);
    ui->editValue->selectAll();
}


bool QDlgKeyNum::eventFilter(QObject *obj, QEvent *e)
{
    QMouseEvent *me = (QMouseEvent*)e;
    if(e->type()==QEvent::MouseButtonPress &&
       me->button() == Qt::LeftButton)
    {

        if(obj == ui->widget_background)
        {
            this->reject();
        }


    }
    return QDialog::eventFilter(obj,e);
}
