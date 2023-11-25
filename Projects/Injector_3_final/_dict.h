#ifndef __DICT_H
#define __DICT_H

#undef Pump_SPEED_MAX
extern HVAR Pump_SPEED_MAX;
#undef Pump_SPEED_MIN
extern HVAR Pump_SPEED_MIN;
#undef Pump_SPEED_GET
extern HVAR Pump_SPEED_GET;
#undef Pump_SPEED_SET
extern HVAR Pump_SPEED_SET;
#undef Pump_C_UP
extern HVAR Pump_C_UP;
#undef Pump_C_DOWN
extern HVAR Pump_C_DOWN;
#undef Pump_D1
extern HVAR Pump_D1;
#undef Pump_A1
extern HVAR Pump_A1;
#undef Pump_Start
extern HVAR Pump_Start;
#undef Pump_Reverse
extern HVAR Pump_Reverse;
#undef Pump_ERROR_D1
extern HVAR Pump_ERROR_D1;
#undef Pump_Bar
extern HVAR Pump_Bar;
#undef Pump_ERROR
extern HVAR Pump_ERROR;
#undef Needles_SPEED_MAX
extern HVAR Needles_SPEED_MAX;
#undef Needles_SPEED_MIN
extern HVAR Needles_SPEED_MIN;
#undef Needles_SPEED_GET
extern HVAR Needles_SPEED_GET;
#undef Needles_SPEED_SET
extern HVAR Needles_SPEED_SET;
#undef Needles_C_UP
extern HVAR Needles_C_UP;
#undef Needles_C_DOWN
extern HVAR Needles_C_DOWN;
#undef Needles_D1
extern HVAR Needles_D1;
#undef Needles_A1
extern HVAR Needles_A1;
#undef Needles_Start
extern HVAR Needles_Start;
#undef Needles_Reverse
extern HVAR Needles_Reverse;
#undef Needles_ERROR_D1
extern HVAR Needles_ERROR_D1;
#undef Needles_Bar
extern HVAR Needles_Bar;
#undef Needles_ERROR
extern HVAR Needles_ERROR;
#undef GetPanelKey
extern HVAR GetPanelKey;

#define Pump_ENABLE_DEVICE 1
#define Needles_ENABLE_DEVICE 1

#undef SER_0
extern HANDLE SER_0;

extern const PVAR __var_table[];
extern void passDataThruBindingOnChange();


#endif
