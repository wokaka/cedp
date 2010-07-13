# (c) 2007 The Board of Trustees of the University of Illinois.

include $(PARBOIL_ROOT)/common/mk/common.mk
include $(PARBOIL_ROOT)/common/mk/cuda.mk

SRCDIR_OBJS=file.o
SRCDIR_CUDAOBJS=main.o
EXTRA_LIBS=-lm -lstdc++
EXTRA_CUDACFLAGS=--use_fast_math -arch=sm_11

LINK_MODE=CUDA

all : $(BIN)

include $(PARBOIL_ROOT)/common/mk/rules.mk
include $(PARBOIL_ROOT)/common/mk/cuda_rules.mk
