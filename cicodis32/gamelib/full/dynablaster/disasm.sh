#!/bin/bash
cd "$(dirname "$0")"
./cicodis dynablaster.txt 2>/dev/null > host/dynablaster.cpp
patch -p0 < dynablaster.patch
