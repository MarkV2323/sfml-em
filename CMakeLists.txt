cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(sfml-em)

# Setup SFML_PATH, must use \\ due to Windows!
set(SFML_PATH C:\\Users\\Mark\\Desktop\\cpp-apps\\lib\\SFML-2.6.1)

# Set Headers
set (HEADERS 
    src/entities/entity.h
    src/entityManager/entityManager.h
    src/entityManagerTwo/entityManagerTwo.h
    src/tests/emTwoTests.h
)

# Set Sources
set(SOURCES
    ${HEADERS}
    src/main.cc
    src/entities/entity.cc
    src/entityManager/entityManager.cc
    src/entityManagerTwo/entityManagerTwo.cc
)

# Build Main Executable (Our Target)
add_executable(sfml-em ${SOURCES})

# Inlcude our internal headers, SFML headers
target_include_directories(sfml-em PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(sfml-em PRIVATE ${SFML_PATH}/include)
target_link_directories(sfml-em PRIVATE ${SFML_PATH}/lib) 

# Specify what sfml-libs to link into our target
target_link_libraries(sfml-em sfml-system sfml-window sfml-graphics sfml-audio sfml-network sfml-main)