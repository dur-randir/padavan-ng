# BUILD INSTRUCTION #

1) You need Linux environment to build the firmware. Ubuntu 16.04.1 LTS and
   Debian 9.x distros has been tested and recommended.
2) Build cross-toolchain for MIPS32_R2 CPU (binutils-2.31, gcc-740, uclibc-1.31)
   from external package toolchain-mipsel.
```bash
cd toolchain && ./build_toolchain.sh
```
3) Configure firmware content via .config file. Use comment mark # for
   disable features. Change "CONFIG_TOOLCHAIN_DIR=" param to target cross-toolchain
   directory.
```bash
vi trunk/.config
```
4) Build firmware via "build_firmware" script. After the build is finished,
   the firmware file (*.trx) will be placed to directory "images".
```bash
cd trunk && ./build_firmware.sh
```

# NOTE #

You need following packages to build the firmware under Debian 9.x 'Stretch':
- autoconf
- automake
- bison
- build-essential
- file
- flex
- gawk
- gettext
- help2man
- kmod
- libtool-bin
- libltdl-dev
- libncurses5-dev
- pkg-config
- sudo
- texinfo
- unzip
- wget
- zlib1g-dev
