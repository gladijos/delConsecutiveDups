#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>

void removeDups(char *pStr) {
  auto writeIdx = 0;
  auto readIdx = writeIdx;
  for (; pStr[readIdx] != '\0'; ++readIdx) {
    if (pStr[readIdx] != pStr[writeIdx]) {
      pStr[++writeIdx] = pStr[readIdx];
    }
  }
  if (writeIdx != readIdx) {
    pStr[writeIdx + 1] = '\0';
  }
}

int main(int /*argc*/, char * /*argv*/ []) {
  std::string inputLine;

  while (true) {
    std::cout << "Please, input string line" << std::endl;
    std::getline(std::cin, inputLine);
    // пример использования
    auto *data = new char(inputLine.length());
    memcpy(data, inputLine.c_str(), inputLine.length());
    removeDups(data);

    std::cout << std::quoted(data) << std::endl;
    delete data;
  }
  return 1;
}