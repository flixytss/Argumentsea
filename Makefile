# Generated Makefile, Just a template. You can modify me

Var0 = clang++

.DEFAULT_GOAL := Link
run:
	
src/lib.cc.out: src/lib.cc
	@echo -e "[\e[1;32m Compiling file src/lib.cc 0.0%... \e[0m]"
	@ccache ${Var0} -c src/lib.cc -o build/lib.cc.out -fPIC -I include
Link: src/lib.cc.out
	@echo -e "[\e[1;32m Linking 100%... \e[0m]"

	@clang++ build/lib.cc.out -o build/libargumentsea.so -shared
all:	run	src/lib.cc.out	Link
install: all
	sudo mv build/libargumentsea.so /usr/lib
	sudo mv ./include/argumentsea.hpp /usr/include/argumentsea.hpp
