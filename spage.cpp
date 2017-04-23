#include "spage.h"
#include "swindow.h"

#include <iostream>
#include <QWebEngineHistory>

// Global pages array
SPage * SPAGES[SPAGES_LIM];
int n_spages = 0;
int current_id = 0;

// Get page index with id
int page_get(int id) {
    int i;
    for(i = 0; (i < n_spages) && (SPAGES[i]->id != id); i++);

    // Found page
    if(i != n_spages)
        return i;

    std::cout << "could not find page" << std::endl;

    return -1;
}

// Get page with focus
int page_get_focus() {
    int current;
    for(current = 0; (current < n_spages) && (SPAGES[current]->visible == false); current++);

    return current;
}

// Append page to [SPAGES]
bool page_append(bool visible) {
    std::cout << "successfully appended page" << std::endl;

    if(n_spages == SPAGES_LIM)
        return false;

    SPAGES[n_spages] = new SPage(visible, current_id++);

    // Append to window
    window->add_page(SPAGES[n_spages]);
    n_spages++;

    return true;
}

// Switch which page is shown
bool page_switch_focus(int id) {
    int index, current;

    // Check if page exists
    if((index = page_get(id)) < 0)
        return false;

    // Get page with focus
    current = page_get_focus();

    // Hide current page with focus
    SPAGES[current]->set_visibility(false);

    // Set new page to visible
    SPAGES[index]->set_visibility(true);
    return true;
}

// Remove page from [SPAGES], reorder
bool page_remove(int id) {
    int index;

    // Check if page exists
    if((index = page_get(id)) < 0)
       return false;

    // Make sure not visible when deleting
    if(SPAGES[index]->visible)
        page_switch_focus(SPAGES[0]->id);

    delete SPAGES[index];

    // Move everything in order
    for(int i = index; i < (n_spages - 1); i++)
        SPAGES[i] = SPAGES[i + 1];

    n_spages--;
    return true;
}

// Load URL on current page
void page_load_url(QString url) {
    SPAGES[page_get_focus()]->load_url(url);
}

// Go forward in history on current page
void page_history_go_forward() {
    SPAGES[page_get_focus()]->history_go_forward();
}

// Go backward in history on current page
void page_history_go_back() {
    SPAGES[page_get_focus()]->history_go_back();
}

// Load URL on page
void SPage::load_url(QString url) {
    load(QUrl(url));
}

// Init page
SPage::SPage(bool visible, int id) {
    load(QUrl("http://localhost/eatit-proto"));

    // Set whether visible or not
    set_visibility(visible);

    // Add signals
    connect(this, SIGNAL(loadFinished(bool)), this, SLOT(update_title(bool)));

    this->id = id;
}

// Update title of page
void SPage::update_title(bool) {
    window()->setWindowTitle(title());
}

// Set visibilty of page
void SPage::set_visibility(bool visible) {
    this->visible = visible;
    setVisible(visible);
}

// Go forward in history
void SPage::history_go_forward() {
    page()->history()->forward();
}

// Go back in history
void SPage::history_go_back() {
    page()->history()->back();
}
