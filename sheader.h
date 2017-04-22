#ifndef SHEADER_H
#define SHEADER_H

#define HEADER_DEFAULT_STYLE_PATH "/home/timmy/workspace/scratch/header.html"

#include <QtWebKit>
#include <QWebView>
#include <QObject>

class SHeader : public QWebView {
    Q_OBJECT

    public:
        SHeader();
        void set_height(int new_height);

    private:
        int height = 40;
        void init();
        void update_height();

    public slots:
        void init_js_interface();

};

extern SHeader * s_header;

#endif // SHEADER_H
