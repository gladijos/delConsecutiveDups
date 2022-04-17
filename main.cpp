#include <cstring>  // for memcpy
#include <iomanip>  // for getline
#include <iostream> // for cin

static const char eol{'\0'};
/**
 * @brief removeDups removes consecutive duplicate characters
 *
 * @param pStr income and outgoing characters sequence
 * @note метод написан для пары локалей en_US.UTF-8, ru_RU.UTF-8
 */
void removeDups(char *pStr) {
  auto writeIdx = 0;
  auto writeIdx2 = 0;
  auto readIdx = writeIdx;
  bool wideSymbol = false;
  for (; pStr[readIdx] != eol;) {

    if (pStr[readIdx] >= 0) {
      if (pStr[readIdx] != pStr[writeIdx]) {
        ++writeIdx;
        if (wideSymbol) {
          ++writeIdx;
        }
        pStr[writeIdx] = pStr[readIdx];
      }
      ++readIdx;
      wideSymbol = false;
    } else {
      if ((pStr[readIdx] != pStr[writeIdx]) ||
          (pStr[readIdx + 1] != pStr[writeIdx + 1])) {
        ++writeIdx;
        if (wideSymbol) {
          ++writeIdx;
        }
        pStr[writeIdx] = pStr[readIdx];
        pStr[writeIdx + 1] = pStr[readIdx + 1];
      }
      readIdx += 2;
      wideSymbol = true;
    }
  }
  if (writeIdx != readIdx) {
    if (wideSymbol) {
      pStr[writeIdx + 2] = eol;
    } else {
      pStr[writeIdx + 1] = eol;
    }
  }
}
/**
 * @brief removeDups removes consecutive duplicate characters
 *
 * @param pStr income and outgoing characters sequence
 * @note метод написан для локалей, в которых символы помещаются в 8 бит.
 */
void removeDupsEnUs(char *pStr) {
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

  setlocale(LC_ALL, "");
  std::cout << "LC_ALL: " << setlocale(LC_ALL, nullptr) << std::endl;
  std::cout << "LC_CTYPE: " << setlocale(LC_CTYPE, nullptr) << std::endl;
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