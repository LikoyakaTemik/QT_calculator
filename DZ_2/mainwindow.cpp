#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <cmath>

#ifdef M_PI
double const pi = M_PI;
#else
double const pi = 4*std::atan(1);
#endif


MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->label_result_value->setText("");
    ui->label_error->setText("");
    on_radioButton_sum_clicked();
    ui->radioButton_sum->setChecked(true);

    this->setStyleSheet("background-color: pink");
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool INT(QString str,bool &flag, double num){
    double ch = str.toInt(&flag, num);
    if(!flag){
        return false;
    }else{
        return true;
    }
}

bool DOUBLE(QString str,bool &flag){
    double ch = str.toDouble(&flag);
    if(!flag){
        return false;
    }else{
        return true;
    }
}

void MainWindow::on_Send_clicked()
{

    QString ch_str;
    double ch1, ch2, answer;
    ch1 = 0;
    ch2 = 0;
    bool flag;
    bool flag_ch1 = true;
    bool flag_ch2 = true;
    bool fin_flag = true;

    if(DOUBLE(ui->cin1->text(), flag)){
        ch1 = ui->cin1->text().toDouble(&flag);
    }else{
        flag_ch1 = false;
    }

    if(DOUBLE(ui->cin2->text(), flag)){
        ch2 = ui->cin2->text().toDouble(&flag);
    }else if(ui->radioButton_vichit->isChecked() || ui->radioButton_umn->isChecked() || ui->radioButton_sum->isChecked() || ui->radioButton_del->isChecked() || ui->sqr->isChecked() || ui->pow->isChecked()){
        flag_ch2 = false;
    }

    if(flag_ch1 == true && flag_ch2 == true){
        if(ui->radioButton_sum->isChecked()){
            answer = ch1 + ch2;
        }else if(ui->radioButton_vichit->isChecked()){
            answer = ch1 - ch2;
        }else if(ui->radioButton_umn->isChecked()){
            answer = ch1 * ch2;
        }else if(ui->radioButton_del->isChecked()){
            answer = ch1 / ch2;
        }else if(ui->sqr->isChecked()){
            answer = pow(ch1, pow(ch2, -1));
        }else if(ui->pow->isChecked()){
            answer = pow(ch1, ch2);
        }else if(ui->sin->isChecked()){
            answer = sin(ch1/57.2956);
        }else if(ui->cos->isChecked()){;
            answer = cos(ch1/57.2956);
        }else if(ui->tg->isChecked()){
            answer = sin(ch1 /57.2956) / cos(ch1 /57.2956);
        }else if(ui->ctg->isChecked()){
            answer = cos(ch1 /57.2956) / sin(ch1 /57.2956);
        }else if(ui->arcsin->isChecked()){
            answer = asin(ch1) * 180 / pi;
        }else if(ui->arccos->isChecked()){
            answer = acos(ch1) * 180 / pi;
        }else if(ui->arctg->isChecked()){
            answer = atan(ch1) * 180 / pi;
        }else if(ui->arcctg->isChecked()){
            answer = (pi/2 - atan(ch1)) * 180 / pi;
        }
    }else{
        fin_flag = false;
    }



    if(fin_flag){
        QString strr;
        strr = strr.setNum(answer,'f',4);
        ui->label_result_value->setText(strr);
    }else{

        ui->label_result_value->setText("НКД");
    }


}

void MainWindow::on_radioButton_umn_clicked()
{
    ui->label_5->setText("Множитель2");
    ui->label_4->setText("Множитель1");
    ui->label_2->setText("Произведение");
}

void MainWindow::on_radioButton_del_clicked()
{
    ui->label_5->setText("Делитель");
    ui->label_4->setText("Делимое");
    ui->label_2->setText("Результат");
}

void MainWindow::on_radioButton_vichit_clicked()
{
    ui->label_5->setText("Вычитаемое");
    ui->label_4->setText("Уменьшаемое");
    ui->label_2->setText("Разность");
}

void MainWindow::on_radioButton_sum_clicked()
{
    ui->label_2->setText("Сумма");
}

void MainWindow::on_sqr_clicked()
{
    ui->cin2->setVisible(true);
    ui->label_5->setText("Степень корня");
    ui->label_4->setText("Число");
    ui->label_2->setText("Результат");
    ui->cin2->clear();
}

void MainWindow::on_pow_clicked()
{
    ui->cin2->setVisible(true);
    ui->label_5->setText("Степень");
    ui->label_4->setText("Число");
    ui->label_2->setText("Результат");
    ui->cin2->clear();
}

void MainWindow::on_sin_clicked()
{
    ui->label_4->setText("Угол в градусах");
    ui->cin2->setVisible(false);
    ui->label_2->setText("Результат");
    ui->label_5->setText("");
}

void MainWindow::on_cos_clicked()
{
    ui->label_4->setText("Угол в градусах");
    ui->cin2->setVisible(false);
    ui->label_5->setText("");
    ui->label_2->setText("Результат");
}

void MainWindow::on_tg_clicked()
{
    ui->label_4->setText("Угол в градусах");
    ui->cin2->setVisible(false);
    ui->label_5->setText("");
    ui->label_2->setText("Результат");
}

void MainWindow::on_ctg_clicked()
{
    ui->label_4->setText("Угол в градусах");
    ui->cin2->setVisible(false);
    ui->label_2->setText("Результат");
    ui->label_5->setText("");
}

void MainWindow::on_arcsin_clicked()
{
    ui->label_4->setText("Синус");
    ui->cin2->setVisible(false);
    ui->label_5->setText("");
    ui->label_2->setText("Результат");
}

void MainWindow::on_arccos_clicked()
{
 ui->label_4->setText("Косинус");
 ui->cin2->setVisible(false);
 ui->label_2->setText("Результат");
 ui->label_5->setText("");
}

void MainWindow::on_arctg_clicked()
{
    ui->label_4->setText("Тангенс");
    ui->label_2->setText("Результат");
    ui->cin2->setVisible(false);
    ui->label_5->setText("");
}

void MainWindow::on_arcctg_clicked()
{
    ui->label_4->setText("Котангенс");
 ui->cin2->setVisible(false);
 ui->label_2->setText("Результат");
 ui->label_5->setText("");
}
