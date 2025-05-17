#!/bin/bash

GREEN='\033[0;32m'
NC='\033[0m' # No Color

echo ""

echo -e "${GREEN}***Cleaning build and dist directories***${NC}"

rm -rf build dist

echo -e "${GREEN}***Clean complete***${NC}"

echo ""

