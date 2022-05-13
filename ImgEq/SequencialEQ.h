//
// Created by tom on 13/05/22.
//

#include <iostream>
#include <vector>
#include "include/CImg.h"

#ifndef OPENCLATTEMPT_SEQUENCIALEQ_H
#define OPENCLATTEMPT_SEQUENCIALEQ_H

class SequencialEQ {

private:
    static int temp();

public:
    void helloWorld();
    std::vector<int> get_intensity_hist(const cimg_library::CImg<unsigned char>& inp_image);
    std::vector<int> get_cumulative_hist();
    std::vector<double> get_normalised_hist();
    std::vector<unsigned char> get_equalised_Img_V();
};


#endif //OPENCLATTEMPT_SEQUENCIALEQ_H
