struct V{short delta,pad;void(*fn)(void*);};struct O{char p[8];V*table;};struct S{char p[0x2880];O*owner;int flag;char q[0xc00];int value;};
extern "C" void RaceEntryCar__flushSound(S*);
extern "C" void RaceEntryCar__clear(S*self,int flag){O*o=self->owner;V*e=o->table+2;e->fn((char*)o+e->delta);self->flag=0;if(flag)RaceEntryCar__flushSound(self);self->value=0;}
