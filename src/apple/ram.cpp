// Copyright Leon Freist
// Author Leon Freist <freist@informatik.uni-freiburg.de>

#include <hwinfo/platform.h>

#ifdef HWINFO_APPLE

#include <hwinfo/monitoring.h>
#include <hwinfo/ram.h>

#include "internal/smbios.h"

namespace hwinfo {

result<Memory> memory() {
  return memory_usage().transform([](const MemoryUsage& usage) {
    // Modules and slots from SMBIOS on Intel Macs. Apple Silicon has no SMBIOS (memory is part of the SoC package).
    const auto& table = internal::system_table();
    Memory memory = table ? internal::memory_info(*table) : Memory{};
    memory.total = usage.total;
    memory.free = usage.free;
    memory.available = usage.available;
    return memory;
  });
}

}  // namespace hwinfo

#endif  // HWINFO_APPLE
