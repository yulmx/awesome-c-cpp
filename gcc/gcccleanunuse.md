make gcccleanunuse_special
gcc -ffunction-sections -fdata-sections -c gcccleanunuse.c
gcc -Wl,--gc-sections -o gcccleanunuse_special gcccleanunuse.o

make gcccleanunuse_normal
gcc -c gcccleanunuse.c
gcc -o gcccleanunuse_normal gcccleanunuse.o

```bash
ls -l gcccleanunuse_*
-rwxrwxr-x 1 yulmx yulmx 16248 Jun 19 01:23 gcccleanunuse_normal
-rwxrwxr-x 1 yulmx yulmx 16000 Jun 19 01:23 gcccleanunuse_special
```
发现：special的size更小，可以减少程序size

分析elf文件
```bash
readelf -a gcccleanunuse_normal | grep func
    22: 00000000000011d3    46 FUNC    GLOBAL DEFAULT   16 func3
    23: 0000000000001177    46 FUNC    GLOBAL DEFAULT   16 func1
    34: 00000000000011a5    46 FUNC    GLOBAL DEFAULT   16 func2
    35: 0000000000001149    46 FUNC    GLOBAL DEFAULT   16 func0

readelf -a gcccleanunuse_special | grep func
    20: 0000000000001177    46 FUNC    GLOBAL DEFAULT   16 func3
    21: 0000000000001149    46 FUNC    GLOBAL DEFAULT   16 func1
```
发现：未使用的函数未被链接进最终的目标文件。

分析 sections
make clean
make gcccleanunuse_special
readelf -t gcccleanunuse.o > gcccleanunuse_special.sections
make clean
make gcccleanunuse_normal
readelf -t gcccleanunuse.o > gcccleanunuse_normal.sections

发现
从object文件中可以发现，fun_0 ~ fun_3 每个函数都是一个独立的section.
而如果使用 make main_normal 生成的object文件，则共享一个默认的sections（.text）。