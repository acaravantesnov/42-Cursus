FROM debian:10.12-slim

RUN apt update && \
	apt upgrade -y && \
	apt install -y	php-fpm \
					php-mysql \
					php-mbstring \
					php-zip \
					php-gd \
					php-xml \
					php-pear \
					php-gettext \
					php-curl \
					curl \
					mariadb-client \
					apt-utils \
					wget

RUN mkdir -p /run/php /var/run/mysqld

# php config
RUN	adduser --system nginx && addgroup --system nginx
COPY conf/php-fpm.conf /etc/php7/php-fpm.conf
COPY conf/www.conf php/7.3/fpm/pool.d/www.conf

COPY conf/index.html /tmp/index.html

# Installing WordPress Command Line Interface
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp

WORKDIR /var/www/html/wordpress

EXPOSE 9000

COPY tools/configure.sh /tmp/configure.sh
ENTRYPOINT [ "sh", "/tmp/configure.sh" ]
