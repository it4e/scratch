#include "scratch.h"
#include "swindow.h"
#include "spage.h"
#include "sheader.h"
#include "jsint.h"

// Initialize application
Scratch::Scratch(int argc, char ** argv) : QApplication(argc, argv) {
    window = new SWindow;

    // Init JS interface
    js_interface = new JSInt;

    // Init header and pages
    s_header = new SHeader;

    // Add elements
    window->add_default_elements();
    page_append(true);

    // Show window
    window->show();
}
