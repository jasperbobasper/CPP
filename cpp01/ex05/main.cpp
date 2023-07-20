#include "Harl.hpp"

int	main(void)
{
	Harl ha;

	ha.complain("debug");
	ha.complain("info");
	ha.complain("warning");
	ha.complain("error");
	ha.complain("info");
	return (0);
}