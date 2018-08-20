#!/usr/bin/env bash
set -e

PROYECT_NAME=white-rabbit

GREEN='\033[0;32m'
NC='\033[0m'
# Multi-Stage baby 8-)

# Build builder
echo -e "${GREEN}Building builder ...${NC}"
docker build --target builder -t ${PROYECT_NAME}:build .
# Create a container named builder for our built image
echo -e "${GREEN}Create builder container ...${NC}"
docker create --name builder ${PROYECT_NAME}:build
# Build release
echo -e "${GREEN}Building release ...${NC}"
docker build --target release -t ${PROYECT_NAME}:latest .
# Clean up
echo -e "${GREEN}Cleaning up ...${NC}"
docker rm -f builder
docker rmi ${PROYECT_NAME}:build
