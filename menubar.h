#ifndef MENUBAR_H
#define MENUBAR_H

#include <QWidget>

class MenuBar : public QWidget
{
  Q_OBJECT
public:
  MenuBar();

public slots:
  void help();
  void about();
  void about_Qt();
};

#endif // MENUBAR_H
