struct Half { signed char b[2]; };
struct Word { signed char b[4]; };
extern "C" void *func_005A48D8(void *,int,unsigned);
extern "C" void *func_005A4724(void *,const void *,unsigned);
extern void (*D_0064A2F0)(int,int,int,void *);
extern "C" int func_00515508(int a,int b,int c,char *p) {
 char buf[0x198];
 func_005A48D8(buf,0,0x198);
 *(Half *)(buf+0)=*(Half *)(p+0);
 int result=*(short *)buf;
 char *dst=buf+24;
 *(Word *)(buf+2)=*(Word *)(p+2);
 *(Word *)(buf+6)=*(Word *)(p+6);
 *(Word *)(buf+8)=*(Word *)(p+10);
 *(Word *)(buf+12)=*(Word *)(p+14);
 Half *src=(Half *)(p+18);
 if(buf[6]==0) {
  *(Half *)(buf+16)=*src;
  *(Half *)(buf+18)=*(Half *)(p+20);
  *(Half *)(buf+20)=*(Half *)(p+22);
  *(Half *)(buf+22)=*(Half *)(p+24);
  func_005A4724(dst,p+26,*(short *)(buf+22));
 }
 if(D_0064A2F0) D_0064A2F0(a,b,c,buf);
 return result;
}
