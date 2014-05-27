
#.PHONY : all clean lib binary

export TOP


clean :
	make -f $(TOP)/src/mkfile/Makefile.binary.mk clean
	make -f $(TOP)/src/mkfile/Makefile.lib.mk clean
	@ for DIR in $(CODE_DIRS); \
    	do \
			if test -d $$DIR; then (cd $$DIR; make clean); else echo "No such directory $$DIR"; fi \
		done


binary :
	make -f $(TOP)/src/mkfile/Makefile.binary.mk

lib :
	make -f $(TOP)/src/mkfile/Makefile.lib.mk

dot :
	make -f $(TOP)/src/mkfile/Makefile.dot.mk

check : 
	make -f $(TOP)/src/mkfile/Makefile.check.mk
