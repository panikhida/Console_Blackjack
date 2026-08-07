/*** includes ***/
#include "game.h"
#include "btui/includes/BTUI.h"
/*** defines ***/
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