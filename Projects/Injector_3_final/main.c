#define HMI_WDT_ENABLE 4000
#define HMI_WDT_TIMEOUT 4000
#define HMI_WDT_CLEAR 1000
#define HMI_WDT_MTCP_TIMEOUT 60000
#define HMI_WDT_MTCPS_TIMEOUT 60000
#define HMI_STARTUP_LED 0
#define HMI_STARTUP_BEEP 1
#define HMI_STARTUP_DELAY 100
#define HMI_BEEP_FREQ 800
#define HMI_BEEP_MS 100
#define HMI_LCD_AUTO_OFF 240
#define HMI_LCD_ON_BEEP 1
#define HMI_LCD_OFF_BEEP 1
#define HMI_LCD_BRIGHTNESS 180
#define HMI_TOUCH_BEEP 1
#define HMI_TCP_TIMEOUT_BEEP 0
#define HMI_NTP_ENABLE 0
#define HMI_NTP_ADDR "time.stdtime.gov.tw"
#define HMI_NTP_FREQ 15000
#define HMI_NTP_ZONE 1000
#define HMI_USER_FLASH 0


#include "hmiworks.h"
int hmi_MACAddrInit(unsigned char * pucMACAddr);
void hmi_TCPInit(void);
void lwIPInit(const unsigned char *pucMac, unsigned long ulIPAddr,
              unsigned long ulNetMask, unsigned long ulGWAddr,
              unsigned long ulIPMode);
//void SoftwareUpdateInit(tSoftwareUpdateRequested pfnCallback);

#define TICKS_PER_SECOND 100
#define MS_PER_TICK      (1000 / TICKS_PER_SECOND)
#define APPLICATION_TITLE "TouchPAD-ICPDAS"

//#define USE_DHCP                 0
#define DEFAULT_IPADDR          	IPADDR(192,168,255,1)
#define DEFAULT_GATEWAY_ADDR    	IPADDR(192,168,255,254)
#define DEFAULT_NET_MASK        	IPADDR(255,255,0,0)

extern volatile unsigned char g_ucLCDIdleUserCallbackStatus;   // 0 = nothing, 1=Idle callback, 2 = wake up callback
extern PFN_VOIDCALLBACK pfnLCDIdleUserCallback;
extern PFN_VOIDCALLBACK pfnLCDWakeupUserCallback;

static volatile tBoolean g_bFirmwareUpdate = false;
static unsigned long g_ulLastClearWatchdog = 0;
static unsigned long g_ulLastHSCallback = 0;
extern volatile bool hmi_gbUSBUpdateSignalled;

void SysTickIntHandler(void)
{
   //lwIPTimer(1000 / TICKS_PER_SECOND);
   hmi_TimerTrigger();
   AudioHandler();
}

void SoftwareUpdateRequestCallback(void)
{
   if (GetRotaryID() == 0)
      g_bFirmwareUpdate = true;
}

int main(void)
{
   unsigned char pucMACAddr[6];

   hmi_DeviceInit(10302);
   hmi_MACAddrInit(pucMACAddr);

   //uart_Init();

   if ( HMI_STARTUP_DELAY )
      hmi_DelayUS( HMI_STARTUP_DELAY * 1000);

   hmi_WdtEnable( 5000 );

   hmi_TCPInit();
   lwIPInit(pucMACAddr, DEFAULT_IPADDR, DEFAULT_NET_MASK, DEFAULT_GATEWAY_ADDR, IPADDR_USE_STATIC);
   I2CM_Driver_Init();
   hmi_WdtClear();  // Don't reboot

   //LocatorInit();
   //LocatorMACAddrSet(pucMACAddr);
   //LocatorAppTitleSet(APPLICATION_TITLE);
   //SoftwareUpdateInit(SoftwareUpdateRequestCallback);

   BuzzerInit();

   hmi_WdtClear();  // Don't reboot

   HMI_INIT(O_LANDSCAPE);
   hmi_BacklightSet( HMI_LCD_BRIGHTNESS );
   hmi_SetLED( HMI_STARTUP_LED );

   hmi_ConfigBeep(HMI_BEEP_FREQ, HMI_BEEP_MS);
   if ( HMI_STARTUP_BEEP )
      hmi_Beep();

   TouchScreenInit();
   TouchScreenCallbackSet(WidgetPointerMessage);

   if ( HMI_TOUCH_BEEP )
      hmi_TurnTouchBeep(1);

   if ( HMI_LCD_AUTO_OFF )
   {
      hmi_LCDIdleSetTimeout( HMI_LCD_AUTO_OFF * 1000 );
      hmi_LCDIdleSetBeep(HMI_LCD_OFF_BEEP, HMI_LCD_ON_BEEP);
   }

   if ( HMI_WDT_ENABLE )
   {
      g_ulLastClearWatchdog = hmi_GetTickCount();
      hmi_WdtEnable( HMI_WDT_TIMEOUT );
   }
   else
      hmi_WdtEnable( 0 );

   hmi_UserFlashConfig(HMI_USER_FLASH);

   hmi_frame0();
   WidgetMessageQueueProcess(); // show initial screen

   while(!g_bFirmwareUpdate)
   {
      if ( hmi_gbUSBUpdateSignalled )
         break;

      hmi_IOScan_Process();
      WidgetMessageQueueProcess();

      if ( HMI_WDT_ENABLE )
      {
         if ( hmi_GetTickCount() - g_ulLastClearWatchdog > HMI_WDT_CLEAR )
         {
            g_ulLastClearWatchdog = hmi_GetTickCount();
            hmi_WdtClear();  // Don't reboot
         }
      }

      if (g_TimerTicksCount != g_ulLastHSCallback)
      {
         // Process High Speed Callback Functions at 10 ms
         hmi_ProcessHSCallback();
         g_ulLastHSCallback = g_TimerTicksCount;

         hmi_GTimerProcess();
      }

      // callback for LCD idle or wake up
      if ( 1 == g_ucLCDIdleUserCallbackStatus && pfnLCDIdleUserCallback )
      {
         g_ucLCDIdleUserCallbackStatus = 0;
         pfnLCDIdleUserCallback();
      }
      else if ( 2 == g_ucLCDIdleUserCallbackStatus && pfnLCDWakeupUserCallback )
      {
         g_ucLCDIdleUserCallbackStatus = 0;
         pfnLCDWakeupUserCallback();
      }
   }

   if ( HMI_WDT_ENABLE )  // Disable Watchdog when firmware update.
      hmi_WdtEnable( 0 );

   if ( hmi_gbUSBUpdateSignalled )
      hmi_dfu_update();

   while(1) { }
}



