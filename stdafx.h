#ifndef STDAFX_H
#define STDAFX_H

#include <QString>
#include <QColor>

//#include "Globe.h"
//#include "QUtility/myhelper.h"

/*��ȫɾ��ָ��*********************************/
#define SAFE_DEL(p)   if(p){delete p;p=NULL;}

/*��ȫɾ��ָ������*********************************/
#define SAFE_DELARR(p) if(p){delete[] p;p=NULL;}

/*��ȡ�ַ����鳤��****************************/
#define ARRAY_LEN(array)  (sizeof(array)/sizeof(array[0]))

#define TM_WIRED 1	//����
#define TM_WIRELESS 2	//����

#define PRT_RSM 0 //RSMģʽ
#define PRT_PIT 1 //PITģʽ
#define RSM_AUTO 0 //RSM�Զ�
#define RSM_MANUAL 1//RSM�ֶ�

#define TM_MODE_BLUETOOTH 1//����
#define TM_MODE_NET 2 //����ֱ�Ӵ���

//�Ƿ���� //0:���� 1��������
#define INTEGRAL_YES 0
#define INTEGRAL_NO 1
//̽ͷ���� //0:���ٶȼ� 1:�ٶȼ�
#define SENSOR_TYPE_ACC 0
#define SENSOR_TYPE_VEL 1

//��������Ƿ��Զ�����		//0:�ֶ� 1:�Զ�
#define INTERVAL_CALC_AUTO 1
#define INTERVAL_CALC_MANUAL 0

//����ͨ��,1��ͨ��1��2��ͨ��2 (˫ͨ��������ʹ��)
#define TRIGGER_CHANNEL_1 1
#define TRIGGER_CHANNEL_2 2


//0-chinese   1 English
#define LAN_CHINESE 0   //����
#define LAN_ENGLISH 1   //Ӣ��

//�ж��Ƿ�Ϊ����
#define isLeap(y)  ( ((((y) % 4) == 0) && (((y) % 100) != 0)) || (((y) % 400) == 0) )

class CR
{
public:
    CR();

private:
    int m_Language;
public:
    int Language(){return m_Language;}

    QString styleFromBgColor(const QColor& color)
    {
        //text-align:left;padding:3px;
        //color:rgb(255,255,255);

        QString strStyle;
        strStyle.sprintf(" background-color:rgba(%d, %d, %d,%d);",color.red(),color.green(),color.blue(),color.alpha());
        return strStyle;
    }

    QString styleButton()
    {
        return ".QPushButton{\
            border-style: none;\
            border: 0px;\
            color: #F0F0F0;\
            padding: 1px;\
            border-radius:0px;\
             background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #5CACEE, stop:1 #4F94CD);}\
            .QPushButton:pressed{ \
            background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #1B89CA, stop:1 #1077B5);}\
            .QPushButton:disabled{ \
             background:gray;\
            }";
    }

    int GetMaxDayFromYearMounth(int year,int mounth)
    {
        int nMaxLen=31;
        switch(mounth)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            nMaxLen=31;
            break;
        case 2:
            if(isLeap(year))
            {
                nMaxLen=29;
            }
            else
            {
                nMaxLen=28;
            }
            break;
        default:
            nMaxLen=30;
            break;
        }
        return nMaxLen;
    }

    bool VerifyDate(int year,int mounth,int day)
    {
        int nMaxLen=GetMaxDayFromYearMounth(year,mounth);
        if(day>nMaxLen)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

public:
    QString stylePopDialog;
public:
    QString strBaseInfo;
    QString strOtherInfo;
    QString strSensorInfo;
    QString strDisplayInfo;

    QString strRoundPile;
    QString strSquarePile;
    QString strOtherPile;

    QString strSourceInDistance;
    QString strExp;
    QString strExpLocal;
    QString strDelayPoint;
    QString strRemark;

    QString strLowPass;
    QString strHighPass;

    //1-10000
    QString strSetLowPass;
    //0-10000
    QString strSetHighPass;

    //0.01-150.00
    QString strPileLength;
    QString strPreLength;
    QString strSetPileLength;
    //0-10000
    QString strDiameter;
    QString strOuterDiameter;
    QString strInnerDiameter;
    QString strSideLength;
    QString strArea;
    //0.01-100000.00
    QString strSensitivity;
    QString strAdjust;
    QString strHammerWeight;
    QString strDensity;
    //1-9999
    QString strPreSpeed;
    QString strSetPileSpeed;
    //5-1000
    QString strSampleInterval;

    QString strAuto;
    QString strManual;

    QString strYes;
    QString strNo;
    QString strOK;
    QString strCANCEL;

    QString strEsc;
    QString strClose;
    QString strOff;
    QString strOn;

    QString strRealSample;
    QString strMeasure;

    QString strTransducer;
    QString strAcc;
    QString strVel;

    QString strBackspace;
    QString strClear;

    QString strInputbetween;
    QString strModifyPileID;
    QString strSingleSave;
    QString strAddSave;

    QString strOpenFileFailed;
    QString strFileIsEmpty;

    QString strScreensaverTimeout;

    QString strYear;
    QString strMounth;
    QString strDay;
    QString strHour;
    QString strMinute;
    QString strSecond;

    QString strInvalidDateTime;
    QString strGuangDongPileLengthRequirement;
    QString strInputStringLen;

    QString strSingle;
    QString strFV;
    QString strVV;
    QString strPileID;
    QString strFileExistTip;
    QString strHaveNoMemory;
    QString strSavePathIsEmpty;
    QString strSaveFile;
    void InitString(int language)
    {
        m_Language=language;

        strBaseInfo = (LAN_CHINESE==language)?QObject::tr("������Ϣ"):"BaseInfo";
        strDisplayInfo = (LAN_CHINESE==language)?QObject::tr("��ʾ��Ϣ"):"DisplayInfo";
        strOtherInfo = (LAN_CHINESE==language)?QObject::tr("������Ϣ"):"OtherInfo";
        strSensorInfo = (LAN_CHINESE==language)?QObject::tr("��������Ϣ"):"SensorInfo";

        strRoundPile = (LAN_CHINESE==language)?QObject::tr("Բ��"):"Round";
        strSquarePile = (LAN_CHINESE==language)?QObject::tr("����"):"Square";
        strOtherPile = (LAN_CHINESE==language)?QObject::tr("����"):"Other";

        strSourceInDistance = (LAN_CHINESE==language)?QObject::tr("�� Դ ��"):"Source In Distance";
        //1-99
        strExp = (LAN_CHINESE==language)?QObject::tr("ָ���Ŵ�"):"E-Magnify";
        //0.00-len*0.50
        strExpLocal = (LAN_CHINESE==language)?QObject::tr("ָ���Ŵ�λ��"):"ExpLocal";
        //0-1000
        strDelayPoint = (LAN_CHINESE==language)?QObject::tr("�ӳٵ���"):"Delay Point";
        strRemark = (LAN_CHINESE==language)?QObject::tr("��    ע"):"Remark";
        strLowPass = (LAN_CHINESE==language)?QObject::tr("��ͨ�˲�"):"Low Pass";
        strHighPass = (LAN_CHINESE==language)?QObject::tr("��ͨ�˲�"):"High Pass";

        //1-10000
        strSetLowPass = (LAN_CHINESE==language)?QObject::tr("���ͨ"):"Low Pass";
        //0-10000
        strSetHighPass = (LAN_CHINESE==language)?QObject::tr("���ͨ"):"High Pass";

        //0.01-150.00
        strPileLength = (LAN_CHINESE==language)?QObject::tr("����"):"Len";
        strPreLength = (LAN_CHINESE==language)?QObject::tr("Ԥ������"):"Length";
        strSetPileLength = (LAN_CHINESE==language)?QObject::tr("��������"):"Set-LE";
        //0-10000
        strDiameter = (LAN_CHINESE==language)?QObject::tr("ֱ��"):"Diameter";
        strOuterDiameter = (LAN_CHINESE==language)?QObject::tr("�⾶"):"Oouter Diameter";
        strInnerDiameter = (LAN_CHINESE==language)?QObject::tr("�ھ�"):"Inner Diameter";
        strSideLength = (LAN_CHINESE==language)?QObject::tr("�߳�"):"Length of Side";
        strArea = (LAN_CHINESE==language)?QObject::tr("���"):"Area";
        //0.01-100000.00
        strSensitivity = (LAN_CHINESE==language)?QObject::tr("������ϵ��"):"Sensitivity";
        strAdjust = (LAN_CHINESE==language)?QObject::tr("����ϵ��"):"Adjust";
        strHammerWeight = (LAN_CHINESE==language)?QObject::tr("����"):"H-Weight";
        strDensity = (LAN_CHINESE==language)?QObject::tr("�ܶ�"):"Density";
        //1-9999
        strPreSpeed = (LAN_CHINESE==language)?QObject::tr("Ԥ�貨��"):"Wave speed";
        strSetPileSpeed = (LAN_CHINESE==language)?QObject::tr("���ò���"):"Set-WS";
        //5-1000
        strSampleInterval = (LAN_CHINESE==language)?QObject::tr("�������"):"Sample Int.";


        strAuto = (LAN_CHINESE==language)?QObject::tr("�Զ�"):"Auto";
        strManual = (LAN_CHINESE==language)?QObject::tr("�ֶ�"):"Manual";

        strYes = (LAN_CHINESE==language)?QObject::tr("��"):"Yes";
        strNo = (LAN_CHINESE==language)?QObject::tr("��"):"No";
        strOK = (LAN_CHINESE==language)?QObject::tr("ȷ��"):"OK";
        strCANCEL = (LAN_CHINESE==language)?QObject::tr("ȡ��"):"CANCEL";
        strEsc = (LAN_CHINESE==language)?QObject::tr("ȡ��"):"ESC";

        strClose = (LAN_CHINESE==language)?QObject::tr("�ر�"):"Close";
        strOff = (LAN_CHINESE==language)?QObject::tr("�ر�"):"Off";
        strOn = (LAN_CHINESE==language)?QObject::tr("����"):"On";

        strRealSample = (LAN_CHINESE==language)?QObject::tr("�ֳ�����"):"Sample";
        strMeasure = (LAN_CHINESE==language)?QObject::tr("��������"):"Measure";

        strTransducer = (LAN_CHINESE==language)?QObject::tr("̽ͷ����"):"Transducer";
        strAcc = (LAN_CHINESE==language)?QObject::tr("���ٶȼ�"):"Acc";
        strVel = (LAN_CHINESE==language)?QObject::tr("�ٶȼ�"):"Vel";

        strClear = (LAN_CHINESE==language)?QObject::tr("���"):"Clear";
        strBackspace = (LAN_CHINESE==language)?QObject::tr("�˸�"):"Back";

        strInputbetween   = (LAN_CHINESE==language)?QObject::tr("��������ֵ "):"Input between ";
        strModifyPileID =  (LAN_CHINESE==language)?QObject::tr("�޸�׮��"):"Modify";
        strSingleSave = (LAN_CHINESE==language)?QObject::tr("��������"):"Save";
        strAddSave = (LAN_CHINESE==language)?QObject::tr("��������"):"Save";

        strOpenFileFailed = (LAN_CHINESE==language)?QObject::tr("�������ļ�ʧ�ܣ�"):"Open file failed!";
        strFileIsEmpty = (LAN_CHINESE==language)?QObject::tr("�ļ�Ϊ�գ�"):"File is empty!";

        strScreensaverTimeout = (LAN_CHINESE==language)?QObject::tr("����ʱ��"):"unUse Time";

        strYear = (LAN_CHINESE==language)?QObject::tr("��"):"Year";
        strMounth = (LAN_CHINESE==language)?QObject::tr("��"):"Mounth";
        strDay = (LAN_CHINESE==language)?QObject::tr("��"):"Day";
        strHour = (LAN_CHINESE==language)?QObject::tr("ʱ"):"Hour";
        strMinute = (LAN_CHINESE==language)?QObject::tr("��"):"Minute";
        strSecond = (LAN_CHINESE==language)?QObject::tr("��"):"Second";

        strInvalidDateTime = (LAN_CHINESE==language)?QObject::tr("��Чʱ����������"):"Invalid Date Time";
        strGuangDongPileLengthRequirement = (LAN_CHINESE==language)?
                                              QObject::tr("������ֵ�����˹㶫�淶��Ҫ��(������׮����1/3)")
                                                  :"Input value is beyond the requirements of specification of Guangdong pile length (no more than 1/3)";

        strInputStringLen = (LAN_CHINESE==language)?QObject::tr("�������ַ������ȣ�"):"Input length of string : ";

        strSingle = (LAN_CHINESE==language)?QObject::tr("��ͨ��"):"Single";
        strVV = (LAN_CHINESE==language)?QObject::tr("˫ͨ��"):"VV";
        strFV = (LAN_CHINESE==language)?QObject::tr("˲̬��Ӧ"):"FV";
        strFileExistTip = (LAN_CHINESE==language)?QObject::tr("�ļ��Ѵ��ڣ��Ƿ񸲸ǣ�"):"File have exist��want to cover��";
        strPileID = (LAN_CHINESE==language)?QObject::tr("׮��"):"Pile ID";
        strHaveNoMemory = (LAN_CHINESE==language)?QObject::tr("�洢�ռ�����������ʧ�ܣ�"):"Have no memory��save failed��";
        strSavePathIsEmpty = (LAN_CHINESE==language)?QObject::tr("���̱���·��Ϊ��!"):"The Save Path is empty��please input!";
        strSaveFile = (LAN_CHINESE==language)?QObject::tr("���ڱ����ļ�,���Ե�..."):"Saving File,Please Wait...";
    }
};

extern CR R;

#endif // STDAFX_H
