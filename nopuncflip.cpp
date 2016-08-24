// PROBLEM: print a string in reverse while preserving punctuation placement.
// EXAMPLE:
// Yeah, let's do it!
// tiod, ste'l ha eY!
// State: Complete
#include <cstdio>

bool isAlphaNumeric(char *val) {
  int chr = (int)*val;
  if ((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z')) {
    return true;
  } else if ((chr >= '0') && (chr <= '9')) {
    return true;
  } else {
    return false;
  }
}

void flipAndPrint(char *str) {
  char *iter = str;
  // find end of string
  while (*iter != '\0') {
    iter++;
  }
  iter--;
  // Now do the printing
  while (*str != '\0') {
    if (isAlphaNumeric(str)) {
      while (!isAlphaNumeric(iter)) {
        iter--;
      }
      printf("%c", *iter);
      iter--;
      str++;
    } else {
      printf("%c", *str);
      str++;
    }
  }
  printf("\n");
}

int main(int argc, char** argv){
  flipAndPrint("Yeah, let's do it!");
  return 0;
}
