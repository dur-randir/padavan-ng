##################################################################
# Board PID # Board Name       # PRODUCT # Note
##################################################################
# ARCHERC50  # TP-LINK ARCHER C50    # MT7628  #
##################################################################

CFLAGS += -DBOARD_ARCHER_C50 -DVENDOR_TPLINK
BOARD_NUM_USB_PORTS=0

### TP-LINK firmware description ###
TPLINK_HWID=0x1D9BA4
TPLINK_HWREV=0x83
TPLINK_HWREVADD=0x1
TPLINK_FLASHLAYOUT=8Mmtk
TPLINK_HVERSION=3
