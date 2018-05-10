To draw face and eyes points
```C++
//    for ( size_t i = 0; i < faces.size(); i++ )
//    {
//        Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
//        ellipse( frame, center, Size( faces[i].width/2, faces[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
//        Mat faceROI = frame_gray( faces[i] );
//        std::vector<Rect> eyes;
//        eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CASCADE_SCALE_IMAGE, Size(30, 30) );
//        for ( size_t j = 0; j < eyes.size(); j++ )
//        {
//            Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
//            int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
//            circle( frame, eye_center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
//        }
//    }
```
To draw face
```C++
//    for (size_t i = 0; i < faces.size(); i++) {
//        cv::Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
//        ellipse(src, center, cv::Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);
//    }
```