FROM debian:10.12-slim

# Install nginx
RUN apt update \
	&& apt upgrade -y \
	&& apt install -y nginx

# Install openssl
RUN mkdir /etc/nginx/ssl
RUN apt install -y openssl
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
        -out /etc/nginx/ssl/acaravan.pem \
        -keyout /etc/nginx/ssl/acaravan.key \
        -subj "/C=IT/ST=Spain/L=Spain/O=42 School/OU=acaravan/CN=acaravan/"

# 
COPY ./conf/nginx.conf /etc/nginx/conf.d/nginx.conf
COPY ./tools/index.html /var/www/html/index.html

EXPOSE 443

ENTRYPOINT [ "nginx", "-g", "daemon off;" ]
