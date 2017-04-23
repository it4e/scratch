#include "jsint.h"
#include "sheader.h"
#include "spage.h"

#include <iostream>

// Global interface object
JSInt * js_interface;

JSInt::JSInt() {

}

// Interface function to set height of header
void JSInt::set_header_height(int height) {
    std::cout << "new height: " << height << std::endl;
    s_header->set_height(height);
}

// Interface function for setting current page focus
void JSInt::set_page_focus(int id) {
    std::cout << "Switching focus to: " << id << std::endl;
    page_switch_focus(id);
}

// Interface function for loading url on current page
void JSInt::load_url(QString url) {
    std::cout << "loading url: " << url.toStdString() << std::endl;
    page_load_url(url);
}

// Interface function for appending a page
void JSInt::append_page() {
    std::cout << "appending page" << std::endl;
    page_append(false);
}

// Interface function for removing a page by id
void JSInt::remove_page(int id) {
    page_remove(id);
}

// Interface function for going forward in history
void JSInt::go_forward() {
    page_history_go_forward();
}

// Interface function for going backward in history
void JSInt::go_back() {
    page_history_go_back();
}

