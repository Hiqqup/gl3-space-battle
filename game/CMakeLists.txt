
set(SOURCE_FILES src/main.cpp
        src/Game.cpp
        src/Game.h
        src/Shader.cpp
        src/Shader.h
        src/Mesh.cpp
        src/Mesh.h
        src/Entity.cpp
        src/Entity.h
        src/Ship.cpp
        src/Ship.h)
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