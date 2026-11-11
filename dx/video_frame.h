// Decoder-independent, limited-range BT.601 planar YUV row conversion.
#pragma once
#include <stdint.h>

enum VideoSurfaceType : uint32_t {
    VIDEO_XRGB8888 = 3,
    // BINKSURFACE32A: the same B, G, R bytes with an alpha byte. A video
    // without an alpha plane is opaque, so it is 0xff - a game that draws the
    // frame with alpha blending saw nothing when this type was refused and the
    // texture stayed as it was.
    VIDEO_ARGB8888 = 5,
    VIDEO_RGB555 = 9,
    VIDEO_RGB565 = 10,
};

// chroma_shift is 1 for YUV420P or 2 for YUV410P. The caller selects
// the chroma row for y >> chroma_shift and supplies width * bpp output bytes.
void video_frame_convert_row(uint8_t *dest, const uint8_t *y, const uint8_t *u, const uint8_t *v,
                             uint32_t width, VideoSurfaceType type, unsigned chroma_shift = 1);
