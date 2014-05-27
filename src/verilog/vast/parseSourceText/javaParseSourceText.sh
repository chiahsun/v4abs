export CLASSPATH=".:/home/chiahsun/antlr/antlr-4.0-complete.jar:/home/chiahsun/antlr/verilog_syntax/syntax_rules/SourceTextInit:$CLASSPATH"

java org.antlr.v4.runtime.misc.TestRig SourceTextInit init -tree < $1

