#include <QApplication>
#include <QMainWindow>
#include "gui/main_window.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    // Set application properties
    app.setApplicationName("Network Simulator");
    app.setApplicationVersion("1.0.0");
    app.setOrganizationName("Aalto University");
    
    // Create and show main window
    netsim::gui::MainWindow window;
    window.show();
    
    return app.exec();
}
