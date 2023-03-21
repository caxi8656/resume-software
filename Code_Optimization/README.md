# Code Optimization, C++
Catherine Xie

This project deals optimizing memory intensive code in an image processing application. The goal is to improve the overall performance of the application by a factor of about 25. The code is structured as five nested for loops and implements a filter using a convolution operation. The routine that is used to apply the filter is instrumented using the rdtscll function to record the starting and finishing times in terms of CPU cycles. The application reads in an image and a filter, represented as a three-dimensional array and an n x n array of numbers, respectively.

  * `cs1300bmp.h` Contains routines for reading and writing images in the BMP format
  * `Filter.h` and `Filter.cpp` Contain the Filter class implementation, is where optimization occurs.
  * `boats.bmp` and `blocks-small.bmp` Contain the test images to calculate runtime.

After optimizing, I decreased the CPE from approximately 700 to 161. Making it four times faster.
