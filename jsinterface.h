#ifndef JSINTERFACE_H
#define JSINTERFACE_H

#include <QObject>

class JSInterface : public QObject {
    Q_OBJECT

    public:
        JSInterface();

    public slots:
        Q_INVOKABLE int new_tab();
        bool remove_tab(int id);
        int load_url_on(int id, QString str);
        int load_url(QString url);
        void reload_url();
        bool switch_tab(int id);
        int history_forward_on(int id);
        int history_forward();
        int history_back_on(int id);
        int history_back();
        void set_header_height(int height);

    signals:
        void update_url(const QString &url);

};

#endif // JSINTERFACE_H
