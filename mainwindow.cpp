#include "mainwindow.h"
#include "ui_mainwindow.h"


double num_first;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Calculator");
    setWindowOpacity(0.98);
    setMinimumSize(243, 366);
    setMaximumSize(243, 366);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_change,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_percent,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_division,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_multiple,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_subtraction,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_back_space,SIGNAL(clicked()),this,SLOT(back_space()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_division->setCheckable(true);
    ui->pushButton_subtraction->setCheckable(true);
    ui->pushButton_multiple->setCheckable(true);
    ui->pushButton_back_space->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *) sender();
    QString new_label;

    if(ui->show_result->text().contains(".") && button->text() == "0")
    {
        new_label = ui->show_result->text() + button->text();
    } else {

    double all_numbers;
    all_numbers = (ui->show_result->text() + button->text()).toDouble();
    new_label = QString::number(all_numbers,'g', 15); }
    ui->show_result->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->show_result->text().contains('.')))
    ui->show_result->setText(ui->show_result->text() + ".");
}

void MainWindow::back_space() {
    int length = ui->show_result->text().length();
    if (length) {
        char last_char = ui->show_result->text().at(length - 1).toLatin1();
        if (!std::isdigit(last_char))
            ui->show_result->setText("0");
        ui->show_result->setText(ui->show_result->text().left(length - 1));
    }
}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton *) sender();
    QString new_label;

    double all_numbers;
    if(button->text() == "+/-")
    {
        all_numbers = (ui->show_result->text()).toDouble();
        all_numbers = all_numbers * -1;
        new_label = QString::number(all_numbers,'g', 15);
        ui->show_result->setText(new_label);
    }
    else if(button->text() == "%")
    {
        all_numbers = (ui->show_result->text()).toDouble();
        all_numbers = all_numbers * 0.01;
        new_label = QString::number(all_numbers,'g', 15);
        ui->show_result->setText(new_label);
    }
}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *) sender();

    num_first = ui->show_result->text().toDouble();
    ui->show_result->setText("");
    button->setChecked(true);
}


void MainWindow::on_pushButton_clean_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_division->setChecked(false);
    ui->pushButton_subtraction->setChecked(false);
    ui->pushButton_multiple->setChecked(false);

    ui->show_result->setText("0");
}

void MainWindow::on_pushButton_equally_clicked()
{
    double labelNumber, num_second;
    QString new_label;

    num_second = ui->show_result->text().toDouble();

    if(ui->pushButton_plus->isChecked()) {
        labelNumber = num_first + num_second;
        new_label = QString::number(labelNumber,'g', 15);
        ui->show_result->setText(new_label);
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_division->isChecked()){
        if(num_second == 0){
            ui->show_result->setText("0");
        } else {
            labelNumber = num_first / num_second;
            new_label = QString::number(labelNumber,'g', 15);
            ui->show_result->setText(new_label); }

        ui->pushButton_division->setChecked(false);
    }
    else if(ui->pushButton_multiple->isChecked()){
        labelNumber = num_first * num_second;
        new_label = QString::number(labelNumber,'g', 15);
        ui->show_result->setText(new_label);
        ui->pushButton_multiple->setChecked(false);
    }
    else if(ui->pushButton_subtraction->isChecked()){
        labelNumber = num_first - num_second;
        new_label = QString::number(labelNumber,'g', 15);
        ui->show_result->setText(new_label);
        ui->pushButton_subtraction->setChecked(false);
    }
}
