find_package(PkgConfig REQUIRED)

add_executable (BaseCalc "BaseCalc.c")

pkg_check_modules(GTK REQUIRED IMPORTED_TARGET gtk4>=4.14)
if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET BaseCalc PROPERTY C_STANDARD 23)
endif()

target_link_libraries(BaseCalc PRIVATE PkgConfig::GTK m)
