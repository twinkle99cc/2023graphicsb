#include <opencv/highgui.h>

int main()

{

    IplImage * img = cvLoadImage("�U��.jpg");

    cvShowImage("week07", img);

    cvWaitKey(0);

}
