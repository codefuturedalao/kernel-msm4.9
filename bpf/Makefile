ebpf-build:
	/opt/android-ndk/toolchains/llvm/prebuilt/linux-x86_64/bin/clang \
    --target=bpf \
    -c \
    -nostdlibinc -no-canonical-prefixes -O2 \
    -isystem bionic/libc/include \
    -isystem bionic/libc/kernel/uapi \
    -isystem bionic/libc/kernel/uapi/asm-arm64 \
    -isystem bionic/libc/kernel/android/uapi \
    -I       system/core/libcutils/include \
    -I       system/core/base/include \
    -I       system/bpf/progs/include \
    -I       system/bpf/libbpf_android/include \
    -MD -MF bpf_cli.d -o bpf_cli.o jni/bpf_cli.cpp
