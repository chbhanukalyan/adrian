
# UNTESTED!!!!

# Makefile for Open Asset Import Library (GNU-make)
# aramis_acg@users.sourceforge.net

#
# Usage: make <target> <macros>

# TARGETS:
#   all                  Build a shared so from the whole library
#   clean                Cleanup object files, prepare for rebuild
#   static               Build a static library (*.a)

# MACROS: (make clean before you change one)
#   NOBOOST=1            Build against boost workaround
#   SINGLETHREADED=1     Build single-threaded library
#   DEBUG=1              Build debug build of library
# 

# C++ object files
OBJECTS   := $(patsubst %.cpp,%.o,  $(wildcard *.cpp)) 
OBJECTS   += $(patsubst %.cpp,%.o,  $(wildcard extra/*.cpp)) 
OBJECTS   += $(patsubst %.cpp,%.o,  $(wildcard ./../contrib/irrXML/*.cpp)) 

# C object files (mainly from zlib)
OBJECTSC  := $(patsubst %.c,%.oc,   $(wildcard ./../contrib/zlib/*.c))

# Include flags for gcc
INCLUDEFLAGS =

# Preprocessor defines for gcc
DEFINEFLAGS = 

# Suffix for the output binary, represents build type
NAMESUFFIX = 

# Output path for binaries
BINPATH = ../bin/gcc/

# GCC compiler flags 
CPPFLAGS=-Wall 

# Setup environment for noboost build
ifeq ($(NOBOOST),1)
	SINGLETHREADED = 1
	INCLUDEFLAGS  += -I../include/BoostWorkaround/
	DEFINEFLAGS   += -DASSIMP_BUILD_BOOST_WORKAROUND 
#	NAMESUFFIX    += -noboost
# else
#	INCLUDEFLAGS  += -I"C:/Program Files/boost/boost_1_35_0"
endif

# Setup environment for st build
ifeq ($(SINGLETHREADED),1)
	DEFINEFLAGS   += -DASSIMP_BUILD_SINGLETHREADED
#	NAMESUFFIX    += -st
endif

# Setup environment for debug build
ifeq ($(DEBUG),1)
	DEFINEFLAGS   += -D_DEBUG -DDEBUG
#	NAMESUFFIX    += -debug
else
	CPPFLAGS      += -o3
	DEFINEFLAGS   += -DNDEBUG -D_NDEBUG
endif

# Output name of shared library
SHARED_TARGET = $(BINPATH)/libassimp$(NAMESUFFIX).so

# Output name of static library
STATIC = $(BINPATH)/libassimp$(NAMESUFFIX).a

# target: all
# usage : build a shared library (*.so)
all:	$(SHARED_TARGET)

$(SHARED_TARGET):  $(OBJECTS)  $(OBJECTSC)
	gcc -o $@ $(OBJECTS) $(OBJECTSC) -shared -lstdc++ 
%.o:%.cpp
	$(CXX) -g -c  $(CPPFLAGS) $? -o $@ $(INCLUDEFLAGS) $(DEFINEFLAGS) -fPIC
%.oc:%.c
	$(CXX) -x c -g -c -ansi $(CPPFLAGS) $? -o $@ -fPIC

# target: clean
# usage : cleanup all object files, prepare for a rebuild
.PHONY: clean
clean:
	-rm -f $(OBJECTS) $(OBJECTSC) $(TARGET)

# target: static
# usage : build a static library (*.a)
static:    $(STATIC) 
$(STATIC):    $(OBJECTS) $(OBJECTSC)
	ar rcs $@ $(OBJECTS) $(OBJECTSC)



