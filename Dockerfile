# build builder
FROM alpine AS builder
MAINTAINER Gi Wah Dávalos Loo <giwirodavalos@gmail.com>
ARG PROYECT_NAME="white-rabbit"
ARG WORKDIR=/usr/local/src/${PROYECT_NAME}

# Install gcc
RUN apk add build-base
# Install libmicrohttpd
RUN apk add libmicrohttpd-dev

# Ensure workdir existence
RUN mkdir -p ${WORKDIR}

# Copy code
COPY . ${WORKDIR}
WORKDIR ${WORKDIR}

RUN make


# build dist image
FROM alpine AS release
ARG PROYECT_NAME="white-rabbit"
COPY --from=builder /usr/local/src/${PROYECT_NAME}/bin /app/
WORKDIR /app
ENTRYPOINT ./${PROYECT_NAME}
