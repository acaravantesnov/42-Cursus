FROM debian:10.12-slim

RUN apt update \
	&& apt upgrade -y \
	&& apt install -y php php-fpm php-opcache php-gd php-mysqli php-curl \
	php-mbstring php-json wget

RUN wget https://wordpress.org/latest.tar.gz \
	&& tar -xvf latest.tar.gz \
	&& rm -rf latest.tar.gz \
	&& mv wordpress /var/www/

EXPOSE 9000

# php config
# RUN	adduser -S nginx &&	addgroup -S nginx
# COPY conf/php-fpm.conf /etc/php7/php-fpm.conf
# COPY conf/www.conf /etc/php7/php-fpm.d/www.conf

# static website
COPY conf/index.html /tmp/index.html

WORKDIR /var/www/html/wordpress

CMD [ "php-fpm7.3", "-F" ]
