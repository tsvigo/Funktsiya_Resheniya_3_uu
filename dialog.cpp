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
#include <QProcess>
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
      qDebug() << "Строка не является числовой, или значение выходит за пределы long long: "<< line ;
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
  std::cout << "Программа остановлена. Ошибки в форматах синапсов или нейронов."<< std::endl;  
}
//########################################################################################################
//########################################################################################################             
// блок вычисления-решения 200 нейрона
   for ( var = 100; var < 200; ++var) // This is the range of neurons
    {
        for (int neuron_index = 0, synapse_index = 0;   neuron_index < 200, synapse_index < 10100;   ++neuron_index, synapse_index = synapse_index + 100)

        {
 // list_of_synapses->at(i)
list_of_neurons->at(var)=list_of_neurons->at(var)+  (list_of_neurons->at(neuron_index)/ list_of_synapses->at(synapse_index)); 

//              });
        } // вычитаем нейроны
    }
//########################################################################################################
    for (int   neuron_index = 100, synapse_index = 10000; neuron_index < 200;   ++neuron_index, ++synapse_index)
    {

  // list_of_neurons[200] = list_of_neurons[200] + (list_of_neurons[neuron_index] / list_of_synapses[synapse_index]); // + на -
list_of_neurons->at(200)=list_of_neurons->at(200)+  (list_of_neurons->at(neuron_index)/ list_of_synapses->at(synapse_index)); 
    }
//########################################################################################################
/////////////   показываем что определила программа
    if 
      //  ( variable_error <=0)
        (list_of_neurons->at(200)<0)

    {
        ui->label->setText(Nazvaniye_fayla_s_neyronami_i_signalom+"\n"+"Программа считает что это 1.");
        Odin_Programmi=true;
        // std::cout << "Программа остановлена. Ошибки в форматах синапсов или нейронов."<< std::endl;  
    }
                  //         else
                      if   (list_of_neurons->at(200)>=0)
                            {
        ui->label->setText(Nazvaniye_fayla_s_neyronami_i_signalom+"\n"+"Программа считает что это не 1.");
          Odin_Programmi=false;
    }
//########################################################################################################
 std::cout << "list_of_neurons->at(200) = "<< list_of_neurons->at(200)<< std::endl;  






//##################### конец ##################################################################################
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    // выбор программы обучения:
    if ( Odin_Programmi==false) // Если не распознана 1:
    {
        Odin_Uchitelia=true; ui->label_2->setText ("Odin_Programmi==false; Odin_Uchitelia=true");
        // cycle_of_distinguishing_a_one_with_vectors_GUI
        QProcess::startDetached(
          
"/home/viktor/my_projects_qt_2_build/build-cycle_of_distinguishing_a_one_with_vectors_GUI_3-Desktop_Qt_5_12_12_GCC_64bit-Debug/cycle_of_distinguishing_a_one_with_vectors_GUI_3"
                                , qApp->arguments());  
//   qApp->quit();
    }
    else // Если не распознана не 1:
    {
        Odin_Uchitelia=false;  ui->label_2->setText ("Odin_Programmi==true; Odin_Uchitelia=false");
        // bez_1
        QProcess::startDetached(

           "/home/viktor/my_projects_qt_2_build/build-bez_1_GUI_3-Desktop_Qt_5_12_12_GCC_64bit-Release/bez_1_GUI_3"
            , qApp->arguments());  
 //          qApp->quit();
    } 
}

