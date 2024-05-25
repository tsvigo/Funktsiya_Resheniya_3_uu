#include "dialog.h"
#include "ui_dialog.h"
#include <QFileDialog>
//########################################################################################################
#include <vector>
#include <iostream>

#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <memory> // Для std::unique_ptr
//########################################################################################################
// Реализация make_unique для C++11
namespace std {
    template<typename T, typename... Args>
    std::unique_ptr<T> make_unique(Args&&... args) {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }
}
//########################################################################################################
// Инициализация умного указателя на std::vector<long long>
    std::unique_ptr<std::vector<long long>> list_of_synapses = std::make_unique<std::vector<long long>>();
     std::unique_ptr<std::vector<long long>> list_of_neurons = std::make_unique<std::vector<long long>>();

QString  Nazvaniye_fayla_s_neyronami_i_signalom="";
bool Odin_Uchitelia;
bool Odin_Programmi;
int var ;
//########################################################################################################
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
//########################################################################################################
    std::cout << "Funktsiya_Resheniya_3_uu"<< std::endl;  
//########################################################################################################   
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Открываем файл для решения

   if (Nazvaniye_fayla_s_neyronami_i_signalom=="")
   {
Nazvaniye_fayla_s_neyronami_i_signalom = QFileDialog::getOpenFileName(this,
              tr("Open txt"), "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/", tr("Txt Files (*.txt)"));
   }           
//########################################################################################################
 // Открытие файла для чтения
    QFile file(Nazvaniye_fayla_s_neyronami_i_signalom);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Не удалось открыть файл!";
           }

    // Создание текстового потока для чтения из файла
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        bool ok;
        long long value = line.toLongLong(&ok);
        if (ok) {
            list_of_neurons->push_back(value);
        } else {
            qDebug() << "Не удалось преобразовать строку в число:" << line;
        }
    }

    // Закрытие файла
    file.close();
    
}

Dialog::~Dialog()
{
    delete ui;
}

