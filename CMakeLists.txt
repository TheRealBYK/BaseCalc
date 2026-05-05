# Copyright (c) 2026 BYK. All Rights Reserved.
#
# This file is part of BaseCalc.
#
# BaseCalc is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, under version 2 of the License.
#
# BaseCalc is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along with BaseCalc. If not, see <https://www.gnu.org/licenses/>.
#
# Maintainer: BYK <bykdev@proton.me>

cmake_minimum_required(VERSION 3.8)

project("BaseCalc")

# Include sub-projects.
add_subdirectory("BaseCalc")

if(EXISTS /usr/share/icons/BaseCalc.svg)
    file(REMOVE /usr/share/icons/BaseCalc.svg)
endif()

if(EXISTS /usr/share/icons/hicolor/48x48/apps/BaseCalc.svg)
    file(REMOVE /usr/share/icons/hicolor/48x48/apps/BaseCalc.svg)
endif()

if(EXISTS /usr/share/icons/hicolor/256x256/apps/BaseCalc.svg)
    file(REMOVE /usr/share/icons/hicolor/256x256/apps/BaseCalc.svg)
endif()

if(EXISTS /usr/share/icons/hicolor/512x512/apps/BaseCalc.svg)
    file(REMOVE /usr/share/icons/hicolor/512x512/apps/BaseCalc.svg)
endif()

if (LINUX)
    install(TARGETS BaseCalc DESTINATION bin)
    install(DIRECTORY "build" DESTINATION lib)
    install(FILES "./icons/Linux/16x16/BaseCalc.png" DESTINATION share/icons/hicolor/16x16/apps/)
    install(FILES "./icons/Linux/32x32/BaseCalc.png" DESTINATION share/icons/hicolor/32x32/apps/)
    install(FILES "./icons/Linux/48x48/BaseCalc.png" DESTINATION share/icons/hicolor/48x48/apps/)
    install(FILES "./icons/Linux/64x64/BaseCalc.png" DESTINATION share/icons/hicolor/64x64/apps/)
    install(FILES "./icons/Linux/128x128/BaseCalc.png" DESTINATION share/icons/hicolor/128x128/apps/)
    install(FILES "./icons/Linux/256x256/BaseCalc.png" DESTINATION share/icons/hicolor/256x256/apps)
    install(FILES "./icons/Linux/512x512/BaseCalc.png" DESTINATION share/icons/hicolor/512x512/apps/)
    install(FILES "./icons/Linux/1024x1024/BaseCalc.png" DESTINATION share/icons/hicolor/1024x1024/apps/)
    install(FILES "./icons/Linux/scalable/BaseCalc.svg" DESTINATION share/icons/hicolor/scalable/apps/)
    install(FILES "LICENSE" DESTINATION share/licenses/basecalc-git/)
    install(FILES "README.md" DESTINATION share/doc/basecalc-git/)
    install(FILES "./install/Linux/BaseCalc.desktop" DESTINATION share/applications/)
elseif(WIN32)
    if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	set(CMAKE_INSTALL_PREFIX "C:/Program Files/BaseCalc" CACHE PATH "..." FORCE)
    endif()
    install(TARGETS BaseCalc RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
    install(FILES "./icons/Windows/BaseCalc.ico" DESTINATION app)
    install(FILES "./install/Windows/BaseCalc.rc" DESTINATION app)
    install(CODE "execute_process(COMMAND cmd /c windres 'C:\Program Files\BaseCalc\app\BaseCalc.rc' -o 'C:\Program Files\BaseCalc\app\BaseCalc.o')")
    add_executable(BaseCalc "C:\Program Files\BaseCalc\app\BaseCalc.o")
    set(CPACK_PACKAGE_VENDOR "BYK")
    set(CPACK_PACKAGE_NAME "BaseCalc")
    set(CPACK_PACKAGE_VERSION "1.2.0")
    set(CPACK_GENERATOR "NSIS")
    set(CPACK_NSIS_MODIFY_PATH ON)
    include(CPack)
endif()
