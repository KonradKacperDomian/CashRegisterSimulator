#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <qlineedit.h>
#include "../core/ProductListManager.h"
#include <QApplication>
#include <QInputDialog>
#include <QDate>
#include <QMessageBox>




MainWindow::MainWindow(DailyRaport &dailyRaport, ProductListManager &productList, QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),VectorOfProducts(productList), dailyRap(dailyRaport)
{
    ui->setupUi(this);
    creatActions(dailyRaport,productList);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printBill()
{
    QMessageBox msgBox;
    msgBox.setText("You choose print a Bill");
    msgBox.setInformativeText("Do you want print a Bill?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int ret = msgBox.exec();

    if (ret == QMessageBox::Yes)
    {
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->listWidget->clear();
        bill.printBillForCustomer();
        dailyRap.addData(bill);
        showBillsList();
    }
   
}


void MainWindow::addProductToBill()
{
    QMessageBox msgBox;
    QLineEdit line;
    msgBox.setText("You choose add Product to Bill");
    msgBox.setInformativeText("Do you want add Product to Bill?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int ret = msgBox.exec();

    if (ret == QMessageBox::Yes)
    {
        bool ok;
        QString text = QInputDialog::getText(0, "Input dialog",
            "Code of Product:", QLineEdit::Normal,
            "", &ok);
        if (ok && !text.isEmpty()) {
            ProductListManager productList;
            if (productList.findProduct(text.toInt()))
            {
                QString text1 = QInputDialog::getText(0, "Input dialog",
                    "How much?", QLineEdit::Normal,
                    "", &ok);
                bill.addProductToBill(text.toInt(), text1.toInt());
                ui->listWidget->clear();
                QListWidgetItem* newItem = new QListWidgetItem;
                newItem->setText(QString::fromStdString( bill.displayRekordOfBill()));
                ui->listWidget->insertItem(1, newItem);
                
            }
        }
    }
   
}

void MainWindow::replacement()
{
    bool ok;
    QString text = QInputDialog::getText(0, "Input dialog",
        "Code of Product:", QLineEdit::Normal,
        "", &ok);
    if (ok && !text.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setText("Do you want remove");
        msgBox.setInformativeText(QString::fromStdString(dailyRap.showOneBill(text.toInt()-1)));
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        int ret = msgBox.exec();
        if (ret == QMessageBox::Yes)
        {
            dailyRap.removeData(text.toInt() );
            showBillsList();
        }
            
    }
    
}
void MainWindow::exit()
{
    close();
}


void MainWindow::showBillsList()
{
    ui->listWidget_3->clear();
    for (int element = 0; element < dailyRap.numberOfBills(); element++)
    {
        if (dailyRap.showOneBill(element)[13] != '0')
        {
            QListWidgetItem* newItem = new QListWidgetItem;
            newItem->setText(QString::fromStdString(dailyRap.showOneBill(element)));
            ui->listWidget_3->insertItem(1, newItem);
        }
        
    }
    ui->listWidget_3->sortItems(Qt::AscendingOrder);
}

void MainWindow::productListManadzer(ProductListManager& productList)
{
    ui->listWidget_2->clear();
    for (int element=0; element<productList.numberOfProducts(); element++)
    {
        QListWidgetItem* newItem = new QListWidgetItem;
        if (productList.displayOneProduct(element)[0] != '0')
        {
            newItem->setText(QString::fromStdString(productList.displayOneProduct(element)));
            ui->listWidget_2->insertItem(1, newItem);
        }
        
    }
    ui->listWidget_2->sortItems(Qt::AscendingOrder);
}

void MainWindow::addProductToListProduct()
{
    char PTU;
    std::string productName;
    double price;

    bool ok;
    QString text = QInputDialog::getText(0, "Input dialog",
        "Type Product Name", QLineEdit::Normal,
        "", &ok);
    if (ok && !text.isEmpty()) {
        productName = text.toStdString();
        QString text1 = QInputDialog::getText(0, "Input dialog",
            "Type PTU", QLineEdit::Normal,
            "", &ok);
        if (ok && !text.isEmpty())
        {
            PTU = text1.toStdString()[0];
            QString text3 = QInputDialog::getText(0, "Input dialog",
                "Type Product Price", QLineEdit::Normal,
                "", &ok);
            if (ok && !text.isEmpty())
            {
                price = text3.toDouble();
                VectorOfProducts.addProductToList(price, PTU, productName);
            }
            
        }
        

        productListManadzer(VectorOfProducts);
    }
}

void MainWindow::removeProductFromList()
{
    bool ok;
    QString text = QInputDialog::getText(0, "Input dialog",
        "Type Product ID", QLineEdit::Normal,
        "", &ok);
    if (ok && !text.isEmpty()) {
        if (VectorOfProducts.findProduct(text.toInt()-1))
        {
            QMessageBox msgBox;
            msgBox.setText("Do you want remove");
            msgBox.setInformativeText("ID   Price   PTU    Name\n"+QString::fromStdString( VectorOfProducts.displayOneProduct(text.toInt()-1))); 
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Yes);
            int ret = msgBox.exec();

            if (ret == QMessageBox::Yes)
            {
                VectorOfProducts.removeProductFromList(text.toInt());
                productListManadzer(VectorOfProducts);
            }
        }
    }
}

void MainWindow::creatActions(DailyRaport& dailyRaport, ProductListManager& productList1)
{
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    productListManadzer(productList1);
    showBillsList();
    connect(ui->pushButton, SIGNAL(released()), this, SLOT(newBill()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(addProductToBill()));
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(printBill()));
    connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(replacement()));
    connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(addProductToListProduct()));
    connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(removeProductFromList()));
    connect(ui->actionQuit, &QAction::triggered, this, &MainWindow::exit);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
}

void MainWindow::about()
{
    QMessageBox msgBox;
    msgBox.setText("The program has been written by Konrad Domian");
    msgBox.setInformativeText("For PROE project II");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}

void MainWindow::newBill()
{
    QMessageBox msgBox;
    msgBox.setText("You choose New Bill");
    msgBox.setInformativeText("Do you want make new acount");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int ret = msgBox.exec();

    if (ret == QMessageBox::Yes)
    {
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        static int j = 1;
        Bill newBill(j++);
        bill = newBill;
    }
}




