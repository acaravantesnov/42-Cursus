FROM debian:10.12-slim

RUN apt update && \
	apt upgrade -y && \
	mkdir run/php

RUN apt install -y	php-fpm \
					php-mysql \
					php-mbstring \
					php-zip \
					php-gd \
					php-xml \
					php-pear \
					php-gettext \
					php-curl

# php config
RUN	adduser --system nginx && addgroup --system nginx
COPY conf/php-fpm.conf /etc/php7/php-fpm.conf
COPY conf/www.conf php/7.3/fpm/pool.d

EXPOSE 9000

COPY tools/configure.sh /tmp/configure.sh
ENTRYPOINT [ "sh", "/tmp/configure.sh" ]
