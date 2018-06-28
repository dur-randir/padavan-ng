##################################################################
# Board PID # Board Name       # PRODUCT # Note
##################################################################
# ARCHERC20  # TP-LINK ARCHER C20    # MT7620  #
##################################################################

CFLAGS += -DBOARD_ARCHER_C20 -DVENDOR_TPLINK
BOARD_NUM_USB_PORTS=1

### TP-LINK firmware description ###
TPLINK_HWID=0xc2000001
TPLINK_HWREV=0x44
TPLINK_HWREVADD=0x1
TPLINK_FLASHLAYOUT=8Mmtk
TPLINK_HVERSION=3

