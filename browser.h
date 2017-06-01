#ifndef BROWSER_H
#define BROWSER_H

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include "browserheader.h"

class Browser : public QApplication {

    public:
        Browser(int argc, char ** argv);

    private:
        QWidget * main_window;

        void window_init();

};

extern QVBoxLayout * layout;
extern BrowserHeader * header;

#endif // APPLICATION_H
