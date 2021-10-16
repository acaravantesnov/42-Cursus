SOURCES =	./phonebook.cpp \

CLANG = clang++

FLAGS = -Wall -Wextra -Werror

RESIDUES =	phonebook \
			a.out \

all:
	$(CLANG) $(FLAGS) $(SOURCES) -o "phonebook"

fclean:
	rm -rf $(RESIDUES)
