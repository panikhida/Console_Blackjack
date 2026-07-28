#include "includes.h"
#include <unistd.h>
#include "btui/includes/BTUI.h"
int main() {
  BTUI tui;
  std::cout << "\e[0;36m";

  tui.enableRaw();
  while (true) {
    char c = '\0';
    if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN) tui.die("read");
    if (iscntrl(c)) {
      std::cout << static_cast<unsigned int>(c) << "\r\n";
    } else {
      std::cout << static_cast<int>(c) << "(" << c << ")\r\n";
    }
    if (c == 'q') break;
  }
  return 0;
}