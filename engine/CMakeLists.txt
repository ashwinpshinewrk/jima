add_library(glad_loader STATIC glad.c)

set_target_properties(glad_loader PROPERTIES LINKER_LANGUAGE C POSITION_INDEPENDENT_CODE ON)

add_library(engine STATIC src/engine.cpp src/stb_image.cpp src/mesh.cpp)

set_target_properties(engine PROPERTIES POSITION_INDEPENDENT_CODE ON)


target_include_directories(glad_loader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(engine PUBLIC glad_loader ${GLFW_LIBRARIES} OpenGL::GL X11 pthread ${CMAKE_DL_LIBS})
