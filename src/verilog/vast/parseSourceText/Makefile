TOP=../../../..
ANTLR_JAR_PATH = $(TOP)/ext_libs
ANTLR_JAR_FLAGS = $(ANTLR_JAR_PATH)/antlr-4.0-complete.jar

export CLASSPATH := .:$(TOP)/src/verilog/antlr_vsyntax/SourceTextInit:$(ANTLR_JAR_FLAGS):$(CLASSPATH)

VFILES=$(wildcard *.v)
LOGS=$(patsubst %.v, %.v.log, $(VFILES))

RUN=runParseSourceText.sh
CPP_EXE=mainParseSourceText.out

.PHONY : all clean

all : $(LOGS)

%.v.log : %.v $(CPP_EXE) $(RUN)
	./$(RUN) $< &> $@

$(CPP_EXE) : ../$(CPP_EXE)
	cp $< .

clean :
	rm -f *.log *.ast *.syntax $(CPP_EXE)

check :
	./run_check.py
