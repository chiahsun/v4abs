export CLASSPATH=".:/home/chiahsun/antlr/antlr-4.0-complete.jar:/home/chiahsun/antlr/verilog_syntax/syntax_rules/ExpressionInit:$CLASSPATH"

java org.antlr.v4.runtime.misc.TestRig ExpressionInit init -tree < $1

