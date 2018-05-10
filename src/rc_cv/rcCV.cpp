//
// Created by PulsarV on 18-5-9.
//

#include <rc_cv/rcCV.h>

void RC::CV::fillter_8UC1(int max, cv::Mat *gray) {
    cv::MatIterator_<uchar> it, end;
    for (it = gray->begin<uchar>(), end = gray->end<uchar>(); it != end; ++it) {
        if (*it < 10)
            *it = 0;
        else
            *it = 255;
    }
}
void RC::CV::detectLine(cv::Mat src, cv::Mat *dst) {
    cv::Mat ROI_IMAGE=src(cv::Rect(0,src.rows/4,src.cols,src.rows/2));
    cv::Mat warp_mat(3,3,CV_32FC1);
    cv::Mat hsv_image;
    cv::Mat mask;
    cv::Mat trash_hsv;
    cv::Mat gray_hsv;
    cv::Mat trash_rgb;
    cv::Mat gray_rgb;
    cv::Mat out_mask;
    cv::Mat kernel = (cv::Mat_<float>(3, 3) << 0, -1, 0, 0, 5, 0, 0, -1, 0);
    cv::filter2D(src, src, CV_8UC3, kernel);
    cv::medianBlur(ROI_IMAGE, ROI_IMAGE, 5);

    cv::cvtColor(ROI_IMAGE, hsv_image, cv::COLOR_BGR2HSV);
    cv::cvtColor(hsv_image, gray_hsv, cv::COLOR_BGR2GRAY);
    cv::cvtColor(ROI_IMAGE, gray_rgb, cv::COLOR_BGR2GRAY);

    cv::filter2D(gray_rgb, gray_rgb, CV_8UC1, kernel);
    cv::imshow("gray_rgb",gray_rgb);
    cv::imshow("gray_hsv",gray_hsv);
//    cv::medianBlur(hsv_image, hsv_image, 5);

    cv::Canny(ROI_IMAGE, mask, 200, 255, 3);



    const cv::Scalar hsvBlack_Low(0, 0, 0);
    const cv::Scalar hsvBlack_High(255, 255, 255);

    cv::threshold(gray_hsv, trash_hsv, 1, 255, cv::THRESH_BINARY);
    cv::threshold(gray_rgb, trash_rgb, 40, 250, cv::THRESH_BINARY);


    cv::inRange(hsv_image, hsvBlack_Low, hsvBlack_High, trash_hsv);
    cv::bitwise_and(ROI_IMAGE, hsv_image, out_mask, trash_hsv);

    cv::cvtColor(hsv_image, ROI_IMAGE, cv::COLOR_HSV2BGR);

    cv::Mat dst_cpu;
    cv::cvtColor(mask, dst_cpu, cv::COLOR_GRAY2BGR);

    RC::lines lines_cpu;{
        cv::HoughLinesP(mask, lines_cpu, 1, CV_PI / 180, 150, 100, 5);
    }
    //std::cout<<lines_cpu.size()<<std::endl;
    if(lines_cpu.size()>0){
        for (size_t i = 0; i < lines_cpu.size(); ++i) {
            cv::Vec4i l = lines_cpu[i];
            int x1=l[0],y1=l[1],x2=l[2],y2=l[0];
            if(x1&&x2!=0){
                double theta=atan((double)y1/(double)x1) - atan((double)y2/(double)x2);
                std::cout<<theta<<std::endl;
            }
            cv::line(ROI_IMAGE,
                     cv::Point(x1, y1),
                     cv::Point(x2, y2),
                     cv::Scalar(0, 255, 255),
                     3,
                     cv::LINE_AA);
        }
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
//    drawDetectLines(src,);
    src.copyTo(*dst);
//    delete(gray_hsv.data);
//    delete(trash_hsv.data);
//    delete(trash_rgb.data);
//    delete(gray_rgb.data);
//    delete(mask.data);
//    delete(hsv_image.data);
//    cv::imshow("cap", *src);
//    cv::imshow("gray_rgb", gray_rgb);
//    cv::imshow("trash_hsv", trash_hsv);
//    cv::imshow("trash_rgb", trash_rgb);
//    cv::imshow("cpu", dst_cpu);
//    cv::imshow("mask", mask);
    cv::imshow("out", out_mask);
//    cv::imshow("hsv", hsv_image);
}

void RC::CV::drawDetectLines(cv::Mat& image,const std::vector<cv::Vec4i>& lines,cv::Scalar & color)
{
    // 将检测到的直线在图上画出来
    std::vector<cv::Vec4i>::const_iterator it=lines.begin();
    while(it!=lines.end())
    {
        cv::Point pt1((*it)[0],(*it)[1]);
        cv::Point pt2((*it)[2],(*it)[3]);
        cv::line(image,pt1,pt2,color,2);
        ++it;
    }
}
std::vector<RC::rc_line> RC::CV::detectLine(cv::Mat &img, int threshold) {
    std::vector<rc_line> lines;
    int diagonal = floor(sqrt(img.rows*img.rows + img.cols*img.cols));
    std::vector< std::vector<int> >p(360, std::vector<int>(diagonal));
    for (int j = 0; j < img.rows; j++) {
        for (int i = 0; i < img.cols; i++) {
            if (img.at<uchar>(j, i) > 0){
                for (int theta = 0; theta < 360; theta++){
                    int r = floor(i*cos(theta / RADIAN) + j*sin(theta / RADIAN));
                    if (r < 0)
                        continue;
                    p[theta][r]++;
                }
            }
        }
    }
    for (int theta = 0; theta < 360; theta++){
        for (int r = 0; r < diagonal; r++){
            int thetaLeft = std::max(0, theta - 1);
            int thetaRight = std::min(359, theta + 1);
            int rLeft = std::max(0, r - 1);
            int rRight = std::min(diagonal - 1, r + 1);
            int tmp = p[theta][r];
            if (tmp > threshold
                && tmp > p[thetaLeft][rLeft] && tmp > p[thetaLeft][r] && tmp > p[thetaLeft][rRight]
                && tmp > p[theta][rLeft] && tmp > p[theta][rRight]
                && tmp > p[thetaRight][rLeft] && tmp > p[thetaRight][r] && tmp > p[thetaRight][rRight]){
                RC::rc_line newline;
                newline.theta = theta;
                newline.r = r;
                lines.push_back(newline);
            }
        }
    }
    return lines;
}

std::vector<cv::Rect> RC::CV::detcetFace(cv::Mat src) {
    cv::CascadeClassifier face_cascade;
    cv::CascadeClassifier eyes_cascade;
    if( !face_cascade.load( "./haarcascades/haarcascade_frontalface_alt.xml" ) ){ std::cout<<"Error loading face cascade"<<std::endl;}
    if( !eyes_cascade.load( "./haarcascades/haarcascade_eye_tree_eyeglasses.xml" ) ){ std::cout<<"Error loading eyes cascade"<<std::endl;}
    std::vector<cv::Rect> faces;
    cv::Mat frame_gray;
    cv::cvtColor( src, frame_gray, cv::COLOR_BGR2GRAY );
    cv::equalizeHist( frame_gray, frame_gray );
    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30) );
    return faces;
}

std::vector<cv::Rect> RC::CV::detcetBody(cv::Mat src) {
    cv::CascadeClassifier body_cascade;
    if( !body_cascade.load( "./haarcascades/haarcascade_fullbody.xml" ) ){ printf("--(!)Error loading face cascade\n");}
    std::vector<cv::Rect> bodies;
    cv::Mat frame_gray;
    cv::cvtColor(src, frame_gray, cv::COLOR_BGR2GRAY);
    equalizeHist(frame_gray, frame_gray);
    body_cascade.detectMultiScale(frame_gray, bodies, 1.1, 2, 0, cv::Size(30, 30));
    return bodies;
}
int* RC::CV::detcetByRightAndLeft(cv::Mat &src) {
    cv::Mat thresh_image;
    double thresh = 100;
    int maxVal = 255;
    int left;
    int right;
    cv::threshold(src,thresh_image,thresh,maxVal,cv::THRESH_BINARY);
    for(int x=0;x<src.rows;x+=1){
        for(int y1=0,y2=0;y1<thresh_image.cols/2;y1+=1,y2+=1){
//            if(thresh_image.at(x,y1)==1)left+=1;
//            if(thresh_image.at(x,y2)==1)right+=1;
        }
    }
    int ans[]={left,right};
    return ans;
}
