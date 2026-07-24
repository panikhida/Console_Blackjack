#include "includes.h"
#include <unistd.h>
#include "BTUI.h"
int main() {
  BTUI tui;
  tui.enableRaw();

  char c;
  while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q') {

  }

  return 0;
}