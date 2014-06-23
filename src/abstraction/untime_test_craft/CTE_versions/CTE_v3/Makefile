SYSTEMC_HOME=/home/chiahsun/tools/systemc/systemc-2.3.0
SYSTEMC_INCLUDE=$(SYSTEMC_HOME)/include
SYSTEMC_LIB=$(SYSTEMC_HOME)/lib-linux64

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
EXES = $(patsubst %.cc, %.out, $(wildcard *.cc))
EXE_OBJS = $(patsubst %.cc, %.o, $(wildcard *.cc))
DEPENDS = $(patsubst %.cc, %.d, $(wildcard *.cc))
DEPENDS += $(patsubst %.cpp, %.d, $(wildcard *.cpp))

CXX = g++
# CFLAGS = -Wall -pedantic -Wextra -Wconversion -Wno-cpp

# CFLAGS = -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-promo -Wstrict-null-sentinel -Wswitch-default -Wundef -Wno-unused # -Werror -Wnoexcept -Wsign-conversion -Wstrict-overflow=5 -Wlogical -Wmissing-declarations
# CFLAGS = -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-include-dirs  -Woverloaded-virtual -Wredundant-decls -Wsign-promo -Wstrict-null-sentinel -Wswitch-default -Wundef -Wno-unused # -Werror -Wnoexcept -Wsign-conversion -Wstrict-overflow=5 -Wlogical -Wmissing-declarations
CFLAGS = -Wno-long-long  -pedantic -Wall 
CFLAGS += -I$(SYSTEMC_INCLUDE)

mode = release
# CFLAGS = -g -Wall -O0 -pedantic 
ifeq ($(mode), debug)
    CFLAGS += -O0 -g
else ifeq ($(mode), test)
    CFLAGS += -O2 -g
else ifeq ($(mode), release)
    CFLAGS += -O3 
else
$(error Unknown mode please check)
endif
# CFLAGS = -g -Wall -O0 -pedantic -D USE_STL=

LFLAGS = -L$(SYSTEMC_LIB) -lsystemc -lm 

.SUFFIXES : .cpp .o .cc .d

all : $(EXES)

$(EXES) :
#all : $(DEPENDS)


clean :
	rm -f $(OBJS) $(EXES) $(EXE_OBJS) $(DEPENDS)

#ifneq ($(MAKECMDGOALS), clean)
-include $(DEPENDS)
#endif

.cpp.d :
	$(CXX) -MM -MG "$<" | sed -e 's@^\(.*\)\.o:@\1.d \1.o:@' > $@	

.cc.d : 
	$(CXX) -MM -MG "$<" | sed -e 's@^\(.*\)\.o:@\1.d \1.o:@' > $@	

.cpp.o :
	$(CXX) $(CFLAGS) -c -o $@ $<

.cc.o :
	$(CXX) $(CFLAGS) -c -o $@ $<

%.out : %.o $(OBJS)
	$(CXX) $(CFLAGS) $(LFLAGS) -o $@ $^

dot :
	make -f Makefile.dot.mk

#CFLAGS = -O -Wall\
		 -pedantic  \
		 -pedantic-errors -Wextra -Waggregate-return -Wcast-align \
		 -Wcast-qual -Wconversion \
		 -Wdisabled-optimization \
		 -Werror -Wfloat-equal -Wformat=2 \
		 -Wformat-nonliteral -Wformat-security  \
		 -Wformat-y2k \
		 -Wimplicit  -Wimport  -Winit-self  -Winline \
		 -Winvalid-pch   \
		 -Wlong-long \
		 -Wmissing-field-initializers -Wmissing-format-attribute   \
		 -Wmissing-include-dirs -Wmissing-noreturn \
		 -Wpacked -Wpointer-arith \
		 -Wredundant-decls \
		 -Wshadow -Wstack-protector \
		 -Wstrict-aliasing=2 -Wswitch-default \
		 -Wswitch-enum \
		 -Wunused \
		 -Wunused-parameter \
		 -Wvariadic-macros \
		 -Wwrite-strings
#         -Weffc++  -Wpadded -Wunreachable-code  \
