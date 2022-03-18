SOURCES =	./tests.cpp \
			./Account.cpp \

CLANG = clang++

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

RESIDUES =	a.out \
			Account.hpp.gch \

all:
	$(CLANG) $(FLAGS) $(SOURCES)

fclean:
	rm -rf $(RESIDUES)