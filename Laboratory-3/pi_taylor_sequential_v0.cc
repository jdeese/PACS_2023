#include <iomanip>
#include <iostream>
#include <limits>
#include <chrono>

// Allow to change the floating point type
using my_float = long double;

my_float pi_taylor(size_t steps) {


    //pow uses by default float,
    // to save time negate the variable for the -1^n sign=-sign (which would be integer)

    int sign = 1;
	float sum = 0.0f;	
	
	for (size_t i= 0; i <= steps; i++) {
		
		sum += sign / static_cast<float>(2 * i +1);			
		sign = -sign;
	}
	
	return 4*sum;
}

int main(int argc, const char *argv[]) {

    // read the number of steps from the command line
    if (argc != 2) {
        std::cerr << "Invalid syntax: pi_taylor <steps>" << std::endl;
        exit(1);

    }
    
    size_t steps = std::stoll(argv[1]);
    auto start_time =std::chrono::steady_clock::now();
    auto pi = pi_taylor(steps);
    auto end_time =std::chrono::steady_clock::now();

    std::cout << "For " << steps << ", pi value: "
        << std::setprecision(std::numeric_limits<my_float>::digits10 + 1)
        << pi << std::endl;
    std::cout << "Time: " << (end_time-start_time).count() << "microseconds" << std::endl;
}
