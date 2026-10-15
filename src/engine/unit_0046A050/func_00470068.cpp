struct S { char pad[0x20]; int w,h,mode; char pad2[0xA68-0x2c]; int *src; };
extern const short D_006AC0D0[], D_006AC2D0[], D_006AC4D0[], D_006AC6D0[];
extern unsigned char D_006AC9D0[];
#define PIX(V,U,Y) { vv=(V); uu=(U); yy=(Y); dst[0]=tbl[yy+D_006AC0D0[vv]]; g=D_006AC6D0[uu]+D_006AC4D0[vv]; dst[1]=tbl[yy+(g<0 ? ((g>>5)|0xF8000000) : (g>>5))]; dst[2]=tbl[yy+D_006AC2D0[uu]]; dst+=3; }
extern "C" void func_00470068(S *s, unsigned char *dst, int stride) {
 int vv,uu,yy,g,x,rows;
 int bw=s->w, bh=s->h;
 int w=bw*8, h=bh*8;
 int *y=s->src;
 int *u=y+bh*bw*64;
 int *v=y+bh*bw*128;
 unsigned char *tbl=D_006AC9D0;
 int skip=stride-w;
 int k=1;
 switch(s->mode) {
 case 1:
  for(rows=h;rows>0;rows--) { for(x=w;x>0;x--) { PIX(y[128],y[64],*y++); } dst+=skip*3; } break;
 case 2: { int size=bh*bw*64;
  for(rows=h;rows>0;rows--) { for(x=w/2;x>0;x--) { PIX(u[size],*u,*y++); PIX(u[size],*u++,*y++); } dst+=skip*3; } break;
 }
 case 3:
  for(rows=h>>k;rows>0;rows--) { for(x=w/2;x>0;x--) { PIX(*v,*u,*y++); PIX(*v++,*u++,*y++); } dst+=skip*3; v-=w/2; u-=w/2;
   for(x=w/2;x>0;x--) { PIX(*v,*u,*y++); PIX(*v++,*u++,*y++); } dst+=skip*3; } break;
 default:
  for(rows=h;rows>0;rows--) { for(x=w;x>0;x--) { PIX(*v++,*u++,*y++); } dst+=skip*3; } break;
 }
}
