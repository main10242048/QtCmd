#include "frmmessagebox.h"
#include "ui_frmmessagebox.h"

#include "../myhelper.h"

frmMessageBox::frmMessageBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmMessageBox)
{
    ui->setupUi(this);

    this->mousePressed = false;
    //设置窗体标题栏隐藏
    //this->setWindowFlags(Qt::FramelessWindowHint);
    //设置窗体关闭时自动释放内存
    this->setAttribute(Qt::WA_DeleteOnClose);
    //设置图形字体
    //IconHelper::Instance()->SetIcon(ui->lab_Ico, QChar(0xf015), 15);
    //IconHelper::Instance()->SetIcon(ui->btnMenu_Close, QChar(0xf00d), 15);
    //ui->btnMenu_Close->setText(tr("X"));
    //关联关闭按钮
    //connect(ui->btnMenu_Close, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(close()));


    if(LAN_ENGLISH == g_language)
    {
        ui->btnOk->setText(tr("OK"));
        ui->btnCancel->setText(tr("CANCEL"));
    }

    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

    setWindowOpacity(0.95);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);


    //窗体居中显示
    myHelper::FormInCenter(ui->widget,QSize(460,250));
    myHelper::FormInCenter(this,1,1);
}

frmMessageBox::~frmMessageBox()
{
    delete ui;
}

void frmMessageBox::SetMessage(const QString &msg, int type)
{
    if(LAN_ENGLISH == g_language)
    {
        if (type == 0) {
            ui->labIcoMain->setStyleSheet("border-image: url(:QUtility/MessageBox/info.png);");
            ui->btnCancel->setVisible(false);
            ui->lab_Title->setText(tr("Prompt"));//提示
        } else if (type == 1) {
            ui->labIcoMain->setStyleSheet("border-image: url(:QUtility/MessageBox/question.png);");
            ui->lab_Title->setText(tr("Question"));//询问
        } else if (type == 2) {
            ui->labIcoMain->setStyleSheet("border-image: url(:QUtility/MessageBox/error.png);");
            ui->btnCancel->setVisible(false);
            ui->lab_Title->setText(tr("Error"));//错误
        }
    }
    else
    {
        if (type == 0) {
            ui->labIcoMain->setStyleSheet("border-image: url(:QUtility/MessageBox/info.png);");
            ui->btnCancel->setVisible(false);
            ui->lab_Title->setText(tr("提示"));//提示
        } else if (type == 1) {
            ui->labIcoMain->setStyleSheet("border-image: url(:QUtility/MessageBox/question.png);");
            ui->lab_Title->setText(tr("询问"));//询问
        } else if (type == 2) {
            ui->labIcoMain->setStyleSheet("border-image: url(:QUtility/MessageBox/error.png);");
            ui->btnCancel->setVisible(false);
            ui->lab_Title->setText(tr("错误"));//错误
        }
    }


    ui->labInfo->setText(msg);
}

void frmMessageBox::on_btnOk_clicked()
{
    done(1);
    this->close();
}
/*
void frmMessageBox::mouseMoveEvent(QMouseEvent *e)
{
    if (mousePressed && (e->buttons() && Qt::LeftButton)) {
        this->move(e->globalPos() - mousePoint);
        e->accept();
    }
}

void frmMessageBox::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        mousePressed = true;
        mousePoint = e->globalPos() - this->pos();
        e->accept();
    }
}

void frmMessageBox::mouseReleaseEvent(QMouseEvent *)
{
    mousePressed = false;
}
*/

void frmMessageBox::paintEvent(QPaintEvent*)
{
//    int ShadowWidth=6;

//    QPainterPath path;
//    path.setFillRule(Qt::WindingFill);
//    path.addRect(ShadowWidth,ShadowWidth, this->width()-ShadowWidth*2, this->height()-ShadowWidth*2);

//    QPainter painter(this);
//    painter.setRenderHint(QPainter::Antialiasing, true);
//    painter.setPen(QColor(16,120,182));
//    painter.drawPath(path);
//    //painter.fillPath(path, QBrush(Qt::white));

//    QColor color(0, 0, 0, 50);
//    for(int i=1; i<ShadowWidth; i++)
//    {
//        QPainterPath path;
//        path.setFillRule(Qt::WindingFill);
//        path.addRect(ShadowWidth-i
//                     , ShadowWidth-i
//                     , this->width()-(ShadowWidth-i)*2
//                     , this->height()-(ShadowWidth-i)*2);
//        color.setAlpha(170  - sqrt(i)*75);
//        painter.setPen(color);
//        painter.drawPath(path);
//    }
}
