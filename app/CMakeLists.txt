set(GAME_NAME "MyGame")

add_executable(${GAME_NAME} main.cpp)

target_link_libraries(${GAME_NAME} PRIVATE engine)
