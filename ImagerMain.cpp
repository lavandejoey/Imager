#include <QApplication>
#include "imager.h"


int main(int argc, char *argv[]) {
    // Set up the spdlog
    spdlog::set_level(spdlog::level::debug);
    spdlog::debug("Starting imager");

    QApplication qappImager(argc, argv);

    // Create the main window
    imager qmwinMainWindow(nullptr);

    // Create the settings
    settings qwigtSettings(&qmwinMainWindow);

    qmwinMainWindow.show();
    return QApplication::exec();
}

