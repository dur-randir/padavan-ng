##################################################################
# Board PID # Board Name       # PRODUCT # Note
##################################################################
# WR845N  # TP-LINK TL-WR845N    # MT7628  #
##################################################################

CFLAGS += -DBOARD_WR845N -DVENDOR_TPLINK
BOARD_NUM_USB_PORTS=0

### TP-LINK firmware description ###
TPLINK_HWID=0x08450003
TPLINK_HWREV=0x1
TPLINK_HWREVADD=0x3
TPLINK_FLASHLAYOUT=4Mmtk
TPLINK_HVERSION=3
