#include "ccpidglobal.h"
bool m_Link_tag = false;

CCPIDData m_ccpiddata;

QRect getScreenResolution()
{
    QDesktopWidget *desk = QApplication::desktop();
    return desk->screenGeometry();
}

QRect getAvailableScreenResolution()
{
    QDesktopWidget *desk = QApplication::desktop();
    return desk->availableGeometry();
}

int getFontSize(int size)
{
    //获取可用桌面大小
    QRect deskRect = getAvailableScreenResolution();

    if(deskRect.height() < 800)
        return 0.72*size;
    else if(deskRect.height() <= 1080)
        return 1.0*size;
    else
        return (deskRect.height() / 1080.0)*size;

}
