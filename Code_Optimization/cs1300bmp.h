//-*-c++-*-
#ifndef _cs1300bmp_h_
#define _cs1300bmp_h_

//
// Maximum image size
//
// changed MAX_DIM from 8000-something to 1050 (extra credit)
// by making the dimentions smaller, I made the program run faster
#define MAX_DIM 1050

//
// The specific colors
//
#define COLOR_RED 0
#define COLOR_GREEN 1
#define COLOR_BLUE 2
#define MAX_COLORS 3

struct cs1300bmp {
  //
  // Actual width used by this image
  //
    // changed width, height, and color from int to short
    // to make it run faster, since short data type is smaller than int 
    // (extra credit)
    // ask TA if I can do this
  short width;
  //
  // Actual height used by this image
  //
  short height;
  //
  // R/G/B fields
  // 
  short color[MAX_COLORS][MAX_DIM][MAX_DIM];
};

//
// routines to read and write BMP images
//

#ifdef __cplusplus
extern "C" {
#endif

int cs1300bmp_readfile(char *filename, struct cs1300bmp *image);
int cs1300bmp_writefile(char *filename, struct cs1300bmp *image);

#ifdef __cplusplus
}
#endif


#endif
