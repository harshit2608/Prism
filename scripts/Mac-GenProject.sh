# Author : Harshit Bargujar
# Copyright (c) Prism
# Script to generate project on Macos
echo "Generating project for macos with gmake2 and clang"
./vendor/premake/bin/premake5 gmake2 --cc=clang --verbose