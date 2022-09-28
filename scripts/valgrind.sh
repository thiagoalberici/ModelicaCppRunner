#! /bin/bash
parent_path=$( cd "$(dirname "${BASH_SOURCE[0]}")"/../ || exit ; pwd -P )

cd "$parent_path"/build/src/ || exit
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --show-reachable=no --keep-debuginfo=yes --suppressions=../../omc-boehm-gc.suppr ./ModelicaMemAlloc "$@"