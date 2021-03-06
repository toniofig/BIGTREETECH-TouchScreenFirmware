#ifndef _TFT_800_480_H_
#define _TFT_800_480_H_

#define LCD_WIDTH   800
#define LCD_HEIGHT  480

#ifndef BYTE_HEIGHT
  #define BYTE_HEIGHT 24
#endif
#ifndef BYTE_WIDTH
  #define BYTE_WIDTH  (BYTE_HEIGHT/2)
#endif

#ifndef LARGE_BYTE_HEIGHT
  #define LARGE_BYTE_HEIGHT 32
#endif
#ifndef LARGE_BYTE_WIDTH
  #define LARGE_BYTE_WIDTH  18
#endif

#define ICON_WIDTH   160
#define ICON_HEIGHT  140
#define TITLE_END_Y  50
#define ICON_START_Y (TITLE_END_Y+10)

#define LIST_ICON_WIDTH   140
#define LIST_ICON_HEIGHT  110

#define INFOBOX_WIDTH     360
#define INFOBOX_HEIGHT    140

#define SMALLICON_WIDTH   24
#define SMALLICON_HEIGHT  24

// Status screen menu
#define SSICON_VAL_Y0             105
#define SSICON_NAME_Y0            10
#define STATUS_MSG_ICON_XOFFSET   5
#define STATUS_MSG_ICON_YOFFSET   5
#define STATUS_MSG_TITLE_XOFFSET  5
#define STATUS_MSG_BODY_XOFFSET   2
#define STATUS_MSG_BODY_YOFFSET   95
#define STATUS_MSG_BODY_BOTTOM    9
#define STATUS_TITLE_SHORT        20
#define STATUS_GANTRY_YOFFSET     6

//Heating Menu
#define PREHEAT_TITLE_Y   6
#define PREHEAT_TOOL_Y    65
#define PREHEAT_BED_Y     105

// Printing menu
#define PICON_LG_WIDTH     255
#define PICON_SM_WIDTH     201
#define PICON_HEIGHT       75
#define PICON_SPACE_X      ((LCD_WIDTH - PICON_LG_WIDTH*2 - PICON_SM_WIDTH - SPACE_X )/2)
#define PICON_SPACE_Y      (ICON_HEIGHT + SPACE_Y - PICON_HEIGHT*2)/2
#define PICON_TITLE_X      80
#define PICON_TITLE_Y      1
#define PICON_VAL_X        75
#define PICON_VAL_Y        (PICON_HEIGHT/2)
#define PICON_VAL_LG_EX    245
#define PICON_VAL_SM_EX    191

// Popup menu
#define POPUP_RECT_WINDOW         {SPACE_X*2, TITLE_END_Y, LCD_WIDTH - SPACE_X*2, LCD_HEIGHT - SPACE_Y}
#define POPUP_TITLE_HEIGHT        80
#define POPUP_BOTTOM_HEIGHT       105
#define POPUP_BUTTON_HEIGHT       75
#define POPUP_RECT_SINGLE_CONFIRM {320, LCD_HEIGHT- SPACE_Y - 10 - POPUP_BUTTON_HEIGHT, 480, LCD_HEIGHT - SPACE_Y - 10}
#define POPUP_RECT_DOUBLE_CONFIRM {140, LCD_HEIGHT- SPACE_Y - 10 - POPUP_BUTTON_HEIGHT, 300, LCD_HEIGHT - SPACE_Y - 10}
#define POPUP_RECT_DOUBLE_CANCEL  {500, LCD_HEIGHT- SPACE_Y - 10 - POPUP_BUTTON_HEIGHT, 660, LCD_HEIGHT - SPACE_Y - 10}

// W25Qxx SPI Flash
/*
 * Because of W25Qxx takes 4K as a sector, the entire sector must be erased before writing.
 * The starting address of each file must be 4K(0x1000) aligned in order to avoid erasing the data of the previous file
 */
#define W25QXX_SECTOR_SIZE (0x1000) // 4096byte = 4K
// Address in SPI Flash W25Qxx                                        /** Memory occupied **/
#define LOGO_ADDR               0x0                                   // 800*480*2 = 0xBB800(+0xBC000) bytes
#define WORD_UNICODE            0xBC000                               // 24*24/8 * 65536(unicode) = 0x480000 bytes(4.5M)
#define BYTE_ASCII_ADDR         (WORD_UNICODE+0x480000)               // 24*12/8 * 95(visible ascii) = 0x0D5C (+0x1000 4K)
#define LARGE_FONT_ADDR         (BYTE_ASCII_ADDR+0x1000)
//#define BYTE_RESERVE_ADDR      0x710000
#define STRINGS_STORE_ADDR      (LARGE_FONT_ADDR+0x3000)                      //for label strings from config file
#define STRINGS_STORE_MAX_SIZE  0x5000                                        //label strings max size
#define PRINT_GCODES_ADDR       (STRINGS_STORE_ADDR+STRINGS_STORE_MAX_SIZE)   //for start/end/cancel gcodes from config file
#define PRINT_GCODES_MAX_SIZE    0x5000                                       //start/end/cancel gcodes  max size
#define CUSTOM_GCODE_ADDR       (PRINT_GCODES_ADDR+PRINT_GCODES_MAX_SIZE)     //for custom gcodes from config file
#define CUSTOM_GCODE_MAX_SIZE    0x5000                                       //custom gocdes max size

#define ICON_ADDR(num)          ((num)*0xB000+CUSTOM_GCODE_ADDR+CUSTOM_GCODE_MAX_SIZE)  // 160*140*2 = 0xAF00 (+0xB000) per button icon
#define INFOBOX_ADDR            (ICON_ADDR(ICON_PREVIEW) + 0xB000)    // 360*140*2 = 0x189C0 (+0x19000)
#define SMALL_ICON_START_ADDR   (INFOBOX_ADDR+0x19000)                // 24*24*2 = 0x480 (+0x1000) per small icon
#define SMALL_ICON_ADDR(num)    ((num)*0x2000+SMALL_ICON_START_ADDR)

#endif
