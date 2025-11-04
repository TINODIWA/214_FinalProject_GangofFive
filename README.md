# 214_FinalProject_GangofFive
# Garden Nursery Management System

This project is a C++ implementation of a garden nursery management system, designed to simulate and manage the operations of a nursery. It leverages several object-oriented design patterns, including Builder, Decorator, Chain of Responsibility, and Command, to provide a modular and extensible architecture.

## Features

- *Staff Management*: Hire, fire, and assign roles to staff members (e.g., Admin, Sales, Gardening, Management).
- *Customer Care*: Mediate interactions between customers and staff.
- *Garden Construction*: Build and manage garden plots, crops, and plants using the Builder and Director patterns.
- *Payment Processing*: Support for multiple payment methods (Card, Cash, EFT).
- *Inventory Management*: Track and update plant inventory, including handling dead or dying plants.
- *Command Pattern*: Assign and execute tasks dynamically among staff members.
- *File-Based Garden Initialization*: Initialize gardens from data files.

## Project Structure

- [Main.cpp](Main.cpp): Entry point and demonstration of system features.
- [Director.h/cpp](Director.cpp): Coordinates the building of gardens using builders.
- [Builder.h/cpp](Builder.cpp), [CropBuilder.h/cpp](CropBuilder.cpp), [PlantBuilder.h/cpp](PlantBuilder.cpp): Implement the Builder pattern for constructing crops and plants.
- [Staff.h/cpp](Staff.cpp), [BaseStaff.h/cpp](BaseStaff.cpp), [Admin.h/cpp](Admin.cpp), [Sales.h/cpp](Sales.cpp), [Gardening.h/cpp](Gardening.cpp), [Management.h/cpp](Management.cpp): Staff roles and Decorator pattern implementation.
- [CustomerCare.h/cpp](CustomerCare.cpp): Handles customer-staff interactions.
- [Payment.h/cpp](Payment.cpp), [Card.h/cpp](Card.cpp), [Cash.h/cpp](Cash.cpp), [EFT.h/cpp](EFT.cpp): Payment processing classes.
- [Garden.h/cpp](Garden.cpp), [GardenPlot.h/cpp](GardenPlot.cpp), [Crop.h/cpp](Crop.cpp), [Plant.h/cpp](Plant.cpp): Garden, plot, crop, and plant representations.
- [Command.h/cpp](Command.cpp), [CheckInventory.h/cpp](CheckInventory.cpp), [CheckPlant.h/cpp](CheckPlant.cpp), [HireStaff.h/cpp](HireStaff.cpp), [FireStaff.h/cpp](FireStaff.cpp): Command pattern for staff tasks.
- [makefile](makefile): Build instructions.

## Build Instructions

1. *Requirements*:  
	- C++ compiler using c++11 standard (e.g., g++)
	- Make

2. *Build the Project*:
	sh
	make main
	

3. *Run the Program*:
	sh
	./main
	

## Usage

- The main program demonstrates staff creation, garden building, payment processing, and command execution.
- Modify or extend the classes to add new staff roles, payment types, or garden features.

## Authors

- Nathan Chisadza
- Unathi Tshakalisa
- Swelihle Makhathini
- Dominiqu Nigatu
- Ryan Liao