/*** includes ***/
#include "game.h"
/*** init ***/
using enum Color;
int main() {
  BTUI tui;
  tui.enableRaw();
  tui.initUI();
  tui.setPaint(tui.p_curr);

  while (true) {
    tui.checkSize();
    if (tui.needRender) tui.renderUi();
    tui.processKeypress();
  }
}