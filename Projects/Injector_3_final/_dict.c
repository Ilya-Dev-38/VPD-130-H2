#include "hmiworks.h"

HVAR Pump_SPEED_MAX = {0, 0, 0, 0, 0, 2, 0, 0, 0};
HVAR Pump_SPEED_MIN = {0, 0, 0, 0, 0, 2, 0, 0, 0};
HVAR Pump_SPEED_GET = {0, 0, 0, 0, 0, 2, 0, 0, 0};
HVAR Pump_SPEED_SET = {0, 0, 0, 0, 0, 2, 0, 0, 0};
HVAR Pump_C_UP = {0, 0, 0, 0, 0, 2, 0, 0, 0};
HVAR Pump_C_DOWN = {0, 0, 0, 0, 0, 2, 0, 0, 0};
HVAR Pump_D1 = {0, 0, 0, 0, 0, 2, 0, 0, 0};
HVAR Pump_A1 = {0, 0, 0, 0, 0, 2, 0, 0, 0};
HVAR Pump_Start = {0, 0, 0, 0, 0, 2, 0, 0, 0};
HVAR Pump_Reverse = {0, 0, 0, 0, 0, 2, 0, 0, 0};
HVAR Pump_ERROR_D1 = {0, 0, 0, 0, 0, 2, 0, 0, 0};
HVAR Pump_Bar = {0, 0, 0, 0, 0, 2, 0, 0, 0};
HVAR Pump_ERROR = {0, 0, 0, 0, 0, 2, 0, 0, 0};
HVAR Needles_SPEED_MAX = {0, 0, 0, 0, 0, 2, 0, 0, 0};
HVAR Needles_SPEED_MIN = {0, 0, 0, 0, 0, 2, 0, 0, 0};
HVAR Needles_SPEED_GET = {0, 0, 0, 0, 0, 2, 0, 0, 0};
HVAR Needles_SPEED_SET = {0, 0, 0, 0, 0, 2, 0, 0, 0};
HVAR Needles_C_UP = {0, 0, 0, 0, 0, 2, 0, 0, 0};
HVAR Needles_C_DOWN = {0, 0, 0, 0, 0, 2, 0, 0, 0};
HVAR Needles_D1 = {0, 0, 0, 0, 0, 2, 0, 0, 0};
HVAR Needles_A1 = {0, 0, 0, 0, 0, 2, 0, 0, 0};
HVAR Needles_Start = {0, 0, 0, 0, 0, 2, 0, 0, 0};
HVAR Needles_Reverse = {0, 0, 0, 0, 0, 2, 0, 0, 0};
HVAR Needles_ERROR_D1 = {0, 0, 0, 0, 0, 2, 0, 0, 0};
HVAR Needles_Bar = {0, 0, 0, 0, 0, 2, 0, 0, 0};
HVAR Needles_ERROR = {0, 0, 0, 0, 0, 2, 0, 0, 0};
HVAR GetPanelKey = {0, 0, 0, 0, 0, 2, 0, 0, 0};

const PVAR __var_table[]={
  &Pump_SPEED_MAX,
  &Pump_SPEED_MIN,
  &Pump_SPEED_GET,
  &Pump_SPEED_SET,
  &Pump_C_UP,
  &Pump_C_DOWN,
  &Pump_D1,
  &Pump_A1,
  &Pump_Start,
  &Pump_Reverse,
  &Pump_ERROR_D1,
  &Pump_Bar,
  &Pump_ERROR,
  &Needles_SPEED_MAX,
  &Needles_SPEED_MIN,
  &Needles_SPEED_GET,
  &Needles_SPEED_SET,
  &Needles_C_UP,
  &Needles_C_DOWN,
  &Needles_D1,
  &Needles_A1,
  &Needles_Start,
  &Needles_Reverse,
  &Needles_ERROR_D1,
  &Needles_Bar,
  &Needles_ERROR,
  &GetPanelKey,
};

int __var_count() { return 27; }

void passDataThruBindingOnChange()
{
}

