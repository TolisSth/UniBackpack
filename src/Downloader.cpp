// Author: Apostolos Chalis 2026 <achalis@csd.auth.gr>
#include "Downloader.hpp"

#include <QDebug> 
#include <QFile>
#include <QString> 
#include <QProcess> 
#include <QTextStream>
#include <QStringList>
#include <QStandardPaths>

QString Downloader::check_package_manager() {
	if (!QStandardPaths::findExecutable("pacman").isEmpty()){
		qDebug() << "Pacman found.";
		return "pacman";
	} else if (!QStandardPaths::findExecutable("apt").isEmpty()) {
		qDebug() << "Apt found.";
		return "apt";
	} else {
		qDebug() << "No supported package manager found.";
		return "Unsupported";
	}
}

bool Downloader::is_in_pacman_repo(const QString &package_name) {
    QProcess process;
    
    process.start("pacman", QStringList() << "-Si" << package_name);
    process.waitForFinished();

    if (process.exitCode() == 0) {
	    qDebug() << "Package" << package_name << "is available in pacman repositories.";
        return true;
    } else {
	    qDebug() << "Package" << package_name << "is NOT available in pacman repositories.";
        return false;
    }
}

QStringList Downloader::read_package_list(bool standard_package_manager, QString package_manager) {
	QStringList installable_with_standard_package_manager; 
	QStringList installable_with_non_standard_package_manager;

	// filtering the packages that can be installed with the standard package manager (etc: apt)
	if (standard_package_manager && package_manager == "pacman") {
		QString filepath_of_list = ":/lists/" + name_of_university + "/" + name_of_department + "/pacman_list.txt";

		qDebug() << "Reading package list from: " << filepath_of_list;
		
		QFile file(filepath_of_list);

		if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            		qDebug() << "Critical Error: Could not open the file!" << file.errorString();
			return installable_with_standard_package_manager;
        	}

		QTextStream in(&file);

    		while (!in.atEnd()) {
        		QString package = in.readLine().trimmed();
        
        		if (!package.isEmpty() && is_in_pacman_repo(package)) {
				qDebug() << "Adding package to installable list: " << package;
            			installable_with_standard_package_manager.append(package);
        		}
    		}
		file.close(); 
		return installable_with_standard_package_manager;
	}

	if (!standard_package_manager && package_manager == "pacman") {
		QString filepath_of_list = ":/lists/" + name_of_university + "/" + name_of_department + "/pacman_list.txt";

		qDebug() << "Reading package list from: " << filepath_of_list;
		
		QFile file(filepath_of_list);

		if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            		qDebug() << "Critical Error: Could not open the file!" << file.errorString();
			return installable_with_non_standard_package_manager;
        	}

		QTextStream in(&file);

    		while (!in.atEnd()) {
        		QString package = in.readLine().trimmed();
        
        		if (!package.isEmpty() && is_in_pacman_repo(package)) {
				qDebug() << "Adding package to installable list: " << package;
            			installable_with_non_standard_package_manager.append(package);
        		}
    		}
		file.close(); 
		return installable_with_non_standard_package_manager; 
	}

	// TODO: Write the same about apt 
}

void Downloader::download_via_pacman(const QStringList &list_to_be_downloaded) {
	if (list_to_be_downloaded.isEmpty()) {
		qDebug() << "Dummy download";
	}
}

void Downloader::download_via_apt(const QStringList &list_to_be_downloaded) {
	if (list_to_be_downloaded.isEmpty()) {
		qDebug() << "Dummy download";
	}
}
