/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Self {char pad[0x858];int sel;};
struct Rec {int a,mode;char pad[0x410];int h;};
struct Cursor {signed char state,pad;short pos,start,end;};
extern "C" Cursor *func_004B5CC0(Self*) throw();
extern "C" int func_004B4080(int,unsigned short*,int,int) throw();
extern "C" int func_004B48E8(unsigned short*,int) throw();
extern "C" void func_004B4CA0(Self*,unsigned short*,int) throw();
extern "C" void func_004B64E0(Self*,unsigned short*,int) throw();
extern "C" void func_004B47F0(unsigned short*,int) throw();
extern "C" void func_004B4320(Cursor*,int,int) throw();
extern "C" int func_004B4138(int,int) throw();
extern "C" unsigned short *func_004B48D0(unsigned short*,int,int) throw();
extern "C" void func_004B5E00(Self*,Cursor*,unsigned short*,int) throw();
extern "C" void func_004B9438(unsigned short*);
extern "C" void func_004B9340(unsigned short*,int,unsigned short*);
extern "C" void func_0057D9C0(const char*,...);
extern char D_006B0458[];
static inline int address(Self *self, int off) { return (int)self+off; }
extern "C" void func_004B6A38(Self *self){
 unsigned short tmp[256];
 int n=1-self->sel;
 int off=n<<5;
 off+=n;
 off<<=3;
 off-=n;
 Cursor *cur=func_004B5CC0(self);
 off*=4;
 off=address(self,off);
 Rec *rec=(Rec*)(off+0x20);
 unsigned short *text=(unsigned short*)(off+0x30);
 int *count=(int*)(off+0x230);
 signed char state=cur->state;
 if(state==2){
  int mode=rec->mode;off=0;
  if(mode==0){
   off=func_004B4080(rec->h-1,text,256,47);
   if(off<0){func_0057D9C0(D_006B0458,off&255,off&0x7f00);off=func_004B48E8(text,47);}
   cur->state=3;
  }else if(mode==1){
   off=1;func_004B4CA0(self,text,256);cur->state=4;
  }else if(mode==state){
   off=1;func_004B4CA0(self,text,256);func_004B9438(text);cur->state=5;
  }else if(mode==3){
   off=1;func_004B64E0(self,tmp,256);func_004B9340(text,256,tmp);cur->state=5;
  }else if(mode==4){
   off=1;func_004B64E0(self,text,256);cur->state=5;
  }
  func_004B47F0(text,47);*count=off;
 }else if(state==3){
  func_004B4320(cur,1,*count);
  int r=func_004B4138(rec->h-1,cur->pos);
  if(r<0)func_0057D9C0(D_006B0458,r&255,r&0x7f00);
  unsigned short *p=func_004B48D0(text,256,cur->pos);
  func_004B5E00(self,cur,p,cur->end-cur->start);
 }
}
