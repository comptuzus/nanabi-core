CC := clang++ -Wall -Wextra -Wpedantic -std=c++17
# CC := clang --analyze # and comment out the linker last line for sanity
SRCEXT := cpp

all: nanabi_test


# $@ target
# $^ all dependecies
nanabi_test: nanabi.o card.o nanabi_test.o
	$(CC) -o $@ $^

%.o : %.cpp nanabi.hpp card.hpp
	$(CC) -o $@ -c $<


clean:
	@echo "** Removing object files and executable..."
	@echo $(RM) -r *.o nanabi_test;  $(RM) -r *.o nanabi_test
#
#install:
#        @echo '** Installing...'
#        cp thegame /usr/bin/
#
#uninstall:
#        @echo '** Uninstalling...'
#        $(RM) /usr/bin/thegame
# 

.PHONY: all nanabi_test clean nanabi_lib
