/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Record { signed char leading; signed char tuning[12]; signed char special[17]; } __attribute__((packed));
struct Input { char header[16]; Record record; };
struct Data { unsigned char flags,kind; short unused; short tuning; short unknown; short axes[4]; };
struct Output { Data *data; };
struct Controls { unsigned short unknown, flags; unsigned short count; char rest[46]; int getFlags() const {return flags;} };
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
static inline int limit(int v) { return v<256?v:256; }
extern "C" void func_0043BBC0(Input *input,Output *output,Controls *controls,int mode) {
 Record r=input->record;
 bool special=((controls->getFlags()>>4)&15)==5;
 Data *data=output->data; void *knobs=&controls->count;
 void *source=func_0055F1F0(controls);
 char selected[48]; func_0055F198(selected,source);
 if(mode==2) { r.special[3]=-1;r.special[0]=-1;r.special[1]=-1;r.special[2]=-1; }
 if(func_0055EFC8(selected,23) || func_0055EFC8(selected,21)) {func_0055F150(selected,20,0);func_0055F150(selected,22,0);}
 func_004389F8(output,selected,r.special,D_006A64D0,16);

 if(special) {
   int firstInput=(func_0055EF50(knobs,5)&255)*2; if(firstInput>=256)firstInput=256; int first=percent(firstInput,60); if(first>=256)first=256;
   int secondInput=(func_0055EF50(knobs,4)&255)*2; if(secondInput>=256)secondInput=256; int second=percent(secondInput,60); if(second>=256)second=256;
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
   case 4: { int cap=256; int scaled=(v&255)*2; if(scaled>=cap)scaled=cap; int result=cap; data->flags|=2; int calculated=percent(scaled,35); if(calculated<cap)result=calculated; data->axes[0]=result<<4; break; }
   case 5: { int cap=256; int scaled=(v&255)*2; if(scaled>=cap)scaled=cap; int result=cap; data->flags|=4; int calculated=percent(scaled,65); if(calculated<cap)result=calculated; data->axes[1]=result<<4; break; }
   case 6: { int cap=256; int scaled=(v&255)*2; if(scaled>=cap)scaled=cap; int result=cap; data->flags|=16; int calculated=percent(scaled,20); if(calculated<cap)result=calculated; data->axes[3]=result<<4; break; }
   case 7: { int cap=256; int scaled=(v&255)*2; if(scaled>=cap)scaled=cap; int result=cap; data->flags|=8; int calculated=percent(scaled,35); if(calculated<cap)result=calculated; data->axes[2]=result<<4; break; }
   }
 }
}
