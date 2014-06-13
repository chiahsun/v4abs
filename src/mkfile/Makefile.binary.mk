INNER_LIBS_PATH=$(TOP)/libs
INNER_LIBS=$(wildcard $(INNER_LIBS_PATH)/*.a)


INNER_LIBS_BASENAMES=$(foreach x, $(INNER_LIBS), $(shell basename $x))
INNER_LIBS_PREFIX=$(INNER_LIBS_BASENAMES:.a=)
INNER_LIBS_PREFIX_SUFFIX=$(INNER_LIBS_PREFIX:lib%=%)
INNER_LIBS_FLAGS=$(foreach x, $(INNER_LIBS_PREFIX_SUFFIX), -l$x)
# $(info libs = $(INNER_LIBS_FLAGS))
# $(error abort)

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
EXES = $(patsubst %.cc, %.out, $(wildcard *.cc))
EXE_OBJS = $(patsubst %.cc, %.o, $(wildcard *.cc))
DEPENDS = $(patsubst %.cc, %.d, $(wildcard *.cc))
DEPENDS += $(patsubst %.cpp, %.d, $(wildcard *.cpp))


INNER_INC=$(TOP)/src
MAKEFILE_DIR=$(TOP)/src/mkfile
DEPEND_GEN=$(MAKEFILE_DIR)/depend.sh
#EXT_INC=$(patsubst %, -I%, $(INNER_LIBS)) $(patsubst %, -I%, $(EXT_INCS))



#EXT_LIB=$(patsubst %, -L%, $(INNER_LIBS))
#EXT_LIB_FLAGS=$(foreach x, $(INNER_LIBS), -l$(shell basename $x))

#PKG_IFLAGS=$(EXT_INC)
PKG_IFLAGS=-I$(INNER_INC)
#PKG_LFLAGS=$(EXT_LIB) $(EXT_LIB_FLAGS)
PKG_LFLAGS=-L$(INNER_LIBS_PATH) $(INNER_LIBS_FLAGS) $(INNER_LIBS_FLAGS) 

CXX = g++ 
# CFLAGS = -Wall -pedantic -Wextra -Wconversion -Wno-cpp

CFLAGS = -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-promo -Wstrict-null-sentinel -Wswitch-default -Wundef -Wno-unused 
#-Wno-language-extension-token
# -Werror -Wnoexcept -Wsign-conversion -Wstrict-overflow=5 -Wlogical -Wmissing-declarations
#CFLAGS = -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-promo -Wstrict-null-sentinel -Wswitch-default -Wundef -Wno-unused -Wno-ignored-qualifiers # -Werror -Wnoexcept -Wsign-conversion -Wstrict-overflow=5 -Wlogical -Wmissing-declarations

# http://stackoverflow.com/questions/1134237/pedantic-gcc-warning-type-qualifiers-on-function-return-type
# -Wno-ignored-qualifiers

mode = debug
# CFLAGS = -g -Wall -O0 -pedantic 
ifeq ($(mode), debug)
    CFLAGS += -O0 -g
else ifeq ($(mode), test)
    CFLAGS += -O2 -g
else ifeq ($(mode), release)
    CFLAGS += -O2 
else
$(error Unknown mode please check)
endif
# CFLAGS = -g -Wall -O0 -pedantic -D USE_STL=

LFLAGS = $(PKG_LFLAGS)

.SUFFIXES : .cpp .o .cc .d

all : $(EXES)

clean :
	rm -f $(OBJS) $(EXES) $(EXE_OBJS) $(DEPENDS)

ifneq ($(MAKECMDGOALS), clean)
-include $(DEPENDS)
endif

.cpp.d :
	$(DEPEND_GEN) $< > $@	

.cc.d : 
	$(DEPEND_GEN) $< > $@	

.cpp.o :
	$(CXX) $(PKG_IFLAGS) $(CFLAGS) -c -o $@ $<

.cc.o :
	$(CXX) $(PKG_IFLAGS) $(CFLAGS) -c -o $@ $<

%.out : %.o $(OBJS)
	$(CXX) $(PKG_IFLAGS) $(CFLAGS) -o $@ $^ $(LFLAGS) 
