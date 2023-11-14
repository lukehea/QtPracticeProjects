#ifndef TEXTFINDER_H
#define TEXTFINDER_H

#include <QMainWindow>
#include <QIODevice>
#include <QFile>
#include <QTextStream>

#include "./ui_textfinder.h"


QT_BEGIN_NAMESPACE
namespace Ui { class TextFinder; }
QT_END_NAMESPACE

class TextFinder : public QMainWindow
{
    Q_OBJECT

public:
    TextFinder(QWidget *parent = nullptr);
    ~TextFinder();

private slots:
    void on_findButton_clicked();

private:
    Ui::TextFinder *ui;
    void loadTextFile();
};
#endif // TEXTFINDER_H
