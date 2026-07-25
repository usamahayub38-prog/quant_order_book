#pragma once

#include <cstdint>
#include <chrono>

enum class Side
{
	Buy,
	Sell
};

class Order
{
public:
	Order(
		uint64_t id,
		Side side,
		double price,
		uint64_t quantity
	);

	uint64_t getId() const;

	Side getSide() const;

	double getPrice() const;

	uint64_t getQuantity() const;

	uint64_t getRemainingQuantity() const;

	void reduceQuantity(uint64_t amount);

private:
	
	uint64_t id_;
	Side side_;
	double price_;
	uint64_t quantity_;
	uint64_t remainingQuanitity_;
	uint64_t timestamp_;
};