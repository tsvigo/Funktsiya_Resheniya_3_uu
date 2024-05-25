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
// читаем нейроны в вектор
 // Открытие файла для чтения
 int chislo_oshibok_neyronov=0;
     std::cout << "читаем нейроны в вектор"<< std::endl;  
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
//            qDebug() << "Не удалось преобразовать строку в число:" << line;
        }
         if (ok) {
//        qDebug() << "Преобразование в long long прошло успешно:";
//        qDebug() << "Значение:" << value;
    } else {
//        qDebug() << "Ошибка преобразования в long long:";
//        qDebug() << "Строка не является числовой, или значение выходит за пределы long long";
          chislo_oshibok_neyronov++;
    }
    }
    // Закрытие файла
    file.close();
      std::cout << "конец чтения нейронов в вектор"<< std::endl;  
        std::cout << "//########################################################################################################"<< std::endl;  
        std::cout << "число ошибок форматов нейронов = "<< chislo_oshibok_neyronov<< std::endl; 
                std::cout << "//########################################################################################################"<< std::endl;   
//########################################################################################################
 // Вывод содержимого вектора
//    for (size_t i = 0; i < list_of_neurons->size(); ++i) {
//        std::cout << "Element " << i << ": " << list_of_neurons->at(i) << std::endl;
//    }
//########################################################################################################
///#################### считываем синасы из файла в вектор #########################################################
 // Открытие файла для чтения
 int chislo_oshibok_sinapsov=0;
   std::cout << "читаем синапсы в вектор"<< std::endl;  
    QFile file2("/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt");
    if (!file2.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Не удалось открыть файл!";
           }

    // Создание текстового потока для чтения из файла
    QTextStream in2(&file2);
    while (!in2.atEnd()) {
        QString line = in2.readLine();
        bool ok;
        long long value = line.toLongLong(&ok);
        if (ok) {
            list_of_synapses->push_back(value);
        } else 
        {
//            qDebug() << "Не удалось преобразовать строку в число:" << line;
        }
         if (ok) {
//        qDebug() << "Преобразование в long long прошло успешно:";
//        qDebug() << "Значение:" << value;
    } else {
//        qDebug() << "Ошибка преобразования в long long:";
//        qDebug() << "Строка не является числовой, или значение выходит за пределы long long";
          chislo_oshibok_sinapsov++;
    }

    }
    // Закрытие файла
    file2.close();
       std::cout << "конец чтения синапсов в вектор"<< std::endl;  
               std::cout << "//########################################################################################################"<< std::endl;  
           std::cout << "число ошибок форматов синапсов = "<< chislo_oshibok_sinapsov<< std::endl;  
                   std::cout << "//########################################################################################################"<< std::endl;  
//########################################################################################################
//########################################################################################################
 // Вывод содержимого вектора
//    for (size_t i = 0; i < list_of_synapses->size(); ++i) {
//        std::cout << "Element " << i << ": " << list_of_synapses->at(i) << std::endl;
//    }
//########################################################################################################
if (chislo_oshibok_sinapsov!=0 || chislo_oshibok_neyronov!=0) // если есть ошибки в форматах синапсов или нейронов останавливаем
// программу
  // Остановить выполнение программы
  {
    exit(EXIT_SUCCESS); 
  std::cout << "Программа остановлена. Ошибки в форматах синапсов или нейронов."<< chislo_oshibok_sinapsov<< std::endl;  
}










//##################### конец ##################################################################################
}

Dialog::~Dialog()
{
    delete ui;
}

