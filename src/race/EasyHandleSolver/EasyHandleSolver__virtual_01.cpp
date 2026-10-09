typedef unsigned int u128 __attribute__((mode(TI)));
typedef union Vec {u128 bits;float v[4];} Vec;
typedef struct Solver {int side;char pad[12];Vec point;} Solver;
typedef struct Input {char pad[0x50];Vec point;char gap[0xE0-0x60];float separation;} Input;
extern "C" int func_004154A0(Solver *self,int unused1,int unused2,Input *input) {Vec *point=&self->point;point->bits=input->point.bits;float x=point->v[0];float adjusted;if(!self->side)adjusted=x+input->separation;else adjusted=x-input->separation;point->v[0]=adjusted;return 1;}
