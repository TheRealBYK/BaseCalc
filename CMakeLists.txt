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

install(TARGETS BaseCalc DESTINATION bin)
install(DIRECTORY "build" DESTINATION lib)
install(FILES "./icons/48x48/BaseCalc.png" DESTINATION share/icons/hicolor/48x48/apps/)
install(FILES "./icons/256x256/BaseCalc.png" DESTINATION share/icons/hicolor/256x256/apps)
install(FILES "./icons/512x512/BaseCalc.png" DESTINATION share/icons/hicolor/512x512/apps/)
install(FILES "./icons/scalable/BaseCalc.svg" DESTINATION share/icons/hicolor/scalable/apps/)
install(FILES "LICENSE" DESTINATION share/licenses/basecalc-git/)
install(FILES "README.md" DESTINATION share/doc/basecalc-git/)
install(FILES "BaseCalc.desktop" DESTINATION share/applications/)
