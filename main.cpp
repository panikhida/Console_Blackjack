#include "includes.h"
#include <unistd.h>
#include "BTUI.h"
int main() {
  BTUI tui;
  tui.enableRaw();

  while (true) {
    char c = '\0';
    read(STDIN_FILENO, &c, 1);

    if (iscntrl(c)) {
      // std::cout << "[" << static_cast<int>(c) << "] | (" << c << ") " << &c << "\n";
      printf("&d\r\n", c);
    } else {
      // std::cout << "[" << static_cast<int>(c) << "] | (" << c << ") " << &c << "\n";
      printf("%d ('%c')\r\n", c, c  );
    }
    if (c == 'q') break;

  }
  return 0;
}