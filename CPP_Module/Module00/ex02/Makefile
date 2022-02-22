SOURCES =	./tests.cpp \
			./Account.cpp \

CLANG = clang++

FLAGS = -Wall -Wextra -Werror

RESIDUES =	a.out \
			Account.hpp.gch \

all:
	$(CLANG) $(FLAGS) $(SOURCES)

fclean:
	rm -rf $(RESIDUES)