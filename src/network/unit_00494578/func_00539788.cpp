struct S{unsigned char enabled;char pad[3];int a,b,handle,state;};extern int func_00539A78(S*);
extern "C" int func_00539788(S*s){if(!s)return 2;s->enabled=0;s->a=0;s->b=0;int result=func_00539A78(s);if(!result)s->enabled=1;return result;}
