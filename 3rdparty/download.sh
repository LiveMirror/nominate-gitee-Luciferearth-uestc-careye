git clone https://github.com/BVLC/caffe.git
git clone -b 3.4.1 https://github.com/opencv/opencv.git
mkdir caffe_build
mkdir opencv_build
cd caffe_build
cmake ../caffe
make
cd ../opencv_build
cmake ../opencv-3.4.1
make
