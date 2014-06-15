CODE_DIRS = $(shell find ./ -mindepth 1 -maxdepth 1 -type d)

all:
	@for DIR in $(CODE_DIRS); \
		do \
		(cd $$DIR; make all) \
		done
		
# $(shell date +"      %Y/%m/%d %H:%M:%S"); \
		

clean:
	@for DIR in $(CODE_DIRS); \
		do \
		(cd $$DIR; make clean) \
		done

check: 
	@for DIR in $(CODE_DIRS); \
		do \
		(cd $$DIR; make check) \
		done
