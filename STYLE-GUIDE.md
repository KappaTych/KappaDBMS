This is a short document describing the preferred coding-style for KappaDBMS.
<br />


##### Google Style-Guide
The main source for all coding-style subtleties can be found here in [Google's style-guides collection](https://github.com/google/styleguide).
<br />
<br />

### Also we have special recommendations on top of that:
________________________________________________________


##### EDITOR MODELINES / PROJECTS GARBAGE
Some editors can interpret configuration information embedded in source files, indicated with special markers.
For example, emacs interprets lines marked like this: `-- mode: c --`.
Do NOT include any of these in source files.
Also do NOT include all garbage produced by your IDE.
It's better to extend '.gitignore' file from such files if there are no patterns for your editor.
People have their own personal editor configurations, and your source files should not override them.
<br />
<br />


##### FILE NAMING
We're hard suggesting you to follow this naming rules:

* C: `.c` for sources and `.h` for headers;
* C++: `.cpp` for sources and `.hpp` for headers;
* Python: `.py` for sources;
* CSS: `.css` for regular css-files and `.scss` for SASS.

<br />


##### INDENTATION
We use 2 spaces for indentation.
Get a decent editor and don't leave whitespace at the end of lines.
<br />
<br />


##### BREAKING LONG LINES
Coding style is all about readability and maintainability using commonly available tools.
The limit on the length of lines is 120 columns and this is a strongly preferred limit.
Statements longer than 120 columns will be broken into sensible chunks, unless exceeding 120 columns significantly increases readability and does not hide information.
Descendants are always substantially shorter than the parent and are placed substantially to the right.
The same applies to function headers with a long argument list.
Make use of vertical spaces to separate different steps of a function.
<br />
<br />


##### FORWARD DECLARATIONS
Use forward declaration in `.h` and `.hpp` files as much as possible.
Instead, include the required files only in the `.c` or `.cpp` files.
This will significantly reduce coupling and compilation times after minor changes.
<br />
<br />


##### TEMPLATES AND META-PROGRAMMING
If you have a task that can be solved without templates - don't use them!
We know that meta-programming is very powerful thing, but there are a lot of reasons to get rid of it.
<br />
<br />


##### TYPEDEFS
Please don't use things like "vc_t" for complex (structures, pointers) things, because it takes a lot of time to understand what does it exactly mean.
You can use only if it helps you to improve readability by making some things (ex., a bunch of namespaces) shorter.
Also, we recommend you to use new typedef syntax:
```
using some_cool_t = boost::library::complex::some<cool>;
```
For 
<br />
<br />


##### BRACKETS
Write left-curly bracket on new line for functions, methods and classes and on same line otherwise.
Just an example of good brackets' style:
```
void someFunction(int value, int expected)
{
	if (value == expected) {
		std::cout << "Passed with original" << std::endl;
	} else if ( secondTry(value) == expected ) {
		std::cout << "Passed with recalculation" << std::endl;
	} else {
		std::cout << "Failed" << std::endl;
	}
}
```
<br />


##### VARIABLE AND FUNCTION NAMES
First of all, use kamelCase (functions, regular and classes' variables / properties) and KamelCase (class'es names and methods) naming-style for everything, except typedef's / using's.
Secondly, use descriptive names.
Don't put multiple assignments on a single line, start all declarations with new line. Ex.:
```
int a, c, b, foo, bar = 2; // <-- Bad!
int bufferSize = 1024; // <-- Good.
void getSomeResult() {}; // <-- Also okay
``` 
<br />


##### FUNCTIONS
Functions should be short and sweet, and do just one thing.
They should fit on one or two screens of text, and do one thing and do that well.
The maximum length of a function is inversely proportional to the complexity and indentation level of that function.
So, if you have a conceptually simple function that is just one long (but simple) case-statement,
where you have to do lots of small things for a lot of different cases, it's OK to have a longer function.
However, if you have a complex function, and you suspect that a less-than-gifted first-year high-school student might not even understand what the function is all about,
you should adhere to the maximum limits all the more closely.
Avoid tricky expressions and use helper functions with descriptive names
(you can ask the compiler to in-line them if you think it's performance-critical, and it will probably do a better job of it than you would have done).

Another measure of the function is the number of local variables.
They shouldn't exceed 5-10, or you're doing something wrong.
Re-think the function, and split it into smaller pieces.
A human brain can generally easily keep track of about 7 different things, anything more and it gets confused.
You know you're brilliant, but maybe you'd like to understand what you did 2 weeks from now.
<br />
<br />


##### ALLOCATING MEMORY
Always use smart pointers, such as std::shared_ptr, to simplify memory management.
<br />
It's normal to use typedef's to make pointers shorter:
```
using std::shared_ptr<Foo> = Foo_S;
using std::weak_ptr<Foo>   = Foo_W;
using std::unique_ptr<Foo> = Foo_U;
```
<br />


##### INCLUDE GUARDS
DON'T use include guards for your code.
Use `#pragma once` instead.
<br />
<br />


##### MACROS, ENUMS AND CONSTANTS
Names of constants are always capitalized SNAKE_CASE.
NEVER use `#define CONSTANT 0x12345` for constants!
Use `const int CONTS_NAME = 12564` instead.
Enums are preferred when defining several related constants.
Also, inline functions are preferable to macros resembling functions.
<br />
<br />


##### COMMENTS
Add comments for functions, function parameters, and logic inside the function.
Please remember that code is often written once but read many times.
Comments are good, but there is also a danger of over-commenting.
NEVER try to explain HOW your code works in a comment: it's much better to write the code so that the working is obvious, and it's a waste of time to explain badly written code.
Generally, you want your comments to tell WHAT your code does, not HOW.
<br />
We suggest you to use JavaDoc style for functions and classes. Ex.:
```
// Single line comment, it's okay
int counter = 1;

double eps = 0.1; // Bad! Don't use this type of comments. There are only one exception - TODOs, for them you can use this style.

/** 
 * The HelloWorldApp class implements an application that
 * simply displays "Hello World!" to the standard output.
 */
class HelloWorld {
public:
	HelloWorld();

	/**
	 * This method just prints some string via std::cout.
	 *
	 * @param std::string String to be printed.
	 * @return 0
	 */
	 int PrintStr(std::string);
}

HelloWorld::HelloWorld() {}

HelloWorld::PrintStr(std::string str)
{
	std::cout << str << str::endl;
	return 0;
}
```
<br />


##### UNUSED CODE
"C doesn't produce garbage" © Dennis Ritchie.
So, don't produce garbage too and clean up all code that wouldn't be used in future!
<br />
<br />


##### THE INLINE DISEASE
Don't use inline unless you know what you are doing.
Overuse use of inline can lead to larger binaries, can cause I-cache thrashing, and can negatively
impact D-cache behaviour if the inlined function accesses large amounts of data and appears in a hot loop.
The decision to inline is usually best left up to the compiler.
The only reason you should use the inline function is to adhere to the one-definition-rule,
i.e., if you want to have method definitions in the header file.
For more details, see [here](https://isocpp.org/wiki/faq/inline-functions#where-to-put-inline-keyword).
<br />
<br />


##### INLINE MEMBER FUNCTIONS
While inline-defined member functions are convenient, they can obscure the publically visible interface of the class, thus making it difficult to use.
By rule of thumb, member accessor definitions that are one line can appear within the class. All other definitions must exist outside the class body.
Example:
```
class Foo {
 public:  
  // Inline definition okay
  void GetBar() const { return bar_; }
  
  // Externally definition
  void Bar2() const;
};

inline void Foo::Bar2() const {
  ... implentation ...
}
```
The example above illustrates a valid use of the `inline` keyword for the definition of `Foo::Bar2()`.
<br />
<br />


##### CONDITIONAL COMPILATION
Wherever possible, don't use preprocessor conditionals (#if, #ifdef) in `.cpp` files; doing so makes code harder to read and logic harder to follow.
Instead, use such conditionals in a header file defining functions for use in those `.cpp` files, providing no-op stub versions in the #else case, and then call those functions unconditionally from `.cpp` files.
The compiler will avoid generating any code for the stub calls, producing identical results, but the logic will remain easy to follow.
