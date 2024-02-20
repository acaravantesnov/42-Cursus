#!/bin/bash

# Wait for the database to be ready.
sleep 10

wp --allow-root core is-installed
if [ $? -eq 0 ]
then
	echo "Wordpress already installed."
	# -F specifies php-fpm to run in foreground.
	/usr/sbin/php-fpm7.4 -F
	exit 0
fi

chown -R root:root /var/www/wordpress

wp core download	--allow-root --version=6.3 --locale=en_US

# Creates config for wordpress.
wp config create	--allow-root \
					--dbname=$SQL_DATABASE \
					--dbuser=$SQL_USER \
					--dbpass=$SQL_PASSWORD \
					--dbhost=$SQL_HOSTNAME \
					--url=$DOMAIN_NAME \
					--path='/var/www/wordpress' \
					--extra-php <<PHP
define('WP_MEMORY_LIMIT', '4096M');
PHP

# Installs wordpress and creates root user.
wp core install	--allow-root \
				--url=$WP_DOMAIN_NAME \
				--title=$WP_TITLE \
				--admin_user=$WP_ADMIN_USER \
				--admin_password=$WP_ADMIN_PASSWORD \
				--admin_email=$WP_ADMIN_EMAIL \
				--path='/var/www/wordpress'

# Add normal user.
wp user create	--allow-root \
				$WP_USER \
				$WP_USER_EMAIL \
				--user_pass=$WP_USER_PASSWORD \
				--role=editor \
				--path='/var/www/wordpress'

wp theme activate twentytwentythree --allow-root

# -F specifies php-fpm to run in foreground.
/usr/sbin/php-fpm7.4 -F
