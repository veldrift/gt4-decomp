typedef unsigned int u32;
typedef int (*Handler)(int,int,int,void *);
typedef void (*Update)(int*,int*,int*);
typedef void (*Observer)(u32,u32,int,int,int,void*);
extern unsigned char D_0064C0F4;
extern int D_0064C0FC,D_0064C100;
extern void *D_0064C0F8;
extern u32 *D_0064C104;
extern Observer D_0064C108;
extern u32 D_0086B3D8,D_0086B3DC,D_0086B3E0;
extern "C" int func_0053A510(u32,u32,Handler *);
extern "C" void *func_005A4724(void*,const void*,u32);
extern "C" int func_0053A300(int a,int b,int c,unsigned char *p,u32 size,Update update) {
 if(D_0064C0F4!=1) return 5;
 if(!D_0064C0FC) return 5;
 if(!D_0064C100) return 5;
 if(!D_0064C0F8) return 5;
 if(!D_0064C104) return 5;
 if(!p) return 2;
 if(size<2) return 2;
 if(size>D_0086B3E0) return 2;
 {
   Handler handler;
   int x=a,y=b,z=c;
   u32 off=0;
   while(off<size) {
    unsigned char *cursor=p+off;
    off+=2;
    u32 row=cursor[0];u32 col=cursor[1];
    if(row>=D_0086B3DC || col>=D_0086B3D8) {
 bad: return 1001;
    }
    if(func_0053A510(row,col,&handler)!=0) return 1001;
    if(handler==0) return 1001;
    D_0064C104[row*D_0086B3D8+col]++;
    func_005A4724(D_0064C0F8,p+off,size-off);
    if(D_0064C108) D_0064C108(row,col,x,y,z,D_0064C0F8);
    int n=handler(x,y,z,D_0064C0F8);
    off+=n;
    if(n<0) goto bad;
    if(off>size) return 1001;
    if(update) update(&x,&y,&z);
   }
   return 0;
 }
}
