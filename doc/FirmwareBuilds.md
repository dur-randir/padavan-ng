# What is difference between the versions (full, base, etc.) of Firmware for routers Asus RT-N56U? #

## Firmware builds for router ASUS RT-N56U ##

In this section we will describe the differences between the various Firmware builds for router ASUS RT-N56U.

- - -

**On this page:**

* [Firmware builds for router ASUS RT-N56U](#markdown-header-firmware-builds-for-router-asus-rt-n56u)
    * [RT-N56U_XXX_aria](#markdown-header-rt-n56u_xxx_aria)

    * [RT-N56U_XXX_base](#markdown-header-rt-n56u_xxx_base)

    * [RT-N56U_XXX_dlna](#markdown-header-rt-n56u_xxx_dlna)

    * [RT-N56U_XXX_trmd](#markdown-header-rt-n56u_xxx_trmd)

    * [RT-N56U_XXX_mini](#markdown-header-rt-n56u_xxx_mini)

    * [RT-N56U_XXX_nano](#markdown-header-rt-n56u_xxx_nano)

- - -

### RT-N56U_XXX_aria ###

** Aria2 build (modified by ZaneZam because of image size issues)**

  *mandatory:*

  * [х] Linux kernel-3.4+ (with upstream backports).
  * [х] IPv6 full support (native and SIT tunnels).
  * [х] NTFS filesystem (Paragon ufsd 8.6 for ASUS).
  * [х] FAT16/FAT32/exFAT filesystem (FAT16/FAT32 via exFAT driver).
  * [х] EXT4/EXT3/EXT2 filesystem (EXT3/EXT2 via EXT4 driver).
  * [х] FUSE kernel modules.
  * [х] NFS kernel modules (NFSv2/3 client/server).
  * [х] IPSET kernel modules.
  * [х] dropbear (SSH client/server).
  * [х] sftp (SSH FTP server).
  * [x] vsftpd (FTP server).
  * [х] xupnpd (multicast IPTV->UPnP proxy).
  * [х] openvpn (security VPN client/server).
  * [х] https server for WebUI.

  *included:*

  * [+] aria2 (multi-protocol download manager).
  * [+] openssl binary (allow generate certificates for openvpn/https).

  *excluded:*

  * [-] minidlna (UPnP/DLNA A/V mediaserver).
  * [-] firefly (iTunes audio mediaserver).
  * [-] transmission (torrent client).
  * [-] UVC camera kernel modules.
  * [-] QoS kernel modules.
  * [-] IFB/IMQ kernel modules.
  * [-] USB HID kernel modules.
  * [-] XFS filesystem.
  * [-] CIFS client kernel modules.
  * [-] openssh (BSD SSH client/server).
  * [-] LPR printing daemon.
  * [-] USB-over-Ethernet printing daemon.
  * [-] samba (SMB server).
  * [-] tcpdump utility.
  * [-] parted utility.
  * [-] Stripped debug messages from Samba server.


### RT-N56U_XXX_base ###

**Base build**

  *mandatory:*

  * [х] Linux kernel-3.4+ (with upstream backports).
  * [х] IPv6 full support (native and SIT tunnels).
  * [х] NTFS filesystem (Paragon ufsd 8.6 for ASUS).
  * [х] FAT16/FAT32/exFAT filesystem (FAT16/FAT32 via exFAT driver).
  * [х] EXT4/EXT3/EXT2 filesystem (EXT3/EXT2 via EXT4 driver).
  * [х] FUSE kernel modules.
  * [х] UVC camera kernel modules.
  * [х] NFS kernel modules (NFSv2/3 client/server).
  * [х] IPSET kernel modules.
  * [х] LPR printing daemon.
  * [х] USB-over-Ethernet printing daemon.
  * [х] dropbear (SSH client/server).
  * [х] sftp (SSH FTP server).
  * [х] vsftpd (FTP server).
  * [х] samba (SMB server).
  * [х] xupnpd (multicast IPTV->UPnP proxy).
  * [х] openvpn (security VPN client/server).
  * [х] https server for WebUI.

  *included:*

  * [+] openssl binary (allow generate certificates for openvpn/https).
  * [+] tcpdump utility.

  *excluded:*

  * [-] minidlna (UPnP/DLNA A/V mediaserver).
  * [-] firefly (iTunes audio mediaserver).
  * [-] transmission (torrent client).
  * [-] aria2 (multi-protocol download manager).
  * [-] QoS kernel modules.
  * [-] IFB/IMQ kernel modules.
  * [-] USB HID kernel modules.
  * [-] XFS filesystem.
  * [-] CIFS client kernel modules.
  * [-] openssh (BSD SSH client/server).
  * [-] parted utility.
  * [-] Stripped debug messages from Samba server.


### RT-N56U_XXX_dlna ###

**DLNA build (modified by ZaneZam because of image size issues)**

  *mandatory:*

  * [х] Linux kernel-3.4+ (with upstream backports).
  * [х] IPv6 full support (native and SIT tunnels).
  * [х] NTFS filesystem (Paragon ufsd 8.6 for ASUS).
  * [х] FAT16/FAT32/exFAT filesystem (FAT16/FAT32 via exFAT driver).
  * [х] EXT4/EXT3/EXT2 filesystem (EXT3/EXT2 via EXT4 driver).
  * [х] FUSE kernel modules.
  * [х] UVC camera kernel modules.
  * [х] NFS kernel modules (NFSv2/3 client/server).
  * [х] IPSET kernel modules.
  * [х] LPR printing daemon.
  * [х] USB-over-Ethernet printing daemon.
  * [х] dropbear (SSH client/server).
  * [х] sftp (SSH FTP server).
  * [х] vsftpd (FTP server).
  * [х] samba (SMB server).
  * [х] xupnpd (multicast IPTV->UPnP proxy).
  * [х] openvpn (security VPN client/server).
  * [х] https server for WebUI.

  *included:*

  * [+] minidlna (UPnP/DLNA A/V mediaserver).

  *excluded:*

  * [-] firefly (iTunes audio mediaserver).
  * [-] aria2 (multi-protocol download manager).
  * [-] transmission (torrent client).
  * [-] transmission web control (advanced WebUI for transmission).
  * [-] QoS kernel modules.
  * [-] IFB/IMQ kernel modules.
  * [-] USB HID kernel modules.
  * [-] XFS filesystem.
  * [-] CIFS client kernel modules.
  * [-] openssh (BSD SSH client/server).
  * [-] openssl binary (allow generate certificates for openvpn/https).
  * [-] tcpdump utility.
  * [-] parted utility.
  * [-] Stripped debug messages from Samba server.


### RT-N56U_XXX_trmd ###

**Transmission build (modified by ZaneZam because of image size issues)**

  *mandatory:*

  * [х] Linux kernel-3.4+ (with upstream backports).
  * [х] IPv6 full support (native and SIT tunnels).
  * [х] NTFS filesystem (Paragon ufsd 8.6 for ASUS).
  * [х] FAT16/FAT32/exFAT filesystem (FAT16/FAT32 via exFAT driver).
  * [х] EXT4/EXT3/EXT2 filesystem (EXT3/EXT2 via EXT4 driver).
  * [х] FUSE kernel modules.
  * [х] NFS kernel modules (NFSv2/3 client/server).
  * [х] IPSET kernel modules.
  * [х] dropbear (SSH client/server).
  * [х] sftp (SSH FTP server).
  * [х] vsftpd (FTP server).
  * [х] xupnpd (multicast IPTV->UPnP proxy).
  * [х] openvpn (security VPN client/server).
  * [х] https server for WebUI.

  *included:*

  * [+] transmission (torrent client).
  * [+] transmission web control (advanced WebUI for transmission).
  * [+] openssl binary (allow generate certificates for openvpn/https).
  * [+] tcpdump utility.
  * [+] parted utility.

  *excluded:*

  * [-] minidlna (UPnP/DLNA A/V mediaserver).
  * [-] firefly (iTunes audio mediaserver).
  * [-] aria2 (multi-protocol download manager).
  * [-] UVC camera kernel modules.
  * [-] QoS kernel modules.
  * [-] IFB/IMQ kernel modules.
  * [-] USB HID kernel modules.
  * [-] XFS filesystem.
  * [-] CIFS client kernel modules.
  * [-] LPR printing daemon.
  * [-] USB-over-Ethernet printing daemon.
  * [-] samba (SMB server).
  * [-] openssh (BSD SSH client/server).
  * [-] Stripped debug messages from Samba server.


### RT-N56U_XXX_mini ###

**Mini build (added by ZaneZam and the default in this fork)**

  *mandatory:*

  * [х] Linux kernel-3.4+ (with upstream backports).
  * [х] IPv6 full support (native and SIT tunnels).
  * [х] NTFS filesystem (Paragon ufsd 8.6 for ASUS).
  * [х] EXT4/EXT3/EXT2 filesystem (EXT3/EXT2 via EXT4 driver).
  * [х] UVC camera kernel modules.
  * [х] NFS kernel modules (NFSv2/3 client/server).
  * [х] IPSET kernel modules.
  * [х] dropbear (SSH client/server).
  * [х] openvpn (security VPN client/server).
  * [х] https server for WebUI.

  *excluded:*

  * [-] NTFS filesystem (Paragon ufsd 8.6 for ASUS).
  * [-] FAT16/FAT32/exFAT filesystem (FAT16/FAT32 via exFAT driver).
  * [-] FUSE kernel modules.
  * [-] UVC camera kernel modules.
  * [-] NFS kernel modules (NFSv2/3 client/server).
  * [-] LPR printing daemon.
  * [-] USB Support.
  * [-] USB-over-Ethernet printing daemon.
  * [-] sftp (SSH FTP server).
  * [-] vsftpd (FTP server).
  * [-] samba (SMB server).
  * [-] xupnpd (multicast IPTV->UPnP proxy).
  * [-] minidlna (UPnP/DLNA A/V mediaserver).
  * [-] transmission (torrent client).


### RT-N56U_XXX_nano ###

**Nano build**

  *mandatory:*

  * [х] Linux kernel-3.4+ (with upstream backports).
  * [х] IPv6 full support (native and SIT tunnels).
  * [х] EXT4/EXT3/EXT2 filesystem (EXT3/EXT2 via EXT4 driver).
  * [х] USB-over-Ethernet printing daemon.
  * [х] dropbear (SSH client/server).

  *excluded:*

  * [-] minidlna (UPnP/DLNA A/V mediaserver).
  * [-] firefly (iTunes audio mediaserver).
  * [-] transmission (torrent client).
  * [-] aria2 (multi-protocol download manager).
  * [-] QoS kernel modules.
  * [-] IFB/IMQ kernel modules.
  * [-] USB HID kernel modules.
  * [-] XFS filesystem.
  * [-] NTFS filesystem (Paragon ufsd 8.6 for ASUS).
  * [-] FAT16/FAT32/exFAT filesystem (FAT16/FAT32 via exFAT driver).
  * [-] FUSE kernel modules.
  * [-] IPSET kernel modules.
  * [-] LPR printing daemon.
  * [-] UVC camera kernel modules.
  * [-] NFS kernel modules (NFSv2/3 client/server).
  * [-] CIFS client kernel modules.
  * [-] openssh (BSD SSH client/server).
  * [-] openssl binary (allow generate certificates for openvpn/https).
  * [-] tcpdump utility.
  * [-] parted utility.
  * [-] sftp (SSH FTP server).
  * [-] vsftpd (FTP server).
  * [-] samba (SMB server).
  * [-] xupnpd (multicast IPTV->UPnP proxy).
  * [-] openvpn (security VPN client/server).
  * [-] https server for WebUI.
  * [-] Stripped debug messages from Samba server.
----

### Main focus (and therefore it's config templates provided in this repo) is ONLY on the Asus RT-N56U router. However original firmware also includes templates testet for supported routers Asus RT-N65U/RT-N14U/RT-N11P. There are also several Firmware builds (base, full, etc.) which are not adressed here. The description of them [can be found here](https://bitbucket.org/padavan/rt-n56u/wiki/EN/FirmwareBuilds) ###