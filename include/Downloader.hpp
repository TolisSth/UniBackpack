// Author: Apostolos Chalis 2026 <achalis@csd.auth.gr>
#ifndef DOWNLOADER_HPP
#define DOWNLOADER_HPP

#include <QObject>
#include <QString>
#include <QDebug>

class Downloader : public QObject {
	Q_OBJECT

	private:
		QString name_of_university;
		QString name_of_department;

	public:
		explicit Downloader(const QString &university, const QString &department, QObject *parent = nullptr)
			: QObject(parent), name_of_university(university), name_of_department(department) {}

		QString check_package_manager();
		void download_pacman();
		void download_apt();

	signals:
		void progress_updated(int percentage);
		void status_message(const QString &message);
		void download_completed(bool success);
};

#endif // DOWNLOADER_HPP
