/*
 * libArkit_Frame.h
 * Copyright (C) 2019 transpalette <transpalette@translaptop>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef LIBARKIT_FRAME_H
#define LIBARKIT_FRAME_H

//#include <map>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <libavcodec/avcodec.h>
#include "libArkit_Matrix.h"

namespace ARKIT
{
    /* TODO: Remove the Pixel structure, it's garbage */
    struct Pixel {
        int x;
        int y;
        unsigned char intensity;

        Pixel(int x, int y)
        {
            this->x = x;
            this->y = y;
            this->intensity = 0;
        }

        Pixel(int x, int y, unsigned char i)
        {
            this->x = x;
            this->y = y;
            this->intensity = i;
        }

        Pixel(unsigned char intensity)
        {
            this->intensity = intensity;
        }

        bool operator() (const Pixel* p) const
        {
            return (p->x == this->x) && (p->y == this->y);
        }
    };

    class Frame
    {
        private:
            uint8_t **data;
            //std::map<int, Pixel*> pixels_cache;
            unsigned int width;
            unsigned int height;

        public:
            Frame(uint8_t **data, int width, int height);
            Frame(int width, int height);
            Frame(const Frame& f);
            ~Frame();
            Pixel* PixelAt(unsigned int x, unsigned int y) const;
            uint8_t RawAt(unsigned int x, unsigned int y) const;
            void WriteAt(unsigned int x, unsigned int y, unsigned char val);
            int Width() const;
            int Height() const;
            Matrix<int> GetIntMatrix() const;
            Matrix<int> GetIntMatrix(int x, int y, int patch_size) const;
            Matrix<double> GetDoubleMatrix() const;
            Matrix<double> GetDoubleMatrix(int x, int y, int patch_size) const;
            Frame operator*(const Frame f) const;
    };
}


#endif /* !LIBARKIT_FRAME_H */
