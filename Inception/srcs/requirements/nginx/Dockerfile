# Build from penultimate stable Debian version (bullseye) image.
FROM debian:bullseye

RUN apt update -y && \
	apt upgrade -y && \
	apt install nginx vim curl -y

RUN mkdir -p /etc/nginx/ssl

RUN apt install openssl -y

# Configure openssl (SSL - Secure Sockets Layer).
# - "req" with "-x509" generates a self-signed certificate.
# - "-nodes" indicates not to encrypt the private key with a password.
# - "-out" specifies where the certificate should be stored.
# - "-keyout" specifies where the private key should be stored.
# - "-subj" specifies the subject of the certificate.
RUN openssl	req -x509 -nodes -days 365 -newkey rsa:2048 \
			-out /etc/ssl/certs/inception.crt \
			-keyout /etc/ssl/private/inception.key \
			-subj "/C=ES/ST=Spain/L=Spain/O=42School/OU=acaravan/CN=acaravan/UID=login"

# Configure nginx
RUN mkdir -p /var/run/nginx
COPY ./conf/nginx.conf /etc/nginx/nginx.conf

RUN mkdir -p /var/www/wordpress
# Main root
RUN chmod 755 /var/www/wordpress
# Main user
RUN chown -R www-data:www-data /var/www/wordpress

# Daemon off to make nginx process run in foreground and stay connected to the
# terminal.
CMD [ "nginx", "-g", "daemon off;" ]
