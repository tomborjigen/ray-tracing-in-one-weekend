#ifndef COLOUR_H
#define COLOUR_H

#include "vec3.h"

#include <iostream>
#include "interval.h"

using colour = vec3;

void write_colour(std::ostream &out, colour pixel_colour, int samples_per_pixel) {

    auto r = pixel_colour.x();
    auto g = pixel_colour.y();
    auto b = pixel_colour.z();


    // divide the colour by the number of samples

    auto scale = 1.0 / samples_per_pixel;

    r *= scale;
    g *= scale;
    b *= scale;

    // writing the translated [0,255] value of each colour

    static const interval intensity(0.000, 0.999);

    out  << static_cast<int>(256 * intensity.clamp(r)) << ' '
        << static_cast<int>(256 * intensity.clamp(g)) << ' '
        << static_cast<int>(256 * intensity.clamp(b)) << '\n';
}

#endif
