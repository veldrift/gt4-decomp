extern "C" void func_0057D8A0(float*,float*,float);
struct S{char pad[0x3a4];float x,y;int gap;float angle;};
extern "C" void func_0045C7E8(S*p){float s,c;func_0057D8A0(&s,&c,p->angle);char*outX=(char*)p+16,*inX=(char*)p+8,*inY=(char*)p+12,*outY=(char*)p+20;int off=0,n=7;do{float*x=(float*)(inX+off),*y=(float*)(inY+off);int d=off+16;float*ox=(float*)(outX+d),*oy=(float*)(outY+d);--n;off+=68;*ox=c**x-s**y+p->x;*oy=s**x+c**y+p->y;}while(n>=0);}
