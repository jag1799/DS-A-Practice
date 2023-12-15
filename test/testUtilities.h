/// @author [Jakob Germann, Software Engineer]
/// @date [2023-2024]
/// @name testUtilities
/// @brief Contains Assertion macros for testing functions and classes.
/// @{

#define ASSERT_EQUAL          (a, b) (a == b)
#define ASSERT_NOT_EQUAL      (a, b) (a != b)
#define ASSERT_LEQ            (a, b) (a <= b)
#define ASSERT_GEQ            (a, b) (a >= b)
#define ASSERT_LESS_THAN      (a, b) (a < b)
#define ASSERT_GREATER_THAN   (a, b) (a > b)