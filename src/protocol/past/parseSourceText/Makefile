TOP=../../../..
ANTLR_JAR_PATH = $(TOP)/ext_libs
ANTLR_JAR_FLAGS = $(ANTLR_JAR_PATH)/antlr-4.0-complete.jar

export CLASSPATH := .:$(TOP)/src/protocol/antlr_psyntax/SourceTextInit:$(ANTLR_JAR_FLAGS):$(CLASSPATH)

CFILES=$(wildcard *.c)
LOGS=$(patsubst %.c, %.c.log, $(CFILES))

RUN=runParseSourceText.sh
CPP_EXE=mainParseSourceText.out

.PHONY : all clean

all : $(LOGS)

%.c.log : %.c $(CPP_EXE) $(RUN)
	./$(RUN) $< &> $@

$(CPP_EXE) : ../$(CPP_EXE)
	cp $< .

clean :
	rm -f *.log *.ast *.syntax $(CPP_EXE)

check :
	./run_check.py
