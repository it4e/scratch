#include <iostream>
#include <QWebChannel>
#include "browserheader.h"

using namespace std;

// Initialize view
BrowserHeader::BrowserHeader(QWidget * parent) : QWebEngineView(parent) {
    js_interface = new JSInterface;


    cout << "Creating header connections" << endl;
    create_connections();

    cout << "Setting header height" << endl;
    set_height(HEADER_DEF_HEIGHT);

    cout << "Creating JS interface bindings" << endl;
    js_bindings_init();

    cout << "Loading default url" << endl;
    load_html();

    //page()->runJavaScript("document.elementFromPoint(10, 10).tagName;", [](const QVariant &v) {qDebug() << v.toString();});
}

// Create view signal connections
void BrowserHeader::create_connections() {
    // Signal on load finished to display window
    connect(this, SIGNAL(loadFinished(bool)), this, SLOT(load_finished_handler(bool)));
}

// Set height of view
void BrowserHeader::set_height(int height) {
    setFixedHeight(height);
}

// Initialize JS interface on view
void BrowserHeader::js_bindings_init() {
    QWebChannel * channel = new QWebChannel(this);
    channel->registerObject("browser", js_interface);

    page()->setWebChannel(channel);
}

// Load HTML file
void BrowserHeader::load_html() {
    load(QUrl::fromLocalFile(HEADER_DEF_PATH));
}

// Load finished handler
void BrowserHeader::load_finished_handler(bool) {
    // Display window
    //this->parentWidget()->show();
}
