extern "C" int func_004C8DB8(const unsigned short* left,const unsigned short* right,int count) {
 while(count>0) {
  unsigned a=*left++; unsigned b=*right++;
  if(a>b)return 1;
  if(a<b)return -1;
  --count;
 }
 return 0;
}
