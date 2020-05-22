#ifndef CCPIDGLOBAL_H
#define CCPIDGLOBAL_H
#include <QApplication>
#include <QDesktopWidget>
#include <QRect>


#define WINTMP1 "D:\\TMP1.TXT"
#define LINUXTMP1 "/home/Lynuc/Users/LogFiles/CHMASK.CFG"

#define WINTMP "D:\\TMP.TXT"
#define LINUXTMP "/home/Lynuc/Users/LogFiles/PIDP.CFG"

/*获取屏幕分辨率*/
QRect getScreenResolution();
/*获取屏幕可用分辨率*/
QRect getAvailableScreenResolution();
/*获取字体大小*/
int getFontSize(int size);
extern bool m_Link_tag;


typedef struct CCPIDData
{
    bool m_ck[5];
    double m_d[5];

}CCPIDData;

extern CCPIDData m_ccpiddata;
#endif // CCPIDGLOBAL_H
