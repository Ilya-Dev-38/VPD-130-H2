#include "hmiworks.h"
BYTE ladder_main(BYTE);

int g_hmi_CurrentFrame = 0;

static const char *g_FrameNames[] = 
{
  "Frame1",
};

const int g_FrameCount = (sizeof(g_FrameNames)/sizeof(char *));

#define MAGIC_NUM_TO_CON		472882027

HANDLE SER_0;


volatile unsigned long g_TimerTicksCount = 0;
unsigned long g_ulTickTmrEvtTrig = 0;

static volatile bool Pump_flag = false;
static volatile bool Needles_flag = false;

void hmi_TimerTrigger()
{
  g_TimerTicksCount++;
  
  if ((g_TimerTicksCount%(200/10)) == 0)
  Pump_flag = true;
  
  if ((g_TimerTicksCount%(200/10)) == 0)
  Needles_flag = true;
  
  if ( g_TimerTicksCount%(100/10) == 0)
  { g_ulTickTmrEvtTrig = g_TimerTicksCount;
    HMI_REQUEST_LADDER_PROCESS();}
  
  switch(g_hmi_CurrentFrame) {
    case 1: {
    break;
    }
  }
}

void hmi_FreeCurrentFrame()
{
  switch (g_hmi_CurrentFrame)
  {
	case 1: hmi_FreeFrameWidgets1(); break;
  }
}

void hmi_GetActiveFrame(char* str, unsigned int len)
{
  int FNLen = strlen(g_FrameNames[g_hmi_CurrentFrame-1]) +1;
  if(len >= FNLen)
    memcpy(str, g_FrameNames[g_hmi_CurrentFrame-1], FNLen);
}

const char* hmi_GetCurrentFrameName()
{ return g_FrameNames[g_hmi_CurrentFrame-1];}

extern int hmi_frame_number_to_go;
void hmi_GotoFrameAction(int nFrame)
{
  switch(nFrame)
  {
	case 1: hmi_Frame1(); break;
  }

  WidgetMessageQueueClear();
  HMI_REDRAW();
}

void hmi_GotoFrame(int nFrame)
{
  hmi_frame_number_to_go = nFrame;
}

int hmi_IndexOfFrame(const char *frame_name)
{
  for (int i=0; i<g_FrameCount; i++)
    if (strcmp(frame_name, g_FrameNames[i]) == 0) return i+1;
  return 0;
}

void hmi_GotoFrameByName(const char *frame_name)
{
  hmi_frame_number_to_go = hmi_IndexOfFrame(frame_name);
}

long hmi_Ladder_Process(tWidget *pWidget, unsigned long ulMessage,
                     unsigned long ulParam1, unsigned long ulParam2)

{
  ladder_main(1);
  passDataThruBindingOnChange();
  default_output(1);
  return 1;
}


BYTE polling_Pump(BYTE en)
{
  if ( ! Pump_ENABLE_DEVICE ) return 0;
BEGIN_FUNCTION_BLOCK();
    
WORD temp;

uart_SetTimeout(SER_0, 200);

mrm_ReadAO(SER_0, 22, 6, 1, &temp); // 7 Р°РґСЂРµСЃ РїРѕР»СѓС‡Р°РµС‚ СЂРµР°Р»СЊРЅСѓСЋ СЃРєРѕСЂРѕСЃС‚СЊ
VAR_SET(Pump_SPEED_GET, temp);

mrm_ReadAO(SER_0, 22, 19, 1, &temp); // 20 Р°РґСЂРµСЃ РїРѕР»СѓС‡Р°РµС‚ Р·РЅР°С‡РµРЅРёРµ A1
VAR_SET(Pump_A1, temp);
VAR_SET(Pump_Bar, temp / (float)655.35);

mrm_ReadAO(SER_0, 22, 10, 1, &temp); // 11 Р°РґСЂРµСЃ РїРѕР»СѓС‡Р°РµС‚ Р·РЅР°С‡РµРЅРёРµ D1
VAR_SET(Pump_D1, temp);
VAR_SET(Pump_ERROR_D1, !temp);

mrm_ReadAO(SER_0, 22, 1, 1, &temp); // 2 Р°РґСЂРµСЃ РїРѕР»СѓС‡Р°РµРј СЃРєРѕСЂРѕСЃС‚СЊ
if(VAR_GET(Pump_C_UP) == 1) temp = temp + (VAR_GET(Pump_SPEED_MAX) - VAR_GET(Pump_SPEED_MIN)) / 100;
if(VAR_GET(Pump_C_DOWN) == 1) temp = temp - (VAR_GET(Pump_SPEED_MAX) - VAR_GET(Pump_SPEED_MIN)) / 100;
if(temp < VAR_GET(Pump_SPEED_MIN)) temp = VAR_GET(Pump_SPEED_MIN);
if(temp > VAR_GET(Pump_SPEED_MAX)) temp = VAR_GET(Pump_SPEED_MAX);
VAR_SET(Pump_SPEED_SET, (temp - VAR_GET(Pump_SPEED_MIN)) / ((VAR_GET(Pump_SPEED_MAX) - VAR_GET(Pump_SPEED_MIN)) / 100));
mrm_WriteAO(SER_0, 22, 1, 1, &temp); // 2 Р°РґСЂРµСЃ Р·Р°РґР°РµС‚ СЃРєРѕСЂРѕСЃС‚СЊ

if(VAR_GET(Pump_Start) == 1){
    if(VAR_GET(Pump_Reverse) != 1){
        temp = 1;
    } else {
        temp = 3;
    }
} else {
    temp = 0;
}
mrm_WriteAO(SER_0, 22, 0, 1, &temp); //Р—Р°РїРёСЃС‹РІР°РµС‚СЃСЏ РІ 1 СЂРµРіРёСЃС‚СЂ




/*
VAR_SET(, mrm_ReadAO(SER_0, 22, 0, 1, &v_ai) ? 1 : 0);
if(VAR_GET(Pump_C_UP) == 1) v_ai++;
if(VAR_GET(Pump_C_DOWN) == 1) v_ai--;
VAR_SET(, v_ai);
VAR_SET(, mrm_WriteAO(SER_0, 22, 0, 1, &v_ai) ? 1 : 0);

VAR_SET(, mrm_ReadAO(SER_0, 22, 20, 1, &s_ai) ? 1 : 0);
VAR_SET(, s_ai);
*/


//Р—РЅР°С‡РµРЅРёРµ Р°РЅР°Р»РѕРіРѕРІРѕРіРѕ РІС…РѕРґР° 1 (AI1) Р°РґСЂРµСЃ 20
//Р”РµР№СЃС‚РІРёС‚РµР»СЊРЅРѕРµ Р·РЅР°С‡РµРЅРёРµ СЃРєРѕСЂРѕСЃС‚Рё РјР°РіРёСЃС‚СЂР°Р»СЊРЅРѕР№ С€РёРЅС‹ Р°РґСЂРµСЃ 7
//С‡Р°СЃС‚РѕС‚РЅРёРєРё Р°РґСЂРµСЃР° 11 Рё 22
END_FUNCTION_BLOCK();

  return 0;
}

BYTE polling_Needles(BYTE en)
{
  if ( ! Needles_ENABLE_DEVICE ) return 0;
BEGIN_FUNCTION_BLOCK();
    
WORD temp;

uart_SetTimeout(SER_0, 200);

mrm_ReadAO(SER_0, 11, 6, 1, &temp); // 7 Р°РґСЂРµСЃ РїРѕР»СѓС‡Р°РµС‚ СЂРµР°Р»СЊРЅСѓСЋ СЃРєРѕСЂРѕСЃС‚СЊ
VAR_SET(Needles_SPEED_GET, temp);

mrm_ReadAO(SER_0, 11, 19, 1, &temp); // 20 Р°РґСЂРµСЃ РїРѕР»СѓС‡Р°РµС‚ Р·РЅР°С‡РµРЅРёРµ A1
VAR_SET(Needles_A1, temp);
VAR_SET(Needles_Bar, temp / (float)655.35);

mrm_ReadAO(SER_0, 11, 10, 1, &temp); // 11 Р°РґСЂРµСЃ РїРѕР»СѓС‡Р°РµС‚ Р·РЅР°С‡РµРЅРёРµ D1
VAR_SET(Needles_D1, temp);
VAR_SET(Needles_ERROR_D1, !temp);

mrm_ReadAO(SER_0, 11, 1, 1, &temp); // 2 Р°РґСЂРµСЃ РїРѕР»СѓС‡Р°РµРј СЃРєРѕСЂРѕСЃС‚СЊ
if(VAR_GET(Needles_C_UP) == 1) temp = temp + (VAR_GET(Needles_SPEED_MAX) - VAR_GET(Needles_SPEED_MIN)) / 100;
if(VAR_GET(Needles_C_DOWN) == 1) temp = temp - (VAR_GET(Needles_SPEED_MAX) - VAR_GET(Needles_SPEED_MIN)) / 100;
if(temp < VAR_GET(Needles_SPEED_MIN)) temp = VAR_GET(Needles_SPEED_MIN);
if(temp > VAR_GET(Needles_SPEED_MAX)) temp = VAR_GET(Needles_SPEED_MAX);
VAR_SET(Needles_SPEED_SET, (temp - VAR_GET(Needles_SPEED_MIN)) / ((VAR_GET(Needles_SPEED_MAX) - VAR_GET(Needles_SPEED_MIN)) / 100));
mrm_WriteAO(SER_0, 11, 1, 1, &temp); // 2 Р°РґСЂРµСЃ Р·Р°РґР°РµС‚ СЃРєРѕСЂРѕСЃС‚СЊ

if(VAR_GET(Needles_Start) == 1){
    if(VAR_GET(Needles_Reverse) != 1){
        temp = 1;
    } else {
        temp = 3;
    }
} else {
    temp = 0;
}
mrm_WriteAO(SER_0, 11, 0, 1, &temp); //Р—Р°РїРёСЃС‹РІР°РµС‚СЃСЏ РІ 1 СЂРµРіРёСЃС‚СЂ




/*
VAR_SET(, mrm_ReadAO(SER_0, 11, 0, 1, &v_ai) ? 1 : 0);
if(VAR_GET(Needles_C_UP) == 1) v_ai++;
if(VAR_GET(Needles_C_DOWN) == 1) v_ai--;
VAR_SET(, v_ai);
VAR_SET(, mrm_WriteAO(SER_0, 11, 0, 1, &v_ai) ? 1 : 0);

VAR_SET(, mrm_ReadAO(SER_0, 11, 20, 1, &s_ai) ? 1 : 0);
VAR_SET(, s_ai);
*/


//Р—РЅР°С‡РµРЅРёРµ Р°РЅР°Р»РѕРіРѕРІРѕРіРѕ РІС…РѕРґР° 1 (AI1) Р°РґСЂРµСЃ 20
//Р”РµР№СЃС‚РІРёС‚РµР»СЊРЅРѕРµ Р·РЅР°С‡РµРЅРёРµ СЃРєРѕСЂРѕСЃС‚Рё РјР°РіРёСЃС‚СЂР°Р»СЊРЅРѕР№ С€РёРЅС‹ Р°РґСЂРµСЃ 7
//С‡Р°СЃС‚РѕС‚РЅРёРєРё Р°РґСЂРµСЃР° 11 Рё 22
END_FUNCTION_BLOCK();

  return 0;
}


void hmi_Connection_Process0(void)
{
  static unsigned int uiLastAccessTicks=0;
  if ( (g_TimerTicksCount - uiLastAccessTicks) < (10 / 10) )
    return;

  static unsigned int polling_module=0;
  switch(polling_module++%2) {
  case 0:
  if (Pump_flag)
  {
    VAR_SET(Pump_ERROR, polling_Pump(1)? 1:0);
    Pump_flag = false;
    uiLastAccessTicks = g_TimerTicksCount;
  }
  break;

  case 1:
  if (Needles_flag)
  {
    VAR_SET(Needles_ERROR, polling_Needles(1)? 1:0);
    Needles_flag = false;
    uiLastAccessTicks = g_TimerTicksCount;
  }
  break;

  default: break;
  } //end switch

}
void hmi_IOScan_Process(void)
{
  static unsigned int polling_connection=0;
  switch(polling_connection++%1) {
  case 0:
  hmi_Connection_Process0(); break;

  default: break;
  } //end switch

  default_input(1);
}

void hmi_frame0()
{
  tContext sContext;
  SER_0 = uart_Open("COM1,115200,N,8,1");
  
  RegisterNullWidgetMsgProc(hmi_Ladder_Process);
  
  hmi_grlib_init(HMI_GRLIB_INIT_MULTI);
  GrContextInit(&sContext, HMI_DISPLAY_DRIVER_PTR);
  hmi_GotoFrame(1);
  GrFlush(&sContext);
}
