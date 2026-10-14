extern "C" int* D_00863770;
extern "C" int func_005316F8(int);
extern "C" int func_0051B968(int enabled,unsigned i) {
 if(i<64) {
  if(!enabled)return 0;
  int r=func_005316F8(36);D_00863770[i]=r;return r;
 }
 return 0;
}
