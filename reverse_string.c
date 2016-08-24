// PROBLEM: Reverse the positions of the words in a string without reversing the words themselves.
// EXAMPLE:
// "This is a string" -> "string a is This"
// Status: Incomplete
#include <stdio.h>

void eliminateLeadingWhitespace(char *s) {
  // Save this off so we can left shift
  // the string later. This is to handle
  // the case stated in the rules:
  // "your reversed string should not contain leading or trailing spaces"
  char *begin = s;
  while (*s == ' ') {
    s++;
  }
  while (*s != '\0') {
    *begin = *s;
    s++;
    begin++;
  }
  // Shift the null char left.
  *begin = *s;
}

void eliminateTrailingWhitespace(char *s) {
  // Slowly move the null byte backwards
  while(*(s - 1) == ' ')
    *(s - 1) = *s;
}

void swapWord(char *begin, char *end) {
  char tmp;
  while(begin != end && begin < end){
    tmp = *begin;
    *begin = *end;
    *end = tmp;
    begin++;
    end++;
  }
}

void reverseWords(char *s) {
  int len = 0;
  char *cursor = s;
  while (*cursor != '\0') {
    cursor++;
    len++;
  }
  if (len <= 1)
    return;
  eliminateLeadingWhitespace(s);
  // The entire string was whitespace
  if (*s == '\0')
    return;
  eliminateTrailingWhitespace(cursor);
  // Move the cursor back off of the
  // null byte.
  cursor--;
  // Now we reverse the words
 char* wordbegin = s; 
 char* wordend = s;
 while (*wordend != '\0') {
   wordend;
   if (*wordend == ' ') {
     swapWord(wordbegin, wordend - 1);
   }
    
 }
}

int main(int argc, char **argv) {
  if (argc >= 2) {
    reverseWords(argv[1]);
    printf("%s\n", argv[1]);
  }
  return 0;
}
