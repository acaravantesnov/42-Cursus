FROM debian:10.12-slim

RUN apt update \
	&& apt upgrade -y \
	&& apt install -y nginx

COPY ./conf/nginx.conf /etc/nginx/conf.d/

EXPOSE 443

CMD [ "nginx", "-g", "daemon off;" ]
