// rosbag_reader.h
#ifndef ROSBAG_READER_H
#define ROSBAG_READER_H

#include <opencv2/opencv.hpp> // Assuming OpenCV is used
#include <string>
#include <vector>

std::vector<cv::Mat> readImagesFromRosbag(const std::string &rosbagPath,
                                          const std::string &imageTopic);

#endif // ROSBAG_READER_H
