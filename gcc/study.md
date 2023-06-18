exe: 可执行文件
obj: .o文件


strip -s EXE: 用于清除所有的符号信息

使用nm查看下可执行程序的符号信息
nm simplesection > nm-exe
```
000000000000038c r __abi_tag
0000000000004018 B __bss_start
0000000000004018 b completed.0
                 w __cxa_finalize@GLIBC_2.2.5
0000000000004000 D __data_start
0000000000004000 W data_start
0000000000001090 t deregister_tm_clones
0000000000001100 t __do_global_dtors_aux
0000000000003dc0 d __do_global_dtors_aux_fini_array_entry
0000000000004008 D __dso_handle
0000000000003dc8 d _DYNAMIC
0000000000004018 D _edata
0000000000004028 B _end
00000000000011b0 T _fini
0000000000001140 t frame_dummy
0000000000003db8 d __frame_dummy_init_array_entry
0000000000002110 r __FRAME_END__
0000000000001149 T func1
0000000000004010 D global_init_var
0000000000003fb8 d _GLOBAL_OFFSET_TABLE_
000000000000401c B global_uninit_var
                 w __gmon_start__
0000000000002008 r __GNU_EH_FRAME_HDR
0000000000001000 T _init
0000000000002000 R _IO_stdin_used
                 w _ITM_deregisterTMCloneTable
                 w _ITM_registerTMCloneTable
                 U __libc_start_main@GLIBC_2.34
0000000000001174 T main
                 U printf@GLIBC_2.2.5
00000000000010c0 t register_tm_clones
0000000000001060 T _start
0000000000004020 b static_auto_var.0
0000000000004014 d static_var.1
0000000000004018 D __TMC_END__

```

当前这个可执行程序的文件大小
ls -al simplesection
-rwxrwxr-x 1 yulmx yulmx 16168 Jun 18 14:41 simplesection


file simplesection
simplesection: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, BuildID[sha1]=56d46faacd69ba33703b65ba3a133fbf42781e25, for GNU/Linux 3.2.0, not stripped



使用strip清除符号信息
strip -s simplesection
再查看可执行文件的符号信息
nm simplesection > nm-exe1
nm: simplesection: no symbols
当前这个可执行程序的文件大小
ls -al simplesection
-rwxrwxr-x 1 yulmx yulmx 14480 Jun 18 14:49 simplesection

size simplesection
   text    data     bss     dec     hex filename
   1478     608      16    2102     836 simplesection


生成map文件 readelf objdump
-Wl，是告诉gcc编译器，这个是ld的选项参数；而-Map=xxx.map就是指定map文件输出的文件名称
gcc -o simplesection simplesection.c -Wl,-Map=simplesection.map
