#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono;
using namespace std::chrono_literals;

class STimer {
	time_point<steady_clock> start, end;
	duration<float> delt;
public:
	STimer() {
		start = high_resolution_clock::now();
	}

	~STimer() {
		end = high_resolution_clock::now();
		delt = end - start;
		auto result = duration_cast<milliseconds>(end - start).count();
		std::cout << " Time for programm runing is " << result << std::endl;

	}
};


/*
В театральной кассе продаются билеты.
Работает три кассы.
Первый кассир обслуживает одного покупателя за 2 мин., //200
второй – за 2,5 мин.,   //250
третий – за 2,8 мин.    //280
Всего надо обслужить 250 человек.
Через каждые 45 мин.   //4500
кассиры закрывают кассу на 10 минутный технический перерыв.
Время, за которое были обслужены все покупатели и количество покупателей,
обслуженные каждым кассиром.

*/

int CLIENT;

void window(int n, int ms) {
	int people_count{};
	int breack_time = 0;

	while (CLIENT < 250) {
		//std::cout << "Window " << n << "selling ticket\n" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(ms));
		breack_time += ms;
		++CLIENT;
		++people_count;
		if (breack_time > 4500) {
			std::cout << "Window " << n << "goes on breake\n" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
	}
	std::cout << "WINDOW " << n << " = " << people_count << std::endl;

}

int main()
{
	STimer s;

	std::thread t1(window, 1, 200);
	std::thread t2(window, 2, 250 );
	std::thread t3(window, 3, 280 );

	t1.join();
	t2.join();
	t3.join();

	
}

