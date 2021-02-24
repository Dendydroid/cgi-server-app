FROM ubuntu:20.04

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update && apt-get install -y apache2 vim g++

WORKDIR /var/www/cgi-bin/

RUN rm /etc/apache2/sites-available/000-default.conf \
    && rm /etc/apache2/sites-enabled/000-default.conf

COPY ./docker/apache/default.conf /etc/apache2/sites-available/default.conf

COPY ./app/index /var/www/cgi-bin/index

COPY ./docker/build.sh /srv/build.sh

RUN chmod -R 755 /var/www/cgi-bin

RUN ln -s /srv/build.sh /usr/bin/build-server

RUN cd /etc/apache2/sites-available && a2ensite default.conf

RUN a2enmod cgi && a2enmod cgid

EXPOSE 80

CMD apachectl -D FOREGROUND
