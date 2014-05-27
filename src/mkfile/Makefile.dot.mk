PNG_DIR=~/public_html/dot

DOT_SOURCES = $(wildcard *.dot)
PNG_OUTPUTS = $(patsubst %.dot, $(PNG_DIR)/%.png, $(DOT_SOURCES))

.PHONY: all

all : $(PNG_OUTPUTS)

$(PNG_DIR)/%.png : %.dot
	dot $< -Tpng -o $@
