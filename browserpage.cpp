#include "browserpage.h"
#include "browser.h"

using namespace std;

// Initalize page
BrowserPage::BrowserPage() {
    //this->setContextMenuPolicy(Qt::CustomContextMenu);

    cout << "Creating connections" << endl;
    create_connections();

    cout << "Loading default url" << endl;
    load_url(PAGE_DEF_URL);
}

// Create signal connections
void BrowserPage::create_connections() {
    // Signal to update page after load has finished
    connect(this, SIGNAL(loadFinished(bool)), this, SLOT(update_view(bool)));

    // Signal for custom right clicking, context menu
    //connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(custom_menu(QPoint)));
}

// Load URL in view
void BrowserPage::load_url(QString url) {
    load(QUrl::fromUserInput(url));
}

// Update view after load has finished
void BrowserPage::update_view(bool state) {
    if(state) {
        window()->setWindowTitle(page()->title() + " - Custom Browser");

        if(! load_failed_last)
            emit header->js_interface->update_url(url().toString());
        else
            load_failed_last = false;

        return;
    }

    // Page failed to load
    setHtml("Failed to load page.");

    load_failed_last = true;
}
