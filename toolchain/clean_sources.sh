#!/bin/bash

echo "=================REMOVE-OLD-BUILD-TREE=================="

if [ -f ct-ng ]; then
	./ct-ng distclean || exit 1
fi
if [ -f Makefile ]; then
	make mrproper || exit 1
fi
if [ -d dl ]; then
        rm -rf dl
fi
if [ -d out ]; then
	rm -rf out
fi

echo "====================All IS DONE!========================"
