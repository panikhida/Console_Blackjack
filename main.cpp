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
  // BTUI::setClr(Clr(green));
  tui.enableRaw();
  tui.initUI();
  while (true) {
    tui.p_drawBox();


    if (tui.needRender) tui.renderUi();
    tui.processKeypress();
  }
}