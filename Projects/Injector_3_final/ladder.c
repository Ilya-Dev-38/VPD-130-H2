#include "hmiworks.h"

extern int ladder_injector_3_final_ldx(int);


BYTE ladder_main(BYTE en)
{
  ladder_injector_3_final_ldx(en);
  return 1;
}

