# Quant Order Book & Matching Engine

## 1. Project Overview

This project aims to simulate a simplified electronic exchange matching engine.

The system will receive buy and sell limit orders, maintain an order book, automatically match compatible orders, execute trades, and store any remaining unmatched orders.

The project is intended as a software engineering exercise focusing on modern C++, software design, testing, version control, and the software development lifecycle (SDLC).

---

# 2. Objectives

The objectives of this project are to:

- Develop a modular C++ application.
- Implement a simplified exchange order book.
- Implement a matching engine using price-time priority.
- Apply good software engineering practices.
- Demonstrate clean architecture and maintainable code.
- Practise requirements gathering, system design, implementation, testing, and documentation.

---

# 3. Functional Requirements

## FR1 - Accept Orders

The system shall accept new limit orders.

Each order shall contain:

- Order ID
- Order Side (Buy or Sell)
- Price
- Quantity

---

## FR2 - Store Buy Orders

The system shall maintain a collection of active buy orders.

Buy orders shall be prioritised by:

1. Highest price
2. Earliest submission time (FIFO)

---

## FR3 - Store Sell Orders

The system shall maintain a collection of active sell orders.

Sell orders shall be prioritised by:

1. Lowest price
2. Earliest submission time (FIFO)

---

## FR4 - Match Orders

When a new order is received, the system shall immediately attempt to match it with compatible orders on the opposite side of the order book.

---

## FR5 - Execute Trades

When compatible orders are found, the system shall execute trades.

The executed quantity shall be the minimum remaining quantity between the two orders.

---

## FR6 - Support Partial Fills

The system shall support partial execution of orders.

If an order is only partially filled, the remaining quantity shall continue participating in future matching.

---

## FR7 - Remove Completed Orders

Orders that have been completely filled shall be removed from the order book.

---

## FR8 - Maintain Order Book

After every trade, the order book shall remain correctly ordered according to price-time priority.

---

## FR9 - Display Order Book

The system shall provide functionality to display the current state of the order book.

The displayed information should include:

- Buy Orders
- Sell Orders
- Price
- Remaining Quantity

---

# 4. Non-Functional Requirements

The system should:

- Be implemented in modern C++.
- Follow object-oriented design principles.
- Be modular and maintainable.
- Be deterministic (same input produces same output).
- Be easy to extend with additional functionality.
- Be tested using automated unit tests.
- Be managed using Git version control.

---

# 5. Assumptions

For Version 1 of the project:

- Only a single financial instrument will be traded.
- Only limit orders are supported.
- Orders cannot be modified after submission.
- Orders may be cancelled (future enhancement).
- The application will run as a console program.
- The system will operate in a single thread.
- Market data feeds are not simulated.
- Networking is out of scope.

---

# 6. Constraints

- The project is intended for educational purposes.
- The implementation should prioritise correctness and maintainability over absolute performance.
- External libraries should be kept to a minimum unless required for testing.

---

# 7. Future Enhancements

Potential future improvements include:

- Market orders
- Order cancellation
- Order modification
- Multiple financial instruments
- Trade history
- Performance benchmarking
- Multi-threaded matching engine
- Persistent storage
- Network API
- Graphical user interface

---

# 8. Success Criteria

The project will be considered successful when it can:

- Accept buy and sell orders.
- Correctly maintain an order book.
- Automatically match compatible orders.
- Correctly handle partial fills.
- Remove completed orders.
- Preserve price-time priority.
- Pass all implemented unit tests.