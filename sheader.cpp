#include "sheader.h"
#include "jsint.h"
#include <iostream>

#include <QWebChannel>

// Global header
SHeader * s_header;

// Initialize header
SHeader::SHeader() {
    init();
    update_height();
}

void SHeader::init() {
    // Initialize JS interface
    init_js_interface();

    // Get HTML style and load it
    QUrl path = QUrl::fromLocalFile(HEADER_DEFAULT_STYLE_PATH);
    load(path);
}

// Set layout properties of header
void SHeader::update_height() {
    std::cout << "setting height to: " << height << std::endl;
    // Set height
    setFixedHeight(height);
}

// Initalize JS interface
void SHeader::init_js_interface() {
    //page()->addToJavaScriptWindowObject("Scratch", js_interface);
    QWebChannel * channel = new QWebChannel(this);
    page()->setWebChannel(channel);

    channel->registerObject("Scratch", js_interface);
}

// Set height of header
void SHeader::set_height(int new_height) {
    this->height = new_height;
    update_height();
}
