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

/**
 * @brief Main application window providing the GUI interface
 * 
 * Contains the network visualization area, control panels, and
 * simulation controls for the network simulator.
 */
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    /**
     * @brief Construct a new MainWindow object
     * @param parent Parent widget
     */
    explicit MainWindow(QWidget* parent = nullptr);
    
    /**
     * @brief Destroy the MainWindow object
     */
    ~MainWindow() = default;

private slots:
    /**
     * @brief Start simulation
     */
    void startSimulation();
    
    /**
     * @brief Stop simulation
     */
    void stopSimulation();
    
    /**
     * @brief Reset simulation
     */
    void resetSimulation();

private:
    void setupUI();
    void setupMenuBar();
    void setupToolBar();
    void setupStatusBar();
    
    // TODO: Implement network topology visualization
    // TODO: Add real-time simulation controls
    // TODO: Implement parameter configuration panels
    
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
