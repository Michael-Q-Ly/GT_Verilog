PROG = thruwire
CXX = g++
OBJS = thruwire.o
S_LIB := Vthruwire__ALL.a
INC_VERILATOR := /cygdrive/c/Users/Micha/Downloads/Installations/Embedded_Applications/FPGA/verilator/include
VERILATED := /cygdrive/c/Users/Micha/Downloads/Installations/Embedded_Applications/FPGA/verilator/include/verilated.cpp
INC_DIR := .
CXXFLAGS = -I$(INC_VERILATOR)	\
	   -I$(INC_DIR)	\
	   

.PHONY: all clean

all: $(PROG)

$(PROG): thruwire.cpp
	$(CXX) $(CXXFLAGS) $(VERILATED) thruwire.cpp $(S_LIB) -o $@ 

#thruwire.o: thruwire.cpp
#	$(CXX) $(CXXFLAGS) -c thruwire.cpp

clean:
	rm -rf thruwire.exe thruwire.o
