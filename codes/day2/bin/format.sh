#!/usr/bin/env sh
buildifier -r .
find . -iname *.h -o -iname *.cc | xargs clang-format -i -style=Google