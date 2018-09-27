##################################################################
# Board PID # Board Name       # PRODUCT # Note
##################################################################
# ARCHERMR200  # TP-LINK ARCHER MR200    # MT7620  #
##################################################################

CFLAGS += -DBOARD_ARCHER_MR200 -DVENDOR_TPLINK
BOARD_NUM_USB_PORTS=1

### TP-LINK firmware description ###
TPLINK_HWID=0xd7500001
TPLINK_HWREV=0x4a
TPLINK_HWREVADD=0x1
TPLINK_FLASHLAYOUT=8Mmtk
TPLINK_HVERSION=3
