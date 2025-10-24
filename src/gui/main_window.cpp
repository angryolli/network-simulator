#include "main_window.hpp"
#include <QApplication>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QMessageBox>

namespace netsim {
namespace gui {

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setupUI();
    setupMenuBar();
    setupToolBar();
    setupStatusBar();
    
    setWindowTitle("Network Simulator");
    setMinimumSize(800, 600);
    resize(1200, 800);
}

void MainWindow::setupUI()
{
    // Create central widget and layout
    centralWidget_ = new QWidget(this);
    setCentralWidget(centralWidget_);
    
    mainLayout_ = new QVBoxLayout(centralWidget_);
    
    // Create network visualization area
    networkScene_ = new QGraphicsScene(this);
    networkView_ = new QGraphicsView(networkScene_, this);
    networkView_->setRenderHint(QPainter::Antialiasing);
    networkView_->setDragMode(QGraphicsView::RubberBandDrag);
    
    // Create control panel
    controlLayout_ = new QHBoxLayout();
    
    // Control buttons
    startButton_ = new QPushButton("Start", this);
    stopButton_ = new QPushButton("Stop", this);
    resetButton_ = new QPushButton("Reset", this);
    
    stopButton_->setEnabled(false);
    
    // Parameter controls
    speedLabel_ = new QLabel("Speed:", this);
    speedSlider_ = new QSlider(Qt::Horizontal, this);
    speedSlider_->setRange(1, 10);
    speedSlider_->setValue(5);
    
    packetRateLabel_ = new QLabel("Packet Rate:", this);
    packetRateSpinBox_ = new QSpinBox(this);
    packetRateSpinBox_->setRange(1, 1000);
    packetRateSpinBox_->setValue(100);
    
    // Layout controls
    controlLayout_->addWidget(startButton_);
    controlLayout_->addWidget(stopButton_);
    controlLayout_->addWidget(resetButton_);
    controlLayout_->addStretch();
    controlLayout_->addWidget(speedLabel_);
    controlLayout_->addWidget(speedSlider_);
    controlLayout_->addWidget(packetRateLabel_);
    controlLayout_->addWidget(packetRateSpinBox_);
    
    // Add to main layout
    mainLayout_->addWidget(networkView_, 1);
    mainLayout_->addLayout(controlLayout_);
    
    // Connect signals
    connect(startButton_, &QPushButton::clicked, this, &MainWindow::startSimulation);
    connect(stopButton_, &QPushButton::clicked, this, &MainWindow::stopSimulation);
    connect(resetButton_, &QPushButton::clicked, this, &MainWindow::resetSimulation);
    
    // TODO: Initialize network scene with placeholder nodes and set up real-time visualization updates
}

void MainWindow::setupMenuBar()
{
    // File menu
    QMenu* fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction("&New Network", this, [this]() {
        // TODO: Implement new network creation
        QMessageBox::information(this, "New Network", "New network functionality not yet implemented");
    });
    fileMenu->addAction("&Load Network", this, [this]() {
        // TODO: Implement network loading
        QMessageBox::information(this, "Load Network", "Load network functionality not yet implemented");
    });
    fileMenu->addSeparator();
    fileMenu->addAction("E&xit", this, &QWidget::close);
    
    // Simulation menu
    QMenu* simMenu = menuBar()->addMenu("&Simulation");
    simMenu->addAction("&Start", this, &MainWindow::startSimulation);
    simMenu->addAction("S&top", this, &MainWindow::stopSimulation);
    simMenu->addAction("&Reset", this, &MainWindow::resetSimulation);
    
    // Help menu
    QMenu* helpMenu = menuBar()->addMenu("&Help");
    helpMenu->addAction("&About", this, [this]() {
        QMessageBox::about(this, "About Network Simulator", 
                          "Network Simulator v1.0.0\n"
                          "Discrete-event network simulation tool\n"
                          "Aalto University");
    });
}

void MainWindow::setupToolBar()
{
    QToolBar* toolBar = addToolBar("Main");
    toolBar->addAction("Start", this, &MainWindow::startSimulation);
    toolBar->addAction("Stop", this, &MainWindow::stopSimulation);
    toolBar->addAction("Reset", this, &MainWindow::resetSimulation);
    toolBar->addSeparator();
    // TODO: Add network editing tools
}

void MainWindow::setupStatusBar()
{
    statusBar()->showMessage("Ready");
    // TODO: Add simulation status indicators and real-time statistics display
}

void MainWindow::startSimulation()
{
    startButton_->setEnabled(false);
    stopButton_->setEnabled(true);
    statusBar()->showMessage("Simulation running...");
    
    // TODO: Initialize simulation engine, start event processing, and begin real-time visualization updates
}

void MainWindow::stopSimulation()
{
    startButton_->setEnabled(true);
    stopButton_->setEnabled(false);
    statusBar()->showMessage("Simulation stopped");
    
    // TODO: Stop simulation engine, pause event processing, and stop visualization updates
}

void MainWindow::resetSimulation()
{
    startButton_->setEnabled(true);
    stopButton_->setEnabled(false);
    statusBar()->showMessage("Simulation reset");
    
    // TODO: Reset simulation state, clear network scene, and reset statistics
}

}
}
