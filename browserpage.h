#ifndef BROWSERPAGE_H
#define BROWSERPAGE_H

#include <iostream>
#include <QWebEngineView>

#define PAGE_DEF_URL "http://google.com"

class BrowserPage : public QWebEngineView {
    Q_OBJECT

    public:
        BrowserPage();
        void load_url(QString url);

    private:
        void create_connections();

        bool load_failed_last = false;

    public slots:
        void update_view(bool);

};

#endif // BROWSERPAGE_H
