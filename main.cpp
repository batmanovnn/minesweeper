#include "mainwindow.h"
#include "menubar.h"

#include <QApplication>
#include <QObject>
#include <QAction>
#include <QMenuBar>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  mBar m;
  w.setWindowTitle("Minesweeper");

  QMenuBar *menuBar;            // Menu
  menuBar = w.menuBar();
  //New
  QAction *newAct = new QAction(QObject::tr("&New"), &w);
  QObject::connect(newAct, &QAction::triggered,
                   &w, &MainWindow::resetGame);
  menuBar->addAction(newAct);
  //Help
  QAction *helpAct = new QAction(QObject::tr("&Help"), &w);
  QObject::connect(helpAct, &QAction::triggered,
                  &m, &mBar::on_actionhelp_triggered);
  menuBar->addAction(helpAct);
  //about
  QAction *aboutAct = new QAction(QObject::tr("&about"), &w);
  QObject::connect(aboutAct, &QAction::triggered,
                  &m, &mBar::on_action_about);
  menuBar->addAction(aboutAct);
  //about_Qt
  QAction *aboutQtAct = new QAction(QObject::tr("&about Qt"), &w);
  QObject::connect(aboutQtAct, &QAction::triggered,
                  &m, &mBar::on_actionabout_Qt_triggered);
  menuBar->addAction(aboutQtAct);

  w.show();
  return a.exec();
}
