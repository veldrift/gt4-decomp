/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Blk { int base; u32 count; };
struct Obj { char pad[12]; int base; char pad10[32]; Blk blocks[18]; };
extern "C" void func_00474430(void*,int);
extern "C" void func_0047E988(void*,int);
extern "C" void func_0047F1D8(void*,int);
extern "C" void func_0047FA40(void*,int);
extern "C" void func_00479730(void*,int);
extern "C" void func_004798D0(void*,int);
extern "C" void func_00479BB8(void*,int);
extern "C" void func_00479098(void*,int);
extern "C" void func_004790B0(void*,int);
extern "C" void func_00479160(void*,int);
extern "C" void func_00481218(void*,int);
extern "C" void func_004790D0(void*,int);
extern "C" void func_00473CC0(Obj *self) {
 Blk *b0=&self->blocks[0];
 int old=self->base;
 self->base=(int)self;
 int delta=(int)self-old;
 if(b0->base) b0->base += delta;
 u32 i0=0;
 if(b0->count) {
  int off=0;
  do {
   ++i0;
   int a=b0->base+off;
   off+=36;
   func_00474430((void*)a,delta);
  } while(i0<b0->count);
 }
 Blk *b1=&self->blocks[1];
 if(b1->base) b1->base += delta;
 u32 i1=0;
 if(b1->count) {
  int off=0;
  do {
   ++i1;
   int a=b1->base+off;
   off+=24;
   func_0047E988((void*)a,delta);
  } while(i1<b1->count);
 }
 Blk *b2=&self->blocks[2];
 if(b2->base) b2->base += delta;
 u32 i2=0;
 if(b2->count) {
  int off=0;
  do {
   ++i2;
   int a=b2->base+off;
   off+=40;
   func_0047F1D8((void*)a,delta);
  } while(i2<b2->count);
 }
 Blk *b3=&self->blocks[3];
 if(b3->base) b3->base += delta;
 Blk *b4=&self->blocks[17];
 if(b4->base) b4->base += delta;
 u32 i4=0;
 if(b4->count) {
  int off=0;
  do {
   ++i4;
   int a=b4->base+off;
   off+=24;
   func_0047FA40((void*)a,delta);
  } while(i4<b4->count);
 }
 Blk *b5=&self->blocks[4];
 if(b5->base) b5->base += delta;
 u32 i5=0;
 if(b5->count) {
  int off=0;
  do {
   ++i5;
   int a=b5->base+off;
   off+=24;
   func_00479730((void*)a,delta);
  } while(i5<b5->count);
 }
 Blk *b6=&self->blocks[5];
 if(b6->base) b6->base += delta;
 u32 i6=0;
 if(b6->count) {
  int off=0;
  do {
   ++i6;
   int a=b6->base+off;
   off+=48;
   func_004798D0((void*)a,delta);
  } while(i6<b6->count);
 }
 Blk *b7=&self->blocks[6];
 if(b7->base) b7->base += delta;
 u32 i7=0;
 if(b7->count) {
  int off=0;
  do {
   ++i7;
   int a=b7->base+off;
   off+=52;
   func_00479BB8((void*)a,delta);
  } while(i7<b7->count);
 }
 Blk *b8=&self->blocks[7];
 if(b8->base) b8->base += delta;
 Blk *b9=&self->blocks[8];
 if(b9->base) b9->base += delta;
 Blk *b10=&self->blocks[9];
 if(b10->base) b10->base += delta;
 u32 i10=0;
 if(b10->count) {
  int off=0;
  do {
   ++i10;
   int a=b10->base+off;
   off+=12;
   func_00479098((void*)a,delta);
  } while(i10<b10->count);
 }
 Blk *b11=&self->blocks[10];
 if(b11->base) b11->base += delta;
 Blk *b12=&self->blocks[11];
 if(b12->base) b12->base += delta;
 Blk *b13=&self->blocks[12];
 if(b13->base) b13->base += delta;
 u32 i13=0;
 if(b13->count) {
  int off=0;
  do {
   ++i13;
   int a=b13->base+off;
   off+=20;
   func_004790B0((void*)a,delta);
  } while(i13<b13->count);
 }
 Blk *b14=&self->blocks[13];
 if(b14->base) b14->base += delta;
 Blk *b15=&self->blocks[14];
 if(b15->base) b15->base += delta;
 u32 i15=0;
 if(b15->count) {
  int off=0;
  do {
   ++i15;
   int a=b15->base+off;
   off+=20;
   func_00479160((void*)a,delta);
  } while(i15<b15->count);
 }
 Blk *b16=&self->blocks[15];
 if(b16->base) b16->base += delta;
 u32 i16=0;
 if(b16->count) {
  do {
   int offset=i16*8;
   ++i16;
   func_00481218((void*)(b16->base+offset),delta);
  } while(i16<b16->count);
 }
 Blk *b17=&self->blocks[16];
 if(b17->base) b17->base += delta;
 u32 i17=0;
 if(b17->count) {
  do {
   int offset=i17*16;
   ++i17;
   func_004790D0((void*)(b17->base+offset),delta);
  } while(i17<b17->count);
 }
}
