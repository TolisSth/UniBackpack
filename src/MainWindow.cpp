// Author: Apostolos Chalis 2026 <achalis@csd.auth.gr>

#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) { 
	QWidget *centralWidget = new QWidget(this);
	setCentralWidget(centralWidget);

	QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    	QPushButton *button = new QPushButton("Click here", this);

	layout->addWidget(button); 
	connect(button, &QPushButton::clicked, this, &MainWindow::handleButtonClick);

	setWindowTitle("Uni Software Downloader - Test");
    	resize(300, 200);
}

void MainWindow::handleButtonClick() {
	QMessageBox::information(this, "Button Clicked", "You clicked the button!");
};
