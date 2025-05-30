cd cicorun_old

mkdir -p build
cat <<EOF > CMakeLists.txt 
# Build active architecture only -> Yes, Architectures -> Standard Architectures
cmake_minimum_required(VERSION 3.0)
project(CicoProject)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_SUPPRESS_REGENERATION ON)
find_package(SDL2 REQUIRED)
include_directories(\${SDL2_INCLUDE_DIRS})
file(GLOB SOURCES "*.cpp")
add_executable(CicoProject \${SOURCES})
target_link_libraries(CicoProject \${SDL2_LIBRARIES})
#install(TARGETS CicoProject DESTINATION bin)
EOF
cd build
cmake -G "Xcode" ..
mv ./CicoProject.xcodeproj ..
cd ..
#rm CMakeLists.txt
rm -rf build
