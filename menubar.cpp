#include "menubar.h"

#include <QMessageBox>

MenuBar::MenuBar(){}

void MenuBar::help()
{

    QMessageBox::about(this, tr("Game rules"),tr(

    "<p>The game begins with the board covered in tiles. Click on any tile to uncover it.</p>"
    "<p>You will reveal:</p>"
    "<p>A colored number, which represent the number of mines in the adjacent tiles. "
    "This will help you deduce where the mines are so that you can mark them with flags."
    "A blank tile, which means there are no mines under any of the adjacent tiles.</p>"
    "<p>A mine, which will detonate and end the game.</p>"
    "<p>Repeat the previous step until you have uncovered all the tiles which do not have mines underneath them. </p>"


    "<p>Copyright &copy; 2021 Batmanov Nikolay</p>"
    "<p>BatmanoNN@gmail.com</p>"

       "<p>  LGPLv3 GNU GENERAL PUBLIC LICENSE Version 3</p>"
       //QUrl url("https://www.gnu.org/licenses/gpl-3.0.txt");
                                                )
                       );
}

void MenuBar::about()
{
  QMessageBox::about(this, tr("Game rules"),tr(
  "<h2>Minesweeper v0.21b</h2>"

  "<p>Copyright &copy; 2021 Batmanov Nikolay</p>"
  "<p>BatmanoNN@gmail.com</p>"

     "<p>  LGPLv3 GNU GENERAL PUBLIC LICENSE Version 3</p>"
     //QUrl url("https://www.gnu.org/licenses/gpl-3.0.txt");
  ));
}

void MenuBar::about_Qt()
{
     QMessageBox::aboutQt(this);
}
