#ifndef MYHELPER_H
#define MYHELPER_H

#include <QtCore>
//#include <QtGui>
#include <QDesktopWidget>
#include <QDir>
#include <QStringList>
#include <QDebug>

#include <QDomElement>
#include <QDomDocument>
#include <QDomText>

#include "../stdafx.h"

#include "./MessageBox/frmmessagebox.h"
#include "./Keyboard/keyboard.h"
#include "./Keyboard/bigKeyboard.h"
#include "./KeyNumber/qdlgkeynum.h"
#include "./TipView/TipView.h"

class myHelper: public QObject
{
public:
    //应用程序 不同仪器平台 类型
    //static long g_AppPlatform;
public:
    //    //子程序后缀1
    //    static QString SubAppName1()
    //    {
    //        switch(g_AppPlatform)
    //        {
    //        case APP_PLATFORM_PRTM:
    //            return "*.PRTL_PRT2";
    //        case APP_PLATFORM_PRTN:
    //            return "*.PRTN_RSM";
    //        default:
    //            return "*.PRTN_RSM";
    //        }
    //    }

    //    //子程序后缀2
    //    static QString SubAppName2()
    //    {
    //        switch(g_AppPlatform)
    //        {
    //        case APP_PLATFORM_PRTM:
    //            return "*.PRTL_PIT";
    //        case APP_PLATFORM_PRTN:
    //            return "*.PRTN_PIT";
    //        default:
    //            return "*.PRTN_PIT";
    //        }
    //    }

    //设置为开机启动
    static void AutoRunWithSystem(bool IsAutoRun, QString AppName, QString AppPath)
    {
        QSettings *reg = new QSettings(
                "HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
                QSettings::NativeFormat);

        if (IsAutoRun) {
            reg->setValue(AppName, AppPath);
        } else {
            reg->setValue(AppName, "");
        }
    }

    //设置编码为UTF8
    static void SetUTF8Code()
    {
#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        QTextCodec::setCodecForLocale(codec);
        QTextCodec::setCodecForCStrings(codec);
        QTextCodec::setCodecForTr(codec);
#endif
    }

    //设置皮肤样式
    static void SetStyle(const QString &styleName)
    {
//        QFile file(QString(":/image/%1.css").arg(styleName));
//        file.open(QFile::ReadOnly);
//        QString qss = QLatin1String(file.readAll());
//        qApp->setStyleSheet(qss);
//        qApp->setPalette(QPalette(QColor("#F0F0F0")));
    }

    //放言切换
    static void SetLanguage(QString str)
    {
        QTranslator *translator = new QTranslator(qApp);
        bool ret=translator->load(str);
        qDebug()<<"SetLanguage:"<<str<<ret;
        qApp->installTranslator(translator);
    }

    //判断是否是IP地址
    static bool IsIP(QString IP)
    {
        QRegExp RegExp("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)");
        return RegExp.exactMatch(IP);
    }

//    //显示信息框,仅确定按钮
//    static void ShowMessageBoxInfo(QString info)
//    {
//        frmMessageBox *msg = new frmMessageBox;
//        msg->SetMessage(info, 0);
//        msg->exec();
//    }

//    //显示错误框,仅确定按钮
//    static void ShowMessageBoxError(QString info)
//    {
//        frmMessageBox *msg = new frmMessageBox;
//        msg->SetMessage(info, 2);
//        msg->exec();
//    }

//    //显示询问框,确定和取消按钮
//    static int ShowMessageBoxQuesion(QString info)
//    {
//        frmMessageBox *msg = new frmMessageBox;
//        msg->SetMessage(info, 1);
//        return msg->exec();
//    }

    static bool ShowKeyboard(QString& strReturn,QString strOld,int min=0,int max=65535,bool bChinese=false)
    {
        bigKeyboard dlg(strOld);
        //keyboard dlg(strOld);
        dlg.SetStringRange(min,max);
        dlg.SetChangeMethodEnabled(bChinese);
        if(QDialog::Accepted==dlg.exec())
        {
            strReturn=dlg.GetReturnValue();
            return true;
        }
        return false;
    }

    static bool ShowKeyboard(QString& strReturn,int min=0,int max=65535,bool bChinese=false)
    {
        //bigKeyboard dlg(strReturn);
        keyboard dlg(strReturn);
        dlg.SetStringRange(min,max);
        dlg.SetChangeMethodEnabled(bChinese);
        if(QDialog::Accepted==dlg.exec())
        {
            strReturn=dlg.GetReturnValue();
            return true;
        }

        return false;
    }

//    static bool ShowKeyNum(QString strTitle,float& fReturn,float min=0,float max=65535,int dot=6)
//    {
//        QDlgKeyNum dlg(strTitle,fReturn,dot,min,max);
//        if(QDialog::Accepted == dlg.exec())
//        {
//            fReturn=dlg.retNumValue;
//            return true;
//        }

//        return false;
//    }

//    static bool ShowKeyNum(QString strTitle,double& fReturn,double min=0,double max=65535,int dot=6)
//    {
//        QDlgKeyNum dlg(strTitle,fReturn,dot,min,max);
//        if(QDialog::Accepted == dlg.exec())
//        {
//            fReturn=dlg.retNumValue;
//            return true;
//        }

//        return false;
//    }

//    static bool ShowKeyNum(QString strTitle,long& nReturn,long min=0,long max=65535)
//    {
//        QDlgKeyNum dlg(strTitle,nReturn,0,min,max);
//        if(QDialog::Accepted == dlg.exec())
//        {
//            nReturn=dlg.retNumValue;
//            return true;
//        }

//        return false;
//    }

//    static bool ShowKeyNum(QString strTitle,int& nReturn,int min=0,int max=65535)
//    {
//        QDlgKeyNum dlg(strTitle,nReturn,0,min,max);
//        if(QDialog::Accepted == dlg.exec())
//        {
//            nReturn=dlg.retNumValue;
//            return true;
//        }

//        return false;
//    }

//    static void ShowTipView(QString strTitle,long delay=800)
//    {
//        TipView dlg(delay);
//        dlg.setTitle(strTitle);
//        dlg.exec();
//    }

    //延时
    static void Sleep(int sec)
    {
        QTime dieTime = QTime::currentTime().addMSecs(sec);
        while ( QTime::currentTime() < dieTime ) {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
    }

    //窗体居中显示
    static void FormInCenter(QWidget *frm)
    {
        int frmX = frm->width();
        int frmY = frm->height();
        //QDesktopWidget w;
        QSize w=ScreenSize();
        int deskWidth = w.width();
        int deskHeight = w.height();
        QPoint movePoint(deskWidth / 2 - frmX / 2, deskHeight / 2 - frmY / 2);
        frm->move(movePoint);
    }

    //窗体居中显示
        static void FormInCenter(QWidget *frm,QSize size)
        {
            int frmX = size.width();
            int frmY = size.height();
            //QDesktopWidget w;
            QSize w=ScreenSize();
            int deskWidth = w.width();
            int deskHeight = w.height();
            QPoint movePoint(deskWidth / 2 - frmX / 2, deskHeight / 2 - frmY / 2);
            frm->move(movePoint);
        }

    //窗体居中显示
    static void FormInCenter(QWidget *frm,float scaleW,float scaleH)
    {
        QSize w=ScreenSize();
        QRect rect;
        rect.setSize(QSize(w.width()*scaleW,w.height()*scaleH));
        rect.moveCenter(QRect(0,0,w.width(),w.height()).center());
        frm->setGeometry(rect);
    }

    // X.X.XMMDD
    static QString GetSoftName(QString path,QString strFilter)
    {
        QDir dir(".");
        QStringList FileNames;
        QStringList Filters;
        Filters<<strFilter;
        dir.setPath(path);
        FileNames = dir.entryList(Filters,QDir::Files,QDir::Name);

        if(FileNames.count()<=0)
        {
            return "";
        }

        //        for(int i=FileNames.count()-1;i>=0;i--)
        //        {
        //            QString str=FileNames.at(i);
        //            str=str.left(str.length()-strFilter.length()+1);
        //            long ver=str.toLong();

        //            if(ver<=1000000)
        //            {
        //                FileNames.removeLast();
        //            }
        //        }

        return FileNames.last();
    }

    // X.X.XMMDD
    static void DeleteFiles(QString path,QString strFilter)
    {
        QDir dir(".");
        QStringList FileNames;
        QStringList Filters;
        Filters<<strFilter;
        dir.setPath(path);
        FileNames = dir.entryList(Filters,QDir::Files,QDir::Name);

        for(int i=0;i<FileNames.count();i++)
        {
            QString fileName=path+"/"+FileNames.at(i);
            dir.remove(fileName);
        }
    }

    //Application File Path
    static QString GetAppFilePath()
    {
#ifdef Q_OS_LINUX
        return "/opt";
#else
        return qApp->applicationDirPath();
#endif
    }

    static QSize ScreenSize()
    {
    #ifdef Q_OS_LINUX
        return QApplication::desktop()->size();
    #else
        //return QApplication::desktop()->size();
        return QSize(800,600);
    #endif
    }

    static QString StringFromUnicode(char* buffer,int len)
    {
        len=GetUnicodeLen(buffer,len);

        int uLen=len/2;
        ushort *uBuffer=new ushort[uLen];
        memcpy(uBuffer,buffer,len);
        QString str=QString::fromUtf16(uBuffer,uLen);

        delete []uBuffer;
        return str;
    }

    static void UnicodeFromString(QString &str,unsigned char* buffer,int len)
    {
        memset(buffer,0,len);
        int uLen=qMin(len,2*str.length());
        const ushort* uBuffer=str.utf16();
        memcpy(buffer,uBuffer,uLen);
    }

    static int GetUnicodeLen(char* buffer,int len)
    {
        for(int i=0;i<len-1;i=i+2)
        {
            if(0==buffer[i] &&
               0==buffer[i+1])
            {
                return i;
            }
        }

        return len;
    }


    static void GetTextElement(QDomElement& root,QString strTagName,QString& value)
    {
        QDomNodeList nodeList=root.elementsByTagName(strTagName);
        if(nodeList.count()<=0)
        {
            return ;
        }

        value=nodeList.at(0).toElement().text();
        //qDebug()<<strTagName<<value;
    }
    static void GetTextElement(QDomElement& root,QString strTagName,float& value)
    {
        QDomNodeList nodeList=root.elementsByTagName(strTagName);
        if(nodeList.count()<=0)
        {
            return ;
        }

        QString strValue=nodeList.at(0).toElement().text();
        //qDebug()<<strTagName<<strValue;
        if(strValue.isEmpty())
        {
            return ;
        }
        else
        {
            value=strValue.toFloat();
        }
    }
    static void GetTextElement(QDomElement& root,QString strTagName,int& value)
    {
        QDomNodeList nodeList=root.elementsByTagName(strTagName);
        if(nodeList.count()<=0)
        {
            //qDebug()<<"no tag "<<strTagName;
            return ;
        }

        QString strValue=nodeList.at(0).toElement().text();
        //qDebug()<<strTagName<<strValue;
        if(strValue.isEmpty())
        {
            return ;
        }
        else
        {
            value=strValue.toInt();
        }
    }

    static void GetTextElement(QDomElement& root,QString strTagName,long& value)
    {
        QDomNodeList nodeList=root.elementsByTagName(strTagName);
        if(nodeList.count()<=0)
        {
            //qDebug()<<"no tag "<<strTagName;
            return ;
        }

        QString strValue=nodeList.at(0).toElement().text();
        //qDebug()<<strTagName<<strValue;
        if(strValue.isEmpty())
        {
            return ;
        }
        else
        {
            value=strValue.toLong();
        }
    }

    static void GetTextElement(QDomElement& root,QString strTagName,bool& value)
    {
        QDomNodeList nodeList=root.elementsByTagName(strTagName);
        if(nodeList.count()<=0)
        {
            //qDebug()<<"no tag "<<strTagName;
            return ;
        }

        QString strValue=nodeList.at(0).toElement().text();
        //qDebug()<<strTagName<<strValue;
        if(strValue.isEmpty())
        {
            return ;
        }
        else if("true"==strValue)
        {
            value=true;
            return ;
        }
        else
        {
            value=false;
        }
    }

    static void SetTextElement(QDomDocument &doc,QDomElement& root
                                ,const QString& strTagName,const QString &strValue)
    {
        QDomElement element=doc.createElement(strTagName);
        QDomText valueElement=doc.createTextNode(strValue);
        element.appendChild(valueElement);

        root.appendChild(element);
    }

    static void SetTextElement(QDomDocument &doc,QDomElement& root
                                ,const QString& strTagName,bool bValue)
    {
        QDomElement element=doc.createElement(strTagName);
        QString strValue=bValue?"true":"false";
        QDomText valueElement=doc.createTextNode(strValue);
        element.appendChild(valueElement);

        root.appendChild(element);
    }
};



#endif // MYHELPER_H
