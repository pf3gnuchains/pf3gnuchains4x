#objdump: -dr --prefix-addresses --show-raw-insn -Mmsa
#name: MSA64 instructions
#as: -64 -mmsa

.*: +file format .*mips.*

Disassembly of section \.text:
[0-9a-f]+ <[^>]*> 7b03945e 	fill\.d	\$w17,s2
[0-9a-f]+ <[^>]*> 78b8c5d9 	copy_s\.d	s7,\$w24\[0\]
[0-9a-f]+ <[^>]*> 78bbd659 	copy_s\.d	t9,\$w26\[3\]
[0-9a-f]+ <[^>]*> 78f841d9 	copy_u\.d	a3,\$w8\[0\]
[0-9a-f]+ <[^>]*> 78fb5259 	copy_u\.d	a5,\$w10\[3\]
[0-9a-f]+ <[^>]*> 7938c5d9 	insert\.d	\$w23\[0\],t8
[0-9a-f]+ <[^>]*> 793bd659 	insert\.d	\$w25\[3\],k0
[0-9a-f]+ <[^>]*> 035bc815 	dlsa	t9,k0,k1,0x1
[0-9a-f]+ <[^>]*> 03bee0d5 	dlsa	gp,sp,s8,0x4
	\.\.\.
