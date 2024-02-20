# Build from penultimate stable Debian version (bullseye) image.
FROM debian:bullseye

# Commands to run during building process.
RUN	apt-get update -y && \
	apt-get upgrade -y && \
	apt-get install mariadb-server -y

# Copy configuration files.
COPY conf/50-server.cnf	/etc/mysql/mariadb.conf.d/50-server.cnf

RUN	mkdir -p /var/run/mysqld && \
	mkdir -p /var/lib/mysql

COPY tools/configure.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/configure.sh

# Set permissions
RUN chown -R mysql:mysql /var/run/mysqld && \
	chown -R mysql:mysql /var/lib/mysql
RUN chmod 777 /var/run/mysqld

CMD [ "sh", "/usr/local/bin/configure.sh" ]
