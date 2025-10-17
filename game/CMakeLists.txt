
set(SOURCE_FILES src/main.cpp)
set(EXE_FILE Game)

add_executable(${EXE_FILE} ${SOURCE_FILES})


# linking stuff here
find_package(glad REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

target_link_libraries(${EXE_FILE} PRIVATE
        glad::glad
        glfw
        glm::glm
        )