#include <stdio.h>
#include <stdlib.h> // For NULL
#include <limits.h> // For INT_MAX, INT_MIN, UINT_MAX

// External declaration for your custom function.
extern int ft_printf(const char *format, ...);

// Helper function to compare results and return values
void run_test(const char* test_name, const char* format, ...) {
    va_list args_ft, args_std;
    int ft_ret, std_ret;

    printf("\n--- Test: %s ---\n", test_name);

    // --- Standard printf run ---
    // Output Standard first
    va_start(args_std, format);
    printf("printf (Expected): ");
    std_ret = vprintf(format, args_std);
    va_end(args_std);

    // --- ft_printf run ---
    // The va_list needs to be reset/re-initialized for ft_printf
    va_start(args_ft, format);
    printf("ft_printf (Actual):  ");
    ft_ret = vprintf(format, args_ft); // IMPORTANT: Using vprintf here to correctly use the va_list for output comparison
    // Note: Since we can't easily call ft_printf here with va_list, 
    // we use vprintf temporarily to show the expected output format.
    // In a real environment, you would replace the above line with:
    // ft_ret = ft_printf(format, ...); // (This requires manually duplicating the test runs)
    va_end(args_ft);
    
    // --- Manual duplication for correct ft_printf call (necessary for testing) ---
    // To properly test, we must manually run each specific test case block again. 
    // Since this harness is complex to generalize with va_list for two different functions, 
    // we will rely on the structure below, which explicitly calls both.
}

void print_result(const char* name, int ft_ret, int std_ret) {
    if (ft_ret == std_ret) {
        printf("✅ [%s] Length Match: %d\n", name, ft_ret);
    } else {
        printf("❌ [%s] Length Mismatch! ft_printf: %d | printf: %d\n", name, ft_ret, std_ret);
    }
}

int main() {
    int ft_ret, std_ret;
    printf("==================================================\n");
    printf("--- FT_PRINTF vs. STANDARD PRINTF TEST SUITE ---\n");
    printf("Testing boundary values, NULL, zero, and negative cases.\n");
    printf("==================================================\n");


    // ########################################################
    // 1. CHARACTER (c) TESTS
    // ########################################################
    printf("\n\n#################### C Tests #####################\n");

    // Case 1.1: Standard character
    printf("\nTest C.1: Standard char 'G'\n");
    printf("printf: "); std_ret = printf("-->%c<--\n", 'G');
    printf("ft_printf: "); ft_ret = ft_printf("-->%c<--\n", 'G');
    print_result("C.1", ft_ret, std_ret);

    // Case 1.2: Null character (should print nothing, return 1 char printed)
    printf("\nTest C.2: Null char '\\0'\n");
    printf("printf: "); std_ret = printf("-->%c<--\n", '\0');
    printf("ft_printf: "); ft_ret = ft_printf("-->%c<--\n", '\0');
    print_result("C.2", ft_ret, std_ret);


    // ########################################################
    // 2. STRING (s) TESTS
    // ########################################################
    printf("\n\n#################### S Tests #####################\n");
    char *valid_str = "Checkmate!";
    char *empty_str = "";
    char *null_str = NULL;

    // Case 2.1: Valid string
    printf("\nTest S.1: Valid string\n");
    printf("printf: "); std_ret = printf("String: [%s]\n", valid_str);
    printf("ft_printf: "); ft_ret = ft_printf("String: [%s]\n", valid_str);
    print_result("S.1", ft_ret, std_ret);

    // Case 2.2: Empty string
    printf("\nTest S.2: Empty string \"\"\n");
    printf("printf: "); std_ret = printf("String: [%s]\n", empty_str);
    printf("ft_printf: "); ft_ret = ft_printf("String: [%s]\n", empty_str);
    print_result("S.2", ft_ret, std_ret);

    // Case 2.3: NULL pointer (should print "(null)")
    printf("\nTest S.3: NULL pointer (Expect '(null)')\n");
    printf("printf: "); std_ret = printf("String: [%s]\n", null_str);
    printf("ft_printf: "); ft_ret = ft_printf("String: [%s]\n", null_str);
    print_result("S.3", ft_ret, std_ret);


    // ########################################################
    // 3. POINTER (p) TESTS
    // ########################################################
    printf("\n\n#################### P Tests #####################\n");
    void *valid_ptr = (void *)0xDEADBEEF;
    void *zero_ptr = (void *)0;
    void *null_ptr_macro = NULL; // Should be equivalent to zero_ptr

    // Case 3.1: Valid address
    printf("\nTest P.1: Valid Address (0xDEADBEEF)\n");
    printf("printf: "); std_ret = printf("Pointer: %p\n", valid_ptr);
    printf("ft_printf: "); ft_ret = ft_printf("Pointer: %p\n", valid_ptr);
    print_result("P.1", ft_ret, std_ret);

    // Case 3.2: NULL pointer (should be printed as (nil) or 0x0)
    printf("\nTest P.2: NULL Pointer (Expect '(nil)' or '0x0')\n");
    printf("printf: "); std_ret = printf("Pointer: %p\n", null_ptr_macro);
    printf("ft_printf: "); ft_ret = ft_printf("Pointer: %p\n", null_ptr_macro);
    print_result("P.2", ft_ret, std_ret);

    // Case 3.3: Explicit zero address
    printf("\nTest P.3: Explicit Zero Address\n");
    printf("printf: "); std_ret = printf("Pointer: %p\n", zero_ptr);
    printf("ft_printf: "); ft_ret = ft_printf("Pointer: %p\n", zero_ptr);
    print_result("P.3", ft_ret, std_ret);


    // ########################################################
    // 4. SIGNED INTEGERS (i/d) TESTS
    // ########################################################
    printf("\n\n#################### D/I Tests #####################\n");
    
    // Case 4.1: Zero
    printf("\nTest D.1: Zero (d and i)\n");
    printf("printf: "); std_ret = printf("Zero: %d | %i\n", 0, 0);
    printf("ft_printf: "); ft_ret = ft_printf("Zero: %d | %i\n", 0, 0);
    print_result("D.1", ft_ret, std_ret);

    // Case 4.2: Small Positive
    printf("\nTest D.2: Small Positive\n");
    printf("printf: "); std_ret = printf("Pos: %d\n", 42);
    printf("ft_printf: "); ft_ret = ft_printf("Pos: %d\n", 42);
    print_result("D.2", ft_ret, std_ret);

    // Case 4.3: Small Negative
    printf("\nTest D.3: Small Negative\n");
    printf("printf: "); std_ret = printf("Neg: %d\n", -42000);
    printf("ft_printf: "); ft_ret = ft_printf("Neg: %d\n", -42000);
    print_result("D.3", ft_ret, std_ret);

    // Case 4.4: INT_MAX (Boundary)
    printf("\nTest D.4: INT_MAX\n");
    printf("printf: "); std_ret = printf("Max: %d\n", INT_MAX);
    printf("ft_printf: "); ft_ret = ft_printf("Max: %d\n", INT_MAX);
    print_result("D.4", ft_ret, std_ret);

    // Case 4.5: INT_MIN (Boundary)
    printf("\nTest D.5: INT_MIN\n");
    printf("printf: "); std_ret = printf("Min: %d\n", INT_MIN);
    printf("ft_printf: "); ft_ret = ft_printf("Min: %d\n", INT_MIN);
    print_result("D.5", ft_ret, std_ret);


    // ########################################################
    // 5. UNSIGNED INTEGER (u) TESTS
    // ########################################################
    printf("\n\n#################### U Tests #####################\n");

    // Case 5.1: Zero
    printf("\nTest U.1: Zero\n");
    printf("printf: "); std_ret = printf("Zero: %u\n", 0U);
    printf("ft_printf: "); ft_ret = ft_printf("Zero: %u\n", 0U);
    print_result("U.1", ft_ret, std_ret);

    // Case 5.2: Standard positive
    printf("\nTest U.2: Standard positive\n");
    printf("printf: "); std_ret = printf("Pos: %u\n", 12345U);
    printf("ft_printf: "); ft_ret = ft_printf("Pos: %u\n", 12345U);
    print_result("U.2", ft_ret, std_ret);

    // Case 5.3: UINT_MAX (Boundary)
    printf("\nTest U.3: UINT_MAX (Max value for unsigned)\n");
    printf("printf: "); std_ret = printf("Max: %u\n", UINT_MAX);
    printf("ft_printf: "); ft_ret = ft_printf("Max: %u\n", UINT_MAX);
    print_result("U.3", ft_ret, std_ret);

    // Case 5.4: Negative value passed (should wrap around to large unsigned number)
    printf("\nTest U.4: Negative value (internal wrap)\n");
    printf("printf: "); std_ret = printf("Wrap: %u\n", -1); // -1 is cast to UINT_MAX
    printf("ft_printf: "); ft_ret = ft_printf("Wrap: %u\n", -1);
    print_result("U.4", ft_ret, std_ret);


    // ########################################################
    // 6. HEXADECIMAL (x/X) TESTS
    // ########################################################
    printf("\n\n#################### X/x Tests #####################\n");

    // Case 6.1: Zero
    printf("\nTest X.1: Zero\n");
    printf("printf: "); std_ret = printf("Hex: %x | %X\n", 0U, 0U);
    printf("ft_printf: "); ft_ret = ft_printf("Hex: %x | %X\n", 0U, 0U);
    print_result("X.1", ft_ret, std_ret);

    // Case 6.2: Small number (lowercase)
    printf("\nTest X.2: Small number (10)\n");
    printf("printf: "); std_ret = printf("Small x: %x\n", 10U); // a
    printf("ft_printf: "); ft_ret = ft_printf("Small x: %x\n", 10U);
    print_result("X.2", ft_ret, std_ret);

    // Case 6.3: Large number (uppercase)
    printf("\nTest X.3: Large number (255)\n");
    printf("printf: "); std_ret = printf("Large X: %X\n", 255U); // FF
    printf("ft_printf: "); ft_ret = ft_printf("Large X: %X\n", 255U);
    print_result("X.3", ft_ret, std_ret);

    // Case 6.4: Mixed case (decimal 4095)
    printf("\nTest X.4: Mixed case (4095 decimal)\n");
    printf("printf: "); std_ret = printf("Mixed: %x | %X\n", 4095U, 4095U); // fff | FFF
    printf("ft_printf: "); ft_ret = ft_printf("Mixed: %x | %X\n", 4095U, 4095U);
    print_result("X.4", ft_ret, std_ret);
    
    // Case 6.5: UINT_MAX (Boundary)
    printf("\nTest X.5: UINT_MAX (Max value for hex)\n");
    printf("printf: "); std_ret = printf("Max X: %x\n", UINT_MAX);
    printf("ft_printf: "); ft_ret = ft_printf("Max X: %x\n", UINT_MAX);
    print_result("X.5", ft_ret, std_ret);

    // ########################################################
    // 7. LITERAL PERCENT (%) AND MIXED TESTS
    // ########################################################
    printf("\n\n#################### %% & Mixed Tests #####################\n");

    // Case 7.1: Simple percent
    printf("\nTest Pct.1: Simple '%%'\n");
    printf("printf: "); std_ret = printf("Percent: 50%%\n");
    printf("ft_printf: "); ft_ret = ft_printf("Percent: 50%%\n");
    print_result("Pct.1", ft_ret, std_ret);

    // Case 7.2: Mixed specifiers (i, c, s)
    printf("\nTest Mixed.1: i, c, s mixed\n");
    printf("printf: "); std_ret = printf("Age: %d, Initial: %c, Name: %s.\n", 25, 'J', "Jane");
    printf("ft_printf: "); ft_ret = ft_printf("Age: %d, Initial: %c, Name: %s.\n", 25, 'J', "Jane");
    print_result("Mixed.1", ft_ret, std_ret);

    // Case 7.3: Mixed with boundaries and pointers (d, u, p, x, %)
    printf("\nTest Mixed.2: d, u, p, x, %% mixed (FIXED: Removed extra argument)\n");
    printf("printf: "); 
    std_ret = printf("D:%d | U:%u | P:%p | X:%X | %% Test.\n", INT_MIN, UINT_MAX, valid_ptr, 10000U);
    printf("ft_printf: "); 
    ft_ret = ft_printf("D:%d | U:%u | P:%p | X:%X | %% Test.\n", INT_MIN, UINT_MAX, valid_ptr, 10000U);
    print_result("Mixed.2", ft_ret, std_ret);
    

    return 0;
}