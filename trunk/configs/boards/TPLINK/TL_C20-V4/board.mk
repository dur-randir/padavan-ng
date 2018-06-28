##################################################################
# Board PID # Board Name       # PRODUCT # Note
##################################################################
# ARCHERC20  # TP-LINK ARCHER C20    # MT7628  #
##################################################################

CFLAGS += -DBOARD_ARCHER_C20 -DVENDOR_TPLINK
BOARD_NUM_USB_PORTS=0

### TP-LINK firmware description ###
TPLINK_HWID=0xc200004
TPLINK_HWREV=0x1
TPLINK_HWREVADD=0x4
TPLINK_FLASHLAYOUT=8Mmtk
TPLINK_HVERSION=3
