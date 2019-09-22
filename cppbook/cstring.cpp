#define _GNU_SOURCE     // (before #include <string>) strdup is not standard C, but if you use GNU libc, then you get it by including the extensions
#include <alloca.h>
#include <string>
#include <cstring>

int main()
{
    std::string s0;
    const char *s1;
    char *s2;
    char *s3;
    char *s4;
    char *s5;

    // This is the initial C++ string.
    s0 = "hello";

    // Method #1: Just use "c_str()" method to obtain a pointer to a
    // null-terminated C string stored in std::string object.
    // Be careful though because when `s0` goes out of scope, s1 points
    // to a non-valid memory.
    s1 = s0.c_str();

    // Method #2: Allocate memory on stack and copy the contents of the
    // original string. Keep in mind that once a current function returns,
    // the memory is invalidated.
    s2 = (char *)alloca(s0.size() + 1);
    memcpy(s2, s0.c_str(), s0.size() + 1);

    // Method #3: Allocate memory dynamically and copy the content of the
    // original string. The memory will be valid until you explicitly
    // release it using "free". Forgetting to release it results in memory
    // leak.
    s3 = (char *)malloc(s0.size() + 1);
    memcpy(s3, s0.c_str(), s0.size() + 1);

    // Method #4: Same as method #3, but using C++ new/delete operators.
    s4 = new char[s0.size() + 1];
    memcpy(s4, s0.c_str(), s0.size() + 1);

    // Method #5: Same as 3 but a bit less efficient..
    s5 = strdup(s0.c_str());

    // Print those strings.
    printf("Original string (%p): %s\n", s0.c_str(), s0.c_str());
    printf("s1 (%p): %s\n", s1, s1);
    printf("s2 (%p): %s\n", s2, s2);
    printf("s3 (%p): %s\n", s3, s3);
    printf("s4 (%p): %s\n", s4, s4);
    printf("s5 (%p): %s\n", s5, s5);

    // Release memory...
    free(s3);
    delete [] s4;
    free(s5);
}