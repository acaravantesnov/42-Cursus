DATA_DIR = /home/acaravan/data
DOCKER_COMPOSE_PATH = ./srcs/docker-compose.yml

NOCOL		=	\033[0m
RED			=	\033[1;31m
ORG			=	\033[0;33m
YEL			=	\033[1;33m
GRN			=	\033[1;32m
BLU			=	\033[0;34m
CYN			=	\033[0;36m
PUR			=	\033[0;35m

all:
	@mkdir -p ${DATA_DIR}/wordpress ${DATA_DIR}/mariadb
	@echo "$(GRN)Building Docker repositories..."
	@docker compose -f ${DOCKER_COMPOSE_PATH} up --build

restart:
	@echo "$(RED)Restarting docker containers..."
	@docker compose -f ${DOCKER_COMPOSE_PATH} restart

stop:
	@echo "$(RED)Stopping docker containers..."
	@docker compose -f ${DOCKER_COMPOSE_PATH} stop

list:
	@echo "$(GRN)IMAGES$(NOCOL)"
	@docker images
	@echo "\n$(GRN)CONTAINERS$(NOCOL)"
	@docker ps -a
	@echo "\n$(GRN)VOLUMES$(NOCOL)"
	@docker volume ls

clean: down

fclean:
	@echo "$(PUR)Stopping docker containers..."
	@docker stop $$(docker ps -qa)
	@echo "$(PUR)Removing docker containers..."
	@docker rm $$(docker ps -qa)
	@echo "$(PUR)Removing docker images..."
	@docker rmi -f $$(docker images -qa)
	@echo "$(PUR)Removing docker volumes..."
	@docker volume rm $$(docker volume ls -q)
	@echo "$(PUR)Removing docker network..."
	@docker network rm inception
	@echo "$(CYN) 🧼🧼🧼 All clean! 🧼🧼🧼 $(NOCOL)"

re: fclean all

.PHONY: all down restart stop list clean fclean re
