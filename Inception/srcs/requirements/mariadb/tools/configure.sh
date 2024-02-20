#!/bin/bash

echo "CREATE DATABASE IF NOT EXISTS ${SQL_DATABASE};" > /var/lib/mysql/mariadb_init.sql
echo "CREATE USER IF NOT EXISTS '${SQL_USER}'@'%' IDENTIFIED BY '${SQL_PASSWORD}';" >> /var/lib/mysql/mariadb_init.sql
echo "GRANT ALL PRIVILEGES ON ${SQL_DATABASE}.* TO '${SQL_USER}'@'%' IDENTIFIED BY '${SQL_PASSWORD}';" >> /var/lib/mysql/mariadb_init.sql
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';" >> /var/lib/mysql/mariadb_init.sql
echo "FLUSH PRIVILEGES;" >> /var/lib/mysql/mariadb_init.sql

# The abscense of & character at the end indicates mysqld to run in foreground.
mysqld --init-file=/var/lib/mysql/mariadb_init.sql

# mysql -u acaravan -p
# SHOW DATABASES;
# USE acaravanDB;
# SHOW TABLES;
# SELECT * FROM <table>;
