/*** includes ***/
#include "btui/includes/BTUI.h"
/*** init ***/
using enum Color;

int main() {
  BTUI tui;
  BJ game;

  tui.enableRaw();
  tui.initUI();
  tui.setPaint(tui.p_curr);
  game.initBlackJack();
  tui.linkGame(&game);
  while (true) {
    tui.checkSize();
    if (tui.needRender) tui.renderUi();
    tui.processKeypress();
  }
}