#ifndef FILEWRITEREAD_H
#define FILEWRITEREAD_H

#include <QFile>
#include <QTextStream>

class FileWriteRead
{
public:
    FileWriteRead(QString fileName, bool rewrite);
     FileWriteRead();

    bool isFileOpen();
    bool tryOpen(QString kode);
    bool write( QString *data ); // QObject ??
    bool closeAndSave(); // delete this ?
    bool close(); // delete this ?
    FileWriteRead *changeFile( QString fileName,bool rewrite );

    QString read (); // Qstring? , return all file, don't tested

public:
    QString fileName;


private:
    void deleteThis();
    bool fileopen;
    bool rewrite;
    QFile *fileStream;
    QTextStream *textStream;
    QTextStream textStreamRead;
    QString code;


};

#endif // FILEWRITEREAD_H
