#include "swindow.h"
#include "sheader.h"
#include "spage.h"

// Global window pointer dec
SWindow * window;

// Initialize window
SWindow::SWindow(QWidget * parent) : QWidget(parent) {
    layout = new QVBoxLayout;

    // Define layout
    layout->setMargin(0);
    layout->setSpacing(0);

    setLayout(layout);
}

// Add default elements
void SWindow::add_default_elements() {
    layout->addWidget(s_header);

    for(int i = 0; i < n_spages; i++)
        layout->addWidget(SPAGES[i]);
}

// Add page to layout
void SWindow::add_page(SPage * page) {
    layout->addWidget(page);
}
