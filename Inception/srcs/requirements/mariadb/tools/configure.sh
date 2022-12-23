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

# Start mysqld and grant privileges
touch temp
cat << EOF > temp
USE mysql;
USE wordpress;
GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY 'acaravan.123' WITH GRANT OPTION;
EOF
/usr/sbin/mysqld --user=$MYSQL_USR --bootstrap < temp
rm -f temp

sed -i "s|skip-networking|# skip-networking|g" /etc/mysql/my.cnf
sed -i "s|.*bind-address\s*=.*|bind-address=0.0.0.0|g" /etc/mysql/my.cnf

# Run mysqld
exec /usr/sbin/mysqld --user=$MYSQL_USR --console

#tail -f /dev/null
