#ifndef BROWSERHEADER_H
#define BROWSERHEADER_H

#include <iostream>
#include <QWebEngineView>
#include "jsinterface.h"

#define HEADER_DEF_HEIGHT 40
#define HEADER_DEF_PATH "/home/timmy/workspace/browser/header.html"

class BrowserHeader : public QWebEngineView {
    Q_OBJECT

    public:
        BrowserHeader(QWidget * parent);
        void set_height(int height);

        JSInterface * js_interface;

    private:
        void create_connections();
        void js_bindings_init();
        void load_html();

    private slots:
        void load_finished_handler(bool);

};

#endif // BROWSERHEADER_H
