//
// Created by tom on 13/05/22.
//

#include "SequencialEQ.h"
#include <iostream>

std::vector<int> SequencialEQ::get_intensity_hist(const cimg_library::CImg<unsigned char>& inp_image) {

    // Create initial intensity vector:
    std::vector<int> intensity(255, 0);

    // Gather the intensity histogram:
    for (int pic_index = 0; pic_index <= inp_image.size(); pic_index++) {
        // We need to get the current value as an int:
        int curr_value = int(image_input[pic_index]);

        // Then we get the curr value of the hist:
        int curr_hist_val = intensity[curr_value];

        // Then we increase the frequency by one:
        int curr_hist_inc = curr_hist_val + 1;

        // Then we set the new value of the vector:
        intensity[curr_value] = curr_hist_inc;
    }


    // Return the intensity hist:
    return intensity;
}