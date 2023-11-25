#ifndef __HMI_FRAME0_H
#define __HMI_FRAME0_H
extern volatile unsigned long g_TimerTicksCount;
extern int g_hmi_CurrentFrame;
extern void hmi_frame0();
extern void hmi_FreeCurrentFrame();
extern void hmi_GotoFrame(int nFrame);
extern void hmi_TimerTrigger();
extern void hmi_TurnBacklight(int bOn);
extern void hmi_IOScan_Process(void);

extern tCanvasWidget Label6;
extern tCanvasWidget Label4;
extern tCanvasWidget Label5;
extern tCheckBoxWidget CheckBox8;
extern void hmi_OnCheckBox8CheckChange(tWidget *pWidget, unsigned long bSelected);

extern tCheckBoxWidget CheckBox16;
extern void hmi_OnCheckBox16CheckChange(tWidget *pWidget, unsigned long bSelected);

extern tCanvasWidget Label18;
extern void hmi_OnFrame12Paint(tWidget *pWidget, tContext *pContext);

extern tCanvasWidget CanvasFrame1;

extern void hmi_FreeFrameWidgets1();


extern void hmi_Frame1();

#endif
