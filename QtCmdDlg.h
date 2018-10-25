#ifndef QTCMDDLG_H
#define QTCMDDLG_H

#include <QDialog>

#include <QStringListModel>
#include <QProcess>

namespace Ui {
    class QtCmdDlg;
}

class QtCmdDlg : public QDialog
{
    Q_OBJECT

public:
    explicit QtCmdDlg(QWidget *parent = 0);
    ~QtCmdDlg();

private:
    Ui::QtCmdDlg *ui;

    QProcess ps;

    QStringList m_logList;

    QStringListModel LogModel;
    QString strCmd;

    void UpdateLogList();
private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_SyncBtn_clicked();
    void on_ClearBtn_clicked();
    void on_DoBtn_clicked();
    void on_CmdBtn_clicked();

    void ReadProcessStandardOutput();
};

#endif // QTCMDDLG_H
