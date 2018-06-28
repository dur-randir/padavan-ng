
-- external 'udpxy' url for multicast playlists (udp://@...)
cfg.udpxy_url='http://gateway.lo:81'

-- downstream interface for builtin multicast proxy (comment 'cfg.udpxy_url' for processing 'udp://@...' playlists)
cfg.mcast_interface='eth2.2'

-- multicast interface for SSDP exchange, 'eth0', 'br0', 'br-lan' for example
cfg.ssdp_interface='br0'

-- Device name
cfg.name='xUPNP-IPTV'

-- syslog facility (syslog,local0-local7)
cfg.log_facility='local0'
