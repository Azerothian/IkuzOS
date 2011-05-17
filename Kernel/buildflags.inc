# Compilation Flags
CFLAGS = -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -fno-omit-frame-pointer -fno-builtin -ffreestanding -DARCH=$(IKUZOS_ARCH) -DSUBARCH=$(IKUZOS_SUBARCH) -DMAJOR_VER="$(IKUZOS_MAJOR)" -DMINOR_VER="$(IKUZOS_MINOR)" -DREVISION="$(IKUZOS_REVISION)" -DIKUZOS_KERNEL_VER="$(IKUZOS_KERNELVER)" -DIKUZOS_NAME="$(IKUZOS_VER_STRING)" -DIKUZOS_CODENAME="$(IKUZOS_CODENAME)"
CDEBUG = -D__DEBUG__
NASMFLAGS = -f elf