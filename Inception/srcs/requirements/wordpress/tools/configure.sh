#!/bin/bash

while ! mariadb -h$MYSQL_HOST -u$WP_DATABASE_USR -p$WP_DATABASE_PWD $WP_DATABASE_NAME &>/dev/null; do
    sleep 3
done

echo 'debconf debconf/frontend select Noninteractive' | debconf-set-selections

# Configure Wordpress
chown -R www-data:www-data /var/www/html/wordpress
chmod -R 755 /var/www/html/wordpress

# Configure Wordpress
cat wp-config-sample.php | sed -e "s/database_name_here/$WP_DB_NAME/g" \
	-e "s/username_here/$WP_DB_USR/g" \
	-e "s/password_here/$WP_DB_PSSWD/g" \
	-e "s/localhost/$MYSQL_HOST/g" > wp-config.php

wp core install --url=acaravan.42.fr --title=acaravan_webpage \
				--admin_user=acaravan --admin_password=acaravan.123 \
				--admin_email=acaravan@student.42madrid.com --allow-root
#wp user create notadmin --porcelain --allow-root


/usr/sbin/php-fpm7.3 -F -R
#tail -f /dev/null
