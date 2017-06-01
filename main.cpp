#include <iostream>
#include "browser.h"

using namespace std;

int main(int argc, char ** argv) {
    Browser browser(argc, argv);

    cout << "Starting application..." << endl;
    return browser.exec();
}
