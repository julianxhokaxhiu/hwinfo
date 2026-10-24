// Copyright Leon Freist
// Author Leon Freist <freist@informatik.uni-freiburg.de>

#include <hwinfo/platform.h>

#ifdef HWINFO_UNIX

#include <hwinfo/monitoring.h>
#include <hwinfo/ram.h>

#include "internal/smbios.h"

namespace hwinfo {

result<Memory> memory() {
  return memory_usage().transform([](const MemoryUsage& usage) {
        // Modules and slots are only in the raw SMBIOS table, which the kernel exposes to root only. Without it (or
        // without SMBIOS, e.g. on most ARM devices) they stay empty.
        const auto& table = internal::system_table();
        Memory memory = table ? internal::memory_info(*table) : Memory{};
        memory.total = usage.total;
        memory.free = usage.free;
        memory.available = usage.available;
        return memory;
      });
}

}  // namespace hwinfo

#endif  // HWINFO_UNIX
