##################################################################
# Board PID # Board Name       # PRODUCT # Note
##################################################################
# WR841N  # TP-LINK TL-WR841N    # MT7628  #
##################################################################

CFLAGS += -DBOARD_WR841N -DVENDOR_TPLINK
BOARD_NUM_USB_PORTS=1

### TP-LINK firmware description ###
TPLINK_HWID=0x08410013
TPLINK_HWREV=0x268
TPLINK_HWREVADD=0x13
TPLINK_FLASHLAYOUT=8Mmtk
TPLINK_HVERSION=3
