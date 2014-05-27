#!/bin/bash

JAVA_PARSE_RULE_HOME=/home/chiahsun/research/ast_versions/ast_parser_generator_versions/ast_parser/parseSourceText
JAVA_PARSE_RULE=javaParseSourceText.sh
JAVA_EXE=$JAVA_PARSE_RULE_HOME/$JAVA_PARSE_RULE

DESING_NAME=$1
CPP_EXE=$2

echo "Read design $1..."

cmd1="$JAVA_EXE $1 &> $1.ast"
eval $cmd1
echo "Run exe $2..."
cmd2="$CPP_EXE $1.ast"
eval $cmd2

