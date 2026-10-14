extern int D_0064B444;
extern char D_00863EC0[], D_00863F00[];
extern "C" int func_005705F8(void *,void *,int,void *,unsigned,int *,void *,int *,int);
extern "C" int func_00522480(void *) throw();
extern "C" int func_00522F18(int fd,int *a,int *b,void *buf,unsigned size,int *received) {
 char addr[16];
 int flags=0;
 int port;
 if (!D_0064B444) return 5;
 if (fd<0) return 2;
 *received=0;
 unsigned amount=size<=4096?size:4096;
 int n=func_005705F8(D_00863EC0,D_00863F00,fd,buf,amount,&flags,addr,&port,2);
 if(n<0) { if(n!=-500) return 50000; n=0; }
 if(n>0) { *b=port; *a=func_00522480(addr); }
 *received=n;
 return 0;
}
