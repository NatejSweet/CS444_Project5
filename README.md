# CS444_Project5
# Test File System

## Building
`make` to build. An executable called `testfs` will be produced.
`make clean` to remove .o build products
`make pristine` to clean up all build products

## Files
`testfs.c`: 
`block.c`: 
`image.c`: 
`block.h`: 
`image.h`: 
`ctest.h`: 

## Data
reads and writes data to disk
blocks are 4096 bits

## Functions

- `main`
- `test_image_fd_init`: tests that before any open, image_fd is -1
- `image_open`: opens a passed file
- `testt_image_fd_gets_set`: tests that after an open, image_fd is no longer -1
- `test_image_open`: tests that the image opens and updates image_fd
    - `image_open`: opens a file, sets image_fd to the return of open, returns image_fd so it can be tested
- `test_image_close`: tests that the image is closed correctly
    - `image_close`: closes the file, returning 0 on success
- `test_bread`: check the blockmap against a new one to test that read works
    - `bread`: reads from the passed block
- `test_bwrite`: 
    - `bwrite`:
    - `bread`

## Notes