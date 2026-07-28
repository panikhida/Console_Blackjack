#include "includes.h"
#include <unistd.h>
#include "btui/includes/BTUI.h"
using enum Color;
int main() {
  BTUI tui;

  BTUI::setClr(Clr(green));

  tui.enableRaw();
  while (true) {
    char c = '\0';
    if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN) {
      BTUI::die("read");
    }

    if (iscntrl(c)) {
      std::cout << static_cast<unsigned int>(c) << "\r\n";
    } else {
      std::cout << static_cast<int>(c) << "(" << c << ")\r\n";
    }
    if (c == 'q') break;
  }

  return 0;
}