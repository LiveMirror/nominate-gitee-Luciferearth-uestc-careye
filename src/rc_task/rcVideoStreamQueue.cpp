//
// Created by PulsarV on 18-5-14.
//
#include <rc_task/rcVideoStreamQueue.h>

int RC::ImageTaskQueue::argc;
char **RC::ImageTaskQueue::argv;
RC::rciqueue RC::ImageTaskQueue::guiImage;
RC::rciqueue RC::ImageTaskQueue::webImage;
RC::rciqueue webImage;

int RC::ImageTaskQueue::initTaskMannger(int argc, char **argv) {
    RC::LOG::logInfo(RC_VIDEOQUEUE_STRING_INITATION);
    ImageTaskQueue::argc=argc;
    ImageTaskQueue::argv=argv;
	return 1;
}
int RC::ImageTaskQueue::pushGUIImage(cv::Mat image) {
    cv::Mat imageUnion;
    image.copyTo(imageUnion);
    delete image.data;
    if(guiImage.size()>RC_MAX_GUI_QUEUE)
        guiImage.push(image);
	return 1;
}
void RC::ImageTaskQueue::popGUIImage(cv::Mat *outImage) {
    if(!guiImage.empty())
        guiImage.front().copyTo(*outImage);
    guiImage.pop();
}
int RC::ImageTaskQueue::pushWebImage(cv::Mat image) {
    cv::Mat imageUnion;
    image.copyTo(imageUnion);
    delete image.data;
    if(webImage.size()>RC_MAX_WEBSTREAM_QUEUE)
        webImage.push(image);
	return 1;
}
void RC::ImageTaskQueue::popWebImage(cv::Mat *outImage) {
    if(!webImage.empty())
        webImage.front().copyTo(*outImage);
    webImage.pop();
}
void RC::ImageTaskQueue::startDefaultGUI() {

}
void RC::ImageTaskQueue::startGtkGUI() {

}
void RC::ImageTaskQueue::startWebStream() {

}
void RC::ImageTaskQueue::startQtGUI() {

}
int RC::ImageTaskQueue::getGuiImageQueueSize() {
    return guiImage.size();
}
int RC::ImageTaskQueue::getWebImageQueueSize() {
    return webImage.size();
}
void RC::ImageTaskQueue::defaultGui() {
    while(true){
        if(!webImage.empty()){
            cv::Mat frame;
            popGUIImage(&frame);
            cv::imshow("DefaultGui",frame);
        }
    }
}