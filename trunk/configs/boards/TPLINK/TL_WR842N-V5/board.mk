##################################################################
# Board PID # Board Name       # PRODUCT # Note
##################################################################
# WR842N  # TP-LINK TL-WR842N    # MT7628  #
##################################################################

CFLAGS += -DBOARD_WR842N -DVENDOR_TPLINK
BOARD_NUM_USB_PORTS=1

### TP-LINK firmware description ###
TPLINK_HWID=0x08420005
TPLINK_HWREV=0x5
TPLINK_HWREVADD=0x5
TPLINK_FLASHLAYOUT=8Mmtk
TPLINK_HVERSION=3
