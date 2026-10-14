extern int D_0064B444;
extern char D_00863EC0[], D_00863F00[];
extern "C" int func_00570688(void *,void *,int,void *,void *);
extern "C" int func_00522480(void *) throw();
extern "C" int func_00522FF0(int fd,int *ready,int *addrout,int *portout) {
 char addr[16];
 unsigned short port;
 *ready=0;
 if(!D_0064B444) return 5;
 if(fd<0) return 2;
 int n=func_00570688(D_00863EC0,D_00863F00,fd,&port,addr);
 if(n<0) { if(n!=-500) return 50000; n=0; }
 if(n>0) { *ready=1; *portout=port; *addrout=func_00522480(addr); }
 return 0;
}
