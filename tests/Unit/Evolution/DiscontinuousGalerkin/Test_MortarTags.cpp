// Distributed under the MIT License.
// See LICENSE.txt for details.

#include "Framework/TestingFramework.hpp"

#include <cstddef>

#include "Evolution/DiscontinuousGalerkin/MortarTags.hpp"
#include "Helpers/DataStructures/DataBox/TestHelpers.hpp"

namespace evolution::dg {
namespace {
template <size_t Dim>
void test() {
  TestHelpers::db::test_simple_tag<Tags::MortarData<Dim>>("MortarData");
  // can use any CouplingResult in MortarDataHistory, just use double for now.
  TestHelpers::db::test_simple_tag<Tags::MortarDataHistory<Dim, double>>(
      "MortarDataHistory");
  TestHelpers::db::test_simple_tag<Tags::MortarMesh<Dim>>("MortarMesh");
  TestHelpers::db::test_simple_tag<Tags::MortarSize<Dim>>("MortarSize");
  TestHelpers::db::test_simple_tag<Tags::MortarNextTemporalId<Dim>>(
      "MortarNextTemporalId");
  TestHelpers::db::test_simple_tag<Tags::BoundaryMessageFromInbox<Dim>>(
      "BoundaryMessageFromInbox");
}
}  // namespace

SPECTRE_TEST_CASE("Unit.Evolution.DG.MortarTags", "[Unit][Evolution]") {
  test<1>();
  test<2>();
  test<3>();
}
}  // namespace evolution::dg
