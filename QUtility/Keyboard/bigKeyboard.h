#ifndef bigKeyboard_H
#define bigKeyboard_H

#include <QDialog>
#include <QButtonGroup>
#include <Qt>
#include <QMouseEvent>
#include <QFile>
#include <QLabel>
#include <QMessageBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QTextBrowser>


namespace Ui {
    class bigKeyboard;
}

class bigKeyboard : public QDialog
{
    Q_OBJECT
public:
    typedef struct
    {
      int start;
      int end;
    } RECORD;

    //���뷨���
    enum EinputMethod{english,pinying,wubi,wuhua,chinese};

public:
    explicit bigKeyboard(QString str="",QWidget *parent=0);
    ~bigKeyboard();

    QString GetReturnValue();
    void SetStringRange(int min,int max);
    void SetChangeMethodEnabled(bool);
protected:
    //void mousePressEvent(QMouseEvent *);
    //void mouseReleaseEvent(QMouseEvent *);
    //void mouseMoveEvent(QMouseEvent *);
    
private:
    void SetbigKeyboard();
    void SetKeyBar();
    void setKeyValue();
    void setBarVisible(int ,bool);
    void setBarEnabled (int sel, bool enable);
    void moveKeys(int);

public slots:
    void keyPressed(int);
    void barPressed(int);

signals:
    void SendInputMessage(QString);
    void SendEnter();
    void SendBackspace();
    void SenEscape();

private:
    //��������
    QPoint dragPosition;
    //�Ƿ������
    bool moveAble;
    //��ҳ
    RECORD record[15];
    QStringList clist;
    char firstFlag;

    //�ַ�����Ч��Χ
    int m_nMinLength;
    int m_nMaxLength;

    Ui::bigKeyboard *ui;
    QButtonGroup *btnKeys;
    QButtonGroup *btnBar;

    //���뷨���
    EinputMethod method;

    bool CapLockFlag,ShiftFlag;
    int currentPage;
    QKeyEvent* transkey(int x,int y);
    //���������ƴ��ת���ɺ���
    bool transPy(QString pyInput);
    QLineEdit *keyRev;

    QFile file;
    void showPage(int index);
    int pageCount;
    void changeInputMethod();
    void changeSize();
    void UpdateBar();
    void clearBar();
    bool openFile(char);
    void UpdateInputMessage(QString);
    void UpdateInputMessage(char);

};

#endif // bigKeyboard_H
