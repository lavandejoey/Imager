#include <iostream>

#include <QtWidgets>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QCoreApplication>
#include <QFile>
#include <QDir>

void initImager(const QString &qstrAppName);

int main(int argc, char *argv[]) {
    QApplication qappImager(argc, argv);
    QString qstrAppName = "Imager";

    // Initialize the application
    initImager(qstrAppName);

    // Create the main window
    QMainWindow qmwinMainWindow;
    qmwinMainWindow.setWindowTitle(qstrAppName);
    qmwinMainWindow.resize(800, 600);

    // Create a central widget for the main window
    QWidget *qcentwidgetMonitor = new QWidget(&qmwinMainWindow);
    qmwinMainWindow.setCentralWidget(qcentwidgetMonitor);

    // Create a layout for the central widget
    QVBoxLayout *layout = new QVBoxLayout(qcentwidgetMonitor);

    // Create a viewfinder widget for camera display
    QCameraViewfinder *viewfinder = new QCameraViewfinder;
    layout->addWidget(viewfinder);


    // Create a capture button
    QPushButton *captureButton = new QPushButton("Capture Photo");
    layout->addWidget(captureButton, 1, Qt::AlignJustify);
    // Create a browse button
    QPushButton *browseButton = new QPushButton("Browse Photos");
    layout->addWidget(browseButton, 1, Qt::AlignJustify);


    // Create a camera object and an image capture object
    QCamera *camera = new QCamera;
    camera->setViewfinder(viewfinder);
    QCameraImageCapture *imageCapture = new QCameraImageCapture(camera);
    // Connect the capture button to capture a photo
    QObject::connect(captureButton, &QPushButton::clicked, [=]() {
        // Capture a photo and save it to a file
        imageCapture->capture(QFileDialog::getSaveFileName(nullptr, "Save Photo", "", "Images (*.jpg *.png)"));
    });

    // Connect the browse button to open a file dialog for browsing photos
    QObject::connect(browseButton, &QPushButton::clicked, [=]() {
        QString filePath = QFileDialog::getOpenFileName(nullptr, "Open Photo", "", "Images (*.jpg *.png)");
        if (!filePath.isEmpty()) {
            // Display the selected photo in a separate window or process it as needed.
            // You can use QPixmap or QImage to load and display the image.
        }
    });

    // Start the camera
    camera->start();

    // Show the main window
    qmwinMainWindow.show();

    return QApplication::exec();
}

void initImager(const QString &qstrAppName) {
    /// For the first time, init with default configs.
    // Get the application's configuration directory
    QString configDir = QCoreApplication::applicationDirPath() + "/config/";

    // Construct the full path to the config file
    QString configFile = configDir + qstrAppName + ".config";

    // Check if the config file exists
    QFile file(configFile);
    if (file.exists()) {
        // Config file exists, load and apply settings
        // You can implement this part to load and apply the configuration
        // settings from the configFile.
        // Example: loadConfigSettings(configFile);
    } else {
        // Config file does not exist, initialize with default settings
        // You can implement this part to create and initialize the
        // default configuration settings for the application.
        // Example: createDefaultConfig(appName, configFile);
    }
}