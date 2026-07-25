#include "Order.h"

Order::Order(
	uint64_t id,
	Side side,
	double price,
	uint64_t quantity
)

	:
	id_(id),
	side_(side),
	price_(price),
	quantity_(quantity),
	remainingQuanitity_(quantity),
	timestamp_(0)
{

}

uint64_t Order::getId() const
{
	return id_;
}

Side Order::getSide() const
{
	return side_;
}

double Order::getPrice() const
{
	return price_;
}


uint64_t Order::getQuantity() const
{
	return quantity_;
}


uint64_t Order::getRemainingQuantity() const
{
	return remainingQuanitity_;
}

void Order::reduceQuantity(uint64_t amount)
{
	if (amount <= remainingQuanitity_)
	{
		remainingQuanitity_ -= amount;
	}
}
