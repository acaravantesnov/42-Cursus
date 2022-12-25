NAME = Inception

NOCOL		=	\033[0m
RED			=	\033[1;31m
ORG			=	\033[0;33m
YEL			=	\033[1;33m
GRN			=	\033[1;32m
BLU			=	\033[0;34m
CYN			=	\033[0;36m
PUR			=	\033[0;35m

#Black        0;30     Dark Gray     1;30
#Red          0;31     Light Red     1;31
#Green        0;32     Light Green   1;32
#Brown/Orange 0;33     Yellow        1;33
#Blue         0;34     Light Blue    1;34
#Purple       0;35     Light Purple  1;35
#Cyan         0;36     Light Cyan    1;36
#Light Gray   0;37     White         1;37

all: $(NAME)

$(NAME):
	@echo "$(GRN)Building Docker repositories..."
	@docker-compose -f srcs/docker-compose.yaml up -d --build > /dev/null

down:
	@echo "$(RED)Stopping docker containers..."
	@docker-compose -f srcs/docker-compose.yaml down > /dev/null

fclean:
	@echo "$(PUR)Stopping docker containers..."
	@docker stop $$(docker ps -qa) > /dev/null
	@echo "$(PUR)Removing docker containers..."
	@docker rm $$(docker ps -qa) > /dev/null
	@echo "$(PUR)Removing docker images..."
	@docker rmi -f $$(docker images -qa) > /dev/null
	@echo "$(PUR)Removing docker volumes..."
	@docker volume rm $$(docker volume ls -q) > /dev/null
	@echo "$(PUR)Removing docker network..."
	@docker network rm inception > /dev/null
	@echo "$(CYN) 🧼🧼🧼 All clean! 🧼🧼🧼 $(NOCOL)"

re: fclean all

.PHONY: all fclean re
