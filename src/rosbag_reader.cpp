#include <cv_bridge/cv_bridge.h>
#include <opencv2/highgui/highgui.hpp>
#include <rosbag/bag.h>
#include <rosbag/view.h>
#include <sensor_msgs/Image.h>

std::vector<cv::Mat> readImagesFromRosbag(const std::string &rosbagPath,
                                          const std::string &imageTopic) {
  rosbag::Bag bag(rosbagPath, rosbag::bagmode::Read);
  rosbag::View view(bag, rosbag::TopicQuery(imageTopic));

  std::vector<cv::Mat> images;

  for (const rosbag::MessageInstance &msg : view) {
    if (auto imageMsg = msg.instantiate<sensor_msgs::Image>()) {
      try {
        images.push_back(
            cv_bridge::toCvCopy(imageMsg, sensor_msgs::image_encodings::BGR8)
                ->image);
      } catch (const cv_bridge::Exception &e) {
        ROS_ERROR("cv_bridge exception: %s", e.what());
      }
    }
  }

  return images;
}