#include "cell.h"
#include <QMouseEvent>
#include <QString>
#include <QStyle>

Cell::Cell(int hazard,
           int state,
           int row,
           int column,
           QWidget *parent) : QPushButton(parent)
{ 
  this->hazard = hazard;
  this->state  = state ;
  this->row    = row   ;
  this->column = column;

  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  setFixedSize(42,42);
  setStyleSheet("background-color: rgb(138, 226, 52)");
}

/*virtual*/
void Cell::mouseReleaseEvent(QMouseEvent *e) {
  int r = getRow();
  int c = getColumn();
  if (e->button() == Qt::LeftButton) emit clicked_left(r,c);
  if (e->button() == Qt::RightButton) emit clicked_right(r,c);
}

/*
*/
int Cell::getRow(){
  return row;
}
int Cell::getColumn(){
  return column;
}
void Cell::setMine(){
  this->hazard = 99;  
}

void Cell::incValue(){
  this->hazard += 1;  
}

int  Cell::getHazard(){
  return hazard;
}

int Cell::resetHazard()
{
  return this->hazard = 0;
}

void Cell::setState(int state){
  this->state = state;
  if (state == 2){            //2-mark
      setStyleSheet("background-color: rgb(100, 0, 250)");
     }
  else if (state == 1){       //1-activated
      setStyleSheet("background-color: rgb(200, 200, 200)");
      if(getHazard() != 99 && getHazard() != 0)
        setText( QString("%1").arg(getHazard() ) );
    }
  else if (state == 0){       //0-wait
      setStyleSheet("background-color: rgb(150, 230, 50)");
    }
}

int Cell::getState(){
  return state;
}
