#!/bin/sh

dir_storage="/etc/storage"

func_create_config()
{
	ip_address=`ip address show br0 | grep -w inet | sed 's|.* \(.*\)/.*|\1|'`
	cp -af /usr/share/privoxy/privoxy $dir_storage
	if [ ! -L "$dir_storage/privoxy/templates" ] ; then
		ln -s /usr/share/privoxy/templates $dir_storage/privoxy/templates
	fi
	chmod 755 $dir_storage/privoxy
	chmod 644 $dir_storage/privoxy/*
	sed -i "s/^listen-address.*/listen-address  ${ip_address}:8118/" $dir_storage/privoxy/config
	/sbin/mtd_storage.sh save
}

func_start()
{
	if [ ! -d "$dir_storage/privoxy" ] ; then
		func_create_config
	fi
	/usr/bin/logger -t privoxy Start privoxy
	/usr/sbin/privoxy --pidfile /var/run/privoxy.pid $dir_storage/privoxy/config
}

func_stop()
{
	/usr/bin/logger -t privoxy Stop privoxy
	killall -q privoxy
}

case "$1" in
start)
	func_start $2
	;;
stop)
	func_stop
	;;
*)
	echo "Usage: $0 {start|stop}"
	exit 1
	;;
esac

exit 0
