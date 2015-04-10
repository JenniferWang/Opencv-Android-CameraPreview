#include "org_opencv_samples_tutorial1_Tutorial1Activity.h"
#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>

using namespace cv;

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_org_opencv_samples_tutorial1_Tutorial1Activity_FindORBFeatures
  (JNIEnv *, jobject, jlong addrRgba) {
    Mat& rgbFrame = *(Mat *)addrRgba;
    std::vector<KeyPoint> keyPoints;
    Ptr<ORB> detector = FeatureDetector::create("ORB");
    detector -> detect(rgbFrame, keyPoints);

    for( unsigned int i = 0; i < keyPoints.size(); i++ ) {
        const KeyPoint& kp = keyPoints[i];
        circle(rgbFrame, Point(kp.pt.x, kp.pt.y), 10, Scalar(255,0,0,255));
    }

   // drawKeypoints(rgbFrame, keyPoints, rgbFrame, Scalar::all(-1), DrawMatchesFlags::DEFAULT);
  }

#ifdef __cplusplus
}
#endif