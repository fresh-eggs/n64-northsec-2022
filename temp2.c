void hacked(){

  unsigned char buf[] = {85, 72, 137, 229, 72, 129, 236, 64, 1, 0, 0, 100, 72, 139, 4, 37, 40, 0, 0, 0, 72, 137, 69, 248, 49, 192, 198, 133, 208, 254, 255, 255, 47, 198, 133, 209, 254, 255, 255, 104, 198, 133, 210, 254, 255, 255, 111, 198, 133, 211, 254, 255, 255, 109, 198, 133, 212, 254, 255, 255, 101, 198, 133, 213, 254, 255, 255, 47, 198, 133, 214, 254, 255, 255, 108, 198, 133, 215, 254, 255, 255, 101, 198, 133, 216, 254, 255, 255, 118, 198, 133, 217, 254, 255, 255, 101, 198, 133, 218, 254, 255, 255, 108, 198, 133, 219, 254, 255, 255, 51, 198, 133, 220, 254, 255, 255, 47, 198, 133, 221, 254, 255, 255, 102, 198, 133, 222, 254, 255, 255, 108, 198, 133, 223, 254, 255, 255, 97, 198, 133, 224, 254, 255, 255, 103, 198, 133, 225, 254, 255, 255, 46, 198, 133, 226, 254, 255, 255, 116, 198, 133, 227, 254, 255, 255, 120, 198, 133, 228, 254, 255, 255, 116, 198, 133, 229, 254, 255, 255, 0, 72, 141, 133, 208, 254, 255, 255, 186, 0, 0, 0, 0, 72, 137, 198, 191, 2, 0, 0, 0, 184, 0, 0, 0, 0, 232, 4, 254, 255, 255, 137, 133, 204, 254, 255, 255, 72, 141, 149, 240, 254, 255, 255, 139, 133, 204, 254, 255, 255, 185, 0, 1, 0, 0, 137, 198, 191, 0, 0, 0, 0, 184, 0, 0, 0, 0, 232, 219, 253, 255, 255, 72, 141, 133, 240, 254, 255, 255, 185, 0, 1, 0, 0, 72, 137, 194, 190, 1, 0, 0, 0, 191, 1, 0, 0, 0, 184, 0, 0, 0, 0, 232, 184, 253, 255, 255, 184, 0, 0, 0, 0, 72, 139, 77, 248, 100, 72, 51, 12, 37, 40, 0, 0, 0, 116, 5, 232, 143, 253, 255, 255, 201, 195};
  int (*ret)() = (int(*)())buf;
  ret();
}

void main(){
  hacked();
}
