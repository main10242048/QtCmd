#ifndef STDAFX_H
#define STDAFX_H

#include <QString>
#include <QColor>

//#include "Globe.h"
//#include "QUtility/myhelper.h"

/*安全删除指针*********************************/
#define SAFE_DEL(p)   if(p){delete p;p=NULL;}

/*安全删除指针数组*********************************/
#define SAFE_DELARR(p) if(p){delete[] p;p=NULL;}

/*获取字符数组长度****************************/
#define ARRAY_LEN(array)  (sizeof(array)/sizeof(array[0]))

#define TM_WIRED 1	//有线
#define TM_WIRELESS 2	//无线

#define PRT_RSM 0 //RSM模式
#define PRT_PIT 1 //PIT模式
#define RSM_AUTO 0 //RSM自动
#define RSM_MANUAL 1//RSM手动

#define TM_MODE_BLUETOOTH 1//蓝牙
#define TM_MODE_NET 2 //网络直接传输

//是否积分 //0:积分 1：不积分
#define INTEGRAL_YES 0
#define INTEGRAL_NO 1
//探头类型 //0:加速度计 1:速度计
#define SENSOR_TYPE_ACC 0
#define SENSOR_TYPE_VEL 1

//采样间隔是否自动计算		//0:手动 1:自动
#define INTERVAL_CALC_AUTO 1
#define INTERVAL_CALC_MANUAL 0

//触发通道,1：通道1，2：通道2 (双通道仪器下使用)
#define TRIGGER_CHANNEL_1 1
#define TRIGGER_CHANNEL_2 2


//0-chinese   1 English
#define LAN_CHINESE 0   //中文
#define LAN_ENGLISH 1   //英文

//判断是否为闰年
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

        strBaseInfo = (LAN_CHINESE==language)?QObject::tr("基本信息"):"BaseInfo";
        strDisplayInfo = (LAN_CHINESE==language)?QObject::tr("显示信息"):"DisplayInfo";
        strOtherInfo = (LAN_CHINESE==language)?QObject::tr("其他信息"):"OtherInfo";
        strSensorInfo = (LAN_CHINESE==language)?QObject::tr("传感器信息"):"SensorInfo";

        strRoundPile = (LAN_CHINESE==language)?QObject::tr("圆形"):"Round";
        strSquarePile = (LAN_CHINESE==language)?QObject::tr("方形"):"Square";
        strOtherPile = (LAN_CHINESE==language)?QObject::tr("异形"):"Other";

        strSourceInDistance = (LAN_CHINESE==language)?QObject::tr("点 源 距"):"Source In Distance";
        //1-99
        strExp = (LAN_CHINESE==language)?QObject::tr("指数放大"):"E-Magnify";
        //0.00-len*0.50
        strExpLocal = (LAN_CHINESE==language)?QObject::tr("指数放大位置"):"ExpLocal";
        //0-1000
        strDelayPoint = (LAN_CHINESE==language)?QObject::tr("延迟点数"):"Delay Point";
        strRemark = (LAN_CHINESE==language)?QObject::tr("备    注"):"Remark";
        strLowPass = (LAN_CHINESE==language)?QObject::tr("低通滤波"):"Low Pass";
        strHighPass = (LAN_CHINESE==language)?QObject::tr("高通滤波"):"High Pass";

        //1-10000
        strSetLowPass = (LAN_CHINESE==language)?QObject::tr("设低通"):"Low Pass";
        //0-10000
        strSetHighPass = (LAN_CHINESE==language)?QObject::tr("设高通"):"High Pass";

        //0.01-150.00
        strPileLength = (LAN_CHINESE==language)?QObject::tr("柱长"):"Len";
        strPreLength = (LAN_CHINESE==language)?QObject::tr("预设柱长"):"Length";
        strSetPileLength = (LAN_CHINESE==language)?QObject::tr("设置柱长"):"Set-LE";
        //0-10000
        strDiameter = (LAN_CHINESE==language)?QObject::tr("直径"):"Diameter";
        strOuterDiameter = (LAN_CHINESE==language)?QObject::tr("外径"):"Oouter Diameter";
        strInnerDiameter = (LAN_CHINESE==language)?QObject::tr("内径"):"Inner Diameter";
        strSideLength = (LAN_CHINESE==language)?QObject::tr("边长"):"Length of Side";
        strArea = (LAN_CHINESE==language)?QObject::tr("面积"):"Area";
        //0.01-100000.00
        strSensitivity = (LAN_CHINESE==language)?QObject::tr("灵敏度系数"):"Sensitivity";
        strAdjust = (LAN_CHINESE==language)?QObject::tr("调整系数"):"Adjust";
        strHammerWeight = (LAN_CHINESE==language)?QObject::tr("锤重"):"H-Weight";
        strDensity = (LAN_CHINESE==language)?QObject::tr("密度"):"Density";
        //1-9999
        strPreSpeed = (LAN_CHINESE==language)?QObject::tr("预设波速"):"Wave speed";
        strSetPileSpeed = (LAN_CHINESE==language)?QObject::tr("设置波速"):"Set-WS";
        //5-1000
        strSampleInterval = (LAN_CHINESE==language)?QObject::tr("采样间隔"):"Sample Int.";


        strAuto = (LAN_CHINESE==language)?QObject::tr("自动"):"Auto";
        strManual = (LAN_CHINESE==language)?QObject::tr("手动"):"Manual";

        strYes = (LAN_CHINESE==language)?QObject::tr("是"):"Yes";
        strNo = (LAN_CHINESE==language)?QObject::tr("否"):"No";
        strOK = (LAN_CHINESE==language)?QObject::tr("确定"):"OK";
        strCANCEL = (LAN_CHINESE==language)?QObject::tr("取消"):"CANCEL";
        strEsc = (LAN_CHINESE==language)?QObject::tr("取消"):"ESC";

        strClose = (LAN_CHINESE==language)?QObject::tr("关闭"):"Close";
        strOff = (LAN_CHINESE==language)?QObject::tr("关闭"):"Off";
        strOn = (LAN_CHINESE==language)?QObject::tr("开启"):"On";

        strRealSample = (LAN_CHINESE==language)?QObject::tr("现场测试"):"Sample";
        strMeasure = (LAN_CHINESE==language)?QObject::tr("计量测试"):"Measure";

        strTransducer = (LAN_CHINESE==language)?QObject::tr("探头类型"):"Transducer";
        strAcc = (LAN_CHINESE==language)?QObject::tr("加速度计"):"Acc";
        strVel = (LAN_CHINESE==language)?QObject::tr("速度计"):"Vel";

        strClear = (LAN_CHINESE==language)?QObject::tr("清除"):"Clear";
        strBackspace = (LAN_CHINESE==language)?QObject::tr("退格"):"Back";

        strInputbetween   = (LAN_CHINESE==language)?QObject::tr("请输入数值 "):"Input between ";
        strModifyPileID =  (LAN_CHINESE==language)?QObject::tr("修改桩号"):"Modify";
        strSingleSave = (LAN_CHINESE==language)?QObject::tr("单存设置"):"Save";
        strAddSave = (LAN_CHINESE==language)?QObject::tr("叠存设置"):"Save";

        strOpenFileFailed = (LAN_CHINESE==language)?QObject::tr("打开数据文件失败！"):"Open file failed!";
        strFileIsEmpty = (LAN_CHINESE==language)?QObject::tr("文件为空！"):"File is empty!";

        strScreensaverTimeout = (LAN_CHINESE==language)?QObject::tr("屏保时间"):"unUse Time";

        strYear = (LAN_CHINESE==language)?QObject::tr("年"):"Year";
        strMounth = (LAN_CHINESE==language)?QObject::tr("月"):"Mounth";
        strDay = (LAN_CHINESE==language)?QObject::tr("日"):"Day";
        strHour = (LAN_CHINESE==language)?QObject::tr("时"):"Hour";
        strMinute = (LAN_CHINESE==language)?QObject::tr("分"):"Minute";
        strSecond = (LAN_CHINESE==language)?QObject::tr("秒"):"Second";

        strInvalidDateTime = (LAN_CHINESE==language)?QObject::tr("无效时间日期设置"):"Invalid Date Time";
        strGuangDongPileLengthRequirement = (LAN_CHINESE==language)?
                                              QObject::tr("输入数值超出了广东规范的要求(不超过桩长的1/3)")
                                                  :"Input value is beyond the requirements of specification of Guangdong pile length (no more than 1/3)";

        strInputStringLen = (LAN_CHINESE==language)?QObject::tr("请输入字符串长度："):"Input length of string : ";

        strSingle = (LAN_CHINESE==language)?QObject::tr("单通道"):"Single";
        strVV = (LAN_CHINESE==language)?QObject::tr("双通道"):"VV";
        strFV = (LAN_CHINESE==language)?QObject::tr("瞬态响应"):"FV";
        strFileExistTip = (LAN_CHINESE==language)?QObject::tr("文件已存在，是否覆盖？"):"File have exist，want to cover？";
        strPileID = (LAN_CHINESE==language)?QObject::tr("桩号"):"Pile ID";
        strHaveNoMemory = (LAN_CHINESE==language)?QObject::tr("存储空间已满，保存失败！"):"Have no memory，save failed！";
        strSavePathIsEmpty = (LAN_CHINESE==language)?QObject::tr("工程保存路径为空!"):"The Save Path is empty，please input!";
        strSaveFile = (LAN_CHINESE==language)?QObject::tr("正在保存文件,请稍等..."):"Saving File,Please Wait...";
    }
};

extern CR R;

#endif // STDAFX_H
