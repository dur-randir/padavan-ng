##################################################################
# Board PID # Board Name       # PRODUCT # Note
##################################################################
# WR840N  # TP-LINK TL-WR840N    # MT7628  #
##################################################################

CFLAGS += -DBOARD_WR840N -DVENDOR_TPLINK
BOARD_NUM_USB_PORTS=0

### TP-LINK firmware description ###
TPLINK_HWID=0x08400004
TPLINK_HWREV=0x1
TPLINK_HWREVADD=0x4
TPLINK_FLASHLAYOUT=8Mmtk
TPLINK_HVERSION=3
