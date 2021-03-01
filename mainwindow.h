#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QGridLayout>
#include "cell.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  //Field of size///
  const static int sizeField  = 16;
  const static int mineNumber = 40;
  //Massive of cell
  Cell *mass[sizeField][sizeField];


signals:
  void signalFromButton(int buttonID);    // Signal to transmit the number
                                          //         of the pressed button

public slots:
    void init(QGridLayout *gameField);    // Create GameField
    void resetGame();                     //Generation cells with mines
protected:
  int countVictory = sizeField * sizeField - mineNumber;

  bool isValid(int i, int j);             //Checking the boundaries
  void setHazard(int row, int column);    //set level hazard for cell
  void openZero(int row, int column);     //open cell with zero hazard
  void openValue(int row, int column);    //open cell other
  void openAll();                         //Game over

private slots:
  void clickedLeft(int row, int column);
  void clickedRight(int row, int column);

private:
  Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
