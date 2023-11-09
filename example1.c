#include "include/pattern_matching.h"
#include<stdio.h>

int main(){
  /*
  Usecase : Confirm whether a product was delivered by a registered delivery agent or not.
  All registered delivery agents have a designated username starting with "DELB"  followed by
  any alphabets or characters followed by 4 digits, e.g DELBCameron9872
  In case the delivery was not carried out by a registered agent, NaN is used.
  Match all the delivery messages that were carried out by registered drivers. 
  */

  const char* string1 = "This product was delivered by DELBJohn01567";
  const char* string2 = "This product was delivered by DELBDavidd01567";
  const char* string3 = "This product was delivered by NaN";

  bool ans1 = pattern_matching(
    "This product was delivered by [D][E][L][B]*[0-9][0-9][0-9][0-9][0-9]", string1
  );
  bool ans2 = pattern_matching(
    "This product was delivered by [D][E][L][B]*[0-9][0-9][0-9][0-9][0-9]", string2
  );
  bool ans3 = pattern_matching(
    "This product was delivered by [D][E][L][B]*[0-9][0-9][0-9][0-9][0-9]", string3
  );

  printf("1.%d, 2.%d, 3.%d", ans1, ans2, ans3);
}