#include "jsinterface.h"
#include "tabs.h"
#include "browser.h"

JSInterface::JSInterface() {

}

// Create a new tab, return id of tab
int JSInterface::new_tab() {
    return ::new_tab();
}

// Remove tab with id, return whether successful or not
bool JSInterface::remove_tab(int id) {
    return ::remove_tab(id);
}

// Load URL on tab with id: -1 page not found, 0 no such id, 1 success
int JSInterface::load_url_on(int id, QString url) {
    return ::load_url(id, url);
}

// Load URL on current tab
int JSInterface::load_url(QString url) {
    return ::load_url(url);
}

// Reload URL on current view
void JSInterface::reload_url() {
    return ::reload_url();
}

// Switch to tab with id, return whether id exists or not
bool JSInterface::switch_tab(int id) {
    return ::switch_tab(id);
}

// Go one step forward in history on tab id, return 0 if no such id, 1 success, -1 fail
int JSInterface::history_forward_on(int id) {
    return ::history_forward(id);
}

// Go one step forward in history on current tab, return 0 if no such id, 1 success, -1 fail
int JSInterface::history_forward() {
    return ::history_forward();
}

// Go one step backward in history on tab id, return 0 if no such id, 1 success, -1 fail
int JSInterface::history_back_on(int id) {
    return ::history_back(id);
}

// Go one step backward in history on current tab, return 0 if no such id, 1 success, -1 fail
int JSInterface::history_back() {
    return::history_back();
}

// Set header height
void JSInterface::set_header_height(int height) {
    header->set_height(height);
}
