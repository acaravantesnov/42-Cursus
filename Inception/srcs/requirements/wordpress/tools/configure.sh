#!/bin/bash

echo 'debconf debconf/frontend select Noninteractive' | debconf-set-selections

# Configure Wordpress
chown -R www-data:www-data /var/www/html/wordpress
chmod -R 755 /var/www/html/wordpress

# Configure Wordpress
wp core download --allow-root
wp core install --url=acaravan.42.fr --title=acaravan_webpage \
				--admin_user=acaravan --admin_password=acaravan.123 \
				--admin_email=acaravan@student.42madrid.com --allow-root

cat wp-config-sample.php | sed -e "s/database_name_here/$WP_DB_NAME/g" \
	-e "s/username_here/$MYSQL_USR/g" \
	-e "s/password_here/$MYSQL_ROOT_PSSWD/g" \
	-e "s/localhost/wordpress/g" > wp-config.php

# Wait for mysql to be ready
while ! mariadb -h$MYSQL_HOST -u$WP_DB_USR -p$WP_DB_PSSWD $WP_DB_NAME &>/dev/null; do
    sleep 3
done
# while ! mysql -h$MYSQL_HOST -u$MYSQL_USR -p$MYSQL_ROOT_PSSWD &>/dev/null; do
# 	sleep 3
# done

#wp user create notadmin --porcelain --allow-root

/usr/sbin/php-fpm7.3 -F -R
#tail -f /dev/null
