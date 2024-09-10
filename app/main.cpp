#include "admin.h"
#include "client.h"
using namespace std;

int main()
{
	Client s("dada", "55012", "01221191831", "dada@bv.f", 55210, 6000),
		c("Abdo", "550562", "01221291831", "dada@bv.f", 551200, 10000);


	

	c.transferTo(5000, s);

	c.displayInfo();
	s.displayInfo();

}
