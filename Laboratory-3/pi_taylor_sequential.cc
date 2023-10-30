#include <iomanip>
#include <iostream>
#include <limits>
#include <chrono>
#include <vector>

// Allow to change the floating point type
using my_float = long double;

my_float pi_taylor(size_t steps) {
	//return 0.0f;
	//Pow converts everything to float. AS we hve the pow of 1, we use if/else
	int sign = 1;
	float sum = 0.0f;

	for (size_t i = 0; i <= steps; i++) {

		sum += sign / static_cast<float>(2 * i + 1);	// es posible que haya que forzar a que uno sea float. por qu� si no forzamos sale otro valor?	
		sign = -sign;
	}

	return 4 * sum;
}

int main() {
/*
    // read the number of steps from the command line
    //Esto no ser�a necesario con el vector de steps
    //if (argc != 2) {
    //    std::cerr << "Invalid syntax: pi_taylor <steps>" << std::endl;
    //    exit(1);

   // }

    //size_t steps = std::stoll(argv[1]);

    //Creamos un vector con todos los valores para ejecutarlo de una vez
    std::vector<std::string> steps = {"16", "128", "1024", "1048576", "4294967295"};

    for (size_t i = 0; i < 5; i++) {
        //Forzamos a que el valor sea long long
        std::string step2=steps[i];
        size_t step = std::stoll(step2);
        //Inicializamos tiempo
        auto start_time = std::chrono::steady_clock::now();
        //Calculamos pi de forma secuencial
        auto pi = pi_taylor(step);
        auto end_time = std::chrono::steady_clock::now();

        //Imprimimos, para el valor: step = steps[i]
        std::cout << "For " << step << ", pi value: "
            << std::setprecision(std::numeric_limits<my_float>::digits10 + 1)
            << pi << std::endl;
        std::cout << "Time " <<std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << "Seconds" << std::endl;
    }
    

*/

    //Si queremos realizar perf
    
    // read the number of steps from the command line
    /*if (argc != 2) {
        std::cerr << "Invalid syntax: pi_taylor <steps>" << std::endl;
        exit(1);

    }*/

    //size_t steps = std::stoll(argv[1]);
    size_t steps = std::stoll("4294967295"); //otra opcion.
    auto pi = pi_taylor(steps);
    std::cout << "For " << steps << ", pi value: "
        << std::setprecision(std::numeric_limits<my_float>::digits10 + 1)
        << pi << std::endl;
    

    
    
}
