FROM debian:10.12-slim

# Install nginx and openssl
RUN apt update \
	&& apt upgrade -y \
	&& apt install -y nginx openssl

# Configure openssl (SSL - Secure Sockets Layer)
RUN mkdir -p /etc/nginx/ssl
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
        -out /etc/nginx/ssl/acaravan.pem \
        -keyout /etc/nginx/ssl/acaravan.key \
        -subj "/C=ES/ST=Spain/L=Spain/O=42 School/OU=acaravan/CN=acaravan/"

# Configure nginx
RUN mkdir -p /run/nginx
COPY ./conf/nginx.conf /etc/nginx/conf.d/nginx.conf

#COPY ./tools/index.html /var/www/html/index.html

EXPOSE 443

ENTRYPOINT [ "nginx", "-g", "daemon off;" ]
