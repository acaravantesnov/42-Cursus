#!/bin/bash

# Create mysqld directory
if [ ! -d "var/run/mysqld/" ]; then
	mkdir -p var/run/mysqld/
fi

if [ ! -d "usr/bin/mysqld" ]; then
	mkdir -p usr/bin/mysqld
fi

echo 'debconf debconf/frontend select Noninteractive' | debconf-set-selections
chmod 777 /var/lib/mysql
chmod 777 /var/run/mysqld
mysql_install_db --user=$MYSQL_USR --datadir=/var/lib/mysql > /dev/null

sed -i "s|skip-networking|# skip-networking|g" /etc/mysql/my.cnf
sed -i "s|.*bind-address\s*=.*|bind-address=0.0.0.0|g" /etc/mysql/my.cnf

# Start mysqld and grant privileges
touch temp
cat << EOF > temp
USE mysql;

FLUSH PRIVILEGES;
DELETE FROM	mysql.user WHERE User='';
DROP DATABASE test;
DELETE FROM mysql.db WHERE Db='test';
DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');
ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PSSWD';
CREATE DATABASE $WP_DB_NAME CHARACTER SET utf8 COLLATE utf8_general_ci;
CREATE USER '$WP_DB_USR'@'%' IDENTIFIED by '$WP_DB_PSSWD';

GRANT ALL PRIVILEGES ON $WP_DB_NAME.* TO '$WP_DB_USR'@'%';

FLUSH PRIVILEGES;
EOF
/usr/sbin/mysqld --user=$MYSQL_USR --bootstrap < temp
rm -f temp

# Run mysqld
exec /usr/sbin/mysqld --user=$MYSQL_USR --console

#tail -f /dev/null
