#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "header.h"

char *read_str_from_file(char *file_name) {
  FILE *fd = fopen(file_name, "r");
  char *str;
  long sz;
  if (fd < 0) {
    printf("open fail\n");
    return NULL;
  }
  fseek(fd, 0L, SEEK_END);
  sz = ftell(fd);
  fseek(fd, 0L, SEEK_SET);
  str = (char *)malloc(sz + 1);
  fread(str, sz, 1, fd);
  return str;
}

int main(int argc, char argv) {
  char *s;
  s = read_str_from_file("broadcast_data");
  printf("%s,%d\n", s,strlen(s));
  udp_broadcast(s,strlen(s),4950,"192.168.46.210");
  return 0;
}
