// Author: Apostolos Chalis 2026 <achalis@csd.auth.gr>
#include "Downloader.hpp"

#include <QDebug> 
#include <QString> 
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
