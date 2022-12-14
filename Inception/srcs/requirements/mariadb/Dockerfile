FROM debian:10.12-slim

RUN apt update \
	&& apt upgrade -y \
	&& apt install -y mariadb-server mariadb-client

EXPOSE 3306

CMD [ "mysqld_safe" ]
