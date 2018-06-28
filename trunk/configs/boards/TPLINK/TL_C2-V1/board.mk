##################################################################
# Board PID # Board Name       # PRODUCT # Note
##################################################################
# ARCHERC2  # TP-LINK ARCHER C2    # MT7620  #
##################################################################

CFLAGS += -DBOARD_ARCHER_C2 -DVENDOR_TPLINK
BOARD_NUM_USB_PORTS=1

### TP-LINK firmware description ###
TPLINK_HWID=0xC7500001
TPLINK_HWREV=0x32
TPLINK_HWREVADD=0x2
TPLINK_FLASHLAYOUT=8Mmtk
TPLINK_HVERSION=3

