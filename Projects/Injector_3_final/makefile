GRFT=GRLIB_ADD_WIDE_FONT_SUPPORT
LD_VER_DEF=LAD_MODS_VER_1
MDL_NUM_DEF=VPD_130_H_V=0x133C
include default.mk
include makedefs.mk

CFLAGS+=-DtBoolean=bool
CFLAGS+=-include stdbool.h
CFLAGS+=-include stdint.h
CFLAGS+=-D${MDL_NUM_DEF}
CFLAGS+=-D${LD_VER_DEF}
CFLAGS+=-DTPD_USE_NO_MOS
CFLAGS+=-DTPD_USE_M4
CFLAGS+=-D${GRFT}

all: clean
all: ${TARGET}.axf

clean:
	@-rm -f *.o
	@-rm -f *.d

${TARGET}.axf: main.o
include frames.mk


SCATTERgcc_${TARGET}=default.ld
LDFLAGSgcc_${TARGET}=-Map ${TARGET}.map

${TARGET}.axf: default.ld


update:
	eflash.exe -d 133C -i ${IP_ADDRESS} -m ${MAC_ADDRESS} ${TARGET}.bin

imgdbin: imagedata.o default.ld
	@arm-none-eabi-ld.exe -T default.ld -o imgd imagedata.o -N
	@arm-none-eabi-objcopy.exe -O binary imgd imgd.bin
		
genbix: imagedata.o default.ld
	@arm-none-eabi-ld.exe -T default.ld -o imgd imagedata.o -N
	@arm-none-eabi-objcopy.exe -O binary imgd imgd.bin
	@createbix ${TARGET}.bin ${TARGET}.bix 3
	@echo Done!
