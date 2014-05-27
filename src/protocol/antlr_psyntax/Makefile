CODE_DIRS = LiteralInit SourceTextInit


LOG=~/public_html/log/log.html
#LOG=/tmp/log.html

all:
	@for DIR in $(CODE_DIRS); \
		do \
		echo >&2 "Executing $(strip $$DIR) ... "; \
		(cd $$DIR; make all) \
		done
		
# $(shell date +"      %Y/%m/%d %H:%M:%S"); \

check:
	@for DIR in $(CODE_DIRS); \
		do \
		(cd $$DIR; make check) \
		done
		

clean:
	@for DIR in $(CODE_DIRS); \
		do \
		(cd $$DIR; make clean) \
		done





log:
	@rm $(LOG)
	@echo "Make, execute and logging ..."
	@echo "<!-- Runned @ " > $(LOG)
	@echo $(shell date +"      %Y/%m/%d %H:%M:%S") >> $(LOG) 
	@echo "-->" >> $(LOG)
	@for DIR in $(CODE_DIRS); \
		do \
		echo >&2 "Executing $(strip $$DIR) ... "; \
		cd $$DIR; \
		make log; \
		cd ..; \
		done
