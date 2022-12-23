#!/bin/bash

# Create mysqld directory
if [ ! -d "var/run/mysqld/" ]; then
	mkdir -p var/run/mysqld/
fi

echo 'debconf debconf/frontend select Noninteractive' | debconf-set-selections
chmod 777 /var/lib/mysql
chmod 777 /var/run/mysqld
mysql_install_db --user=mysql --datadir=/var/lib/mysql

# Start mysql
service mysql start

# Download MariaDB on the container
wget https://downloads.mariadb.com/MariaDB/mariadb_repo_setup

# Install MariaDB on the container
sh mariadb_repo_setup

# Create root user
mysql -u root

# Install mysqlclient
apt install -y default-mysql-client

# Give privileges to root user
GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY 'Inceptiondb.123' WITH GRANT OPTION;

# Create database
exec /usr/bin/mysqld --user=mysql --console
#tail -f /dev/null
