#include <iostream>
#include <string>
#include <cassert>
#include <map>
#include <BeeNum/Brat.h>

using namespace BeeNum;


int main() {
	Brat a;
	Brat c;

	std::vector<std::vector<std::string>> data = {
		{"453453/434538", "1.04352898940944175192963561299587147729312511218811", "1.1kevzj90iucwsuh3jpribijw1mmg61qt71c5kztpvp2duatfet_b36"},
		{"171770057/8920503206", "0.01925564657433967632610253892890086810647574134171", "0.0oye3bbxc9ql9aq5wf6pcs85eirfkx3mojty0nze25udix3o6q_b36"},
		{"3648111/3648112", "0.99999972588560877516918340226396558000412268044402", "0.zzzzjfb96azavcnmk4nog2c7q7zyq5wghfp6i9805vzpdrcw1e_b36"},
		{"364811100000/3648112", "99999.97258856087751691834022639655800041226804440214554", "255r.z0h3b3ihxp0vodkay768y1nrfhr9lcttlmjblmude4q62lh9mu_b36"},
	};
	
	///////////////////////////////////////////////////////////

	std::cout << "Point:" << std::endl;
	std::cout << "Decimal:" << std::endl;
	int p = 50;

	for (auto& s : data) {
		a = s[0];
		std::cout << "a = " << a << std::endl;
		std::cout << "a.point = " << a.point(p) << std::endl;
		std::cout << "s = " << s[1] << std::endl;
		assert(a.point(p) == s[1]);
		std::cout << std::endl;
	}

	std::cout << "Base36:" << std::endl;
	int b = 36;
	for (auto& s : data) {
		a = s[0];
		std::cout << "a = " << a << std::endl;
		std::cout << "a.point = " << a.point(p) << std::endl;
		std::cout << "a.point = " << a.point(p, b) << std::endl;
		std::cout << "s = " << s[1] << std::endl;
		std::cout << "s = " << s[2] << std::endl;
		assert(a.point(p, b) == s[2]);
		std::cout << std::endl;
	}

}
