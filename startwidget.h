#ifndef STARTWIDGET_H
#define STARTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QThread>
class StartWidget :public QWidget
{
public:
    StartWidget(QWidget *parent = NULL);
    /*初始化函数*/
    void startInit();

protected:
    void showEvent(QShowEvent*);
    void resizeEvent(QResizeEvent *);
private:
    QLabel *m_pLynuc;
    QLabel *m_pmessage;
};

#endif // STARTWIDGET_H
