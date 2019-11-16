#include <time.h>
#include <stdlib.h>
#include <string>

#define CODE_SIZE 8

void createCode(std::string &codeRef);
int checkCode(const std::string &codeRef1, const std::string &codeRef2);
int changeCode(std::string &codeRef);