struct S{unsigned unused,pos,end,total;char*data;};
extern "C" int func_005385B0(S*,unsigned*);
extern "C" void*func_005A4724(void*,const void*,unsigned);
extern "C" int func_00538228(S*s,const char*src,unsigned size){unsigned avail=0;int result=2;if(s&&src&&size){int r=func_005385B0(s,&avail);if(r)return r;if(avail>=size){unsigned tail=s->end-s->pos;if(tail>=size){func_005A4724(s->data+s->pos,src,size);s->total+=size;s->pos+=size;if(s->pos==s->end)s->pos=0;}else{size-=tail;func_005A4724(s->data+s->pos,src,tail);s->total+=tail;func_005A4724(s->data,src+tail,size);unsigned total=s->total;s->pos=size;s->total=total+size;}result=0;}else result=200;}return result;}
