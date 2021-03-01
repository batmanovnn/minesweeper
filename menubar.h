#ifndef MENUBAR_H
#define MENUBAR_H

#include <QWidget>

class mBar : public QWidget
{
  Q_OBJECT
public:
  mBar();

public slots:
  void on_actionhelp_triggered();
  void on_action_about();
  void on_actionabout_Qt_triggered();
};

#endif // MENUBAR_H
