/*** includes ***/
// #include "includes.h"
// #include <unistd.h>
#include "btui/includes/BTUI.h"
/*** defines ***/
// #define CTRL_KEY(k) ((k) & 0x1f)
/*** init ***/
using enum Color;
int main() {
  BTUI tui;
  BTUI::setClr(Clr(green));
  tui.enableRaw();
  while (true) {
    tui.initUI();
    BTUI::refreshScreen();
    tui.p_drawBox();
    BTUI::processKeypress();
  }
}