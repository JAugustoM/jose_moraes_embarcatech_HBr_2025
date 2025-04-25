#ifndef SSD1306_FONT_CP437_H // Start of SSD1306_FONT_CP437_H
#define SSD1306_FONT_CP437_H

#include <stdint.h>

/**
 * 
 * ******************** DO NOT MODIFY THIS FILE MANUALLY! ********************
 * The file was generated with SSD1306Fnt font generator, so do not edit it  
 * unless you are 100000% sure in your actions. If you need something to have 
 * changed in the file, the best solution is to use SSD1306Fnt again. 
 *
 **/

#define SSD1306_CP437_GLYPH_COUNT	0x41u

const uint8_t* ssd1306_cp437_get_glyph(uint32_t utf8_code);

#endif // End of SSD1306_FONT_CP437_H
