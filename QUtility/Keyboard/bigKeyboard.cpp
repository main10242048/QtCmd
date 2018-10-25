#include <qdebug.h>
#include <QRect>
#include "bigKeyboard.h"
#include "ui_bigKeyboard.h"
#include <QApplication>
#include <QDesktopWidget>

#include "../myhelper.h"

bigKeyboard::bigKeyboard(QString str,QWidget *parent) :
        //QDialog(parent,Qt::Tool|Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint),
        QDialog(parent),
        ui(new Ui::bigKeyboard)
{
    ui->setupUi(this);

    btnKeys = new QButtonGroup;
    SetbigKeyboard();
    QObject::connect(btnKeys,SIGNAL(buttonClicked (int)),this,SLOT(keyPressed(int)));

    btnBar = new QButtonGroup;
    SetKeyBar();
    QObject::connect(btnBar,SIGNAL(buttonClicked (int)),this,SLOT(barPressed(int)));

    method = english;
    moveAble = false;

    //这个属性保存的是窗口部件跟踪鼠标是否生效
    //    this->setMouseTracking(true);

    CapLockFlag = false;
    ShiftFlag = false;
    setKeyValue();
    firstFlag = ' ';


    UpdateBar();
    //changeSize();

    ui->valueEdit->setText(str);
    ui->valueEdit->selectAll();
    this->m_nMinLength=0;
    this->m_nMaxLength=65535;

    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    QRect rect;
    rect.setRect(0
                 ,0//myHelper::ScreenSize().height()/2
                 ,myHelper::ScreenSize().width()
                 ,myHelper::ScreenSize().height());

    setGeometry(rect);

    ui->Key_Close->setText(R.strClose);

    ui->Key_Comma->setVisible(false);
    ui->Key_Colon->setVisible(false);

    ui->listDown->setEnabled (false);
    ui->listUp->setEnabled (false);

    ui->key_Space->setEnabled (false);
}

bigKeyboard::~bigKeyboard()
{
    delete btnKeys;
    delete btnBar;
    delete ui;
}

QString bigKeyboard::GetReturnValue()
{
    return ui->valueEdit->text().trimmed();
}

void bigKeyboard::SetStringRange(int min,int max)
{
    this->m_nMinLength=min;
    this->m_nMaxLength=max;
}

void bigKeyboard::SetChangeMethodEnabled(bool enabled)
{
    ui->key_LangueChange->setEnabled(enabled);
}

/*
#if 0
void bigKeyboard::mousePressEvent (QMouseEvent *event)
{

    if (event->button() != Qt::LeftButton) return;
    moveAble = true;
    widget_pos = pos();
    mouse_pos = event->globalPos();

}
void bigKeyboard::mouseReleaseEvent(QMouseEvent *event)
{

    if (event->button() != Qt::LeftButton) return;
    moveAble = false;

}
void bigKeyboard::mouseMoveEvent ( QMouseEvent * event )
{


    if (moveAble)
    {
        QPoint pos = event->globalPos();
        int x = pos.x() - mouse_pos.x();
        int y = pos.y() - mouse_pos.y();
        QWidget::move(widget_pos.x() + x,widget_pos.y() + y);
    }

}
#else
void bigKeyboard::mousePressEvent(QMouseEvent * event)
{
    if (event->button() == Qt::LeftButton)
    {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        moveAble = true;
        event->accept();
    }
}

void bigKeyboard::mouseMoveEvent(QMouseEvent * event)
{
    if ((event->buttons() & Qt::LeftButton) && moveAble)
    {
        move(event->globalPos() - dragPosition);
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void bigKeyboard::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button()!=Qt::LeftButton) return;
    moveAble = false;

}
#endif
*/

void bigKeyboard::SetKeyBar()
{
    btnBar->addButton (ui->font_1,Qt::Key_0);
    btnBar->addButton (ui->font_2,Qt::Key_1);
    btnBar->addButton (ui->font_3,Qt::Key_2);
    btnBar->addButton (ui->font_4,Qt::Key_3);
    btnBar->addButton (ui->font_5,Qt::Key_4);
    btnBar->addButton (ui->font_6,Qt::Key_5);
    btnBar->addButton (ui->font_7,Qt::Key_6);
    btnBar->addButton (ui->font_8,Qt::Key_7);
    btnBar->addButton (ui->font_9,Qt::Key_8);
    btnBar->addButton (ui->font_10,Qt::Key_9);
    btnBar->addButton (ui->listUp,Qt::Key_Up);
    btnBar->addButton (ui->listDown,Qt::Key_Down);
}

void bigKeyboard::SetbigKeyboard()
{
    btnKeys->addButton(ui->key_0,Qt::Key_0);
    btnKeys->addButton(ui->key_1,Qt::Key_1);
    btnKeys->addButton(ui->key_2,Qt::Key_2);
    btnKeys->addButton(ui->key_3,Qt::Key_3);
    btnKeys->addButton(ui->key_4,Qt::Key_4);
    btnKeys->addButton(ui->key_5,Qt::Key_5);
    btnKeys->addButton(ui->key_6,Qt::Key_6);
    btnKeys->addButton(ui->key_7,Qt::Key_7);
    btnKeys->addButton(ui->key_8,Qt::Key_8);
    btnKeys->addButton(ui->key_9,Qt::Key_9);

    btnKeys->addButton(ui->key_A,Qt::Key_A);
    btnKeys->addButton(ui->key_B,Qt::Key_B);
    btnKeys->addButton(ui->key_C,Qt::Key_C);
    btnKeys->addButton(ui->key_D,Qt::Key_D);
    btnKeys->addButton(ui->key_E,Qt::Key_E);
    btnKeys->addButton(ui->key_F,Qt::Key_F);
    btnKeys->addButton(ui->key_G,Qt::Key_G);
    btnKeys->addButton(ui->key_H,Qt::Key_H);
    btnKeys->addButton(ui->key_I,Qt::Key_I);
    btnKeys->addButton(ui->key_J,Qt::Key_J);
    btnKeys->addButton(ui->key_K,Qt::Key_K);
    btnKeys->addButton(ui->key_L,Qt::Key_L);
    btnKeys->addButton(ui->key_M,Qt::Key_M);
    btnKeys->addButton(ui->key_N,Qt::Key_N);
    btnKeys->addButton(ui->key_O,Qt::Key_O);
    btnKeys->addButton(ui->key_P,Qt::Key_P);
    btnKeys->addButton(ui->key_Q,Qt::Key_Q);
    btnKeys->addButton(ui->key_R,Qt::Key_R);
    btnKeys->addButton(ui->key_S,Qt::Key_S);
    btnKeys->addButton(ui->key_T,Qt::Key_T);
    btnKeys->addButton(ui->key_U,Qt::Key_U);
    btnKeys->addButton(ui->key_V,Qt::Key_V);
    btnKeys->addButton(ui->key_W,Qt::Key_W);
    btnKeys->addButton(ui->key_X,Qt::Key_X);
    btnKeys->addButton(ui->key_Y,Qt::Key_Y);
    btnKeys->addButton(ui->key_Z,Qt::Key_Z);

    btnKeys->addButton(ui->Key_Comma, Qt::Key_Comma); //,
    //btnKeys->addButton(ui->Key_Period, Qt::Key_Period);  //.
    //btnKeys->addButton(ui->Key_Slash, Qt::Key_Slash);
    //btnKeys->addButton(ui->Key_rslash,Qt::Key_Romaji);
    btnKeys->addButton(ui->Key_Colon, Qt::Key_Colon);  //:

    btnKeys->addButton(ui->key_Space,Qt::Key_Space);
    btnKeys->addButton(ui->key_Enter,Qt::Key_Enter);
    btnKeys->addButton(ui->key_Backspace,Qt::Key_Backspace);
    //btnKeys->addButton(ui->key_Escape,Qt::Key_Escape);
    btnKeys->addButton(ui->key_Cap_Lock,Qt::Key_CapsLock);
    btnKeys->addButton(ui->key_LangueChange,Qt::Key_Control);

    //btnKeys->addButton (ui->Key_left,Qt::Key_Left);
    //btnKeys->addButton (ui->Key_right,Qt::Key_Right);
    //btnKeys->addButton (ui->Key_up,Qt::Key_Up);
    //btnKeys->addButton (ui->Key_down,Qt::Key_Down);
    btnKeys->addButton (ui->key_minus,Qt::Key_Minus); //-
    //btnKeys->addButton (ui->key_equal,Qt::Key_Equal); //=
    //btnKeys->addButton (ui->key_braceleft,Qt::Key_BraceLeft); //{
    //btnKeys->addButton (ui->key_braceright,Qt::Key_BraceRight); //}
    //btnKeys->addButton (ui->Key_quotation,Qt::Key_QuoteDbl); //'
    //btnKeys->addButton (ui->Key_xx,Qt::Key_acute);  //`
    btnKeys->addButton (ui->Key_Close,Qt::Key_Close);
    btnKeys->addButton (ui->key_Shift,Qt::Key_Shift);
}

void bigKeyboard::barPressed(int id )
{
    QString str;
    QWidget * widget;

    switch(id)
    {
    case Qt::Key_0 :  str = ui->font_1->text (); break;
    case Qt::Key_1 :  str = ui->font_2->text (); break;
    case Qt::Key_2 :  str = ui->font_3->text (); break;
    case Qt::Key_3 :  str = ui->font_4->text (); break;
    case Qt::Key_4 :  str = ui->font_5->text (); break;
    case Qt::Key_5 :  str = ui->font_6->text (); break;
    case Qt::Key_6 :  str = ui->font_7->text (); break;
    case Qt::Key_7 :  str = ui->font_8->text (); break;
    case Qt::Key_8 :  str = ui->font_9->text (); break;
    case Qt::Key_9 :  str = ui->font_10->text (); break;
    case Qt::Key_Up:
        if(currentPage)
        {
            currentPage --;
            showPage(currentPage);
        }
        return;
    case Qt::Key_Down:
        if((currentPage + 1) < pageCount)
        {
            currentPage ++;
            showPage(currentPage);
        }
        return;
    }

// 外部焦点文本框 更新输入文本
//    widget = QApplication::focusWidget();

//    QLineEdit *qle = qobject_cast<QLineEdit*>( widget);
//    if(qle == 0)
//    {
//        QTextEdit *qte = qobject_cast<QTextEdit*>( widget);
//        if(qte == 0)
//        {
//            QPlainTextEdit * qpte = qobject_cast<QPlainTextEdit*>( widget);
//            if(qpte == 0)
//            {
//                QTextBrowser *qtb = qobject_cast<QTextBrowser*>( widget);
//                if(qtb != 0) qtb->insertPlainText (str);
//            }
//            else qpte->insertPlainText (str);
//        }
//        else   qte->insertPlainText (str);
//    }
//    else qle->insert (str);

    UpdateInputMessage(str);

    clearBar();
}

void bigKeyboard::UpdateInputMessage(QString str)
{
    if(str.isEmpty())
    {
        return ;
    }

    QString strTitle=ui->valueEdit->text();
    //ui->valueEdit->setText(strTitle+str);
    ui->valueEdit->insert(str);

    emit SendInputMessage(str);
}

void bigKeyboard::UpdateInputMessage(char c)
{
    UpdateInputMessage(QString(c));
}


void bigKeyboard::keyPressed(int id )
{
    QKeyEvent *key;
    char c=0;
    char nustr[] = {')','!','@','#','$','[','^','-',']','('};
    
    switch (id)
    {
    case Qt::Key_0...Qt::Key_9:
        c = id - Qt::Key_0;
        if(ShiftFlag) c = *(nustr + c);//大写
        else c += '0';
        if( (ShiftFlag) || ((method == wuhua) && (c > '5')) || ((!ShiftFlag) && (method != wuhua)) )
        {
            UpdateInputMessage(c);
        }
        else //五笔划输入法编码
        {
            QString ch;
            ch.clear ();
            ch.append (c);
            transPy(ch);
        }
        break;

    case Qt::Key_A...Qt::Key_Z:
        c = 'a' + id - Qt::Key_A;
        if( CapLockFlag || ((!CapLockFlag) && (ShiftFlag)))  //Cap Locked
        {
            if(ShiftFlag ^ CapLockFlag) c -= 0x20;
            UpdateInputMessage(c);
        }
        else
        {
            if((method == english) || (method == wuhua) || (CapLockFlag)
                || ((method == wubi) && (c == 'z')))  //英文、笔划输入法或大写或五笔输入法按键为z
                {
                UpdateInputMessage(c);
            }
            else  //拼音、五笔输入法编码
            {
                QString ch;
                ch.clear ();
                ch.append (c);
                transPy(ch);
            }
        }
        break;

    case Qt::Key_Space :  //空格
        if(ui->font_1->isVisible() &&
           ui->font_1->isEnabled())  //有可选汉字输入
        {
            barPressed(Qt::Key_0);
        }
        else
        {
            UpdateInputMessage(' ');
        }
        break;

    case Qt::Key_Backspace :
        if((method == english) || ((method != english) && (ui->lineEdit->text ().isEmpty ())))
        {
            //key = new QKeyEvent(QEvent::KeyPress, Qt::Key_Backspace, Qt::NoModifier);
            //QCoreApplication::postEvent(QApplication::focusWidget(), key);
//            QString str=ui->valueEdit->text();
//            if(!str.isEmpty())
//            {
//                ui->valueEdit->setText(str.left(str.length()-1));
//            }

            ui->valueEdit->backspace();
        }
        else   //编码输入处理
        {
            QByteArray text;
            int len;
            text = ui->lineEdit->text ().toAscii ();
            len = strlen(text);
            if(len)
            {
                text[len - 1] = 0;
                if(len == 1) {
                    ui->lineEdit->clear();
                    clearBar  ();
                }
                else {
                    ui->lineEdit->setText (text);
                    transPy("");
                }
            }
        }
        break;

    case Qt::Key_Enter :
        {
            //        if((method == english) || ((method != english) && (ui->lineEdit->text ().isEmpty ())))
            //        {
            //            key = new QKeyEvent(QEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier);
            //            QCoreApplication::postEvent(QApplication::focusWidget(), key);
            //        }
            //        else  //中文输入编码作为字符串输入并清除
            //        {
            //            clearBar ();
            //        }
            int len=this->GetReturnValue().length();
            if(len>=this->m_nMinLength &&
               len<=this->m_nMaxLength)
            {
                accept();
            }
            else
            {
                QString str = R.strInputStringLen+QString(tr("%1-%2").arg(m_nMinLength).arg(m_nMaxLength));
                //myHelper::ShowMessageBoxInfo(str);
                return ;
            }
            break;
        }
    case Qt::Key_Escape :
        //key = new QKeyEvent(QEvent::KeyPress, Qt::Key_Escape, Qt::NoModifier);
        //QCoreApplication::postEvent(QApplication::focusWidget(), key);
        //        emit SenEscape();
        break;
    case Qt::Key_CapsLock :
        if(CapLockFlag) CapLockFlag = false;
        else CapLockFlag = true;
        setKeyValue();
        break;
    case Qt::Key_Shift:
        if(ShiftFlag) ShiftFlag = false;
        else ShiftFlag = true;
        setKeyValue();
        break;
    case Qt::Key_Control :  //languageChange
        changeInputMethod();
        break;
    case Qt::Key_Left:
    case Qt::Key_Right:
    case Qt::Key_Up:
    case Qt::Key_Down:
        break;
    case Qt::Key_Comma : //逗号
        UpdateInputMessage(ShiftFlag? '+':',');
        break;
    case Qt::Key_Period : //小数点
        UpdateInputMessage(ShiftFlag? '>':'.');
        break;
    case Qt::Key_Slash :  //左斜杠
        UpdateInputMessage(ShiftFlag? '?':'/');
        break;
    case Qt::Key_Colon :  //冒号
        UpdateInputMessage(ShiftFlag? '=':';');
        break;
    case Qt::Key_Minus:
        UpdateInputMessage(ShiftFlag? '_':'-');
        break;
    case Qt::Key_Equal:
        UpdateInputMessage(ShiftFlag? '+':'=');
        break;
    case Qt::Key_BraceLeft:
        UpdateInputMessage(ShiftFlag? '{':'[');
        break;
    case Qt::Key_BraceRight:
        UpdateInputMessage(ShiftFlag? '}':']');
        break;
    case Qt::Key_QuoteDbl: //'
        UpdateInputMessage(ShiftFlag? '\"':'\'');
        break;
    case Qt::Key_Romaji: //反斜杠
        UpdateInputMessage(ShiftFlag? '|':'\\');
        break;
    case Qt::Key_acute: //`
        UpdateInputMessage(ShiftFlag? '~':'`');
        break;
    case Qt::Key_Close:
        //close ();
        reject();
    default:
        break;

    }
}

void bigKeyboard::setKeyValue()
{
    ui->key_0->setText (ShiftFlag? ")":"0");
    ui->key_1->setText (ShiftFlag? "!":"1");
    ui->key_2->setText (ShiftFlag? "@":"2");
    ui->key_3->setText (ShiftFlag? "#":"3");
    ui->key_4->setText (ShiftFlag? "$":"4");
    ui->key_5->setText (ShiftFlag? "[":"5");
    ui->key_6->setText (ShiftFlag? "^":"6");
    ui->key_7->setText (ShiftFlag? "-":"7");
    ui->key_8->setText (ShiftFlag? "]":"8");
    ui->key_9->setText (ShiftFlag? "(":"9");
    bool shift_caplock = (ShiftFlag ^ CapLockFlag);
    ui->key_A->setText (shift_caplock? "A":"a");
    ui->key_B->setText (shift_caplock? "B":"b");
    ui->key_C->setText (shift_caplock? "C":"c");
    ui->key_D->setText (shift_caplock? "D":"d");
    ui->key_E->setText (shift_caplock? "E":"e");
    ui->key_F->setText (shift_caplock? "F":"f");
    ui->key_G->setText (shift_caplock? "G":"g");
    ui->key_H->setText (shift_caplock? "H":"h");
    ui->key_I->setText (shift_caplock? "I":"i");
    ui->key_J->setText (shift_caplock? "J":"j");
    ui->key_K->setText (shift_caplock? "K":"k");
    ui->key_L->setText (shift_caplock? "L":"l");
    ui->key_M->setText (shift_caplock? "M":"m");
    ui->key_N->setText (shift_caplock? "N":"n");
    ui->key_O->setText (shift_caplock? "O":"o");
    ui->key_P->setText (shift_caplock? "P":"p");
    ui->key_Q->setText (shift_caplock? "Q":"q");
    ui->key_R->setText (shift_caplock? "R":"r");
    ui->key_S->setText (shift_caplock? "S":"s");
    ui->key_T->setText (shift_caplock? "T":"t");
    ui->key_U->setText (shift_caplock? "U":"u");
    ui->key_V->setText (shift_caplock? "V":"v");
    ui->key_W->setText (shift_caplock? "W":"w");
    ui->key_X->setText (shift_caplock? "X":"x");
    ui->key_Y->setText (shift_caplock? "Y":"y");
    ui->key_Z->setText (shift_caplock? "Z":"z");
    ui->Key_Comma->setText (ShiftFlag? "+":",");
    //ui->Key_Period->setText (ShiftFlag? ">":".");
    //ui->Key_Slash->setText (ShiftFlag? "?":"/");
    //ui->Key_rslash->setText (ShiftFlag? "|":"\\");
    ui->Key_Colon->setText (ShiftFlag? "=":";");
    ui->key_minus->setText (ShiftFlag? "_":"-");
    //ui->key_equal->setText (ShiftFlag? "+":"=");
    //ui->key_braceleft->setText (ShiftFlag? "{":"[");
    //ui->key_braceright->setText (ShiftFlag? "}":"]");
    //ui->Key_quotation->setText (ShiftFlag? "\"":"\'");
    //ui->Key_xx->setText (ShiftFlag? "~":"`");
}

void bigKeyboard::setBarVisible (int sel, bool enable)
{
    switch(sel) {
    case 0: ui->font_1->setVisible (enable);
        ui->lineEdit->setVisible (enable);
    case 1: ui->font_2->setVisible (enable);
    case 2: ui->font_3->setVisible (enable);
    case 3: ui->font_4->setVisible (enable);
    case 4: ui->font_5->setVisible (enable);
    case 5: ui->font_6->setVisible (enable);
    case 6: ui->font_7->setVisible (enable);
    case 7: ui->font_8->setVisible (enable);
    case 8: ui->font_9->setVisible (enable);
    case 9: ui->font_10->setVisible (enable);
    }
}

void bigKeyboard::setBarEnabled (int sel, bool enable)
{
    for(int i=0;i<10;i++)
    {
        QPushButton* pBtn=(QPushButton*)(btnBar->buttons().at(i) );

        if(i<sel)
        {
            pBtn->setEnabled(true);
        }
        else
        {
            pBtn->setEnabled(false);
            pBtn->setText("");
        }
    }
}

void bigKeyboard::UpdateBar()
{
    bool bVisible=true;
    if(english==this->method)
    {
        bVisible=false;
    }

    setBarVisible(0,bVisible);
    ui->listDown->setVisible (bVisible);
    ui->listUp->setVisible (bVisible);

    ui->pinyinWidget->setVisible(bVisible);
    ui->numberWidget->setVisible(!bVisible);
}

void bigKeyboard::clearBar ()
{
    ui->lineEdit->clear ();

    setBarEnabled(0,false);
    ui->listDown->setEnabled (false);
    ui->listUp->setEnabled (false);
}

bool bigKeyboard::transPy(QString pyInput)
{
    QByteArray strPy,strInput,xxx;
    int len,len1,comp;
    QString ddd;
    bool foundChinese;
    ui->lineEdit->insert(pyInput);
    strInput = ui->lineEdit->text ().toAscii ();
    len = strInput.count ();;

    if(method == wuhua) foundChinese = true;
    else foundChinese = openFile(strInput.at (0));

    if(foundChinese)
    {
        foundChinese = false;
        do
        {
            xxx = file.readLine().trimmed ();
            if(xxx.isEmpty ()) break;
            ddd.clear ();
            ddd.append (xxx);
            clist = ddd.split (" ");//, QString::SkipEmptyParts);
            strPy = clist.value (0).toAscii ();
            len1 = strPy.count ();
            if(len > len1) continue;
            comp = memcmp(strPy,strInput,len);
            if(!comp)
            {
                //               findNothing = false;
                foundChinese = true;
                break;
            }
        } while(!ddd.isEmpty ());
        file.seek(0);
    } 

    //计算分页数据
    pageCount = currentPage = 0;
    //    if(findNothing == false)
    if(foundChinese)
    {
        int count = 0,i;
        len1 = 1;
        do
        {
            record[pageCount].start = len1;

            for(len = len1;len < clist.count ();)
            {
                clist.value(len).trimmed ();
                QByteArray data = clist.value (len).toAscii ();
                clist.value(len).replace("\n","\0");

                i = data.count () / 2;//strlen(data.data ());
                i *= 16;
                i += 9;
                if((count + i <= 250) && (len - len1 < 9))
                {
                    if( len == clist.count() - 1 ) break;
                    count += i;
                    len ++;
                }
                else
                {
                    count = 0;
                    break;;
                }
            }
            record[pageCount].end = len;
            len1 = len + 1;
            pageCount ++;
        } while(len + 1 < clist.count ());
        //如果找到匹配的中文字符
        //       findNothing = true;
        showPage(currentPage);    //显示第一页匹配的字符,从0开始
    }
    else //if(findNothing)    //如果没有匹配的中文字符
    {
//        QString ss = ui->lineEdit->text ();
//        clearBar  ();
//        ui->lineEdit->setText (ss);
        return false;
    }

    return true;
}

void bigKeyboard::showPage(int index)
{
    int n =0,m,left = 0,top;
    bool isValid = true;
    QPushButton *qp = NULL;
    QString str;
    left = ui->font_1->geometry ().left ();
    top = ui->font_1->geometry ().top ();

    //    qDebug() << "start:" << record[index].start << "  end:" << record[index].end << endl;
    for(n = record[index].start; n <= record[index].end; n ++)
    {
        m = clist.value (n).count () ;// / 2;
        m *= 16;
        m += 9;
        switch(n - record[index].start)
        {
        case 0: qp = ui->font_1 ;break;
        case 1: qp = ui->font_2 ;break;
        case 2: qp = ui->font_3 ;break;
        case 3: qp = ui->font_4 ;break;
        case 4: qp = ui->font_5 ;break;
        case 5: qp = ui->font_6 ;break;
        case 6: qp = ui->font_7 ;break;
        case 7: qp = ui->font_8 ;break;
        case 8: qp = ui->font_9 ;break;
        case 9: qp = ui->font_10 ;break;
        default: isValid = false;
        }

        if(isValid)
        {
            //qp->setGeometry (left,top,m,25);
            str.clear ();
            str.append (clist.value (n));
            qp->setText (str);
        }
        left += m;
    }

    setBarEnabled(n - record[index].start,false);


    if(pageCount > 1)  //多于一页
    {
        if(index == 0)
        {
            ui->listUp->setEnabled (false);
            ui->listDown->setEnabled (true);
        }
        else if((index + 1) == pageCount)
        {
            ui->listUp->setEnabled (true);
            ui->listDown->setEnabled (false);
        }
        else
        {
            ui->listDown->setEnabled (true);
            ui->listUp->setEnabled (true);
        }
    }
    else
    {
        ui->listDown->setEnabled (false);
        ui->listUp->setEnabled (false);
    }
    //    qDebug() << "exit showPage()" << endl;
}

void bigKeyboard::moveKeys (int diff)
{
    ui->key_0->move (ui->key_0->x (),ui->key_0->y () + diff);
    ui->key_1->move (ui->key_1->x (),ui->key_1->y () + diff);
    ui->key_2->move (ui->key_2->x (),ui->key_2->y () + diff);
    ui->key_3->move (ui->key_3->x (),ui->key_3->y () + diff);
    ui->key_4->move (ui->key_4->x (),ui->key_4->y () + diff);
    ui->key_5->move (ui->key_5->x (),ui->key_5->y () + diff);
    ui->key_6->move (ui->key_6->x (),ui->key_6->y () + diff);
    ui->key_7->move (ui->key_7->x (),ui->key_7->y () + diff);
    ui->key_8->move (ui->key_8->x (),ui->key_8->y () + diff);
    ui->key_9->move (ui->key_9->x (),ui->key_9->y () + diff);

    ui->key_A->move (ui->key_A->x (),ui->key_A->y () + diff);
    ui->key_B->move (ui->key_B->x (),ui->key_B->y () + diff);
    ui->key_C->move (ui->key_C->x (),ui->key_C->y () + diff);
    ui->key_D->move (ui->key_D->x (),ui->key_D->y () + diff);
    ui->key_E->move (ui->key_E->x (),ui->key_E->y () + diff);
    ui->key_F->move (ui->key_F->x (),ui->key_F->y () + diff);
    ui->key_G->move (ui->key_G->x (),ui->key_G->y () + diff);
    ui->key_H->move (ui->key_H->x (),ui->key_H->y () + diff);
    ui->key_I->move (ui->key_I->x (),ui->key_I->y () + diff);
    ui->key_J->move (ui->key_J->x (),ui->key_J->y () + diff);
    ui->key_K->move (ui->key_K->x (),ui->key_K->y () + diff);
    ui->key_L->move (ui->key_L->x (),ui->key_L->y () + diff);
    ui->key_M->move (ui->key_M->x (),ui->key_M->y () + diff);
    ui->key_N->move (ui->key_N->x (),ui->key_N->y () + diff);
    ui->key_O->move (ui->key_O->x (),ui->key_O->y () + diff);
    ui->key_P->move (ui->key_P->x (),ui->key_P->y () + diff);
    ui->key_Q->move (ui->key_Q->x (),ui->key_Q->y () + diff);
    ui->key_R->move (ui->key_R->x (),ui->key_R->y () + diff);
    ui->key_S->move (ui->key_S->x (),ui->key_S->y () + diff);
    ui->key_T->move (ui->key_T->x (),ui->key_T->y () + diff);
    ui->key_U->move (ui->key_U->x (),ui->key_U->y () + diff);
    ui->key_V->move (ui->key_V->x (),ui->key_V->y () + diff);
    ui->key_W->move (ui->key_W->x (),ui->key_W->y () + diff);
    ui->key_X->move (ui->key_X->x (),ui->key_X->y () + diff);
    ui->key_Y->move (ui->key_Y->x (),ui->key_Y->y () + diff);
    ui->key_Z->move (ui->key_Z->x (),ui->key_Z->y () + diff);

    ui->Key_Comma->move (ui->Key_Comma->x (),ui->Key_Comma->y () + diff); //,
    //ui->Key_Period->move (ui->Key_Period->x (),ui->Key_Period->y () + diff);  //.
    //ui->Key_Slash->move (ui->Key_Slash->x (),ui->Key_Slash->y () + diff);   // 斜杠
    //ui->Key_rslash->move (ui->Key_rslash->x (),ui->Key_rslash->y () + diff); //反斜杠
    ui->Key_Colon->move (ui->Key_Colon->x (),ui->Key_Colon->y () + diff);  //:

    ui->key_Space->move (ui->key_Space->x (),ui->key_Space->y () + diff);
    ui->key_Enter->move (ui->key_Enter->x (),ui->key_Enter->y () + diff);
    ui->key_Backspace->move (ui->key_Backspace->x (),ui->key_Backspace->y () + diff);
    //ui->key_Escape->move (ui->key_Escape->x (),ui->key_Escape->y () + diff);
    ui->key_Cap_Lock->move (ui->key_Cap_Lock->x (),ui->key_Cap_Lock->y () + diff);
    ui->key_LangueChange->move (ui->key_LangueChange->x (),ui->key_LangueChange->y () + diff);

    //ui->Key_left->move (ui->Key_left->x (),ui->Key_left->y () + diff);
    //ui->Key_right->move (ui->Key_right->x (),ui->Key_right->y () + diff);
    //ui->Key_up->move (ui->Key_up->x (),ui->Key_up->y () + diff);
    //ui->Key_down->move (ui->Key_down->x (),ui->Key_down->y () + diff);

    ui->key_minus->move (ui->key_minus->x (),ui->key_minus->y () + diff); //-
    //ui->key_equal->move (ui->key_equal->x (),ui->key_equal->y () + diff); //=
    //ui->key_braceleft->move (ui->key_braceleft->x (),ui->key_braceleft->y () + diff); //{
    //ui->key_braceright->move (ui->key_braceright->x (),ui->key_braceright->y () + diff); //}
    //ui->Key_quotation->move (ui->Key_quotation->x (),ui->Key_quotation->y () + diff); //'
    //ui->Key_xx->move (ui->Key_xx->x (),ui->Key_xx->y () + diff);  //`
    ui->Key_Close->move (ui->Key_Close->x (),ui->Key_Close->y () + diff);
    ui->key_Shift->move (ui->key_Shift->x (),ui->key_Shift->y () + diff);

    //ui->key_Ctrl->move (ui->key_Ctrl->x (),ui->key_Ctrl->y () + diff);
    //ui->key_Alt->move (ui->key_Alt->x (),ui->key_Alt->y () + diff);
    //ui->key_Tab->move (ui->key_Tab->x (),ui->key_Tab->y () + diff);
}

void bigKeyboard::changeSize ()
{
    return;
    QRect qrect = geometry ();
    setGeometry (qrect.x (),qrect.y (),(method == english? 430:420),(method == english? 125:150));;
    moveKeys(method == english? -25:25);
}

void bigKeyboard::changeInputMethod()
{
    switch(method){
    case english:
        //英文输入转拼音输入法
        method = pinying;
        ui->key_LangueChange->setText (tr("拼音"));
        break;
//    case pinying:
//        //拼音输入法转五笔输入法
//        method = wubi;
//        ui->key_LangueChange->setText (tr("五笔"));
//        break;
//    case wubi:
//        method = wuhua;
//        //五笔输入法转五笔划输入法
//        ui->key_LangueChange->setText (tr("五划"));
//        if(file.isOpen ()) file.close ();
//        file.setFileName(":QUtility/Keyboard/src/WBH.TXT");
//        if( !file.open(QIODevice::ReadOnly | QIODevice::Text) )
//        {
//            QMessageBox::warning(0,tr("加载错误"),tr("无法加载字符编码库文件\n请检查文件是否有效！"));
//        }
//        break;
//    case wuhua:
    default:  //中文输入法转英文字符输入
        method = english;
        ui->key_LangueChange->setText (tr("EN"));
        changeSize();
        break;
    }

    UpdateBar();
    firstFlag = ' ';
}

bool bigKeyboard::openFile(char ch)
{
    bool retValue = true;
    char fileName[128];
    
    if( ((method == pinying) && ((ch == 'i') || (ch == 'u') || (ch == 'v')) )
        || ((method == wubi) && (ch == 'z')) )
        {
        //    	   firstFlag = ch;
        return false;
    }
    if(ch == firstFlag) return true;

    firstFlag = ch;
    sprintf(fileName,":QUtility/Keyboard/src/%s%c",(method == pinying)? "py":"wb",ch);
    
    if(file.isOpen ()) file.close ();
    file.setFileName(fileName);
    {
        if( !file.open(QIODevice::ReadOnly | QIODevice::Text) )
        {
            retValue = false;
            QMessageBox::warning(0,tr("加载错误"),tr("无法加载字符编码库文件%1\n请检查文件是否有效！").arg (file.fileName ()));
        }
    }
    
    return retValue;
}
