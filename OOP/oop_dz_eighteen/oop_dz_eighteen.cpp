#include <iostream>
#include "GamingLaptop.h"
#include "Smartphone.h"

int main()
{
	GamingLaptop laptop1{ "Omen-17", 123323423, "HP", true };
	laptop1.on();
	Smartphone phone{ "Iphone 13", 333333, "Apple" };
	phone.on();
	phone.take_photo();
}
