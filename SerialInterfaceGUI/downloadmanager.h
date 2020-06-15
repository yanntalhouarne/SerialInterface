#ifndef DOWLOADMANAGER_H
#define DOWLOADMANAGER_H

#include <QCoreApplication>
#include <QFile>
#include <QFileInfo>
#include <QList>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QStringList>
#include <QTimer>
#include <QUrl>

#include <QObject>
#include <QDir>

#include "genericdialog.h"

class downloadManager: public QObject
{
    Q_OBJECT

    QNetworkAccessManager manager;
    QNetworkReply * currentDownload = nullptr;

public:
    downloadManager();
    void doDownload(const QUrl &url);
    QString computeFilename(QString basename);
    QString saveFileName(const QUrl &url);
    bool saveToDisk(const QString &filename, QIODevice *data);
    bool getErr();
    QString getFileName();

        QDir curDir;

public slots:
    //void execute();
    void downloadFinished();

signals:
    void finishedSignal();

private:
    void setErr();
    bool downloadManagerErr = 0;
    QDir baseDir;
    QString filename;

    genericDialog * m_genericDialog = nullptr;
};












#endif // DOWLOADMANAGER_H





















