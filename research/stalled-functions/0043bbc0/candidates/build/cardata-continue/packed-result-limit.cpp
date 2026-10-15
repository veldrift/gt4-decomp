/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Record { signed char leading; signed char tuning[12]; signed char special[17]; } __attribute__((packed));
struct Input { char header[16]; Record record; };
struct Data { unsigned char flags,kind; short unused; short tuning; short unknown; short axes[4]; };
struct Output { Data *data; };
struct Controls { unsigned short unknown, flags; unsigned short count; char rest[46]; };
extern "C" void *func_0055F1F0(Controls *);
extern "C" void func_0055F198(void *,void *);
extern "C" int func_0055EFC8(void *,int);
extern "C" void func_0055F150(void *,int,int);
extern "C" int func_0055EF50(void *,int);
extern "C" void func_004389F8(Output *,void *,signed char *,const char *,int);
extern "C" void func_004386F0(Output *,int,int,int);
extern char D_006A64D0[];
extern unsigned char D_006A64C0[],D_006A64E0[];
extern short D_00622F58[];
extern unsigned short D_00623158[];
static inline int percent(int value,int divisor) { return value*100/divisor; }
static inline int axis(int v,int divisor) {
 int cap=256; v=(v&255)*2; if(v>=cap)v=cap;
 int result=cap; int calculated=percent(v,divisor); if(calculated<cap)result=calculated;
 return result<<4;
}
extern "C" void func_0043BBC0(Input *input,Output *output,Controls *controls,int mode) {
 Record r=input->record;
 bool special=(((int)controls->flags>>4)&15)==5;
 Data *data=output->data; void *knobs=&controls->count;
 void *source=func_0055F1F0(controls);
 char selected[48]; func_0055F198(selected,source);
 if(mode==2) { r.special[3]=-1;r.special[0]=-1;r.special[1]=-1;r.special[2]=-1; }
 if(func_0055EFC8(selected,23) || func_0055EFC8(selected,21)) {func_0055F150(selected,20,0);func_0055F150(selected,22,0);}
 func_004389F8(output,selected,r.special,D_006A64D0,16);

 if(special) {
   int first=(func_0055EF50(knobs,5)&255)*2; if(first>=256)first=256; first=percent(first,60); if(first>=256)first=256;
   int second=(func_0055EF50(knobs,4)&255)*2; if(second>=256)second=256; second=percent(second,60); if(second>=256)second=256;
   if(first==0 && second==0) { data->kind=0;data->tuning=0;data->flags &= ~1; }
   else { int value=(first-second)<<4;data->kind=3;data->flags|=1;data->tuning=value; }
 }
 int count=*(unsigned short *)knobs;if(count>12)count=12;
 for(int i=0;i<count;++i) { int v=func_0055EF50(knobs,D_006A64C0[i]);int code=r.tuning[i];
   if(code==0) { if(data->tuning!=0)continue;v=D_00622F58[v]; } else v=D_00623158[v];
   func_004386F0(output,2,code,v);
 }
 if(special)for(int i=0;i<12;++i) {
   int v=func_0055EF50(knobs,D_006A64E0[i]); if(!v)continue;
   switch(r.special[i]) { case -1: case 17: break;
   case 4:  data->flags|=2;data->axes[0]=axis(v,35);break;
   case 5:  data->flags|=4;data->axes[1]=axis(v,65);break;
   case 6:  data->flags|=16;data->axes[3]=axis(v,20);break;
   case 7:  data->flags|=8;data->axes[2]=axis(v,35);break;
   }
 }
}
