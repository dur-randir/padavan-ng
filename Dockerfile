FROM lsiobase/ubuntu:xenial

# env setting
LABEL maintainer="Andy Voigt <voigt-andy@hotmail.de>"

# update and upgrade all pkgs
ENV DEBIAN_FRONTEND noninteractive
RUN \
  apt-get update && apt-get -yq dist-upgrade && \
  apt-get install -yq apt-utils locales

# set right locale and use it
RUN echo "en_US.UTF-8 UTF-8"> /etc/locale.gen && locale-gen
ENV LC_ALL en_US.UTF-8

# install all the required pkgs
RUN apt-get install -yq \
  unzip curl cmake gperf gawk flex bison nano help2man libtool-bin \
  git python-docutils gettext automake autopoint texinfo build-essential \
  pkg-config zlib1g-dev libgmp3-dev libmpc-dev libmpfr-dev libncurses5-dev libltdl-dev && \
  rm -rf \
    /tmp/* \
    /var/lib/apt/lists/* \
    /var/tmp/*

# clone repository
RUN git clone --depth=1 https://github.com/zanezam/padavan-ng.git /opt/padavan-ng

# fix permissions && build toolchain
RUN cd /opt/padavan-ng/toolchain && chmod a+x clean_sources.sh build_toolchain.sh && \
  ./clean_sources.sh && ./build_toolchain.sh

# default dir
WORKDIR /opt/padavan-ng
