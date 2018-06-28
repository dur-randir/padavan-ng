##################################################################
# Board PID # Board Name       # PRODUCT # Note
##################################################################
# MR3420  # TP-LINK TL-MR3420    # MT7628  #
##################################################################

CFLAGS += -DBOARD_MR3420 -DVENDOR_TPLINK
BOARD_NUM_USB_PORTS=1

### TP-LINK firmware description ###
TPLINK_HWID=0x34200005
TPLINK_HWREV=0x5
TPLINK_HWREVADD=0x5
TPLINK_FLASHLAYOUT=8Mmtk
TPLINK_HVERSION=3
