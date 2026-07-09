https://theogill.medium.com/creating-a-kernel-from-scratch-1a1aa569780f

First lets Build the assembly file into a object file
```
$ nasm -f elf32 boot.asm -o boot.o
```

Build Kernel.C into a object

```
$ gcc -m32 -c kernel.c -o kernel.o
```

Build Keyboard.C and Source.C
```
$ gcc -m32 -c Keyboard.c -o Keyboard.o
$ gcc -m32 -c Source.c -o Source.o
```
Link everything into one executable
```
ld -m elf_i386 -T linker.ld -o kernel boot.o kernel.o Keyboard.o Source.o
```


Build the .iso


mkdir -p iso/boot/grub
cp kernel iso/boot/
cp grub.cfg iso/boot/grub/
grub-mkrescue -o my-kernel.iso iso/
