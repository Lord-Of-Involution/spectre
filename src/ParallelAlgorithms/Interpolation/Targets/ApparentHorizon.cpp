// Distributed under the MIT License.
// See LICENSE.txt for details.

#include "ParallelAlgorithms/Interpolation/Targets/ApparentHorizon.hpp"

#include <algorithm>

#include "IO/Logging/Verbosity.hpp"
#include "Utilities/GenerateInstantiations.hpp"

namespace Frame {
struct Inertial;
}  // namespace Frame

namespace intrp::OptionHolders {
template <typename Frame>
ApparentHorizon<Frame>::ApparentHorizon(Strahlkorper<Frame> initial_guess_in,
                                        ::FastFlow fast_flow_in,
                                        ::Verbosity verbosity_in)
    : initial_guess(std::move(initial_guess_in)),
      fast_flow(std::move(fast_flow_in)),    // NOLINT
      verbosity(std::move(verbosity_in)) {}  // NOLINT
// clang-tidy std::move of trivially copyable type.

template <typename Frame>
void ApparentHorizon<Frame>::pup(PUP::er& p) {
  p | initial_guess;
  p | fast_flow;
  p | verbosity;
}

template <typename Frame>
bool operator==(const ApparentHorizon<Frame>& lhs,
                const ApparentHorizon<Frame>& rhs) {
  return lhs.initial_guess == rhs.initial_guess and
         lhs.fast_flow == rhs.fast_flow and lhs.verbosity == rhs.verbosity;
}

template <typename Frame>
bool operator!=(const ApparentHorizon<Frame>& lhs,
                const ApparentHorizon<Frame>& rhs) {
  return not(lhs == rhs);
}

// Explicit instantiations
#define FRAME(data) BOOST_PP_TUPLE_ELEM(0, data)

#define INSTANTIATE(_, data)                                         \
  template struct ApparentHorizon<FRAME(data)>;                      \
  template bool operator==(const ApparentHorizon<FRAME(data)>& lhs,  \
                           const ApparentHorizon<FRAME(data)>& rhs); \
  template bool operator!=(const ApparentHorizon<FRAME(data)>& lhs,  \
                           const ApparentHorizon<FRAME(data)>& rhs);
GENERATE_INSTANTIATIONS(INSTANTIATE,
                        (::Frame::Grid, ::Frame::Distorted, ::Frame::Inertial))

#undef FRAME
#undef INSTANTIATE
}  // namespace intrp::OptionHolders
