#ifndef SWINDOW_H
#define SWINDOW_H

#include <QtWebKit>
#include <QWidget>
#include <QVBoxLayout>
#include "spage.h"

class SWindow : public QWidget {
    Q_OBJECT

    public:
        SWindow(QWidget * parent = 0);
        void add_default_elements();
        void add_page(SPage * page);

    private:
        QVBoxLayout * layout;

};

extern SWindow * window;

#endif // SWINDOW_H
