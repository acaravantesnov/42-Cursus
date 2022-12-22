FROM debian:10.12-slim

RUN apt update \
	&& apt upgrade -y \
	&& apt install -y nginx

# RUN mkdir /etc/nginx/ssl
# RUN apt install -y openssl
# RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
#         -out /etc/nginx/ssl/raccoman.pem \
#         -keyout /etc/nginx/ssl/raccoman.key \
#         -subj "/C=IT/ST=Spain/L=Spain/O=42 School/OU=acaravan/CN=acaravan/"

COPY ./conf/nginx.conf /etc/nginx/conf.d/
COPY ./tools/index.html /var/www/html/

EXPOSE 443

CMD [ "nginx", "-g", "daemon off;" ]
