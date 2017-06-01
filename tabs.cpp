#include <QWebEngineHistory>
#include <iostream>
#include <unordered_map>
#include "tabs.h"
#include "browserpage.h"
#include "browser.h"

// Tabs container
std::unordered_map<int, BrowserPage *> tabs;
int id_index = 0;
int current_id = 0;

// Create a new tab, return id of tab
int new_tab(bool visible) {
    BrowserPage * page = new BrowserPage();

    tabs.insert(std::pair<int, BrowserPage *>(id_index, page));

    page->setVisible(visible);
    layout->addWidget(page);

    return id_index++;
}

// Remove tab with id, return whether successful or not
bool remove_tab(int id) {
    BrowserPage * page;

    // Check whether page with id exists
    try {
        page = tabs.at(id);
    }
    catch(const std::out_of_range &err) {
        return false;
    }

    delete page;
    tabs.erase(id);

    return true;
}

// Load URL on tab with id: -1 page not found, 0 no such id, 1 success
int load_url(int id, QString url) {
    BrowserPage * page;

    // Check whether page with id exists
    try {
        page = tabs.at(id);
    }
    catch(const std::out_of_range &err) {
        return 0;
    }

    page->load_url(url);
    return 1;
}

// Load URL on current tab: -1 page not found, 0 no current page, 1 success
int load_url(QString str) {
    if(! load_url(current_id, str))
        return 0;

    return 1;
}

// Reload URL on current tab
void reload_url() {
    tabs.at(current_id)->reload();
}

// Switch to tab with id, return whether id exists or not
bool switch_tab(int id) {
    BrowserPage * page;

    // Check whether page with id exists
    try {
        page = tabs.at(id);
    }
    catch(const std::out_of_range &err) {
        return false;
    }

    // Update window to correspond to current view
    page->update_view(true);

    // Hide current tab and show new
    tabs.at(current_id)->setVisible(false);
    page->setVisible(true);

    current_id = id;

    return true;
}

// Go one step forward in history on tab id, return 0 if no such id, 1 success, -1 fail
int history_forward(int id) {
    BrowserPage * page;

    // Check whether page with id exists
    try {
        page = tabs.at(id);
    }
    catch(const std::out_of_range &err) {
        return 0;
    }

    page->page()->history()->forward();
    return 1;
}

// Go one step forward in history on current tab, return 0 if no such id, 1 success, -1 fail
int history_forward() {
    if(! history_forward(current_id))
        return 0;

    return 1;
}

// Go one step backward in history on tab id, return 0 if no such id, 1 success, -1 fail
int history_back(int id) {
    BrowserPage * page;

    // Check whether page with id exists
    try {
        page = tabs.at(id);
    }
    catch(const std::out_of_range &err) {
        return 0;
    }

    page->page()->history()->back();
    return 1;
}

// Go one step backward in history on current tab, return 0 if no such id, 1 success, -1 fail
int history_back() {
    if(! history_back(current_id))
        return 0;

    return 1;
}
