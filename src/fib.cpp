//: Title       : fib.cpp
//: Date        : 2021-10-04
//: Author      : "Kjetil Kristoffer Solberg" <post@ikjetil.no>
//: Version     : 1.2
//: Description : A simple fibonacci series n-th calculator.
//
// #include
//
#include <iostream>
#include <iomanip>
#include <cmath>

namespace ItSoftware::Fibonacci
{
	//
	// using
	//
	using std::cout;
	using std::stol;
	using std::endl;
	using std::setw;
	using std::setfill;
	using std::locale;
	using std::pow;
	using std::sqrt;

	//
	// global data
	//
	uint64_t g_cc = 0;

	//
	// #define
	//
	constexpr auto VERSION_NO = "1.2";
	constexpr auto CLR_GREEN = "\033[32m";
	constexpr auto CLR_WHITE = "\033[37;1m";
	constexpr auto CLR_RESET = "\033[0m";

	//
	// Function: Fib
	//
	// (i): calculate the fibonacci series
	//
	uint64_t FibRecursive(const uint64_t l) 
	{
		g_cc++;

		switch(l) {
		case 0: return 0;
		case 1: return 1;
		}
		return FibRecursive(l-1) + FibRecursive(l-2);
	}

	//
	// Function: FibFormula
	//
	// (i): calculate fibonnaci using formula
	//
	uint64_t FibFormula(const uint64_t l)
	{
		const auto sqrt_5 = sqrt(5);
		return ((pow((1+sqrt_5),l) - pow((1-sqrt_5),l))/(pow(2,l)*sqrt_5)); 
	}

	//
	// Function: main
	//
	// (i): entry point
	//
	int main(int argc, const char* argv[])
	{
		cout << CLR_RESET << CLR_GREEN;
		cout << "##" << endl;
		cout << "## Fibonnaci Series N-th Calculator" << endl;
		cout << "## Author  : Kjetil Kristoffer Solberg <post@ikjetil.no>" << endl;
		cout << "## Version : " << VERSION_NO << endl;
		cout << "## Usage   : fib <integer>" << endl;
		cout << "##" << endl;
		cout << CLR_RESET << CLR_WHITE;

		if ( argc != 2 ) {
			cout << "ABEND FAILURE: INVALID NUMBER OF ARGUMENTS." << endl;
			return EXIT_FAILURE;
		}

		long l = 0;
		try
		{
			l = stol(argv[1]);
		}
		catch ( std::logic_error ) {
			cout << "ABEND FAILURE: INVALID ARGUMENT VALUE. NOT A NUMBER." << endl;
			return EXIT_FAILURE;
		}

		if ( l <= 0 || l > 93 ) {
			cout << "ABEND FAILURE: INVALID ARGUMENT VALUE. OUT OF RANGE." << endl;
			return EXIT_FAILURE;
		}

		try
		{
			cout.imbue(locale(""));
		}
		catch (std::runtime_error) {
			// ignore
		}

		cout << CLR_RESET << CLR_GREEN;
		cout << "## Calculating for n-th: " << l << endl;
		cout << "##" << endl;
		cout << CLR_RESET << CLR_WHITE;

		cout << setw(15) << "Method" << setw(30) << "Result" << setw(30) << "Func. Calls" << endl;
		cout << setw(15) << ">> FibFormula" << setw(30) << setfill(' ') << FibFormula(l) << setw(30) << "1" << endl;

		if (l <= 50 ) {
			cout << setw(15) << ">> FibRecursive" << setw(30) << setfill(' ') << FibRecursive(l) << setw(30) << g_cc << endl;
		}
		else {
			cout << setw(15) << ">> FibRecursive" << setw(30) << setfill(' ') << "-" << setw(30) << "-" << endl;
		}

		return EXIT_SUCCESS;
	}
}

//
// Function: main
//
// (i): Entry point.
//      Redirect to ItSoftware::Fibonacci::main.
//
int main(int argc, const char* argv[])
{
	return ItSoftware::Fibonacci::main(argc, argv);
}