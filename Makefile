# Generated Makefile, Just a template. You can modify me

Var0 = clang++

.DEFAULT_GOAL := all
run:
	
src/lib.cc.o: src/lib.cc
	@echo -e "[\e[1;32m Compiling file src/lib.cc 0.0%... \e[0m]"
	@ccache ${Var0} -c src/lib.cc -o build/lib.cc.o -fPIC -I include
Link: src/lib.cc.o
	@echo -e "[\e[1;32m Linking 100%... \e[0m]"

	@clang++ build/lib.cc.o -o build/libargumentsea.so -shared
all:	run	src/lib.cc.o	Link
install:
	sudo mv build/libargumentsea.so /usr/lib