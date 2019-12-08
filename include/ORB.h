/*
 * ORB.h
 * Copyright (C) 2019 transpalette <transpalette@arch-cactus>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef ORB_H
#define ORB_H

#include "BRIEF.h"
#include "FAST.h"
#include "FeatureExtractor.h"
#include "Harris.h"

namespace arlite {
class ORBExtractor : FeatureExtractor
{
  private:
    size_t n_keypoints;
    unsigned short pog_levels;
    float scaling_factor;
    /* Build a scale pyramid of the base image */
    ScalePyramid BuildPyramid();
    FASTExtractor fast_extractor;
    HarrisExtractor harris_extractor;
    BRIEFDescriptor brief_descriptor;

  public:
    ORBExtractor(size_t n_keypoints);
    std::vector<Keypoint> GetKeypoints();
    std::vector<Keypoint> Extract(const Frame* frame);
    Frame* GetAnnotatedFrame();
};
}

#endif /* !ORB_H */
