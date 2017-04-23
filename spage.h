#ifndef SPAGE_H
#define SPAGE_H

#define SPAGES_LIM 20 // Maximum pages open at once

#include <QWebEngineView>
#include <iostream>

class SPage : public QWebEngineView {
    Q_OBJECT

    public:
        SPage(bool visible, int id);
        void load_url(QString url);
        void history_go_forward();
        void history_go_back();
        void set_visibility(bool visible = false);
        bool visible;
        int id;

    private:

    private slots:
        void update_title(bool);

};

extern bool page_switch_focus(int id);
extern void page_history_go_forward();
extern void page_history_go_back();
extern void page_load_url(QString url);
extern bool page_append(bool visible = false);
extern bool page_remove(int id);
extern SPage * SPAGES[SPAGES_LIM];
extern int n_spages;

#endif // SPAGE_H
