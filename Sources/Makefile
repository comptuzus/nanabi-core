CC := clang++ -Wall -Wextra -Wpedantic -std=c++17
# CC := clang --analyze # and comment out the linker last line for sanity
SRCEXT := cpp

all: main-test


# $@ target
# $^ all dependecies
main-test: hanabi.o card.o main-test.o
	$(CC) -o $@ $^

%.o : %.cpp hanabi.hpp card.hpp
	$(CC) -o $@ -c $<


clean:
	@echo "** Removing object files and executable..."
	@echo " $(RM) -r *.o main-test
#
#install:
#        @echo '** Installing...'
#        cp thegame /usr/bin/
#
#uninstall:
#        @echo '** Uninstalling...'
#        $(RM) /usr/bin/thegame
# 

.PHONY: all thegame clean
