# File Name	: Makefile
# Purpose	: Build an LED Walker project
# Author	: Michael Ly
# Date		: Feb 15, 2022

.PHONY: all
all: ledWalker_tb

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
CXXFLAGS = -I$(VINC) -I$(OBJDIR)

$(OBJDIR)/VledWalker.cpp: ledWalker.v
	$(VERILATOR) $(VFLAGS) ledWalker.v

$(LIBARCHIVE): $(OBJDIR)/VledWalker.cpp
	make --no-print-directory -C $(OBJDIR) -f Vledwalker.mk

$(PROG): ledWalker.cpp $(LIBARCHIVE)
	$(CXX) $(CXXFLAGS) $(VINC)/verilated.cpp	\
		$(VINC)/verilated_vcd_c.cpp $< 		\
		$(LIBARCHIVE) -o $@

.PHONY: clean
clean:
	rm -rf obj_dir/ ledWalker/ *.o *.exe ledWalker.vcd

