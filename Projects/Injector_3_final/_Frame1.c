#include "hmiworks.h"
#pragma GCC diagnostic ignored "-Wunused-variable"

static tWidget *thisCanvas = (tWidget *)&CanvasFrame1;
static tContext globalContext;
static tContext *thisContext = &globalContext;

#pragma GCC diagnostic warning "-Wunused-variable"


static void hmi_ConnectWidgetVariable();
static void hmi_DisconnectWidgetVariable();
const unsigned char * ObjectList17_65x80[] = {
  HGF_Button_M__BtnMAG0_65x80,
  HGF_Button_M__BtnMAN1_65x80,
};

#include "__frame1.h"

Canvas(Label6, WIDGET_ROOT, 0, 0,
   HMI_DISPLAY_DRIVER_PTR, 3, 145, 80, 49,
   CANVAS_STYLE_TEXT | CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE
    | CANVAS_STYLE_TEXT_HCENTER | CV_AOPT_VISIBLE | CV_AOPT_ENABLED | CANVAS_STYLE_TEXT_OPAQUE
  , 0xFFFFFF, 0x000000, 0x000000,
  g_pFontCrimsonPro18, "Label6", 0, 0);
Canvas(Label4, WIDGET_ROOT, 0, 0,
   HMI_DISPLAY_DRIVER_PTR, 10, 32, 143, 77,
   CANVAS_STYLE_TEXT | CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE
    | CANVAS_STYLE_TEXT_HCENTER | CV_AOPT_VISIBLE | CV_AOPT_ENABLED | CANVAS_STYLE_TEXT_OPAQUE
  , 0xFFFFFF, 0x000000, 0x000000,
  g_pFontCrimsonPro18, "Label4", 0, 0);
Canvas(Label5, WIDGET_ROOT, 0, 0,
   HMI_DISPLAY_DRIVER_PTR, 167, 32, 143, 77,
   CANVAS_STYLE_TEXT | CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE
    | CANVAS_STYLE_TEXT_HCENTER | CV_AOPT_VISIBLE | CV_AOPT_ENABLED | CANVAS_STYLE_TEXT_OPAQUE
  , 0xFFFFFF, 0x000000, 0x000000,
  g_pFontCrimsonPro18, "Label4", 0, 0);
tCheckBoxWidget CheckBox8 =
  CheckBoxStruct(WIDGET_ROOT, 0, 0, HMI_DISPLAY_DRIVER_PTR, 247, 115, 65, 80,
  CB_STYLE_IMG | CB_AOPT_VISIBLE | CB_AOPT_ENABLED,
  16, 0xFFFFFF, 0x000000, 0x000000, g_pFontCrimsonPro18, "",
  ObjectList17_65x80, hmi_OnCheckBox8CheckChange, 0, 0, 2);
tCheckBoxWidget CheckBox16 =
  CheckBoxStruct(WIDGET_ROOT, 0, 0, HMI_DISPLAY_DRIVER_PTR, 88, 117, 65, 80,
  CB_STYLE_IMG | CB_AOPT_VISIBLE | CB_AOPT_ENABLED,
  16, 0xFFFFFF, 0x000000, 0x000000, g_pFontCrimsonPro18, "",
  ObjectList17_65x80, hmi_OnCheckBox16CheckChange, 0, 0, 2);
Canvas(Label18, WIDGET_ROOT, 0, 0,
   HMI_DISPLAY_DRIVER_PTR, 164, 143, 80, 49,
   CANVAS_STYLE_TEXT | CANVAS_STYLE_FILL | CANVAS_STYLE_OUTLINE
    | CANVAS_STYLE_TEXT_HCENTER | CV_AOPT_VISIBLE | CV_AOPT_ENABLED | CANVAS_STYLE_TEXT_OPAQUE
  , 0xFFFFFF, 0x000000, 0x000000,
  g_pFontCrimsonPro18, "Label6", 0, 0);


Canvas(CanvasFrame1, WIDGET_ROOT, 0, 0, HMI_DISPLAY_DRIVER_PTR, 0, 0,
  320, 240, (CANVAS_STYLE_APP_DRAWN | CV_AOPT_VISIBLE), 0, 0, 0, 0, 0, 0, hmi_OnFrame12Paint);

void hmi_renderFrame12Vector(tContext *pContext, int ox, int oy) {
  GrContextFontSet(pContext, g_pFontCrimsonPro18);
  hmi_SetForeground(pContext, 0x00000000);
  hmi_DrawString(pContext, "+", -1, ox+83, oy+208, 0);
  GrContextFontSet(pContext, g_pFontCrimsonPro18);
  hmi_SetForeground(pContext, 0x00000000);
  hmi_DrawString(pContext, "+", -1, ox+280, oy+208, 0);
  GrContextFontSet(pContext, g_pFontCrimsonPro18);
  hmi_SetForeground(pContext, 0x00000000);
  hmi_DrawString(pContext, "Stop", -1, ox+142, oy+208, 0);
  GrContextFontSet(pContext, g_pFontCrimsonPro18);
  hmi_SetForeground(pContext, 0x00000000);
  hmi_DrawString(pContext, "Pump %", -1, ox+47, oy+7, 0);
  GrContextFontSet(pContext, g_pFontCrimsonPro18);
  hmi_SetForeground(pContext, 0x00000000);
  hmi_DrawString(pContext, "Needles %", -1, ox+198, oy+9, 0);
  GrContextFontSet(pContext, g_pFontCrimsonPro18);
  hmi_SetForeground(pContext, 0x00000000);
  hmi_DrawString(pContext, "-", -1, ox+29, oy+208, 0);
  GrContextFontSet(pContext, g_pFontCrimsonPro18);
  hmi_SetForeground(pContext, 0x00000000);
  hmi_DrawString(pContext, "-", -1, ox+220, oy+208, 0);
  GrContextFontSet(pContext, g_pFontCrimsonPro18);
  hmi_SetForeground(pContext, 0x00000000);
  hmi_DrawString(pContext, "Bar", -1, ox+29, oy+121, 0);
  GrContextFontSet(pContext, g_pFontCrimsonPro18);
  hmi_SetForeground(pContext, 0x00000000);
  hmi_DrawString(pContext, "Error", -1, ox+182, oy+120, 0);
}
void hmi_OnFrame12Paint(tWidget *pWidget, tContext *pContext)
{
  hmi_SetForeground(pContext, 0xFFFFFF);
  hmi_FillRect(pContext, 0, 0, 320, 240);
  hmi_renderFrame12Vector(pContext, 0, 0);
}

static void hmi_InitGlobalContext()
{
  GrContextInit(thisContext, thisCanvas->pDisplay);
  GrContextClipRegionSet(thisContext, &(thisCanvas->sPosition));
}
void hmi_InitFrameWidgets1()
{
  hmi_EnableDrawings(0);
  WidgetAdd(WIDGET_ROOT, (tWidget *)(&CanvasFrame1));
  WidgetAdd(WIDGET_ROOT, (tWidget *)&Label6);
  WidgetAdd(WIDGET_ROOT, (tWidget *)&Label4);
  WidgetAdd(WIDGET_ROOT, (tWidget *)&Label5);
  WidgetAdd(WIDGET_ROOT, (tWidget *)&CheckBox8);
  CheckBoxSelectedSetNP(&CheckBox8, VAR_GET(Needles_Start)?1:0);

  WidgetAdd(WIDGET_ROOT, (tWidget *)&CheckBox16);
  CheckBoxSelectedSetNP(&CheckBox16, VAR_GET(Pump_Start)?1:0);

  WidgetAdd(WIDGET_ROOT, (tWidget *)&Label18);
  hmi_InitGlobalContext();
  hmi_ConnectWidgetVariable();
  hmi_EnableDrawings(1);
}

void hmi_FreeFrameWidgets1()
{
  hmi_DisconnectWidgetVariable();
  WidgetRemove((tWidget *)(&CanvasFrame1));
  WidgetRemove((tWidget *)(&Label6));
  WidgetRemove((tWidget *)(&Label4));
  WidgetRemove((tWidget *)(&Label5));
  WidgetRemove((tWidget *)(&CheckBox8));
  WidgetRemove((tWidget *)(&CheckBox16));
  WidgetRemove((tWidget *)(&Label18));
}


static void Label6_display_Pump_Bar(PVAR pv)
{
  static char buf[13];
  LongToDecString(PVAR_GET(pv), buf, 1);
  LabelTextSet(&Label6, buf);
}
static void Label4_display_Pump_SPEED_SET(PVAR pv)
{
  static char buf[13];
  usprintf(buf, "%d", PVAR_GET(pv));
  LabelTextSet(&Label4, buf);
}
static void Label5_display_Needles_SPEED_SET(PVAR pv)
{
  static char buf[13];
  usprintf(buf, "%d", PVAR_GET(pv));
  LabelTextSet(&Label5, buf);
}

void hmi_OnCheckBox8CheckChange(tWidget *pWidget, unsigned long bSelected)
{
  VAR_WRITE_DEVICE(Needles_Start, CheckBoxValueGet(pWidget));
}
static void CheckBox8_display_Needles_Start(PVAR pv)
{
  CheckBoxValueSet(&CheckBox8, PVAR_GET(pv));
}

void hmi_OnCheckBox16CheckChange(tWidget *pWidget, unsigned long bSelected)
{
  VAR_WRITE_DEVICE(Pump_Start, CheckBoxValueGet(pWidget));
}
static void CheckBox16_display_Pump_Start(PVAR pv)
{
  CheckBoxValueSet(&CheckBox16, PVAR_GET(pv));
}
static void Label18_display_Pump_ERROR_D1(PVAR pv)
{
  static char buf[13];
  usprintf(buf, "%d", PVAR_GET(pv));
  LabelTextSet(&Label18, buf);
}
static void display_Needles_SPEED_SET(PVAR pv)
{
  Label5_display_Needles_SPEED_SET(pv);
}

static void display_Needles_Start(PVAR pv)
{
  CheckBox8_display_Needles_Start(pv);
}

static void display_Pump_Bar(PVAR pv)
{
  Label6_display_Pump_Bar(pv);
}

static void display_Pump_ERROR_D1(PVAR pv)
{
  Label18_display_Pump_ERROR_D1(pv);
}

static void display_Pump_SPEED_SET(PVAR pv)
{
  Label4_display_Pump_SPEED_SET(pv);
}

static void display_Pump_Start(PVAR pv)
{
  CheckBox16_display_Pump_Start(pv);
}

static void hmi_ConnectWidgetVariable()
{
  if (g_hmi_CurrentFrame != 1) return;
  Needles_SPEED_SET.display = display_Needles_SPEED_SET;
  Needles_Start.display = display_Needles_Start;
  Pump_Bar.display = display_Pump_Bar;
  Pump_ERROR_D1.display = display_Pump_ERROR_D1;
  Pump_SPEED_SET.display = display_Pump_SPEED_SET;
  Pump_Start.display = display_Pump_Start;
  display_Needles_SPEED_SET(&Needles_SPEED_SET);
  display_Needles_Start(&Needles_Start);
  display_Pump_Bar(&Pump_Bar);
  display_Pump_ERROR_D1(&Pump_ERROR_D1);
  display_Pump_SPEED_SET(&Pump_SPEED_SET);
  display_Pump_Start(&Pump_Start);
}

static void hmi_DisconnectWidgetVariable()
{
  Needles_SPEED_SET.display = 0;
  Needles_Start.display = 0;
  Pump_Bar.display = 0;
  Pump_ERROR_D1.display = 0;
  Pump_SPEED_SET.display = 0;
  Pump_Start.display = 0;
}

void hmi_Frame1()
{
  hmi_FreeCurrentFrame();
  g_hmi_CurrentFrame = 1;
  hmi_InitFrameWidgets1();
}

