# Build from penultimate stable Debian version (bullseye) image.
FROM debian:bullseye

# Commands to run during building process.
RUN apt update -y && \
	apt upgrade -y && \
	apt install wget php7.4 php-fpm php-mysql mariadb-client -y

# Uses the sed command to modify the www.conf file in the /etc/php/7.4/fpm/pool.d
# directory. This changes the socket that PHP-FPM listens on from a Unix domain
# socket to a TCP port.
COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d/

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp

# We copy the script, give the right to launch it in local on our computer.
COPY ./tools/auto_config.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/auto_config.sh

# Copies the php.ini file from the conf directory to the /etc/php/7.4/fpm
# COPY ./conf/php.ini /etc/php/7.4/fpm/

# Creates the /run/php directory, which is used by PHP-FPM to store Unix domain
# sockets.
RUN mkdir /run/php

WORKDIR /var/www/wordpress

ENTRYPOINT [ "/usr/local/bin/auto_config.sh" ]
