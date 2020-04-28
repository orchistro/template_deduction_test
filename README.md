# template_deduction_test

For testing function template deduction by an argument which is a Callable.

Wanted to call different template functions based on the return type of the Callable:
* One function template is for Callables that return something.
* The other function template is for Callables that return `void`.

BTW, this got to be implemented without using `concept`.
So, I resorted to using `std::enable_if`.

And this compiles fine with gcc 7 or higher, clang 7 or higher. (clang was tested on http://godbolt.org)

