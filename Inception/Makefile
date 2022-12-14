NAME = Inception

all: $(NAME)

$(NAME):
	@echo "Building Docker repositories..."
	docker compose -f srcs/docker-compose.yml up -d --build

clean:
	@echo "Cleaning Docker repositories..."
	docker compose -f srcs/docker-compose.yml down

fclean: clean
	@echo "Removing Docker repositories..."
	docker compose -f srcs/docker-compose.yml rm -f

re: fclean all

.PHONY: all clean fclean re
