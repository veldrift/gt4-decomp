struct __attribute__((packed)) V{unsigned long value;};struct S{char p[0x60];V data;};extern S*D_0064B47C;int func_00531C78(V*p){if(!p)return 23;*p=D_0064B47C->data;return 0;}
