
# compiler for OS X
CXX=clang++

# compiler for Ubuntu
#CXX=g++

CXX_FLAGS = -g `root-config --cflags`

LD_FLAGS = -lstdc++ `root-config --ldflags --libs`

all: analysis

analysis: analysis.cxx
	  $(CXX) $(CXX_FLAGS) -o analysis analysis.cxx $(LD_FLAGS)

