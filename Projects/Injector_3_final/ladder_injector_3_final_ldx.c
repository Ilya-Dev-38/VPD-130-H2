#include "hmiworks.h"


//@GetPanelKey
static BYTE r0_s1_f0(BYTE en)
{
if (!en) return 0;

int hmi_fb_id = hmi_ReadPanelKey();
VAR_WRITE_DEVICE(GetPanelKey , hmi_fb_id);

return 1;

}

static BYTE r0_s1(BYTE en)
{
  en &= r0_s1_f0(en);
  return en;
}

static BYTE r0_s2(BYTE en)
{
  return en;
}

//@rung0
static BYTE r0(BYTE en)
{
  en &= r0_s1(en);
  return r0_s2(en);
}
//====================================

//@Equal
static BYTE r1_s1_f0(BYTE en)
{
if (!en) return 0;

if( (1) == VAR_VALUE(GetPanelKey)) return 1;

return 0;

}

static BYTE r1_s1(BYTE en)
{
  en &= r1_s1_f0(en);
  return en;
}

static BYTE r1_s2_coil0(BYTE en)
{
  return (en);
}

static BYTE r1_s2(BYTE en)
{
      VAR_WRITE_DEVICE(Pump_C_DOWN, r1_s2_coil0(en));
  return en;
}

//@rung1
static BYTE r1(BYTE en)
{
  en &= r1_s1(en);
  return r1_s2(en);
}
//====================================

//@Equal
static BYTE r2_s1_f0(BYTE en)
{
if (!en) return 0;

if( (2) == VAR_VALUE(GetPanelKey)) return 1;

return 0;

}

static BYTE r2_s1(BYTE en)
{
  en &= r2_s1_f0(en);
  return en;
}

static BYTE r2_s2_coil0(BYTE en)
{
  return (en);
}

static BYTE r2_s2(BYTE en)
{
      VAR_WRITE_DEVICE(Pump_C_UP, r2_s2_coil0(en));
  return en;
}

//@rung2
static BYTE r2(BYTE en)
{
  en &= r2_s1(en);
  return r2_s2(en);
}
//====================================

//@Equal
static BYTE r3_s1_p0_f0(BYTE en)
{
if (!en) return 0;

if( (4) == VAR_VALUE(GetPanelKey)) return 1;

return 0;

}

static BYTE r3_s1_p0_c1(BYTE en)
{
  if (!en) return 0;
  return (VAR_VALUE(Pump_ERROR_D1));
}

static BYTE r3_s1_p0(BYTE en)
{
  BYTE result = 0;
  result |= r3_s1_p0_f0(en);
  result |= r3_s1_p0_c1(en);
  return result;
}

//@Add
static BYTE r3_s1_f1(BYTE en)
{
if (!en) return 0;

VAR_WRITE_DEVICE(Pump_Start, (0) + (0));

return 1;

}

//@Add
static BYTE r3_s1_f2(BYTE en)
{
if (!en) return 0;

VAR_WRITE_DEVICE(Needles_Start, (0) + (0));

return 1;

}

static BYTE r3_s1(BYTE en)
{
  en &= r3_s1_p0(en);
  en &= r3_s1_f1(en);
  en &= r3_s1_f2(en);
  return en;
}

static BYTE r3_s2(BYTE en)
{
  return en;
}

//@rung3
static BYTE r3(BYTE en)
{
  en &= r3_s1(en);
  return r3_s2(en);
}
//====================================

//@Equal
static BYTE r4_s1_f0(BYTE en)
{
if (!en) return 0;

if( (8) == VAR_VALUE(GetPanelKey)) return 1;

return 0;

}

static BYTE r4_s1(BYTE en)
{
  en &= r4_s1_f0(en);
  return en;
}

static BYTE r4_s2_coil0(BYTE en)
{
  return (en);
}

static BYTE r4_s2(BYTE en)
{
      VAR_WRITE_DEVICE(Needles_C_DOWN, r4_s2_coil0(en));
  return en;
}

//@rung4
static BYTE r4(BYTE en)
{
  en &= r4_s1(en);
  return r4_s2(en);
}
//====================================

//@Equal
static BYTE r5_s1_f0(BYTE en)
{
if (!en) return 0;

if( (16) == VAR_VALUE(GetPanelKey)) return 1;

return 0;

}

static BYTE r5_s1(BYTE en)
{
  en &= r5_s1_f0(en);
  return en;
}

static BYTE r5_s2_coil0(BYTE en)
{
  return (en);
}

static BYTE r5_s2(BYTE en)
{
      VAR_WRITE_DEVICE(Needles_C_UP, r5_s2_coil0(en));
  return en;
}

//@rung5
static BYTE r5(BYTE en)
{
  en &= r5_s1(en);
  return r5_s2(en);
}
//====================================

//@Add
static BYTE r6_s1_f0(BYTE en)
{
if (!en) return 0;

VAR_WRITE_DEVICE(Needles_SPEED_MIN, (100) + (0));

return 1;

}

static BYTE r6_s1(BYTE en)
{
  en &= r6_s1_f0(en);
  return en;
}

static BYTE r6_s2(BYTE en)
{
  return en;
}

//@rung6
static BYTE r6(BYTE en)
{
  en &= r6_s1(en);
  return r6_s2(en);
}
//====================================

//@Add
static BYTE r7_s1_f0(BYTE en)
{
if (!en) return 0;

VAR_WRITE_DEVICE(Needles_SPEED_MAX, (600) + (0));

return 1;

}

static BYTE r7_s1(BYTE en)
{
  en &= r7_s1_f0(en);
  return en;
}

static BYTE r7_s2(BYTE en)
{
  return en;
}

//@rung7
static BYTE r7(BYTE en)
{
  en &= r7_s1(en);
  return r7_s2(en);
}
//====================================

//@Add
static BYTE r8_s1_f0(BYTE en)
{
if (!en) return 0;

VAR_WRITE_DEVICE(Pump_SPEED_MIN, (0) + (0));

return 1;

}

static BYTE r8_s1(BYTE en)
{
  en &= r8_s1_f0(en);
  return en;
}

static BYTE r8_s2(BYTE en)
{
  return en;
}

//@rung8
static BYTE r8(BYTE en)
{
  en &= r8_s1(en);
  return r8_s2(en);
}
//====================================

//@Add
static BYTE r9_s1_f0(BYTE en)
{
if (!en) return 0;

VAR_WRITE_DEVICE(Pump_SPEED_MAX, (500) + (0));

return 1;

}

static BYTE r9_s1(BYTE en)
{
  en &= r9_s1_f0(en);
  return en;
}

static BYTE r9_s2(BYTE en)
{
  return en;
}

//@rung9
static BYTE r9(BYTE en)
{
  en &= r9_s1(en);
  return r9_s2(en);
}
//====================================

static rung_func __rung_table[] =
{
  r0,
  r1,
  r2,
  r3,
  r4,
  r5,
  r6,
  r7,
  r8,
  r9,
};



BYTE ladder_injector_3_final_ldx(BYTE en)
{
  g_NextRung = 0;
  while (g_NextRung < 10) {
    __rung_table[g_NextRung++](en);
	if (g_NextRung < 0) break;
  }
  return 0;
}

