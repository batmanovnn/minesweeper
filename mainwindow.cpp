#include "mainwindow.h"
#include "cell.h"

#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QTime>

class Cell;

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)  
{
  QWidget *widget = new QWidget();
  QVBoxLayout *layout_v = new QVBoxLayout();
  QGridLayout *gameField = new QGridLayout();

  init(gameField);
  resetGame();

  layout_v->addLayout(gameField);
  widget->setLayout(layout_v);

  setCentralWidget(widget);
}


void MainWindow::init(QGridLayout *gameField){
  for (int i=0;i<sizeField;i++) {
      for (int j = 0; j < sizeField; ++j) {
          mass[i][j] = new Cell(0,0,i,j);

          gameField->addWidget(mass[i][j],i,j,1,1);
          connect(mass[i][j], &Cell::clicked_left,  this, &MainWindow::clickedLeft );
          connect(mass[i][j], &Cell::clicked_right, this, &MainWindow::clickedRight);
        }
    }
}


void MainWindow::resetGame(){
  for (int i=0;i<sizeField;i++) {
      for (int j = 0; j < sizeField; ++j) {
          mass[i][j]->setState(0);
          mass[i][j]->resetHazard();
          mass[i][j]->setText("");
      }
   }

  // Seed the random generator with current time
  QTime time = QTime::currentTime();
  qsrand((uint)time.msec());
  for (int k = 0; k < mineNumber;) {
    int i = qrand() % sizeField;
    int j = qrand() % sizeField;
    if (99 == mass[i][j]->getHazard())
      continue;
    else {
      setHazard(i,j);
      ++k;
    }
  }
}


bool MainWindow::isValid(int row, int column) {
  return row >= 0         && column >= 0
      && row <  sizeField && column <  sizeField
      && 99 != mass[row][column]->getHazard();

}


void MainWindow::setHazard(int row, int column){
  mass[row][column]->setMine();  

  int i = row;
  int j = column;
  if (isValid(i  - 1, j - 1)) mass[i - 1][j - 1]->incValue();
  if (isValid(i - 1, j))      mass[i - 1][j]    ->incValue();
  if (isValid(i - 1, j + 1))  mass[i - 1][j + 1]->incValue();
  if (isValid(i, j - 1))      mass[i]    [j - 1]->incValue();
  if (isValid(i, j + 1))      mass[i]    [j + 1]->incValue();
  if (isValid(i + 1, j - 1))  mass[i + 1][j - 1]->incValue();
  if (isValid(i + 1, j))      mass[i + 1][j]    ->incValue();
  if (isValid(i + 1, j + 1))  mass[i + 1][j + 1]->incValue();
}


void MainWindow::clickedRight(int row, int column)
{
  Cell *a = mass[row][column];
  int st = a->getState();

  if(st == 1)               //1-activated
    return;
  else if(st == 0)          //0-wait
    a->setState(2);
  else if(st == 2)          //2-mark
    a->setState(0);
}


void MainWindow::clickedLeft(int row, int column)
{
  //  Alredy open
  if(mass[row][column]->getState() == 1)
    return;

  //  BANG!
  if(mass[row][column]->getHazard() == 99){
    openAll();
    QMessageBox::information(0, "Game over", "! ! ! BANG ! ! !");
    return;
  }

  if(mass[row][column]->getHazard() == 0)
    openZero(row, column);
  else{
      mass[row][column]->setState(1);
      countVictory --;
      openValue(row, column);
    }

  // Win check
  if(countVictory == 0){
    openAll();
    QMessageBox::information(0, "Game over", "You won !");
    }
}


void MainWindow::openZero(int row, int column){
  mass[row][column]->setState(1);
  countVictory --;
  for (int i=row-1; i<row+2; i++) {
      for (int j = column-1; j < column+2; j++) {
          if(isValid(i,j) && mass[i][j]->getState() == 0){
            if(mass[i][j]->getHazard() == 0){
               openZero(i,j);
               }
            else {
                mass[i][j]->setState(1);
                countVictory --;
            }
          }
       }
    }

}

void MainWindow::openValue(int row, int column){
  for (int i=row-1; i<row+2; i++) {
      for (int j = column-1; j < (column+2); j++) {
          if(isValid(i,j) && mass[i][j]->getState() == 0){
            if(mass[i][j]->getHazard() == 0)
               openZero(i,j);
          }
       }
    }
}


void MainWindow::openAll(){
  for (int i=0;i<sizeField;i++) {
      for (int j = 0; j < sizeField; ++j) {
          mass[i][j]->setState(1);
          if(mass[i][j]->getHazard() == 99){
            mass[i][j]->setText("BANG");
            mass[i][j]->setStyleSheet("background-color: rgb(250, 0, 0)");
          }
      }
    }
}

MainWindow::~MainWindow()
{    
}





