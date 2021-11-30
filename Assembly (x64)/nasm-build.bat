set projectName=hello
nasm -f elf64 -o %projectName%.o %projectName%.asm
ld -m elf_x86_64 -o %projectName% %projectName%.o
./%projectName%