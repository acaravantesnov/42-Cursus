#!/bin/bash

# Wait for MySQL to be ready
while ! mariadb -h$MYSQL_HOST -u$MYSQL_USR -p$WP_DB_PSSWD $WP_DB_NAME &>/dev/null; do
    sleep 3
done

echo 'debconf debconf/frontend select Noninteractive' | debconf-set-selections

# Install Wordpress
wget https://wordpress.org/latest.tar.gz
tar -xvzf latest.tar.gz
rm -rf latest.tar.gz

# Configure Wordpress
chown -R www-data:www-data /var/www/html/wordpress
chmod -R 755 /var/www/html/wordpress

wp core download --allow-root
wp config create --dbname=$WP_DB_NAME --dbuser=$WP_DB_USR --dbpass=$WP_DB_PSSWD \
				--allow-root
wp core install --url=acaravan.42.fr --title=acaravan_webpage \
				--admin_user=acaravan --admin_password=acaravan.123 \
				--admin_email=acaravan@student.42madrid.com --allow-root
#wp user create notadmin --porcelain --allow-root

/usr/sbin/php-fpm7.3 -F -R
#tail -f /dev/null
