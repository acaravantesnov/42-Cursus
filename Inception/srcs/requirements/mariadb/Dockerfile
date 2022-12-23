FROM debian:10.12-slim

RUN apt update \
	&& apt upgrade -y \
	&& apt install -y mariadb-server mariadb-client wget apt-utils systemd \
	sudo curl

# Copying .sh and .sql files to /tmp/ and /var/local/bin/ respectively
COPY tools/configure.sh /tmp/configure.sh
COPY tools/file.sql /var/local/bin/file.sql

# Giving execution rights to daemon for mysql
#RUN chmod +x mysqld

EXPOSE 3306

CMD [ "sh", "tmp/configure.sh" ]
#CMD [ "tail", "-f", "/dev/null" ]
