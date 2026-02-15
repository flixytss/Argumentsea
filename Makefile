# Generated Makefile, Just a template. You can modify me

Var0 = clang++

.DEFAULT_GOAL := all
run:
	
src/lib.cc.o: src/lib.cc
	ccache ${Var0} -c src/lib.cc -o build/lib.cc.o  -fPIC -I include
	@echo "[[[1;32m Compiling file src/lib.cc 0.0%...[0m]]"
Link: src/lib.cc.o
	clang++ build/lib.cc.o -o build/libargumentsea.so -shared
	@echo "[[[1;32m Linking 100%...[0m]]"

all:	run	src/lib.cc.o	Link
install:
	sudo mv build/libargumentsea.so /usr/bin