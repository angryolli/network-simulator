#include <QApplication>
#include <QMainWindow>
#include "src/gui/main_window.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    // Properties
    app.setApplicationName("Network Simulator");
    app.setApplicationVersion("1.0.0");
    app.setOrganizationName("Aalto University");
    
    // Main window
    netsim::gui::MainWindow window;
    window.show();
    
    return app.exec();
}
