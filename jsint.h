#ifndef JSINT_H
#define JSINT_H

#include <QtWebKit>
#include <QObject>

class JSInt : public QObject {
    Q_OBJECT

    public:
        JSInt();

    private:

    // Interface API
    public slots:
        void set_header_height(int height);
        void set_page_focus(int id);
        void append_page();
        void remove_page(int id);
        void load_url(QString url);

};

extern JSInt * js_interface;

#endif // JSINT_H
