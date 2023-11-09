#include<stdio.h>
#include<stdbool.h>
#include "include/pattern_matching.h"

int main(){
  compile_result("main.[ch]pp", "main.app", false);
  compile_result("?at", "Cat", true);
  compile_result("??at", "Gyat", true);
  compile_result("?at", "at", false);
  compile_result("main.***", "main.cpp", true);

  compile_result("*at", "Cat", true);
  compile_result("*at", "Gyat", true);
  compile_result("*.js", "React.js", true);
  compile_result("main.*", "main.cxx", true);
  compile_result("*.*", "package.hpp", true);

  compile_result("main.[ch]", "main.c", true);
  compile_result("main.[ch]", "main.py", false);
  compile_result("main.[ch]pp", "main.hpp", true);

  return 0;
}