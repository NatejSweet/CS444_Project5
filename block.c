#include "block.h"
#include "image.h"
#include <stdio.h>
#include <unistd.h>


#define BLOCK_SIZE 4096

extern int image_fd;


unsigned char *bread(int block_num, unsigned char *block){
    lseek(image_fd, block_num * BLOCK_SIZE, SEEK_SET);
    read(image_fd, block, BLOCK_SIZE);
    return block;
}
void bwrite(int block_num, unsigned char *block){
    lseek(image_fd, block_num * BLOCK_SIZE, SEEK_SET);
    write(image_fd, block, BLOCK_SIZE);
    return;
}