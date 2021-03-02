#ifndef MENUBAR_H
#define MENUBAR_H

#include <QWidget>

class mBar : public QWidget
{
  Q_OBJECT
public:
  mBar();

public slots:
  void help();
  void about();
  void about_Qt();
};

#endif // MENUBAR_H
