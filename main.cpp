#include "widget.h"
#include <QApplication>
#include "startwidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StartWidget st;
    st.show();

    st.startInit();

    //Widget w;
    //w.show();

    return a.exec();
}
