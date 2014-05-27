EXT_PKGS=/home/chiahsun/research/ast_versions/ast_parser_generator_versions/ast_parser /home/chiahsun/research/process_communication_graph/vexpr

EXT_INC=$(patsubst %, -I%, $(EXT_PKGS))
EXT_LIB=$(patsubst %, -L%, $(EXT_PKGS))
EXT_LIB_FLAGS=$(foreach x, $(EXT_PKGS), -l$(shell basename $x))

#all :
#	@echo $(EXT_INC)
#	@echo $(EXT_LIB)
#	@echo $(EXT_LIB_FLAGS)

PKG_IFLAGS=$(EXT_INC)
PKG_LFLAGS=$(EXT_LIB) $(EXT_LIB_FLAGS)
