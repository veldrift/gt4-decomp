/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Out { int pad; char data[12]; };
struct Hdr { unsigned char kind; char pad[3]; Out *data; unsigned short count; short padA; Hdr *next; };
extern "C" int func_004C1AF8(Hdr *) throw();
extern "C" void func_004C2030(int,void *);
extern "C" int func_004C2758(int,int,int,Out *);
extern "C" int func_004C2830(int,unsigned short *,int,int,Hdr **);
extern "C" int func_004C2B10(int,unsigned short *,int,Hdr **);
extern "C" int func_004C2F48(int,unsigned short *,int,int,Hdr **);
extern "C" signed char func_004C4E58(unsigned short *);
extern "C" signed char func_004C4ED0(unsigned short *,int);
extern "C" signed char func_004C4FB0(unsigned short *);
extern "C" void *func_004C8C20(int,int);
extern "C" int func_004C8ED0(unsigned short *);
extern "C" int func_004C1B28(int self,int mode,unsigned short *key,int ctx,Hdr **out) {
 unsigned short one[8];
 int type=0; int kind; int r;
 *out=0;
 int len=func_004C8ED0(key);
 Hdr *previous=0;
 if(len==0)return len;
 one[0]=key[0];one[1]=0;
 if(mode==1) {
  kind=0;
  r=func_004C4E58(key);
  if(r==0) {
   r=func_004C4FB0(key);
   if(r>0) {
    kind=r;type=0x11;
    r=func_004C4ED0(key,kind);
    if(r!=-1) {
     if(r==0) {kind=1;type=0x12;}
     else kind=r;
    }
   }
  } else {kind=r;type=0x10;}
  if(kind>0) {
   Out *data=(Out *)func_004C8C20(self,16);
   if(data==0)return 0x80000322;
   if(func_004C2758(type,kind,ctx,data)<=0) {func_004C2030(self,data);return 0;}
   type=(int)func_004C8C20(self,16);
   if(type==0) {func_004C2030(self,data);return 0x80000322;}
   ((Hdr *)type)->kind=kind;((Hdr *)type)->data=data;((Hdr *)type)->count=1;((Hdr *)type)->next=0;
   *out=(Hdr *)type;
  }
  int n=func_004C2B10(self,key,ctx,out);
  if(n<0)return n;
  r=func_004C2830(self,one,1,ctx,out);
  if(r>=0) {
   if(key[1]!=0)r=func_004C2830(self,key,len,ctx,out);

  }
  if(r<0) {
   if((r&0x7f00)!=0x1100)return r;
   r=func_004C1AF8(*out);
  }
  return r+n;
 }
 r=func_004C2F48(self,one,ctx,0,out);
 if(r<0)goto initial_error;
 if(key[1]!=0)r=func_004C2F48(self,key,ctx,0,out);
 if(r<0) {initial_error: return r;}
 if(*out==0)return 0;
 for(;;) {
  Hdr *head=*out;
  for(Hdr *h=head;h;) {
   kind=h->kind;
   unsigned short *part=(unsigned short *)(kind*2+(int)key);
   if(kind!=len) {
    int sub=(int)&h->data->data;
    one[0]=part[0];
    r=func_004C2F48(self,one,sub,kind,out);
    if(r>=0) {
     if(part[1]!=0)r=func_004C2F48(self,part,sub,kind,out);
     if(r>=0) {h=h->next;continue;}
    }
    return r;
   }
   h=h->next;
  }
  if(previous==*out)break;
  previous=head;
 }
 return func_004C1AF8(*out);
}
