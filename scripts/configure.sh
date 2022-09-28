#! /bin/bash
root=$( cd "$(dirname "${BASH_SOURCE[0]}")"/../ || exit ; pwd -P )

cd "$root" || exit
cmake -S . -B build "$@"