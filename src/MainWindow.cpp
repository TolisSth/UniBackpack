// Author: Apostolos Chalis 2026 <achalis@csd.auth.gr>
// Co-Author: Ioannis Michadasis

#include "ui_MainWindow.h"
#include "MainWindow.hpp"

#include <QDebug>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::MainWindow) {
	
	ui->setupUi(this);

	university_model = new QStandardItemModel(this);
	department_model = new QStandardItemModel(this);

	QList<QPair<QString, QString>> universities = {
    	{"Aristotle University of Thessaloniki", ":/auth_logo.png"},
    	{"University of Western Macedonia",      ":/uowm_logo.png"},
    	{"University of Macedonia",              ":/uom_logo.png"}
	};

	for (const auto &[name, iconPath] : universities) {
    	QStandardItem *item = new QStandardItem(QIcon(iconPath), name);
    	university_model->appendRow(item);
	}

	ui->listView->setModel(university_model);
	showing_universities = true;

	connect(ui->listView, &QListView::clicked, this, &MainWindow::on_university_selection);
}

MainWindow::~MainWindow() {
	delete ui;
}

void MainWindow::on_university_selection(const QModelIndex &index) {
	if (showing_universities) {
		QString selectedUni = university_model->data(index, Qt::DisplayRole).toString();
		qDebug() << "Selected: " << selectedUni;

		QStringList departments;

		if (selectedUni == "Aristotle University of Thessaloniki") {
			departments << "Back to Universities" 
						<< "Informatics" 
						<< "Physics";
		} else if (selectedUni == "University of Western Macedonia") {
			departments << "Back to Universities" 
						<< "Informatics" 
						<< "Mechanical Engineering";
		} else if (selectedUni == "University of Macedonia") {
			departments << "Back to Universities" 
						<< "Applied Informatics" 
						<< "Economics";
		}

		department_model->clear();
		for (const QString &dept : departments) {
    		department_model->appendRow(new QStandardItem(dept));
		}
		ui->listView->setModel(department_model);
		showing_universities = false; 
	} else {
		if (index.row() == 0) {
			ui->listView->setModel(university_model);
			showing_universities = true;
		} else {
			QString selectedDept = department_model->data(index, Qt::DisplayRole).toString();
			qDebug() << "Installing for department: " << selectedDept;
		}
	}
}
