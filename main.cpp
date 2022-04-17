#include <cstring>  // for memcpy
#include <iomanip>  // for getline
#include <iostream> // for cin

static const char eol{'\0'};
/**
 * @brief removeDups removes consecutive duplicate characters
 *
 * @param pStr income and outgoing characters sequence
 */
void removeDups(char *pStr) {
  auto writeIdx = 0;
  auto readIdx = writeIdx;
  for (; pStr[readIdx] != eol; ++readIdx) {
    if (pStr[readIdx] != pStr[writeIdx]) {
      pStr[++writeIdx] = pStr[readIdx];
    }
  }
  if (writeIdx != readIdx) {
    pStr[writeIdx + 1] = eol;
  }
}

int main(int /*argc*/, char * /*argv*/ []) {
  std::string inputLine;

  while (true) {
    printf("Please, input string line\n");
    std::getline(std::cin, inputLine);
    auto strLen = inputLine.length();
    auto *data = new char(strLen + 1);
    memcpy(data, inputLine.c_str(), strLen);
    data[strLen] = eol;
    // пример использования
    // наверное после getline из std::cin логичнее использовать std::cout, но в
    // примере пользования был printf, так и оставил :)
    printf("INCOME \"%s\"\n", data);
    removeDups(data);
    printf("RESULT \"%s\"\n", data);
    delete data;
  }
  return 0;
}