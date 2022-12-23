#!/bin/bash

# Wait for MySQL to be ready
while ! mariadb -u root -pInceptiondb.123 -e "show databases;" > /dev/null 2>&1; do
	echo "Waiting for MySQL to be ready..."
	sleep 1
done

apt -y update && apt -y upgrade && apt -y install apt-utils wget
echo 'debconf debconf/frontend select Noninteractive' | debconf-set-selections

# Install Wordpress
wget https://wordpress.org/latest.tar.gz
tar -xvzf latest.tar.gz
rm -rf latest.tar.gz

# Configure Wordpress
chown -R www-data:www-data /var/www/html/wordpress
chmod -R 755 /var/www/html/wordpress

wp core download --allow-root
wp config create --dbname=database --dbuser=acaravan --dbpass=Inceptiondb.123 \
				--allow-root
wp core install --url=acaravan.42.fr --title=acaravan_webpage \
				--admin_user=acaravan --admin_password=Inception.123 \
				--admin_email=acaravan@student.42madrid.com --allow-root
#wp user create notadmin --porcelain --allow-root

/usr/sbin/php-fpm7.3 -F -R
#tail -f /dev/null
