# File Name	: Makefile
# Purpose	: Build cpp testbenches
# Author	: Michael Ly
# Date		: Feb 14, 2022


.PHONY: all
all: blinky

PROG1 = blinky
INCDIR = obj_dir
CXX = g++
LIBDIR := $(INCDIR)
S_LIB := $(INCDIR)/Vblinky__ALL.a
VERILATOR := verilator
# VERILATOR_ROOT ?= $(shell bash -c 'verilator -V|grep VERILATOR_ROOT | head -1 | sed -e "s/^.*=\s*//"')
VERILATOR_ROOT ?= /cygdrive/c/Users/Micha/Downloads/Installations/Embedded_Applications/FPGA/verilator/
VINC := $(VERILATOR_ROOT)/include
CXXFLAGS = -I$(VINC) -I$(INCDIR)

# Ideally, we'd want -GWIDTH=12
# We can have an `ifdef inside blinky.v
obj_dir/Vblinky.cpp: blinky.v
	$(VERILATOR) -Wall -cc blinky.v
	# $(VERILATOR) --trace -Wall -cc blinky.v

$(S_LIB): obj_dir/Vblinky.cpp
	make --no-print-directory -C obj_dir -f Vblinky.mk

blinky: blinky.cpp $(S_LIB)
	$(CXX) -I$(VINC) -I$(INCDIR)		\
		$(VINC)/verilated.cpp       	\
		blinky.cpp $(S_LIB)		\
		-o $(PROG1)

.PHONY: clean
clean:
	rm -rf obj_dir/ blinky blinkytrace.vcd *.o *.exe
