// Distributed under the MIT License.
// See LICENSE.txt for details.

#pragma once

#include <charm++.h>
#include <exception>

namespace sys {

/// \ingroup UtilitiesGroup
/// \brief Exit the program normally.
/// This should only be called once over all processors.
[[noreturn]] inline void exit(const int exit_code = 0) {
  CkExit(exit_code);
  // the following call is never reached, but suppresses the warning that
  // a 'noreturn' function does return
  std::terminate();  // LCOV_EXCL_LINE
}

}  // namespace sys
