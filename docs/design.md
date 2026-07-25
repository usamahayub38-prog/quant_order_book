# Quant Order Book & Matching Engine - System Design

## 1. System Overview

The Quant Order Book & Matching Engine is a simplified simulation of an electronic exchange matching system.

The system receives incoming buy and sell limit orders, maintains an order book of unmatched orders, identifies compatible orders, executes trades, and updates the remaining market state.

The design follows a modular architecture where each component has a clear responsibility.

---

# 2. High-Level Architecture

The system consists of four main components:

```
                 Incoming Orders
                       |
                       v
              +----------------+
              | Matching Engine |
              +----------------+
                       |
          +------------+------------+
          |                         |
          v                         v
   +-------------+          +-------------+
   | Buy Orders  |          | Sell Orders |
   | Order Book  |          | Order Book  |
   +-------------+          +-------------+
                       |
                       v
                Executed Trades
```

---

# 3. System Components

## 3.1 Order

### Purpose

Represents a single order submitted to the exchange.

An order contains the information required for matching and execution.

### Responsibilities

The Order component shall store:

- Unique order identifier
- Order side (Buy or Sell)
- Price
- Quantity
- Submission timestamp

### Design Notes

The Order object is a data representation only.

It should not:

- Perform matching
- Modify other orders
- Interact with the order book

These responsibilities belong to higher-level components.

---

# 3.2 Order Book

## Purpose

The Order Book maintains all currently active orders that have not been completely executed.

The book is divided into two sides:

- Buy side (Bids)
- Sell side (Asks)

---

## Buy Side

Buy orders are prioritised by:

1. Highest price
2. Earliest submission time

Example:

```
Price
105
103
100
```

The highest bid has the highest execution priority.

---

## Sell Side

Sell orders are prioritised by:

1. Lowest price
2. Earliest submission time

Example:

```
Price
101
102
105
```

The lowest ask has the highest execution priority.

---

## Responsibilities

The Order Book shall:

- Add new orders
- Remove completed orders
- Provide access to the best available buy order
- Provide access to the best available sell order
- Display current order book state

---

## Non-Responsibilities

The Order Book shall not:

- Decide whether orders can trade
- Execute trades
- Calculate trade quantities

These responsibilities belong to the Matching Engine.

---

# 3.3 Matching Engine

## Purpose

The Matching Engine controls the trading logic.

It receives incoming orders and determines whether they can be matched against existing orders.

---

## Responsibilities

The Matching Engine shall:

1. Receive incoming orders
2. Check the opposite side of the order book
3. Determine whether prices are compatible
4. Execute trades
5. Update order quantities
6. Store any remaining quantity

---

## Matching Rules

### Buy Order

A buy order can match when:

```
Buy Price >= Lowest Sell Price
```

---

### Sell Order

A sell order can match when:

```
Sell Price <= Highest Buy Price
```

---

## Trade Quantity

The executed quantity is:

```
minimum(buy quantity, sell quantity)
```

This allows partial order execution.

---

# 3.4 Trade

## Purpose

Represents a completed transaction between a buyer and seller.

---

## Responsibilities

A Trade records:

- Buyer order ID
- Seller order ID
- Execution price
- Executed quantity
- Execution timestamp

---

# 4. Order Processing Flow

When a new order arrives:

```
              New Order
                  |
                  v
          Matching Engine
                  |
          Can order match?
                  |
        +---------+---------+
        |                   |
       Yes                  No
        |                   |
        v                   v
 Execute Trade        Add to Order Book
        |
        v
 Update Remaining Quantity
        |
        v
 Remove Completed Orders
```

---

# 5. Price-Time Priority

The matching engine follows exchange priority rules.

## Price Priority

The best price executes first.

For buyers:

Higher prices have priority.

Example:

```
Buy £105
Buy £100
```

The £105 order executes first.

---

For sellers:

Lower prices have priority.

Example:

```
Sell £99
Sell £102
```

The £99 order executes first.

---

## Time Priority

If multiple orders exist at the same price:

The earliest order submitted executes first.

Example:

```
09:00 Buy £100
09:01 Buy £100
```

The 09:00 order receives execution priority.

---

# 6. Design Principles

## Separation of Responsibilities

Each component has a single responsibility.

Example:

| Component | Responsibility |
|-----------|----------------|
| Order | Store order information |
| OrderBook | Maintain active orders |
| Matching Engine | Apply matching rules |
| Trade | Represent executed transactions |

---

## Modularity

Components should be independent and easy to test.

For example:

- Order matching logic can be tested independently.
- Order storage can be tested independently.

---

## Extensibility

The design should allow future features without major restructuring.

Possible future additions:

- Market orders
- Order cancellation
- Multiple instruments
- Market data simulation
- Networking
- Performance optimisation

---

# 7. Version 1 Scope

## Included Features

- Limit orders
- Single instrument
- Buy/sell order book
- Price-time priority
- Order matching
- Partial fills
- Trade generation
- Unit testing

---

## Excluded Features

The following are outside the scope of Version 1:

- Real exchange connectivity
- Multiple trading venues
- Database persistence
- Network communication
- Graphical user interface
- Multi-threaded processing

---

# 8. Future Improvements

Potential improvements include:

## Performance

- Benchmark matching latency
- Optimise data structures
- Reduce memory allocations

## Concurrency

- Multi-threaded order processing
- Lock-free data structures

## Market Simulation

- Historical market replay
- Multiple traders
- Market data feeds

## Trading Features

- Market orders
- Stop orders
- Order cancellation
- Order modification