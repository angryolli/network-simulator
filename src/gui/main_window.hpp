#pragma once

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QSpinBox>

namespace netsim {
namespace gui {

// Main application window providing the GUI interface
// Contains the network visualization area, control panels, and
// simulation controls for the network simulator.
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    // Construct a new MainWindow object
    // parent: Parent widget
    explicit MainWindow(QWidget* parent = nullptr);
    
    // Destroy the MainWindow object
    ~MainWindow() = default;

private slots:
    // Start simulation
    void startSimulation();
    
    // Stop simulation
    void stopSimulation();
    
    // Reset simulation
    void resetSimulation();

private:
    void setupUI();
    void setupMenuBar();
    void setupToolBar();
    void setupStatusBar();
    
    // TODO: Implement network topology visualization, real-time simulation controls, and parameter configuration panels
    
    // UI Components
    QWidget* centralWidget_;
    QGraphicsView* networkView_;
    QGraphicsScene* networkScene_;
    QVBoxLayout* mainLayout_;
    QHBoxLayout* controlLayout_;
    
    // Control buttons
    QPushButton* startButton_;
    QPushButton* stopButton_;
    QPushButton* resetButton_;
    
    // Parameter controls
    QLabel* speedLabel_;
    QSlider* speedSlider_;
    QLabel* packetRateLabel_;
    QSpinBox* packetRateSpinBox_;
};

} // namespace gui
} // namespace netsim
