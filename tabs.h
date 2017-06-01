#ifndef TABS_H
#define TABS_H

#include <QString>

extern int new_tab(bool visible = false);
extern bool remove_tab(int id);
extern int load_url(int id, QString url);
extern int load_url(QString str);
extern void reload_url();
extern bool switch_tab(int id);
extern int history_forward(int id);
extern int history_forward();
extern int history_back(int id);
extern int history_back();

#endif // TABS_H
