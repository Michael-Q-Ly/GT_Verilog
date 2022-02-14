PROG1 = thruwire
PROG2 = maskbus

CXX = g++
OBJS = thruwire.o

LIB_DIR := obj_dir
S_LIB := $(LIB_DIR)/Vthruwire__ALL.a
VERILATOR_DIR := /cygdrive/c/Users/Micha/Downloads/Installations/Embedded_Applications/FPGA/verilator/include
VERILATED := /cygdrive/c/Users/Micha/Downloads/Installations/Embedded_Applications/FPGA/verilator/include/verilated.cpp

INC_DIR := obj_dir
SRC1 = $(INC_DIR)/thruwire.cpp
SRC2 = $(INC_DIR)/maskbus.cpp

CXXFLAGS = -I$(VERILATOR_DIR)	\
	   -I$(INC_DIR)		\
#	   -g -Wall

.PHONY: all clean

all: $(PROG1) $(PROG2)

$(PROG1): thruwire.o
	$(CXX) $(CXXFLAGS) $(VERILATED) $(SRC1) $(S_LIB) -o $@ 

thruwire.o: $(SRC1)
	$(CXX) $(CXXFLAGS) -c $<

$(PROG2): maskbus.o
	$(CXX) $(CXXFLAGS) $(VERILATED) $(SRC2) $(S_LIB) -o $@ 

maskbus.o: $(SRC2)
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -rf *.o *.exe

