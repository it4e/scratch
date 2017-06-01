#include "browsersettings.h"

// Initialize global browser settings
BrowserSettings::BrowserSettings() {
    default_settings();
}

// Set default settings
void BrowserSettings::default_settings() {
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::ErrorPageEnabled, false);
}
