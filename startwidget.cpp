#include "startwidget.h"
#include "ccpidglobal.h"
#include <QRect>
#include <QPushButton>
#include <QVBoxLayout>
#include "ciportal.h"
#include "fileportal.h"
#include <stdio.h>
#include <stdlib.h>

StartWidget::StartWidget(QWidget *parent)
    :QWidget(parent)
{
    /*显示顶层无边框*/
    this->setWindowFlags(Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);
    //this->setAttribute(Qt::WA_TranslucentBackground);

    this->setStyleSheet("QWidget{background-color:rgb(12,51,101);border:2px solid red;}");
    this->setAttribute(Qt::WA_SetStyle);

    m_pLynuc = new QLabel(this);
    m_pLynuc->setText("Lynuc");
    m_pLynuc->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    m_pLynuc->setStyleSheet("QLabel{backgorund-color:rgb(12,51,101);"
                            "color:#FFFFFF;font-family:'Arial Black';"
                            "width:auto;height:auto;"
                            "font-size:"+QString::number(getFontSize(150))+"px;}");

    m_pmessage = new QLabel(this);
    m_pmessage->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    m_pmessage->setStyleSheet("QLabel{font-family:simhei;"
                              "color:#FFFFFF;width:auto;height:auto;}"
                              "font-size:"+QString::number(getFontSize(20))+"px;}");

    QVBoxLayout *vlayout = new QVBoxLayout(this);
    vlayout->addWidget(m_pLynuc);
    vlayout->addWidget(m_pmessage);
    vlayout->setSpacing(0);
    vlayout->setMargin(0);

    vlayout->setStretchFactor(m_pLynuc,5);
    vlayout->setStretchFactor(m_pmessage,1);


    QRect rect =  getAvailableScreenResolution();

    this->setGeometry(rect.width()/3,
                      rect.height()/3,
                      rect.width()/3,
                      rect.height()/3);

}

void StartWidget::startInit()
{
    m_pmessage->setText("启动成功！");
    m_pmessage->setText("连接控制器！");
    //m_Link_tag = OnLinkMachine(0,192,168,1,158);
    if(m_Link_tag)
        m_pmessage->setText("连接成功！");
    else
        m_pmessage->setText("连接失败！");

    m_pmessage->setText("同步tmp1！");
    //if(RecvFile(192,168,1,158,WINTMP1,LINUXTMP1))
    {
        FILE * fp = fopen(WINTMP1,"rb");
        double a,b,c,d,e;
        long num = fscanf(fp,"%lf,%lf,%lf,%lf,%lf,",&a,&b,&c,&d,&e);

        if(num == 5)
        {
            if(a > 0.5){m_ccpiddata.m_ck[0] = true;}
            else{m_ccpiddata.m_ck[0] = false;}
            if(b > 0.5){m_ccpiddata.m_ck[1] = true;}
            else{m_ccpiddata.m_ck[1] = false;}
            if(c > 0.5){m_ccpiddata.m_ck[2] = true;}
            else{m_ccpiddata.m_ck[2] = false;}
            if(d > 0.5){m_ccpiddata.m_ck[3] = true;}
            else{m_ccpiddata.m_ck[3] = false;}
            if(e > 0.5){m_ccpiddata.m_ck[4] = true;}
            else{m_ccpiddata.m_ck[4] = false;}
            m_pmessage->setText("获取远程轴配置成功！");
        }
        else
        {
            for(int i =0;i<5;i++)
            {
                m_ccpiddata.m_ck[i] = false;
            }
            m_pmessage->setText("获取远程轴配置失败,采用默认配置！");
        }

        num = fscanf(fp,"%lf,%lf,%lf,%lf,%lf,",&a,&b,&c,&d,&e);
        if(num == 5)
        {
            m_ccpiddata.m_d[0] = a;
            m_ccpiddata.m_d[1] = b;
            m_ccpiddata.m_d[2] = c;
            m_ccpiddata.m_d[3] = d;
            m_ccpiddata.m_d[4] = e;
        }
        else
        {
            m_ccpiddata.m_d[0] = 0;
            m_ccpiddata.m_d[1] = 0;
            m_ccpiddata.m_d[2] = 0;
            m_ccpiddata.m_d[3] = 0;
            m_ccpiddata.m_d[4] = 0;
        }

        fclose(fp);
    }
    //else
    {
        m_pmessage->setText("获取远程轴配置失败,采用默认配置！");
    }
}

void StartWidget::showEvent(QShowEvent *)
{
}

void StartWidget::resizeEvent(QResizeEvent *)
{
}
