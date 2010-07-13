# (c) 2007 The Board of Trustees of the University of Illinois.

# Cuda-related definitions common to all benchmarks

########################################
# Variables
########################################

# Paths
CUDAHOME=/usr/local/cuda

# Programs
CUDACC=nvcc

# Flags
CUDACFLAGS=$(INCLUDEFLAGS) -g --keep -O3 -Xcompiler "-m32" $(EXTRA_CUDACFLAGS)
CUDALDFLAGS=$(LDFLAGS) -Xcompiler "-m32"                                      \
	-L$(CUDAHOME)/lib -L$(PARBOIL_ROOT)/common/src $(EXTRA_CUDALDFLAGS)
CUDALIBS=-lcuda $(LIBS)
