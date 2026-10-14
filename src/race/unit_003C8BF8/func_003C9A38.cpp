struct Vec2 {float x,y;};
struct __attribute__((packed)) Pair {unsigned long value;};
struct State {int kind;Pair position;int hits,index,edge,vertex;float distance;int flags;};
struct Polygon {int count;Vec2 points[0];};
struct Self {unsigned short opaque0,count;Polygon** polygons;};
extern "C" int func_003C9E70(Self*,const Vec2*);
extern "C" void func_003C8F38(State*);
extern "C" void func_003C8F60(State*,const Vec2*);
extern "C" float func_003C9298(Polygon*,int,const Vec2*,const Vec2*,State*);
extern "C" float func_003C96E0(Polygon*,int,const Vec2*,const Vec2*,State*,int);
extern "C" float func_003C9908(Polygon*,int,const Vec2*,const Vec2*,State*,int);
extern "C" float func_003C9A38(Self* self,const Vec2* from,const Vec2* to,State* state){
 int inside=func_003C9E70(self,to);
 State backup=*state;
 float result=0;
 switch(state->kind){
 case 0:
  func_003C8F38(state);func_003C8F60(state,from);
  for(int i=0;i<self->count;++i)func_003C9298(self->polygons[i],i,from,to,state);
  if(!state->hits && inside)func_003C8F60(state,to);
  break;
 case 1:
  if(state->index>=0)result=func_003C96E0(self->polygons[state->index],state->index,from,to,state,inside);
  else if(inside)func_003C8F60(state,to);
  break;
 case 2:
  if(state->index>=0)result=func_003C9908(self->polygons[state->index],state->index,from,to,state,inside);
  else if(inside)func_003C8F60(state,to);
  break;
 }
 return result;
}
