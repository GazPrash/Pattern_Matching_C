#include "include/pattern_matching.h"

bool pattern_matching(const char *pattern, const char *text)
{
  while (*pattern != '\0' && *text != '\0')
  {
    switch (*pattern)
    {
    case '?' /* constant-expression */:
    {
      pattern++;
      text++;
    }
    break;
    case '*':
    {
      if (pattern_matching(pattern + 1, text))
        return true;
      text++;
    }
    break;
    case '[':
    {
      // [abc]at   --   cat
      bool found_match = false;
      pattern++;
      if (*(pattern + 1) == '-')
      {
        if (*text >= *pattern && *text <= *(pattern + 2))
        {
          pattern += 4;
          text++;
          break;
        }
      }
      while (*pattern != ']')
      {
        if (*pattern == '\0')
        {
          printf("Syntax Error!");
          return false;
        }
        if (*pattern == *text)
        {
          found_match = true;
        }
        pattern++;
      }

      if (found_match)
      {
        pattern++;
        text++;
      }
      else
        return false;
    }
    break;

    default:
      if (*pattern == *text)
      {
        pattern++;
        text++;
      }
      else
        return false;
    }
  }
  if (*text == '\0')
  {
    while (*pattern == '*')
      pattern++;
    return (*pattern == '\0');
  }
  return false;
}

void compile_result(const char* pattern, const char * text, bool expected){
  bool matchResult = pattern_matching(pattern, text);
  if (matchResult != expected){
    perror("SYNTAX_ERROR\n\n");
    return;
  }
  printf(
    "%s - %s | RESULT %s: ", pattern, text, matchResult ? "MATCHED!\n" : "UNMATCHED!\n"
  );
}