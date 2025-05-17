GREEN='\033[0;32m'
NC='\033[0m' # No Color (reset)

echo ""

rm -rf build

mkdir -p build
cd build

echo -e "${GREEN}***Generating build files***${NC}"
cmake ..
echo ""

echo -e "${GREEN}***Building the project***${NC}"
cmake --build .
echo ""

echo -e "${GREEN}***Installing the project***${NC}"
cmake --install . --prefix ../dist
echo ""

