// Author: Apostolos Chalis 2026 <achalis@csd.auth.gr>
#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QPushButton>
#include <QWidget> 
#include <QVBoxLayout>
#include <QMessageBox> 

class MainWindow : public QMainWindow
{
    	Q_OBJECT
	
	public:
    	MainWindow(QWidget *parent = nullptr);
	
	private slots: 
		void handleButtonClick();

};

#endif // MAINWINDOW_HPP
