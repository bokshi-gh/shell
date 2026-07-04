rm -rf build

mkdir -p build
cd build

cmake ..
cmake --build .
cmake --install . --prefix ../dist
