// main.cc
#include "rosbag_reader.h"
#include <iostream>
#include <opencv2/opencv.hpp> // Assuming OpenCV is used

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " <path_to_rosbag> <image_topic>\n";
    return 1;
  }

  const std::string rosbagPath = argv[1];
  const std::string imageTopic = argv[2];

  const std::vector<cv::Mat> images =
      readImagesFromRosbag(rosbagPath, imageTopic);

  // Process or display the images as needed

  return 0;
}