##################################################################
# Board PID # Board Name       # PRODUCT # Note
##################################################################
# MR3020  # TP-LINK TL-MR3020    # MT7628  #
##################################################################

CFLAGS += -DBOARD_MR3020 -DVENDOR_TPLINK
BOARD_NUM_USB_PORTS=1

### TP-LINK firmware description ###
TPLINK_HWID=0x30200003
TPLINK_HWREV=0x3
TPLINK_HWREVADD=0x3
TPLINK_FLASHLAYOUT=8Mmtk
TPLINK_HVERSION=3
