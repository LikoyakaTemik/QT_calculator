#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Send_clicked();

    void on_radioButton_sum_clicked();

    void on_radioButton_vichit_clicked();

    void on_radioButton_umn_clicked();

    void on_radioButton_del_clicked();

    void on_sqr_clicked();

    void on_pow_clicked();

    void on_sin_clicked();

    void on_cos_clicked();

    void on_tg_clicked();

    void on_ctg_clicked();

    void on_arcsin_clicked();

    void on_arccos_clicked();

    void on_arctg_clicked();

    void on_arcctg_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
