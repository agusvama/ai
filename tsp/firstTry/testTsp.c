#include <criterion/criterion.h>
#include "tsp.h"

Test(functionsTest, testing_functions){
  int array[3] = {1,2,3};
  int visitedNodes[11] = {11,0,0,0,0,0,0,0,0,0,0};
  cr_assert_eq(includes(array, 3, 3), true);
  cr_assert_eq(includes(array, 5, 3), false);
  cr_assert_eq(includes(visitedNodes, 5, 11), false);
  cr_assert_eq(includes(visitedNodes, 0, 11), true);
  cr_assert_eq(includes(visitedNodes, 11, 11), true);
}

Test(canTravelTest, returns_true_if_can_travel_from_to){
  cr_assert_eq(travel(1, 2), true);
  cr_assert_eq(travel(1, 4), false);
  cr_assert_eq(travel(3, 0), false);
  cr_assert_eq(travel(6, 11), true);
  cr_assert_eq(travel(11, 11), false);
}

Test(travelingTest, returns_total_of_a_travel){
  cr_assert_eq(traveling(1), 2784);
}
