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

find_package(PkgConfig REQUIRED)

if (UNIX)
    message(STATUS "Configuring for a UNIX / UNOX-Like System.")
    add_executable (BaseCalc "BaseCalc.c")
    target_link_libraries(BaseCalc PRIVATE m)
elseif(WIN32)
    enable_language(RC)
    message(STATUS "Configuring for a WIN32 System.")
    add_executable (BaseCalc "BaseCalc.c" "../install/Windows/BaseCalc.rc")
    target_link_options(BaseCalc PRIVATE "/SUBSYSTEM:WINDOWS" "/ENTRY:mainCRTStartup")
    set(CPACK_PACKAGE_VENDOR "BYK")
    set(CPACK_PACKAGE_NAME "BaseCalc")
    set(CPACK_PACKAGE_VERSION "1.2.0")
    set(CPACK_GENERATOR "NSIS")
    set(CPACK_NSIS_MODIFY_PATH ON)
    set(CPACK_NSIS_MUI_ICON "./icons/Windows/BaseCalc.ico")
    include(CPack)
endif()

pkg_check_modules(GTK REQUIRED IMPORTED_TARGET gtk4>=4.14)
if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET BaseCalc PROPERTY C_STANDARD 23)
endif()

target_link_libraries(BaseCalc PRIVATE PkgConfig::GTK)

install(FILES "BaseCalc.h" DESTINATION include)
