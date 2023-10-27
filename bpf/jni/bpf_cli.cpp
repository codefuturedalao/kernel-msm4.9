#include <android-base/macros.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <bpf/BpfMap.h>
#include <bpf/BpfUtils.h>
#include <libbpf_android.h>
#include "libbpf.h"

int main() {
    constexpr const char tp_prog_path[] = "/sys/fs/bpf/prog_bpf_test_tracepoint_sched_sched_switch";
    constexpr const char tp_map_path[] = "/sys/fs/bpf/map_bpf_test_cpu_pid_map";
    // Attach tracepoint and wait for 4 seconds
    int mProgFd = bpf_obj_get(tp_prog_path);
    // int mMapFd = bpf_obj_get(tp_map_path);
    bpf_attach_tracepoint(mProgFd, "sched", "sched_switch");
    sleep(1);
    android::bpf::BpfMap<int, int> myMap(tp_map_path);

    while(1) {
        usleep(40000);

        // Read the map to find the last PID that ran on CPU 0
        // android::bpf::BpfMap<int, int> myMap(mMapFd);
        printf("last PID running on CPU %d is %d\n", 0, *myMap.readValue(0));
    }
    exit(0);
}
