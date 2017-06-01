#include "browser.h"
#include "browserpage.h"
#include "tabs.h"
#include "browsersettings.h"

QVBoxLayout * layout;
BrowserHeader * header;
BrowserSettings * default_settings;

// Initalize browser
Browser::Browser(int argc, char ** argv) : QApplication(argc, argv) {
    layout = new QVBoxLayout();
    main_window = new QWidget();
    default_settings = new BrowserSettings();
    header = new BrowserHeader(main_window);

    window_init();
    main_window->show();
}

// Initalize window
void Browser::window_init() {
    layout->setSpacing(0);
    layout->setMargin(0);

    main_window->setLayout(layout);

    layout->addWidget(header);
    ::new_tab(true);
}
