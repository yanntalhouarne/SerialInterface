#include "downloadmanager.h"


downloadManager::downloadManager()
{
   baseDir = QDir::current();// get base directory
   m_genericDialog = new genericDialog();
   connect(&manager, &QNetworkAccessManager::finished, this, &downloadManager::downloadFinished);
}

void downloadManager::doDownload(const QUrl &url)
{
    QNetworkRequest request(url);
    currentDownload = manager.get(request);
}

QString downloadManager::computeFilename(QString basename)
{
    if (QFile::exists(basename))
    {
        QByteArray ba = basename.toLocal8Bit();
        QByteArray ba2;
        int i = 0;
        while (i < ba.size())
        {
            if (ba[i] == '.')
            {
                if ((ba[i-3] == '(') && (ba[i-1] == ')'))
                {
                    auto temp = ba[i-2];
                    ba[i-2] = temp+1;
                    basename = ba;
                }
                else
                {
                    // get base name
                    for (int j = 0; j < i; j++)
                        ba2.append(ba[j]);
                    // add nbr
                    ba2.append("(");
                    ba2.append("1");
                    ba2.append(")");
                    while ((ba[i] != char(0x00)) && (i<ba.size()))
                    {
                        ba2.append(ba[i]);
                        i++;
                    }
                    basename = ba2;
                }

                return computeFilename(basename);
                //break;
            } // end of: if (ba[i] == '.')
            i++;
        } // end of: while (i < ba.size())
    }
    else
    {
        return basename;
    }
}

QString downloadManager::saveFileName(const QUrl &url)
{
    QString path = url.path();
    QString basename = QFileInfo(path).fileName();

    if (basename.isEmpty())
        basename = "download";

    // make new bin directory (if it doesn't already exists)
    QDir::setCurrent(baseDir.path());
    curDir.setCurrent("bin");
    if (!curDir.exists())
        baseDir.mkdir("bin");
    QDir::setCurrent(curDir.path());


    basename = computeFilename(basename);


    return basename;
}

bool downloadManager::saveToDisk(const QString &filename, QIODevice *data)
{
    QDir::setCurrent(curDir.path());
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly))
    {
        setErr();
//        fprintf(stderr, "Could not open %s for writing: %s\n",
//                qPrintable(filename),
//                qPrintable(file.errorString()));
//        return false;
    }

    file.write(data->readAll());
    file.close();

    return true;
}

bool downloadManager::getErr()
{
    return downloadManagerErr;
}

QString downloadManager::getFileName()
{
    return filename;
}

void downloadManager::setErr()
{
    downloadManagerErr = true;
}

void downloadManager::downloadFinished()
{
    QUrl url = currentDownload->url();
    if (currentDownload->error())
    {
        setErr();
//        fprintf(stderr, "Download of %s failed: %s\n",
//                url.toEncoded().constData(),
//                qPrintable(reply->errorString()));
    }
    else
    {
        filename = saveFileName(url);
        if (saveToDisk(filename, currentDownload))
        {
//            printf("Download of %s succeded (saved to %s)\n",
//                   url.toEncoded().constData(), qPrintable(filename));
        }
    }

    emit finishedSignal();
}

