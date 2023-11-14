#include "textfinder.h"

TextFinder::TextFinder(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextFinder)
{
    ui->setupUi(this);
    loadTextFile();
}

TextFinder::~TextFinder()
{
    delete ui;
}


void TextFinder::on_findButton_clicked()
{
    QString stringToSearch = ui->lineEdit->text();
    ui->textEdit->find(stringToSearch, QTextDocument::FindWholeWords);
}

void TextFinder::loadTextFile()
{
    QFile inputFile(":/input.txt");
    inputFile.open(QIODevice::ReadOnly);

    QTextStream inStream(&inputFile);
    QString fileLine = inStream.readAll();
    inputFile.close();

    ui->textEdit->setPlainText(fileLine);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}
