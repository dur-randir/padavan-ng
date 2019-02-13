##################################################################
# Board PID # Board Name       # PRODUCT # Note
##################################################################
# WR841N  # TP-LINK TL-WR841N    # MT7628  #
##################################################################

CFLAGS += -DBOARD_WR841N -DVENDOR_TPLINK
BOARD_NUM_USB_PORTS=0

### TP-LINK firmware description ###
TPLINK_HWID=0x08410014
TPLINK_HWREV=0x283
TPLINK_HWREVADD=0x14
TPLINK_FLASHLAYOUT=4Mmtk
TPLINK_HVERSION=3
