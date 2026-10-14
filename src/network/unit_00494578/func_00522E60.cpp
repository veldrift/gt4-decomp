extern int D_0064B444;
extern char D_00863EC0[], D_00863F00[];
extern "C" int func_005704A8(void *,void *,int,void *,unsigned,int *,int);
extern "C" int func_00522E60(int fd,void *buf,unsigned size,int *out) {
 int flags=0;
 if(!D_0064B444) return 5;
 if(fd<0) return 2;
 unsigned amount=size<=4096?size:4096;
 int n=func_005704A8(D_00863EC0,D_00863F00,fd,buf,amount,&flags,2);
 if(n<0) return (flags&4)?0xC356:0xC350;
 if(flags&4) { *out=n&0xFFFF; return 0xC356; }
 *out=n;
 return 0;
}
