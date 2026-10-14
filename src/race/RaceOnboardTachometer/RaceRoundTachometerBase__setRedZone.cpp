struct S { char pad[0x860]; int flag; char pad2[0x30];float value; };
extern "C" void func_003EC608(S *);
extern "C" void RaceRoundTachometerBase__setRedZone(S *s,float value) { if(s->value != value || !s->flag) { s->value=value;func_003EC608(s); } }
