# BUILD.bazel
load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "rosbag_reader",
    srcs = ["rosbag_reader.cc"],
    hdrs = ["rosbag_reader.h"],
    visibility = ["//visibility:public"],
    deps = [
        "@opencv//:core",
        "@opencv//:highgui",
        "@opencv//:imgcodecs",
        "@opencv//:imgproc",
    ],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    copts = ["-std=c++11"],
    deps = [
        ":rosbag_reader",
    ],
    args = [
        "./input/2020-06-16-23-25-22.bag",
        "/camera/dalsa",
    ],
)