#include <QtGui/QApplication>
#include "QtCmdDlg.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtCmdDlg w;
    w.show();

    return a.exec();
}
