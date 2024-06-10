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
#include <fstream>

#include <iostream>
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
 //   std::unique_ptr<std::vector<long long>> list_of_synapses = std::make_unique<std::vector<long long>>();
     std::unique_ptr<std::vector<long long>> list_of_neurons = std::make_unique<std::vector<long long>>();

//QString  Nazvaniye_fayla_s_neyronami_i_signalom="";
bool Odin_Uchitelia;
bool Odin_Programmi;
int var ;
 int neuron_index = 0, synapse_index = 0;
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
    // Запускаем диалог выбора файла при старте приложения
QString fileName2 = QFileDialog::getOpenFileName(this, tr("Open Text File"),
 "/mnt/6017d124-d970-486e-b68f-59b516dd0511/risunki_Stability_Matrix/chars74k_png_Fnt_Sample1_black-white/300/txt/",
 tr("Text Files (*.txt);;All Files (*)"));
    if (!fileName2.isEmpty()) {
    ;;  //  QMessageBox::information(this, tr("File Selected"), tr("You selected:\n%1").arg(fileName2));
    } else {
    ;;  //  QMessageBox::information(this, tr("No File Selected"), tr("You did not select any file."));
    }

//########################################################################################################
// читаем нейроны в вектор
 // Открытие файла для чтения
 int chislo_oshibok_neyronov=0;
     std::cout << "читаем нейроны в вектор"<< std::endl;  
   // QFile file(Nazvaniye_fayla_s_neyronami_i_signalom);
      QFile file(
            //      "home/viktor/Загрузки/data/none/300/masshtab/black-white/1/neurons_and_signal.txt"
                //  "/home/viktor/neurons_and_signal.txt"
                  fileName2
                  );
      if (!file.exists()) {
          qDebug() << "File does not exist!";
          return;
      }

      if (file.isOpen()) {
          qDebug() << "File was already open!";
          file.close();
      }
//      if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//          qDebug() << "Failed to open the file!";
//          return;
//      }
    ///home/viktor/Загрузки/data/none/300/masshtab/black-white/1/neurons_and_signal.txt
    if (!file.open(QIODevice::ReadOnly// | QIODevice::Text
                   )) {
        qDebug() << "Не удалось открыть файл!";
      //  file.close();
        return;
           }


    // Создание текстового потока для чтения из файла
    QTextStream in(&file);
//###########################################################################

//###########################################################################

    // Читаем первые 201 строку из файла
    int lineCount = 0;
    while (lineCount < 201 && !in.atEnd()) {
        QString line = in.readLine();
        if (line.trimmed().isEmpty()) {
            std::cerr << "Line " << (lineCount + 1) << " is empty, skipping." << std::endl;
            continue;  // Пропускаем пустые строки
        }

        bool ok;
        long long number = line.toLongLong(&ok);
        if (ok) {
            list_of_neurons->push_back(number);
            ++lineCount;  // Увеличиваем счетчик только при успешной конвертации
        } else {
            std::cerr << "Failed to convert line " << (lineCount + 1) << " to number: " << qPrintable(line) << std::endl;
        }
    }

    // Закрываем файл
    file.close();

    // Проверка, что удалось прочитать ровно 201 непустую строку
    if (lineCount != 201) {
        std::cerr << "Error: Only " << lineCount << " valid lines were read from the file." << std::endl;
     //   return 1;
    }
//###########################################################################
      std::cout << "конец чтения нейронов в вектор"<< std::endl;  
   //     std::cout << "//########################################################################################################"<< std::endl;
        std::cout << "число ошибок форматов нейронов = "<< chislo_oshibok_neyronov<< std::endl; 
    std::cout << "//########################################################################################################"<< std::endl;
//########################################################################################################
//########################################################################################################
///#################### считываем синапсы из файла в вектор #########################################################
 // Открытие файла для чтения
   std::cout << "читаем синапсы в вектор"<< std::endl;  
   ///////////////////////////////////// загрузка синапсов из файла в вектор
                          std::ifstream is("/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt");
                           std::istream_iterator<unsigned long long> start(is), end;
                           std::vector<unsigned long long> list_of_synapses(start, end);
                           std::cout << "Read " << list_of_synapses.size() << " numbers" << std::endl;
//###########################################################################
/////###########################################################################
       std::cout << "конец чтения синапсов в вектор"<< std::endl;  
 //      std::cout << "//########################################################################################################"<< std::endl;

  std::cout << "//########################################################################################################"<< std::endl;
//########################################################################################################
  /////////////   показываем что определила программа
//      if
//        //  ( variable_error <=0)
//          (list_of_neurons->at(200)<0)

//      {
//          ui->label->setText("Программа считает что это 1.");
//        std::cout << "list_of_neurons->at(200) = "<< list_of_neurons->at(200)<< std::endl;
//         // Odin_Programmi=true;
//           //  goto d;
//      }
//                             else {
//          ui->label->setText("Программа считает что это не 1.");
//          std::cout << "list_of_neurons->at(200) = "<< list_of_neurons->at(200)<< std::endl;
//     //     goto d;
//          //  Odin_Programmi=false;

//      }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//########################################################################################################
//########################################################################################################             
// блок вычисления-решения 200 нейрона
//###########################################################################//###########################################################################
//###########################################################################//###########################################################################
// проверка - решение
      // если программа тут считает то 200 нейрон получается другой
for ( var = 100;              // первый for
var < 200

 ; ++var) // This is the range of neurons

{
//    if (list_of_neurons->at(200)<0) break;
    for ( neuron_index = 0, synapse_index = 0;

      /*,*/ synapse_index < 10100;
        ++neuron_index, synapse_index = synapse_index + 100)

    { // // ошибка сегментации

 //if (synapse_index>10100 )
    if (neuron_index < 200//&& synapse_index<200
            )

        list_of_neurons->at(var)
//###########################################################################
                =
                list_of_neurons->at(var) //-5310911
        +
                (
                (list_of_neurons->at(neuron_index)
          //  /   // деление
                 -
         list_of_synapses.at(synapse_index))
                    )
                    ; // + на -

    } //
  //  if       (list_of_neurons->at(200)<0) goto d;
}
//////////////////////
for (int   neuron_index = 100, synapse_index = 10000;       // второй for

synapse_index < 10100
;
  ++neuron_index, ++synapse_index)
{

//      if (list_of_synapses->at(synapse_index)!=0)
    list_of_neurons->at(200)
//###########################################################################
            =
            list_of_neurons->at(200) //-5310911
    +
            (
            (list_of_neurons->at(neuron_index)
           //  / // деление
             -
             list_of_synapses.at(synapse_index))
                )
    ; // + на -
//if       (list_of_neurons->at(200)<0) goto d;
//   std::cout << "list_of_neurons->at(200)= "  <<list_of_neurons->at(200)  <<std::endl;
}

//###########################################################################
//###########################################################################
//########################################################################################################
/////////////   показываем что определила программа
    if 
      //  ( variable_error <=0)
        (list_of_neurons->at(200)<0)

    {
    ui->label->setText("Программа считает что это 1.");
        std::cout <<"Программа считает что это 1."   <<std::endl;
        Odin_Programmi=true;
        // std::cout << "Программа остановлена. Ошибки в форматах синапсов или нейронов."<< std::endl;  
    }
                  //         else
                      if   (list_of_neurons->at(200)>=0)
                            {
      ui->label->setText("Программа считает что это не 1.");
         std::cout <<"Программа считает что это не 1."   <<std::endl;
          Odin_Programmi=false;
    }
//########################################################################################################
 std::cout << "240 строка (после решения): list_of_neurons->at(200) = "<< list_of_neurons->at(200)<< std::endl;






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
          
"/home/viktor/my_projects_qt_2_build/build-cycle_of_distinguishing_a_one_with_vectors_GUI_2_uu-Desktop_Qt_5_12_12_GCC_64bit-Release/cycle_of_distinguishing_a_one_with_vectors_GUI_2_uu"
                                , qApp->arguments());  
//   qApp->quit();
    }
    else // Если не распознана не 1:
    {
        Odin_Uchitelia=false;  ui->label_2->setText ("Odin_Programmi==true; Odin_Uchitelia=false");
        // bez_1
        QProcess::startDetached(

           "/home/viktor/my_projects_qt_2_build/build-bez_1_GUI_3_uu-Desktop_Qt_5_12_12_GCC_64bit-Release/bez_1_GUI_3_uu"
            , qApp->arguments());  
 //          qApp->quit();
    } 
}

