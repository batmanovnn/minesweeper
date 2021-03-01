#ifndef CELL_H
#define CELL_H

#include <QWidget>
#include <QPushButton>

class Cell : public QPushButton
{
  Q_OBJECT

  int row;
  int column;
  int hazard = 0;    //level hazard: 0-8; 99-BANG!
  int state  = 0;    //state trigger cell(0-wait;1-activated;2-mark)

public:
  Cell(int hazard, int state, int  row, int column, QWidget *parent = nullptr);
  void setMine();
  void incValue();      //Increase in the value of "hazard" for the cell

  int  getHazard();
  int  resetHazard();

  void setState(int state);
  int  getState();
  int  getRow();
  int  getColumn();
private:


signals:
  void clicked_left(int row, int column);
  void clicked_right(int row, int column);

protected:
  virtual void mouseReleaseEvent(QMouseEvent *e);

};

#endif // CELL_H
