NAME = Inception

all: $(NAME)

$(NAME):
	@echo "Building Docker repositories..."
	docker compose -f srcs/docker-compose.yaml up -d --build

clean:
	@echo "Cleaning Docker repositories..."
	docker compose -f srcs/docker-compose.yaml down

fclean: clean
	@echo "Removing Docker repositories..."
	docker compose -f srcs/docker-compose.yaml rm -f

re: fclean all

.PHONY: all clean fclean re
