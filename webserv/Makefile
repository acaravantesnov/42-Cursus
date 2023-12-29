NAME			=	webserv

S				=	src/

O				=	obj/

H				=	-I inc/

FILES			=	main.cpp \
					Config.cpp \
					HttpRequest.cpp \
					HttpResponder.cpp \
					HttpLogic.cpp \
					HttpResponse.cpp \
					HttpHeader.cpp \
					HttpStatusCode.cpp \
					Server.cpp \
					CGI.cpp \
					Utils.cpp

SRCS			=	$(addprefix $S, $(filter-out main.cpp, $(FILES))) main.cpp

OBJS			=	$(SRCS:$S%.cpp=$O%.o)

CXX				=	c++
RM				=	rm -f
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98 -pedantic


NOCOL		=	\033[0m
RED			=	\033[1;31m
ORG			=	\033[0;33m
YEL			=	\033[1;33m
GRN			=	\033[1;32m
BLU			=	\033[0;34m
CYN			=	\033[0;36m
PUR			=	\033[0;35m

# Black        0;30     Dark Gray     1;30
# Red          0;31     Light Red     1;31
# Green        0;32     Light Green   1;32
# Brown/Orange 0;33     Yellow        1;33
# Blue         0;34     Light Blue    1;34
# Purple       0;35     Light Purple  1;35
# Cyan         0;36     Light Cyan    1;36
# Light Gray   0;37     White         1;37

all:			$(NAME)
				@printf "\r$(GRN) webserv compiled$(NOCOL)\n\n"
				@printf "$(PUR)- All objs done$(NOCOL)\n"
				@printf "$(YEL)- webserv up to date and ready to run$(NOCOL)\n"

$O%.o:			$S%.cpp
				@[ -d $O ] || mkdir $O
				@[ -d $O$C ] || mkdir $O$C
				@printf "$(BLU)#$(NOCOL)"
				@$(CXX) $(CXXFLAGS) $H -c $< -o $@

$(NAME):		$(OBJS)
				@$(CXX) $(CXXFLAGS) $H $(SRCS) -o $(NAME)
				@[ -e $(NAME) ]

clean:
				@${RM} -rf $O

fclean:			clean
				@${RM} ${NAME}
				@echo "$(CYN) 🧼🧼🧼 All clean! 🧼🧼🧼\n$(NOCOL)"

re:				fclean all

.PHONY:			all clean fclean re test
