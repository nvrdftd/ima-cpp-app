#!/bin/bash
set -o errexit

LOCATION=antlr-4.7.1-complete.jar
JAVASRC=./javasrc
CPPSRC=./src
java -jar $LOCATION -Dlanguage=Java -listener -no-visitor -o $JAVASRC Ima.g4
java -jar $LOCATION -Dlanguage=Cpp -listener -no-visitor -package antlrcpp -o $CPPSRC Ima.g4
cd $JAVASRC
javac -cp "../antlr-4.7.1-complete.jar" *.java
cd ..
alias imago='java -cp "./antlr-4.7.1-complete.jar:$JAVASRC" org.antlr.v4.gui.TestRig'
alias imago='java -cp "./antlr-4.7.1-complete.jar:./javasrc" org.antlr.v4.gui.TestRig'
