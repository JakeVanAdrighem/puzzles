// PROBLEM: Determine if the input string contains a valid number.
// EXAMPLE: "1.43" -> True
// "3e4"    -> True
// "14ab42" -> False
// State: Incomplete

#include <stdbool.h>
#include <stdio.h>
// This is for skipping any whitespace prefix
// which, according the the instructions for
// this problem, is a valid input.
char* skipWhitespace(char* s){
    while(*s == ' '){
        s++;
    }
    return s;
}

// This is for confirming any whitespace is trailing
// and not splitting the input string. The return
// value of this function is expected to be used
// as the final return value for a particular 'Maybe'
// function.
bool checkTrailingWhitespace(char* s){
    while(*s != '\0'){
        if(*s != ' '){
            return false;
        }
        s++;
    }
    return true;
}

bool isInteger(char* s){
    if((*s >= '0') && (*s <= '9'))
        return true;
    return false;
}

bool isMaybeInteger(char* s){
    printf("isMaybeInteger\n");
    bool hasDigits = false;
    // Save off the start of the string so that we can validate the sign
    // position if we need to.
    char* begin = s;
    while(*s != '\0'){
        if((*s == '-' || *s == '+')){
          if(s != begin)
            return false;
        }
        // Consider both prefix and suffix whitespace.
        else if(*s == ' '){
            // If we find non-prefix whitespace, it better
            // be trailing whitespace and not splitting the string
            // this means we can just check and return the result.
            return checkTrailingWhitespace(s);
        }
        // At this point we've checked for all non integer
        // character cases. If we find anything other than [0-9]
        // it's definitely not a valid integer.
        else if(isInteger(s)){
            hasDigits = true;
        }
        else
          return false;
        s++;
    }
    if(!hasDigits)
        return false;
    return true;
}

bool isMaybeFloat(char* s){
    printf("isMaybeFloat\n");
    // Save off the pointer so that
    // we can efficiently check for a '.'
    // at the beginning of the string.
    bool foundDot = false;
    bool hasDigits = false;
    char* begin = s;
    while(*s != '\0'){
        if((*s == '-' || *s == '+')){
          if(s != begin)
            return false;
        }
        // Check for our floating point.
        else if(*s == '.'){
            if(foundDot){
                return false;
            }
            else{
                foundDot = true;
            }
        }
        else if(*s == ' '){
            // If we find non-prefix whitespace, it better
            // be trailing whitespace and not splitting the string
            // this means we can just check and return the result.
            return checkTrailingWhitespace(s) && hasDigits;
        }
        // All special cases considered, the only possibilities left
        // are values [0-9].
        else if(isInteger(s)){
            hasDigits = true;
        }
        else
          return false;
        s++;
    }
    if(!hasDigits)
        return false;
    return true;
}

bool isMaybeScientificNotation(char* s){
    printf("isMaybeScience\n");
    bool hasExponent = false;
    bool hasSign = false;
    bool hasLeftDigits = false;
    bool hasRightDigits = false;
    // Save off a pointer to the beginning of the string. We
    // use this to check the position of the exponent char
    // and sign.
    char* begin = s;
    while(*s != '\0') {
        if(*s == 'e' || *s == 'E') {
            printf("has e\n");
            // If the exponent character is at the beginning
            // this isn't a valid float.
            if(s == begin){
                return false;
            }
            hasExponent = true;
        }
        else if(*s == '-' || *s == '+'){
            if(s == begin){
                return false;
            }
            else if(!hasExponent){
                return false;
            }
            // The sign must immediately follow the exponent value.
            else if (!(*(s-1) == 'e' || *(s-1) == 'E')){
                return false;
            }
            hasSign = true;
        }
        // Consider both prefix and suffix whitespace.
        else if(*s == ' '){
            // If we find non-prefix whitespace, it better
            // be trailing whitespace and not splitting the string
            // this means we can just check and return the result.
            return checkTrailingWhitespace(s);
        }
        // All special cases considered, the only possibilities left
        // are values [0-9].
        else if(isInteger(s)){
            if(hasExponent)
              hasRightDigits = true;
            else
              hasLeftDigits = true;
        }
        else
          return false;
        s++;
    }
    if(!hasLeftDigits || !hasRightDigits)
        return false;
    return true;
}

bool isNumber(char* s) {
    bool result = false;
    s = skipWhitespace(s);
    // Either empty string or
    // all whitespace.
    if(*s == '\0')
        return false;
    if(isMaybeInteger(s))
        return true;
    else if(isMaybeFloat(s))
        return true;
    else if(isMaybeScientificNotation(s))
        return true;
    return false;
}

int main(int argc, char** argv){
  if(argc >= 2){
    if(isNumber(argv[1]))
      printf("true\n");
    else
      printf("false\n");
  }
}
