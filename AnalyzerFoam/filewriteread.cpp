#include "filewriteread.h"
#include <iostream>

FileWriteRead::FileWriteRead(QString fileNameTmp, bool rewriteTmp)
{
    this->fileopen = false;
    this->fileName=fileNameTmp;
    this->rewrite=rewriteTmp;


}

FileWriteRead::FileWriteRead()
{
    this->fileopen = false;
    this->fileName="default.txt";
    this->rewrite=false;

}
bool FileWriteRead::isFileOpen()
{
    return this->fileopen;
}

bool FileWriteRead::tryOpen(QString kode)
{
    if (this->fileopen){
        return fileopen;
    }
    else {

        this->fileStream = new QFile (this->fileName);
        if ( (this->fileStream->exists()==false) || this->rewrite == true ){
            this->fileStream->open(QIODevice::WriteOnly);

        }
        else {
            this->fileStream->open(QIODevice::Append);
        }
        this->textStream = new QTextStream (this->fileStream);
        this->textStream->setFieldWidth(10);
        this->textStream->setFieldAlignment(QTextStream::AlignCenter);
        this->code=kode;
        this->textStream->setCodec(this->code.toUtf8().constData());



    }
    this->fileopen = this->fileStream->exists();
    return this->fileopen;

}
bool FileWriteRead::write( QString *data )
{
    if (!this->fileopen){
        return false;

    }
    else{
        *this->textStream << *data;
        return true;

    }

}
bool FileWriteRead::closeAndSave(){
    if (fileopen){
         this->fileopen=false;
         this->fileStream->close();
         deleteThis();
         return true;
     }
return false;

}

bool FileWriteRead::close(){
     if (fileopen){
         deleteThis();
         return true;
     }
     return false;

}


void FileWriteRead::deleteThis(){
    delete this->textStream;
    delete this->fileStream;
    delete this;
}
FileWriteRead *FileWriteRead::changeFile( QString fileName,bool rewrite ){
    if (fileopen){
        this->closeAndSave();
    }
    return  new FileWriteRead ( fileName,rewrite );

}
QString FileWriteRead::read (){
    if (!this->fileopen  )
    {
        this->fileStream = new QFile (this->fileName);
        if (this->fileStream->exists())
        {
            this->textStreamRead.setDevice(this->fileStream);
            return this->textStreamRead.readAll();
        }

    }
    return "";
}

