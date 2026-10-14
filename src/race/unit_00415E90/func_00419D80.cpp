struct __attribute__((aligned(16))) Vec { float x,y,z,w; };
struct Segment { char opaque[0x30]; Vec delta; float length,inverseLength; };
struct Face { Segment edge; Vec u,v; };
struct Self { Face first; Segment a[8]; Face second; Segment b[10]; };
extern "C" void func_0041BD70(Face*,const Vec*,const Vec*,const Vec*,const Vec*);
extern "C" void func_0041B778(Segment*,const Vec*,const Vec*);
extern "C" void func_00419D80(Self* self,const Vec* points) {
 func_0041BD70(&self->first,points,points+1,points+5,points+9);
 func_0041B778(&self->a[0],points+1,points+2);
 func_0041B778(&self->a[1],points+5,points+6);
 func_0041B778(&self->a[2],points+2,points+3);
 func_0041B778(&self->a[3],points+6,points+7);
 func_0041B778(&self->a[4],points+3,points+4);
 func_0041B778(&self->a[5],points+7,points+8);
 func_0041B778(&self->a[6],points+9,points+10);
 func_0041B778(&self->a[7],points+10,points+11);
 func_0041BD70(&self->second,points+11,points+13,points+14,points+15);
 func_0041B778(&self->b[0],points+18,points+19);
 func_0041B778(&self->b[1],points+22,points+23);
 func_0041B778(&self->b[2],points+19,points+20);
 func_0041B778(&self->b[3],points+23,points+24);
 func_0041B778(&self->b[4],points+16,points+17);
 func_0041B778(&self->b[5],points+13,points+18);
 func_0041B778(&self->b[6],points+14,points+22);
 func_0041B778(&self->b[7],points+20,points+21);
 func_0041B778(&self->b[8],points+24,points+25);
 func_0041B778(&self->b[9],points+15,points+16);
}
