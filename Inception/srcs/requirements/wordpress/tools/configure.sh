#!/bin/bash

# Configure Wordpress
apt -y update && apt -y upgrade && \
apt -y install apt-utils && \
echo 'debconf debconf/frontend select Noninteractive' | debconf-set-selections && \
apt -y install wget

wget https://wordpress.org/latest.tar.gz
tar -xvzf latest.tar.gz
rm -rf latest.tar.gz

chown -R www-data:www-data /var/www/html/wordpress
chmod -R 755 /var/www/html/wordpress

/usr/sbin/php-fpm7.3 -F -R

#tail -f /dev/null
