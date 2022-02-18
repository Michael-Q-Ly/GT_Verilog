# File Name	: Makefile
# Purpose	: Build an LED Walker project
# Author	: Michael Ly
# Date		: Feb 15, 2022

.PHONY: all
all: ledWalker_tb ledWalker2_tb

VERILATOR = verilator
# VERILATOR_ROOT ?= ${shell bash -c 'verilator -V|grep VERILATOR_ROOT | head -1 | sed -e "s/^.*=\s*//"'}
# VERILATOR_ROOT = /cygdrive/c/Users/Micha/Downloads/Installations/Embedded_Applications/FPGA/verilator
VERILATOR_ROOT = /usr/include/verilator
VINC := $(VERILATOR_ROOT)/include
VFLAGS = --trace -Wall -cc

CXX = g++
PROG = ledWalker_tb
OBJS = ledWalker.o
OBJDIR = obj_dir
LIBDIR = $(OBJDIR)
LIBARCHIVE = $(LIBDIR)/VledWalker__ALL.a
LIBARCHIVE2 = $(LIBDIR)/VledWalker2__ALL.a
CXXFLAGS = -I$(VINC) -I$(OBJDIR)

# LED Walker
$(OBJDIR)/VledWalker.cpp: ledWalker.v
	$(VERILATOR) $(VFLAGS) ledWalker.v

$(LIBARCHIVE): $(OBJDIR)/VledWalker.cpp
	make --no-print-directory -C $(OBJDIR) -f VledWalker.mk

$(PROG): ledWalker.cpp $(LIBARCHIVE)
	$(CXX) $(CXXFLAGS) $(VINC)/verilated.cpp	\
		$(VINC)/verilated_vcd_c.cpp $< 		\
		$(LIBARCHIVE) -o $@

# LED Walker 2
$(OBJDIR)/VledWalker2.cpp: ledWalker2.v
	$(VERILATOR) $(VFLAGS) ledWalker2.v

$(LIBARCHIVE2): $(OBJDIR)/VledWalker2.cpp
	make --no-print-directory -C $(OBJDIR) -f VledWalker2.mk

ledWalker2_tb: ledWalker2.cpp $(LIBARCHIVE2)
	$(CXX) $(CXXFLAGS) $(VINC)/verilated.cpp	\
		$(VINC)/verilated_vcd_c.cpp $< 		\
		$(LIBARCHIVE2) -o $@

.PHONY: clean
clean:
	rm -rf obj_dir/ ledWalker/ ledWalker2/ *.o *.exe ledWalker.vcd ledWalker2.vcd

