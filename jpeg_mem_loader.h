#pragma once

void load_mem_jpeg(dlib::matrix<dlib::rgb_pixel>& img, const uint8_t* img_data, int len);
void load_bytes_arr(dlib::matrix<dlib::rgb_pixel>& img, const uint8_t* img_data, int rows, int columns);
