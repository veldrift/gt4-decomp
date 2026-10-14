struct Target;struct Owner {char opaque0[0x84];Target* target;};struct Self {Owner* owner;};
struct State {char opaque0[0x1c];unsigned char kind;char opaque1d[0x50];unsigned char mode,enabled,mapped;float rate,scale;};
struct Extended {char opaque0[0x466];unsigned char active,disabled;char opaque468[0x44];short limit;char opaque4ae[3];unsigned char flags;char opaque4b2[0x10f];unsigned char pending;};
extern float D_006220C8[0],D_006220B0[0];extern unsigned char D_006220A8[0];
extern "C" int func_00354E38(Self*);
extern "C" int func_00343C20(Self*);
extern "C" int func_00463C28(State*,int,int);
extern "C" void func_00387D38(Target*,int);
extern "C" void func_00469E48(State*);
inline int getKind(const State* state){return state->kind;}
extern "C" void func_003F19E0(Self* self,int unused,int event,int value){
 State* state=(State*)((char*)self+0x14);Extended* extended=(Extended*)((char*)self+0x104);
 switch(event){
 case 4:
  if(state->mode==value)break;
  state->mode=value;state->scale=D_006220C8[value];state->rate=D_006220B0[value];
  if(func_00354E38(self))state->mapped=D_006220A8[value];
  break;
 case 5:
  if(state->enabled==value)break;
  state->enabled=value;
  if(!value && !extended->disabled && (getKind(state)==1||state->kind==2))func_00463C28(state,6,0);
  break;
 case 6:
  if(!extended->limit||func_00343C20(self))break;
  if(value){if(!(extended->flags&8)){extended->pending=0;extended->flags|=8;}}
  else if(extended->flags&8){extended->flags&=0xf7;if(extended->flags&4)extended->pending=1;}
  break;
 case 10:
  if(!value){extended->active=0;func_00387D38(self->owner->target,0);}
  else {extended->active=1;func_00387D38(self->owner->target,1);func_00469E48(state);}
  break;
 }
}
