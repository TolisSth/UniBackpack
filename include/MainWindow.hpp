// Authors: Apostolos Chalis 2026 <achalis@csd.auth.gr>, Ioannis Michadasis 2026 <cs05415@uowm.gr>
#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QStandardItemModel>
#include <QModelIndex>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    	Q_OBJECT
	
	public:
    		MainWindow(QWidget *parent = nullptr);
		~MainWindow(); 
	
	private slots: 
		void on_university_selection(const QModelIndex &index);

	private:
    		Ui::MainWindow *ui;

		QStandardItemModel *university_model;
		QStandardItemModel *department_model;

		bool showing_universities;
		QString current_university;
};

#endif // MAINWINDOW_HPP
