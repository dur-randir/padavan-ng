#!/bin/sh

resolver=$(nvram get dnscrypt_resolver)
localipaddr=$(nvram get dnscrypt_ipaddr)
localport=$(nvram get dnscrypt_port)
options=$(nvram get dnscrypt_options)

func_start()
{
	# Start dnscrypt-proxy

	/usr/bin/logger -t DNSCrypt-proxy listening on $localipaddr:$localport.
	/usr/sbin/dnscrypt-proxy -R $resolver -a $localipaddr:$localport -u dnscrypt -d $options
}

func_stop()
{
	# Stop dnscrypt-proxy

	/usr/bin/logger -t DNSCrypt-proxy service is stopped.
	killall -q dnscrypt-proxy
}

case "$1" in
start)
	func_start $2
	;;
stop)
	func_stop
	;;
restart)
	func_stop
	func_start $2
	;;
*)
	echo "Usage: $0 {start|stop|restart}"
	exit 1
	;;
esac

exit 0
