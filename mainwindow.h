#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QGridLayout>
#include "cell.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT

  //Field of size///
  const static int sizeField  = 16;
  const static int mineNumber = 40;
  int countVictory = sizeField * sizeField - mineNumber;
  //Massive of cell
  Cell *mass[sizeField][sizeField];


public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  bool isValid(int i, int j);             //Checking the boundaries
  void setHazard(int row, int column);    //set level hazard for cell
  void openZero(int row, int column);     //open cell with zero hazard
  void openValue(int row, int column);    //open cell other
  void openAll();                         //Game over

public slots:
  void resetGame();                     //Generation cells with mines

private slots:
  void init(QGridLayout *gameField);    // Create GameField

  void clickedLeft(int row, int column);
  void clickedRight(int row, int column);

};

#endif // MAINWINDOW_H
