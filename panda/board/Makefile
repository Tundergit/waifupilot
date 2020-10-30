PROJ_NAME = panda
CFLAGS = -g -Wall -Wextra -Wstrict-prototypes -Werror

CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4
CFLAGS += -mhard-float -DSTM32F4 -DSTM32F413xx -mfpu=fpv4-sp-d16 -fsingle-precision-constant
dp_vw := $(shell cat /data/params/d/dp_vw)
$(info dp_vw is ${dp_vw})
ifeq ($(dp_vw), 1)
  CFLAGS += -Dvw
endif
STARTUP_FILE = startup_stm32f413xx

include build.mk
