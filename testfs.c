#include "image.h"
#include "block.h"
#include "ctest.h"


void test_image_fd_init(void){
    CTEST_ASSERT(image_fd==-1, "Test image_fd is -1 before use");
}

void test_image_fd_gets_set(void){
    CTEST_ASSERT(image_fd!=-1, "Test image_fd gets set once used");
}
void test_image_open(void){
    CTEST_ASSERT(image_open("sample.txt",1)==4, "Test image_open");
}

void test_image_close(void){
    CTEST_ASSERT(image_close()==0, "Test image_close");
}

void test_bread(void){
    unsigned char blockMap[4096]={1,1,1,1,1,1};
    CTEST_ASSERT(bread(2,blockMap)==blockMap, "Test bread");
}
void test_bwrite(void){
    unsigned char tmp[4096] = {1,1,1,1,1,0};
    bwrite(3,tmp);
    CTEST_ASSERT(bread(3,tmp)==tmp, "Test bwrite(write, then assert read)");
}
#ifdef CTEST_ENABLE
int main(){
    CTEST_VERBOSE(1);
    test_image_fd_init();
    image_open("sample.txt",0);
    test_image_fd_gets_set();
    test_image_open();
    test_image_close();
    test_bread();
    test_bwrite();
    CTEST_RESULTS();
    CTEST_EXIT();
    return 0;
}

#else
int main(){
    image_open("sample.txt",0);
    unsigned char tmp[4096];
    bread(0,tmp);
    tmp[0] =1;
    bwrite(0,tmp);
    bread(0,tmp);
    return 0;
}
#endif