#!/bin/bash

echo "=================REMOVE-OLD-BUILD-TREE=================="

git clean -xfd ../toolchain
git checkout ../toolchain

echo "====================All IS DONE!========================"
