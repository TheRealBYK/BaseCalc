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

install(TARGETS BaseCalc DESTINATION bin)
install(DIRECTORY "build" DESTINATION lib)
install(FILES "BaseCalc.svg" DESTINATION share/icons/)
install(FILES "LICENSE" DESTINATION share/licenses/basecalc-git/)
install(FILES "README.md" DESTINATION share/doc/basecalc-git/)
install(FILES "BaseCalc.desktop" DESTINATION share/applications/)
