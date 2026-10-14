struct Base{char pad[0x14];void*vt;Base() __asm__("func_003AEBA8");};struct S:Base{int a;unsigned b;int c,d;S() __asm__("func_003A5760");};extern char RaceFuelMeter__vtable[];
S::S(){vt=RaceFuelMeter__vtable;a=0;b=0x80e3b896u;c=0;d=0;}
