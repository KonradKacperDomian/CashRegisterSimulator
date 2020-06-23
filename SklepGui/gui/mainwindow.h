#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "core/ProductListManager.h"
#include "core/DailyRaport.h"
#include "core/Bill.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(DailyRaport&, ProductListManager&, QWidget *parent = nullptr);
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    //void quit();
    void removeProductFromList();
    void newBill();
    void printBill();
    void addProductToBill();
    void replacement();
    void exit();
    //void checkId();
    void showBillsList();
    void productListManadzer(ProductListManager& productList);
    void addProductToListProduct();
    void about();
    //void listItemDoubleClicked(QWidgetItem* item);


private:
    Ui::MainWindow *ui;
    void creatActions(DailyRaport& dailyRaport, ProductListManager& productList);
    
    DailyRaport newDailyRaport;
    ProductListManager &VectorOfProducts;
    DailyRaport& dailyRap;
    Bill bill;
};
#endif // MAINWINDOW_H
