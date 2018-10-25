#include "QtCmdDlg.h"
#include "ui_QtCmdDlg.h"

#include "./QUtility/myhelper.h"

QtCmdDlg::QtCmdDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QtCmdDlg)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    QRect rect;
    rect.setRect(0
                 ,0
                 ,myHelper::ScreenSize().width()
                 ,myHelper::ScreenSize().height());

    setGeometry(rect);

    connect(&ps,SIGNAL(readyReadStandardOutput()),this,SLOT(ReadProcessStandardOutput()));

    connect(&ps,SIGNAL(readyReadStandardError()),this,SLOT(ReadProcessStandardOutput()));

}

QtCmdDlg::~QtCmdDlg()
{
    delete ui;
}

void QtCmdDlg::ReadProcessStandardOutput()
{
    QString ret = ps.readAllStandardOutput();

    QStringList strList=ret.split("\n");
    m_logList<<strList<<"";

    UpdateLogList();
}

void QtCmdDlg::UpdateLogList()
{
    //QStringListModel *model = new QStringListModel(m_logList);
    LogModel.setStringList(m_logList);
    ui->Log_listView->setModel(&LogModel);
}

void QtCmdDlg::on_CmdBtn_clicked()
{
    //QString strCmd;
    if(myHelper::ShowKeyboard(strCmd) )
    {
        m_logList<<"CMD:"+strCmd;
        UpdateLogList();

        on_DoBtn_clicked();
    }
}

void QtCmdDlg::on_DoBtn_clicked()
{
    if(strCmd.isEmpty())
    {
        m_logList<<"Error:cmd is empty";
        UpdateLogList();
        return ;
    }

    //m_logList<<"123"<<"234";
    //UpdateLogList();

    m_logList<<"DO:"+strCmd;
    UpdateLogList();


    //ps.start(strCmd);

    QStringList args;
    args<<"-c";
    args<<strCmd;
    ps.start("sh",args);
}

void QtCmdDlg::on_ClearBtn_clicked()
{
    m_logList.clear();

    UpdateLogList();
}

void QtCmdDlg::on_SyncBtn_clicked()
{
    QStringList args;
    args<<"-c";
    args<<"sync";
    ps.start("sh",args);
}

void QtCmdDlg::on_pushButton_clicked()
{
    strCmd="cp /sbin/udhcpc_bak /sbin/udhcpc -rf";
    on_DoBtn_clicked();
}

void QtCmdDlg::on_pushButton_2_clicked()
{
    strCmd="cp /media/sda1/interfaces /etc/network/interfaces -rf";
    on_DoBtn_clicked();
}

void QtCmdDlg::on_pushButton_3_clicked()
{

//    if(strCmd.isEmpty())
//    {
//        m_logList<<"Error:cmd is empty";
//        UpdateLogList();
//        return ;
//    }

//    m_logList<<"DO:"+strCmd;
//    UpdateLogList();

    strCmd="/opt/PDAL -qws";

    ps.start(strCmd);
}
